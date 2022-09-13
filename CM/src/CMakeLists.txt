cmake_minimum_required(VERSION 3.10)


# set the project name and version
project(CMakeTesting VERSION 1.0)

configure_file(CMakeTestingConfig.h.in CMakeTestingConfig.h)



# add the executable
add_executable(${PROJECT_NAME} main.cpp )

add_subdirectory(SourcesAndHeaders)

target_include_directories(${PROJECT_NAME} PUBLIC SourcesAndHeaders)

target_link_directories(${PROJECT_NAME} PRIVATE SourcesAndHeaders)

target_link_libraries(${PROJECT_NAME} Action AddContextAction CheckReservedWordAction ConcatenateDataAction ConcatenateKeyAction DataReadyAction DictionaryData ErrorTratementAction JsonAnalizer  MoveAction RemoveContextAction  StayAction )   





target_include_directories(CMakeTesting PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )

                           