
cmake_minimum_required(VERSION 2.8)

#Déclaration du projet

project(Final_Mystic_quest)

set (EXECUTABLE_OUTPUT_PATH ../mke/build/${CMAKE_BUILD_TYPE})

#Génération de la liste des fichiers sources


file(
	GLOB_RECURSE
	source_files
	../src/*
)

#Déclaration de l’éxecutable

add_executable(

	execute

	${source_files}

)
