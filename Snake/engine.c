//
// Created by Administrator on 17/03/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "engine.h"
#include "dungeon.h"

//seleziona la modalità di gioco
int select_mode(){
    printf(YELLOW BOLD"Seleziona la tua modalità!\n\n"RESET);
    printf(GREEN ITALIC"Per giocare tu, inserisci:         \t "RESET RED"[1]\n"RESET GREEN ITALIC"Per far giocare la CPU, inserisci:\t "RESET RED"[0]\n"RESET);
    int play;
    scanf("%d", &play);
    return play;
}

//inizializza la testa del serpente
void initialize_snake(){
    // sto dicendo al programma che la O dell'inizio è la testa del mio Snake
    head = (snake_node *)malloc(sizeof(snake_node));
    head->x = x_head;
    head->y = y_head;
    head->next = NULL;
}

//controlla la vittoria
int check_win(char fine){
    if (fine == END) {
        printf("\n");
        printf(BOLD BLUE"Congratulazioni avventuriero! Sei arrivato alla fine!\n"RESET);
        printf(BOLD BLUE"Ecco il tuo punteggio:"RESET GREEN" %d punti!\n"RESET, score);
        printf(BOLD BLUE"Hai incontrato "RESET RED"%d nemici"RESET BOLD BLUE" !\n"RESET, enemy_count);
        printf(BOLD BLUE"Hai totalizzato:"RESET MAGENTA" %d mosse"RESET BOLD BLUE".\n\n"RESET, move_count);
        return 1;
    }
    else
        return 0;
}

// seleziona la mossa fino a che non è corretta
char select_move() {
    printf("\n");
    printf(CIANO ITALIC"Seleziona una mossa: "RESET GREEN"W"RESET CIANO ITALIC" (up), "RESET GREEN"S"RESET CIANO ITALIC" (down), "RESET GREEN"D"RESET CIANO ITALIC" (right), "RESET GREEN"A"RESET CIANO ITALIC" (left)\n"RESET);
    char move;
    scanf("%c", &move);
    while (move != 'W' && move != 'S' && move != 'A' && move != 'D') {
        scanf(" %c", &move);
        if(x_head != x_exit)
            printf(RED SFUMATO"La mossa inserita non è corretta. Prova di nuovo:\n"RESET);
    }
    return move;
}

// sequenza di terminazione del movimento dopo ogni mossa
char end_moving_sequence(char dungeon[][COL]) {
    move_count++;
    score--;
    clear_screen();
    print_dungeon(dungeon);
    printf("\n");
    char go_new = select_move();
    return go_new;
}

// aggiunge un pezzo in coda e aggiorna la posizione nel campo
void engine_tail(char dungeon[][COL], int a, int b) {
    int as, bs;

    snake_node *node = head;
    while (node->next != NULL) {
        node = node->next;
    }
    node->next = (snake_node *)malloc(sizeof(snake_node));
    node->next->next = NULL;
    node->next->x = node->x;
    node->next->y = node->y;


    node = head->next;

    dungeon[a][b] = 'O';
    x_head = a;
    y_head = b;
    a = head->x;
    b = head->y;
    head->x = x_head;
    head->y = y_head;

    while (node->next != NULL) {
        as = a;
        bs = b;
        dungeon[a][b] = 'o';
        a = node->x;
        b = node->y;
        node->x = as;
        node->y = bs;
        node = node->next;
    }
    dungeon[a][b] = 'o';
    dungeon[node->x][node->y] = 'o';
}

//muove tutto lo snake normalmente
void move_default(char dungeon[][COL], int a, int b) {
    if (snake_lenght == 0) {
        dungeon[a][b] = 'O';
        dungeon[x_head][y_head] = ' ';
        x_head = a;
        y_head = b;
        head->x = x_head;
        head->y = y_head;
    } else {
        snake_node *node = head->next;
        dungeon[a][b] = 'O';
        x_head = a;
        y_head = b;
        a = head->x;
        b = head->y;
        head->x = x_head;
        head->y = y_head;

        while (node->next != NULL) {
            int as = a, bs = b;
            dungeon[a][b] = 'o';
            a = node->x;
            b = node->y;
            node->x = as;
            node->y = bs;
            node = node->next;
        }
        dungeon[a][b] = 'o';
        dungeon[node->x][node->y] = ' ';
        node->x = a;
        node->y = b;
    }
}

