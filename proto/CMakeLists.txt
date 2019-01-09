find_package(Protobuf REQUIRED)

include_directories(${Protobuf_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

file(GLOB PROTO_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*.proto")
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTO_FILES})

add_library(protodefs ${PROTO_SRCS} ${PROTO_HDRS})
target_link_libraries(protodefs PUBLIC ${Protobuf_LIBRARIES})

add_executable(proto_test proto_test.cpp)
target_link_libraries(proto_test protodefs)