cmake_minimum_required(VERSION 3.10)
set(PROJECT_NAME Star_wasteland)

project(${PROJECT_NAME})
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} /W1")
set(CMAKE_CXX_STANDARD 17)

find_package(Doxygen)
option(BUILD_DOCUMENTATION "Create and install documentation (requires Doxygen)" ${DOXYGEN_FOUND})
if(DOXYGEN_FOUND)
    set(DOXYGEN ${CMAKE_SOURCE_DIR}/doc/Doxyfile.in)
    add_custom_target(
		docs ALL
		COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN}
		VERBATIM
		WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/doc
	)
endif()

include_directories(prj)
include_directories(libs)

set(CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}")
install(FILES 
	${CMAKE_SOURCE_DIR}/libs/SFML/bin/openal32.dll
	${CMAKE_SOURCE_DIR}/libs/SFML/bin/sfml-audio-d-2.dll
	${CMAKE_SOURCE_DIR}/libs/SFML/bin/sfml-graphics-d-2.dll
	${CMAKE_SOURCE_DIR}/libs/SFML/bin/sfml-system-d-2.dll
	${CMAKE_SOURCE_DIR}/libs/SFML/bin/sfml-window-d-2.dll 
	CONFIGURATIONS Debug 
	DESTINATION ${PROJECT_BINARY_DIR}/prj/Debug)
install(FILES 
	${CMAKE_SOURCE_DIR}/libs/SFML/bin/openal32.dll
	${CMAKE_SOURCE_DIR}/libs/SFML/bin/sfml-audio-d-2.dll
	${CMAKE_SOURCE_DIR}/libs/SFML/bin/sfml-graphics-d-2.dll
	${CMAKE_SOURCE_DIR}/libs/SFML/bin/sfml-system-d-2.dll
	${CMAKE_SOURCE_DIR}/libs/SFML/bin/sfml-window-d-2.dll 
	CONFIGURATIONS Debug 
	DESTINATION ${PROJECT_BINARY_DIR}/prj)
	
install(FILES 
	${CMAKE_SOURCE_DIR}/libs/SFML/bin/openal32.dll
	${CMAKE_SOURCE_DIR}/libs/SFML/bin/sfml-audio-2.dll
	${CMAKE_SOURCE_DIR}/libs/SFML/bin/sfml-graphics-2.dll
	${CMAKE_SOURCE_DIR}/libs/SFML/bin/sfml-system-2.dll
	${CMAKE_SOURCE_DIR}/libs/SFML/bin/sfml-window-2.dll 
	CONFIGURATIONS Release 
	DESTINATION ${PROJECT_BINARY_DIR}/prj/Release)
install(FILES 
	${CMAKE_SOURCE_DIR}/libs/SFML/bin/openal32.dll
	${CMAKE_SOURCE_DIR}/libs/SFML/bin/sfml-audio-2.dll
	${CMAKE_SOURCE_DIR}/libs/SFML/bin/sfml-graphics-2.dll
	${CMAKE_SOURCE_DIR}/libs/SFML/bin/sfml-system-2.dll
	${CMAKE_SOURCE_DIR}/libs/SFML/bin/sfml-window-2.dll 
	CONFIGURATIONS Release 
	DESTINATION ${PROJECT_BINARY_DIR}/prj)
	
	
install(DIRECTORY ${CMAKE_SOURCE_DIR}/src CONFIGURATIONS Debug
	DESTINATION ${PROJECT_BINARY_DIR}/prj/Debug)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/src CONFIGURATIONS Debug
	DESTINATION ${PROJECT_BINARY_DIR}/prj)
	
install(DIRECTORY ${CMAKE_SOURCE_DIR}/src CONFIGURATIONS Release
	DESTINATION ${PROJECT_BINARY_DIR}/prj/Release)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/src CONFIGURATIONS Release
	DESTINATION ${PROJECT_BINARY_DIR}/prj)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/doc DESTINATION ${PROJECT_BINARY_DIR})

add_subdirectory(prj)