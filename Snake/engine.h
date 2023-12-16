//
// Created by Administrator on 17/03/2023.
//

#include <stdio.h>
#include "globals.h"

#ifndef MAIN_C_ENGINE_H
#define MAIN_C_ENGINE_H

#endif //MAIN_C_ENGINE_H

// struttura per un nodo del serpente
typedef struct list_t {
    int x;
    int y;
    struct list_t *next;
} snake_node;

snake_node *head;

int select_mode();

void initialize_snake();

int check_win(char fine);

char select_move();

char end_moving_sequence(char dungeon[][COL]);

void engine_tail(char dungeon[][COL], int a, int b);

void move_default(char dungeon[][COL], int a, int b);

void half_tail(char dungeon[][COL]);

void move(char dungeon[][COL], char direction);

void deallocate_snake();