#include <fcntl.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <google/protobuf/text_format.h>
#include <iostream>
#include <unistd.h>

#include "symbol.pb.h"

using namespace kicad::proto;

int main()
{
    symbol::Symbol symbol;
    auto shape = symbol.add_shapes();
    shape->set_line_type( common::LineType::DOTTED );
    auto point = shape->mutable_line()->add_points();
    point->set_x( 2 );
    point->set_y( 3 );

    shape = symbol.add_shapes();
    auto circle = shape->mutable_circle();
    circle->mutable_center()->set_x( 0 );
    circle->mutable_center()->set_y( 100 );
    circle->set_radius( 42 );

    auto pin = symbol.add_pins();
    pin->set_type( symbol::Pin_PinType::Pin_PinType_BIDIRECTIONAL );
    auto pin_name = pin->mutable_name();
    pin_name->set_text( "1" );
    pin->mutable_at()->set_x( 100 );
    pin->mutable_at()->set_y( 100 );
    pin->set_angle( 100 );

    pin = symbol.add_pins();
    pin->set_type( symbol::Pin_PinType::Pin_PinType_PASSIVE );
    pin->mutable_number()->set_text( "2" );

    auto part = symbol.add_parts();
    part->set_name( "ANTIMATTER CONDENSER" );
    part->set_power( true );
    auto property = part->add_properties();
    property->set_name( "OUTPUT" );
    property->set_value( "121GW" );
    property->set_visible( true );

    int fd = open( "symbol.pb", O_CREAT | O_TRUNC | O_WRONLY, S_IRUSR | S_IWUSR );
    std::cout << fd << std::endl;
    google::protobuf::io::FileOutputStream fileOutputStream( fd );
    google::protobuf::TextFormat::Print( symbol, &fileOutputStream );
    fileOutputStream.Close();
    close( fd );

    fd = open( "symbol.pb", O_RDONLY );
    google::protobuf::io::FileInputStream fileInputStream( fd );
    symbol::Symbol symbol2;
    google::protobuf::TextFormat::Parse( &fileInputStream, &symbol2 );
    fileInputStream.Close();
    close( fd );

    google::protobuf::io::OstreamOutputStream stdoutStream( &std::cout );
    google::protobuf::TextFormat::Print( symbol2, &stdoutStream );
}