//taglia la coda a metà se viene preso un ! o 'o'
void half_tail(char dungeon[][COL]){
    snake_node *node = head;
    snake_lenght = (int) snake_lenght/2;
    for(int i = 0; i < snake_lenght; i++)
        node = node->next;

    snake_node *S_node = node;

    while(S_node != NULL)
    {
        dungeon[S_node->x][S_node->y] = ' ';
        S_node = S_node->next;
    }

    node->next = NULL;
}

//funzione principale che decide cosa fare in base al movimento
void move(char dungeon[][COL], char direction) {
    if(direction == 'W'){
        bool win = check_win(dungeon[x_head-1][y_head]);
        if(win)
            return;

        if(x_head == 0)
            return move(dungeon, end_moving_sequence(dungeon));

        if(dungeon[x_head - 1][y_head] == FOOD) {
            snake_lenght++;
            score += 10;
            engine_tail(dungeon, x_head - 1, y_head);
            move(dungeon, end_moving_sequence(dungeon));
        }
        else if(dungeon[x_head - 1][y_head] == MAKITA){
            makita_count+=3;
            dungeon[x_head - 1][y_head] = ' ';
            move_default(dungeon, x_head - 1, y_head);
            move(dungeon, end_moving_sequence(dungeon));
        }
        else if(dungeon[x_head - 1][y_head] == ENEMY || dungeon[x_head - 1][y_head] == BODY){
            if(dungeon[x_head - 1][y_head] == ENEMY) {
                enemy_count++;
                score = score - (snake_lenght*5);
            }
            dungeon[x_head - 1][y_head] = ' ';
            half_tail(dungeon);
            move_default(dungeon, x_head - 1, y_head);
            move(dungeon, end_moving_sequence(dungeon));
        }
        else if(dungeon[x_head - 1][y_head] == WALL){
            if(makita_count == 0){
                move(dungeon,end_moving_sequence(dungeon));
            }else{
                dungeon[x_head - 1][y_head] = ' ';
                makita_count--;
                move_default(dungeon, x_head - 1, y_head);
                move(dungeon, end_moving_sequence(dungeon));
            }
        }
        else{
            move_default(dungeon, x_head - 1, y_head);
            move(dungeon, end_moving_sequence(dungeon));
        }
    }
    if(direction == 'S'){
        bool win = check_win(dungeon[x_head+1][y_head]);
        if(win)
            return;

        if(x_head == ROW - 1)
            return move(dungeon, end_moving_sequence(dungeon));

        if(dungeon[x_head + 1][y_head] == FOOD) {
            snake_lenght++;
            score += 10;
            engine_tail(dungeon, x_head +1, y_head);
            move(dungeon, end_moving_sequence(dungeon));
        }
        else if(dungeon[x_head + 1][y_head] == MAKITA){
            makita_count+=3;
            dungeon[x_head + 1][y_head] = ' ';
            move_default(dungeon, x_head + 1, y_head);
            move(dungeon, end_moving_sequence(dungeon));
        }
        else if(dungeon[x_head + 1][y_head] == ENEMY || dungeon[x_head + 1][y_head] == BODY){
            if(dungeon[x_head + 1][y_head] == ENEMY){
                enemy_count++;
                score = score - ((snake_lenght*10)/2);
            }
            dungeon[x_head + 1][y_head] = ' ';
            half_tail(dungeon);
            move_default(dungeon, x_head + 1, y_head);
            move(dungeon, end_moving_sequence(dungeon));
        }
        else if(dungeon[x_head + 1][y_head] == WALL){
            if(makita_count == 0){
                printf("Non puoi oltrepassare questo muro! \n");
                move(dungeon,end_moving_sequence(dungeon));
            }else{
                dungeon[x_head + 1][y_head] = ' ';
                makita_count--;
                move_default(dungeon, x_head + 1, y_head);
                move(dungeon, end_moving_sequence(dungeon));
            }
        }
        else{
            move_default(dungeon, x_head +1, y_head);
            move(dungeon, end_moving_sequence(dungeon));
        }
    }
    if(direction == 'D'){
        bool win = check_win(dungeon[x_head][y_head + 1]);
        if(win)
            return;

        if(y_head == COL - 1)
            return move(dungeon, end_moving_sequence(dungeon));

        if(dungeon[x_head][y_head + 1] == FOOD) {

            snake_lenght++;
            score += 10;
            engine_tail(dungeon, x_head, y_head + 1);
            move(dungeon, end_moving_sequence(dungeon));
        }
        else if(dungeon[x_head][y_head + 1] == MAKITA){
            makita_count+=3;
            dungeon[x_head][y_head + 1] = ' ';
            move_default(dungeon, x_head, y_head + 1);
            move(dungeon, end_moving_sequence(dungeon));
        }
        else if(dungeon[x_head][y_head + 1] == ENEMY || dungeon[x_head][y_head + 1] == BODY){
            if(dungeon[x_head][y_head + 1] == ENEMY){
                enemy_count++;
                score = score - ((snake_lenght*10)/2);
            }
            dungeon[x_head][y_head + 1] = ' ';
            half_tail(dungeon);
            move_default(dungeon, x_head, y_head + 1);
            move(dungeon,end_moving_sequence(dungeon));
        }
        else if(dungeon[x_head][y_head + 1] == WALL){
            if(makita_count == 0){
                printf("Non puoi oltrepassare questo muro! \n");
                move(dungeon,end_moving_sequence(dungeon));
            }else{
                dungeon[x_head][y_head + 1] = ' ';
                makita_count--;
                move_default(dungeon, x_head, y_head + 1);
                move(dungeon, end_moving_sequence(dungeon));
            }
        }
        else{
            move_default(dungeon, x_head, y_head + 1);
            move(dungeon, end_moving_sequence(dungeon));
        }
    }
    if(direction == 'A'){
        if(y_head == 0 )
            return move(dungeon, end_moving_sequence(dungeon));

        if(dungeon[x_head][y_head - 1] == FOOD) {

            snake_lenght++;
            score += 10;
            engine_tail(dungeon, x_head, y_head - 1);
            move(dungeon, end_moving_sequence(dungeon));
        }
        else if(dungeon[x_head][y_head - 1] == MAKITA){
            makita_count+=3;
            dungeon[x_head][y_head - 1] = ' ';
            move_default(dungeon, x_head, y_head - 1);
            move(dungeon, end_moving_sequence(dungeon));
        }
        else if(dungeon[x_head][y_head - 1] == ENEMY || dungeon[x_head][y_head - 1] == BODY){
            if(dungeon[x_head][y_head - 1] == ENEMY){
                enemy_count++;
                score = score - ((snake_lenght*10)/2);
            }
            dungeon[x_head][y_head - 1] = ' ';
            half_tail(dungeon);
            move_default(dungeon, x_head, y_head - 1);
            move(dungeon,end_moving_sequence(dungeon));
        }
        else if(dungeon[x_head][y_head - 1] == WALL){
            if(makita_count == 0){
                printf("Non puoi oltrepassare questo muro! \n");
                move(dungeon,end_moving_sequence(dungeon));
            }else{
                dungeon[x_head][y_head - 1] = ' ';
                makita_count--;
                move_default(dungeon, x_head, y_head - 1);
                move(dungeon, end_moving_sequence(dungeon));
            }
        }
        else{
            move_default(dungeon, x_head, y_head - 1);
            move(dungeon, end_moving_sequence(dungeon));
        }
    }
}

//dealloca tutta la lista snake
void deallocate_snake(){
    snake_node* current = head;
    snake_node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}