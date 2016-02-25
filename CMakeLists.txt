cmake_minimum_required(VERSION 2.8)
project(finnigan-parser)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	add_definitions(-std=c++11)
	add_definitions(-Wno-c++1z-extensions)
endif()

############
# UNTHERMO #
############

# Get and run Go unthermo project.

# TODO How to test that Go is present ?
#set(ENV{GOPATH} $ENV{PWD})
#execute_process(COMMAND go get bitbucket.org/proteinspector/ms/unthermo)
#execute_process(COMMAND go run src/bitbucket.org/proteinspector/ms/unthermo/tools/printspectrum.go -sn 1 -raw ../test/res/20150403_G46_N1060_NEG_Test.raw
#                OUTPUT_FILE 20150403_G46_N1060_NEG_Test.output
#                )

file(GLOB sources RELATIVE ${CMAKE_CURRENT_LIST_DIR} src/*.cpp)
add_executable(finnigan_parser ${sources})
