//
// Created by Administrator on 17/03/2023.
//
#include <stdio.h>

#include "globals.h"
#include "macro.h"

#ifndef MAIN_C_DUNGEON_H
#define MAIN_C_DUNGEON_H

#endif //MAIN_C_DUNGEON_H

void random_generation();

void __attribute__((constructor)) init();

void random_generation();




void clear_screen();

void header_dungeon();

void print_dungeon(char dungeon[][COL]);

int find_max(int a, int b, int c);

void dungeon_elements(char dungeon[][COL]);

void create_dungeon(char dungeon[][COL]);




