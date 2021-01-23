set(SOURCE_FILES asteroid.h asteroid.cpp
        CheckBox.h CheckBox.cpp
        main.cpp
        Menu.h Menu.cpp
        MenuButton.h MenuButton.cpp
        planet.h planet.cpp
        player.cpp player.h 
	Rollover.h Rollover.cpp
	settings.h settings.cpp
	spawner.h spawner.cpp
	textureLoader.h textureLoader.cpp
	TopResults.h TopResults.cpp
	weapon.h weapon.cpp)

set(SFML_ROOT ${SFML_DIR})
set(SFML_STATIC_LIBRARIES FALSE)
set(CMAKE_MODULE_PATH "${SFML_DIR}/cmake/Modules")
find_package(SFML REQUIRED COMPONENTS audio graphics window system)

include_directories("${SFML_DIR}/include")
add_executable (${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})