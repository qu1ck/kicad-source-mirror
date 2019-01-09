find_program(PROTOC_EXECUTABLE NAMES protoc)

if(PROTOC_EXECUTABLE)
    message(STATUS "Found protobuf compiler: ${PROTOC_EXECUTABLE}")
else(PROTOC_EXECUTABLE)
    message(FATAL_ERROR "Protobuf compiler executable not found")
endif(PROTOC_EXECUTABLE)

file(GLOB PROTO_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*.proto")
string(REPLACE ";" " " PROTO_FILES_STR "${PROTO_FILES}")
foreach(PROTO_FILE ${PROTO_FILES})
    string(REPLACE ".proto" ".pb.h" PROTO_FILE_H ${PROTO_FILE})
    string(REPLACE ".proto" ".pb.cc" PROTO_FILE_CC ${PROTO_FILE})
    set(PROTO_FILES_H ${PROTO_FILES_H} "cpp-gen/${PROTO_FILE_H}")
    set(PROTO_FILES_CC ${PROTO_FILES_CC} "cpp-gen/${PROTO_FILE_CC}")
endforeach()

set(PROTO_FILES_SRC ${PROTO_FILES_CC} ${PROTO_FILES_H})

message(STATUS "Proto executable found: ${PROTOC_EXECUTABLE}")
message(STATUS "Proto files: ${PROTO_FILES_STR}")
message(STATUS "Proto files srcs: ${PROTO_FILES_SRC}")

add_custom_command(
        OUTPUT ${PROTO_FILES_SRC}
        COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_BINARY_DIR}/cpp-gen
        COMMAND ${PROTOC_EXECUTABLE} --cpp_out=${CMAKE_CURRENT_BINARY_DIR}/cpp-gen ${PROTO_FILES}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        DEPENDS ${PROTO_FILES}
        COMMENT "Compiling protobuf definitions for ${PROTO_FILES_STR}"
)

add_library(proto STATIC ${PROTO_FILES_SRC})

add_executable(proto_test proto_test.cpp)

target_include_directories(proto_test PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/cpp-gen)

target_link_libraries(proto_test proto)

set_target_properties(proto_test PROPERTIES LINK_FLAGS "-lprotobuf")