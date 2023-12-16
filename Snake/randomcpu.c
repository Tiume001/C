//
// Created by Administrator on 28/03/2023.
//

#include <stdbool.h>
#include <stdlib.h>
#include "randomcpu.h"
#include "engine.h"
#include <unistd.h>


char select_move_cpu() {
    char move;
    int rand_cpu_movement = rand() % 100; //aumento la probabilità che vada a destra
    while(1){
        if(rand_cpu_movement>=0 && rand_cpu_movement<20)
            move = 'W';
        else if(rand_cpu_movement>=20 && rand_cpu_movement<40)
            move = 'A';
        else if(rand_cpu_movement>=40 && rand_cpu_movement<60)
            move = 'S';
        else
            move = 'D';

        printf(BLUE BOLD"Mossa del serpente random: %c\n"RESET, move);
        return move;
    }
}

char end_moving_sequence_cpu(char dungeon[][COL]) {
    move_count++;
    score--;
    usleep(15000); //ritardo di num millisecondi
    clear_screen();
    print_dungeon(dungeon);
    printf("\n");
    char go_new = select_move_cpu();
    return go_new;
}

void move_cpu(char dungeon[][COL], char direction) {
    if(direction == 'W'){
        bool win = check_win(dungeon[x_head-1][y_head]);
        if(win)
            return;

        if(x_head == 0)
            return move_cpu(dungeon, end_moving_sequence_cpu(dungeon));

        if(dungeon[x_head - 1][y_head] == FOOD) {
            snake_lenght++;
            score += 10;
            engine_tail(dungeon, x_head - 1, y_head);
            move_cpu(dungeon, end_moving_sequence_cpu(dungeon));
        }
        else if(dungeon[x_head - 1][y_head] == MAKITA){
            makita_count+=3;
            dungeon[x_head - 1][y_head] = ' ';
            move_default(dungeon, x_head - 1, y_head);
            move_cpu(dungeon, end_moving_sequence_cpu(dungeon));
        }
        else if(dungeon[x_head - 1][y_head] == ENEMY || dungeon[x_head - 1][y_head] == BODY){
            if(dungeon[x_head - 1][y_head] == ENEMY) {
                enemy_count++;
                score = score - (snake_lenght*5);
            }
            dungeon[x_head - 1][y_head] = ' ';
            half_tail(dungeon);
            move_default(dungeon, x_head - 1, y_head);
            move_cpu(dungeon, end_moving_sequence_cpu(dungeon));
        }
        else if(dungeon[x_head - 1][y_head] == WALL){
            if(makita_count == 0){
                move_cpu(dungeon,end_moving_sequence_cpu(dungeon));
            }else{
                dungeon[x_head - 1][y_head] = ' ';
                makita_count--;
                move_default(dungeon, x_head - 1, y_head);
                move_cpu(dungeon, end_moving_sequence_cpu(dungeon));
            }
        }
        else{
            move_default(dungeon, x_head - 1, y_head);
            move_cpu(dungeon, end_moving_sequence_cpu(dungeon));
        }
    }
    if(direction == 'S'){
        bool win = check_win(dungeon[x_head+1][y_head]);
        if(win)
            return;

        if(x_head == ROW - 1)
            return move_cpu(dungeon, end_moving_sequence_cpu(dungeon));

        if(dungeon[x_head + 1][y_head] == FOOD) {
            snake_lenght++;
            score += 10;
            engine_tail(dungeon, x_head +1, y_head);
            move_cpu(dungeon, end_moving_sequence_cpu(dungeon));
        }
        else if(dungeon[x_head + 1][y_head] == MAKITA){
            makita_count+=3;
            dungeon[x_head + 1][y_head] = ' ';
            move_default(dungeon, x_head + 1, y_head);
            move_cpu(dungeon, end_moving_sequence_cpu(dungeon));
        }
        else if(dungeon[x_head + 1][y_head] == ENEMY || dungeon[x_head + 1][y_head] == BODY){
            if(dungeon[x_head + 1][y_head] == ENEMY){
                enemy_count++;
                score = score - ((snake_lenght*10)/2);
            }
            dungeon[x_head + 1][y_head] = ' ';
            half_tail(dungeon);
            move_default(dungeon, x_head + 1, y_head);
            move_cpu(dungeon, end_moving_sequence_cpu(dungeon));
        }
        else if(dungeon[x_head + 1][y_head] == WALL){
            if(makita_count == 0){
                //printf("Non puoi oltrepassare questo muro! \n");
                move_cpu(dungeon,end_moving_sequence_cpu(dungeon));
            }else{
                dungeon[x_head + 1][y_head] = ' ';
                makita_count--;
                move_default(dungeon, x_head + 1, y_head);
                move_cpu(dungeon, end_moving_sequence_cpu(dungeon));
            }
        }
        else{
            move_default(dungeon, x_head +1, y_head);
            move_cpu(dungeon, end_moving_sequence_cpu(dungeon));
        }
    }
    if(direction == 'D'){
        bool win = check_win(dungeon[x_head][y_head + 1]);
        if(win)
            return;

        if(y_head == COL - 1)
            return move_cpu(dungeon, end_moving_sequence_cpu(dungeon));

        if(dungeon[x_head][y_head + 1] == FOOD) {

            snake_lenght++;
            score += 10;
            engine_tail(dungeon, x_head, y_head + 1);
            move_cpu(dungeon, end_moving_sequence_cpu(dungeon));
        }
        else if(dungeon[x_head][y_head + 1] == MAKITA){
            makita_count+=3;
            dungeon[x_head][y_head + 1] = ' ';
            move_default(dungeon, x_head, y_head + 1);
            move_cpu(dungeon, end_moving_sequence_cpu(dungeon));
        }
        else if(dungeon[x_head][y_head + 1] == ENEMY || dungeon[x_head][y_head + 1] == BODY){
            if(dungeon[x_head][y_head + 1] == ENEMY){
                enemy_count++;
                score = score - ((snake_lenght*10)/2);
            }
            dungeon[x_head][y_head + 1] = ' ';
            half_tail(dungeon);
            move_default(dungeon, x_head, y_head + 1);
            move_cpu(dungeon,end_moving_sequence_cpu(dungeon));
        }
        else if(dungeon[x_head][y_head + 1] == WALL){
            if(makita_count == 0){
                //printf("Non puoi oltrepassare questo muro! \n");
                move_cpu(dungeon,end_moving_sequence_cpu(dungeon));
            }else{
                dungeon[x_head][y_head + 1] = ' ';
                makita_count--;
                move_default(dungeon, x_head, y_head + 1);
                move_cpu(dungeon, end_moving_sequence_cpu(dungeon));
            }
        }
        else{
            move_default(dungeon, x_head, y_head + 1);
            move_cpu(dungeon, end_moving_sequence_cpu(dungeon));
        }
    }
    if(direction == 'A'){
        if(y_head == 0 )
            return move_cpu(dungeon, end_moving_sequence_cpu(dungeon));

        if(dungeon[x_head][y_head - 1] == FOOD) {

            snake_lenght++;
            score += 10;
            engine_tail(dungeon, x_head, y_head - 1);
            move_cpu(dungeon, end_moving_sequence_cpu(dungeon));
        }
        else if(dungeon[x_head][y_head - 1] == MAKITA){
            makita_count+=3;
            dungeon[x_head][y_head - 1] = ' ';
            move_default(dungeon, x_head, y_head - 1);
            move_cpu(dungeon, end_moving_sequence_cpu(dungeon));
        }
        else if(dungeon[x_head][y_head - 1] == ENEMY || dungeon[x_head][y_head - 1] == BODY){
            if(dungeon[x_head][y_head - 1] == ENEMY){
                enemy_count++;
                score = score - ((snake_lenght*10)/2);
            }
            dungeon[x_head][y_head - 1] = ' ';
            half_tail(dungeon);
            move_default(dungeon, x_head, y_head - 1);
            move_cpu(dungeon,end_moving_sequence_cpu(dungeon));
        }
        else if(dungeon[x_head][y_head - 1] == WALL){
            if(makita_count == 0){
                //printf("Non puoi oltrepassare questo muro! \n");
                move_cpu(dungeon,end_moving_sequence_cpu(dungeon));
            }else{
                dungeon[x_head][y_head - 1] = ' ';
                makita_count--;
                move_default(dungeon, x_head, y_head - 1);
                move_cpu(dungeon, end_moving_sequence_cpu(dungeon));
            }
        }
        else{
            move_default(dungeon, x_head, y_head - 1);
            move_cpu(dungeon, end_moving_sequence_cpu(dungeon));
        }
    }
}

