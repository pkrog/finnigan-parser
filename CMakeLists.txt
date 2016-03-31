cmake_minimum_required(VERSION 2.8)
project(finnigan-parser)

#########
# BOOST #
#########

find_package(Boost 1.59.0 REQUIRED COMPONENTS filesystem unit_test_framework system)

if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
endif()

##################
# COMPILER FLAGS #
##################

# Enabling C++ 11 for MacOS-X
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	add_definitions(-std=c++11)
	#	add_definitions(-Wno-c++1z-extensions)
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

###########
# LIBRARY #
###########

file(GLOB libsrc RELATIVE ${CMAKE_CURRENT_LIST_DIR} src/lib/*.cpp)
add_library(finnigan SHARED ${libsrc})
target_include_directories(finnigan PUBLIC include)
target_include_directories(finnigan PRIVATE include/msfinnigan)

###########
# PROGRAM #
###########

file(GLOB prgsrc RELATIVE ${CMAKE_CURRENT_LIST_DIR} src/parser/*.cpp)
add_executable(finnigan-parser ${prgsrc})
target_link_libraries(finnigan-parser finnigan ${Boost_LIBRARIES})

#########
# TESTS #
#########

# Compile tests
add_executable(test-finnigan test/test-finnigan.cpp)
target_link_libraries(test-finnigan finnigan ${Boost_LIBRARIES})

# Run tests
enable_testing()
add_test(test_finnigan test-finnigan ${CMAKE_CURRENT_LIST_DIR}/test)
