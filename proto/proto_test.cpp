#include <iostream>
#include <google/protobuf/text_format.h>

#include "common.pb.h"

int main() {
  ColorRGBA color;
  color.set_r(100);
  color.set_g(0);
  color.set_b(200);
  color.set_a(256);

  std::string str;
  google::protobuf::TextFormat::PrintToString(color, &str);
  std::cout << str << std::endl;
}