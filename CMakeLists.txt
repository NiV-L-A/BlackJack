cmake_minimum_required(VERSION 3.10)

project(BlackJack C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-format -Wno-deprecated-declarations -Wno-format-security -rdynamic")

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

include_directories(${GTK3_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
link_directories(${GTK3_LIBRARY_DIRS})

find_program(GLIB_COMPILE_RESOURCES glib-compile-resources REQUIRED)

add_custom_command(
        OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/risorse.c
        COMMAND ${GLIB_COMPILE_RESOURCES}
        --target=${CMAKE_CURRENT_BINARY_DIR}/risorse.c
        --generate-source
        --sourcedir=${CMAKE_CURRENT_SOURCE_DIR}/GUI
        ${CMAKE_CURRENT_SOURCE_DIR}/GUI/bin/risorse.xml
        DEPENDS
        ${CMAKE_CURRENT_SOURCE_DIR}/GUI/bin/risorse.xml
        ${CMAKE_CURRENT_SOURCE_DIR}/GUI/bin/GUI.glade
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/GUI/bin
)

add_custom_target(resources DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/risorse.c)

add_executable(BlackJack
        main.c
        Banco.c
        Giocatore.c
        GestioneStoricoPartite.c
        GestioneUtenti.c
        GUI/bin/InterfacciaGrafica.c
        Globali.c
        GUI/bin/GestioneGraficaPartita.c
        ${CMAKE_CURRENT_BINARY_DIR}/risorse.c)

add_dependencies(BlackJack resources)

target_link_libraries(BlackJack ${GTK3_LIBRARIES})