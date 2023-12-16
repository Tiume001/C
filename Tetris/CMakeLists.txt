cmake_minimum_required(VERSION 3.21)
project(project_copia C)

set(CMAKE_C_STANDARD 11)

add_executable(project_copia
        main.c functions.h pedine.h pedine.c campo.h campo.c turni_players.h turni_players.c prova.h)
