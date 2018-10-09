cmake_minimum_required(VERSION 3.1)
project(FMI)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Release)

## NOTE: This to take effect must be before add_executable
link_directories(FmiTest.Model/binaries/linux64)

set(SRCS fmitest.cpp fmi_interface.cpp)
add_executable(fmitest ${SRCS})

## Link libraries
find_library(PUGI_XML pugixml)
target_link_libraries(fmitest ${PUGI_XML})

## Interface with an FMI model
include_directories(FmiTest.Model/sources/include/fmi2)
## NOTE: I would like to use find_library, but the .so does not start with lib
## and thus to force g++ to link to it we need to add : before the name.
## Unfortunately CMake does not know that
# find_library(FMI FmiTest_Model.so PATHS FmiTest.Model/binaries/linux64)
# target_link_libraries(fmitest ${FMI})
target_link_libraries(fmitest :FmiTest_Model.so)
