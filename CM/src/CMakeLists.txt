cmake_minimum_required(VERSION 3.10)


# set the project name and version
project(CMakeTesting VERSION 1.0)

configure_file(CMakeTestingConfig.h.in CMakeTestingConfig.h)

# add the executable
add_executable(CMakeTesting main.cpp)   

target_include_directories(CMakeTesting PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )