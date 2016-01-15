
cmake_minimum_required(VERSION 2.8)

#Déclaration du projet

project(Final_Mystic_quest)

#definition de std C++11
add_definitions("-g -std=c++11")

set (EXECUTABLE_OUTPUT_PATH ../bin/${CMAKE_BUILD_TYPE})

#Génération de la liste des fichiers sources


file(
	GLOB_RECURSE
	source_files
	src/*.cpp
)

#Déclaration de l’éxecutable

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
set(SFML_ROOT "/usr/lsa")
set(CMAKE_MODULE_PATH "${SFML_ROOT}/share/SFML/cmake/Modules"
${CMAKE_MODULE_PATH})

find_package(SFML 2 COMPONENTS system window graphics audio network REQUIRED)
include_directories(${SFML_INCLUDE_DIR})

add_executable(

	execute

	${source_files}

) 

target_link_libraries(execute ${SFML_LIBRARIES})
