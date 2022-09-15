cmake_minimum_required(VERSION 3.10)


# set the project name and version
project(CMakeTesting VERSION 1.0)

configure_file(CMakeTestingConfig.h.in CMakeTestingConfig.h)


# add the executable
add_executable(${PROJECT_NAME} main.cpp )



add_subdirectory(includes/Action)
add_subdirectory(includes/AddContextAction)
add_subdirectory(includes/CheckReservedWordAction)
add_subdirectory(includes/ConcatenateKeyAction)
add_subdirectory(includes/ConcatenateDataAction)
add_subdirectory(includes/DataReadyAction)
add_subdirectory(includes/DictionaryData)
add_subdirectory(includes/ErrorTratementAction)
add_subdirectory(includes/JsonAnalizer)
add_subdirectory(includes/MoveAction)
add_subdirectory(includes/RemoveContextAction)
add_subdirectory(includes/StayAction)


target_link_libraries(${PROJECT_NAME} 	PUBLIC Action
					PUBLIC AddContextAction
					PUBLIC CheckReservedWordAction
					PUBLIC ConcatenateKeyAction
					PUBLIC ConcatenateDataAction
					PUBLIC DataReadyAction
					PUBLIC DictionaryData
					PUBLIC ErrorTratementAction
					PUBLIC JsonAnalizer
					PUBLIC MoveAction
					PUBLIC RemoveContextAction					
					PUBLIC StayAction
	)



target_include_directories(CMakeTesting PUBLIC
                         "${PROJECT_BINARY_DIR}/includes/Action"
			 "${PROJECT_BINARY_DIR}/includes/AddContextAction"
			 "${PROJECT_BINARY_DIR}/includes/CheckReservedWordAction"
			 "${PROJECT_BINARY_DIR}/includes/ConcatenateDataAction"
			 "${PROJECT_BINARY_DIR}/includes/DataReadyAction"
			 "${PROJECT_BINARY_DIR}/includes/DictionaryData)"
			 "${PROJECT_BINARY_DIR}/includes/ErrorTratementAction"
			 "${PROJECT_BINARY_DIR}/includes/JsonAnalizer"
			 "${PROJECT_BINARY_DIR}/includes/MoveAction"
			 "${PROJECT_BINARY_DIR}/includes/RemoveContextAction"
			 "${PROJECT_BINARY_DIR}/includes/StayAction"

)

                           