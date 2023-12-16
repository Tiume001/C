//
// Created by Administrator on 17/03/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "dungeon.h"

// Dichiarazione della funzione che inizializza il generatore di numeri casuali
void random_generation();

// Inizializza il generatore di numeri casuali all'avvio del programma
void __attribute__((constructor)) init() { random_generation(); }

// Definizione della funzione che inizializza il generatore di numeri casuali
void random_generation() { srand(time(NULL)); }

void clear_screen() {
#ifdef __unix__
    system("clear");
#endif

#ifdef __APPLE__
    system("clear");
#endif

#ifdef __WIN32__
    system("cls");
#endif
}

// funzione che stampa il benvenuto del gioco
void header_dungeon (){

    printf("╔");
    for(int i=0; i<34; i++){
        printf("══");
    }
    printf("╗\n");

    printf(BOLD "║"RESET);
    printf(BOLD"                    Benvenuto in "YELLOW UNDERLINE"SNAKE LABYRINTH"RESET YELLOW"®"RESET"!                  "RESET);
    printf(BOLD "║\n"RESET);
    printf(BOLD "║"RESET);
    printf("                                                                    ");
    printf(BOLD "║\n"RESET);
    printf(BOLD "║"RESET);
    printf("  In questo gioco lo scopo è arrivare alla fine del labirinto (]).  ");
    printf(BOLD "║\n"RESET);
    printf(BOLD "║"RESET);
    printf("            Conduci il tuo serpente in fondo al labirinto,          ");
    printf(BOLD "║\n"RESET);
    printf(BOLD "║"RESET);
    printf("       raccogli tutte le"GREEN" monete ($)"RESET" e fai più punti possibile!      ");
    printf(BOLD "║\n"RESET);
    printf(BOLD "║"RESET);
    printf("                    Ma... Presta molta attenzione!!                 ");
    printf(BOLD "║\n"RESET);
    printf(BOLD "║"RESET);
    printf("   Nel percorso sono presenti ostacoli da cui dovrai guardarti "RED"(!)"RESET"  ");
    printf(BOLD "║\n"RESET);
    printf(BOLD "║"RESET);

    printf("                                                                    ");
    printf(BOLD "║\n"RESET);
    printf(BOLD "║"RESET);
    printf(ITALIC BLUE" Ora tocca a te: diventa il Re del labirinto e "UNDERLINE"sconfiggi la paura!"RESET"  "RESET);
    printf(BOLD "║\n"RESET);
    printf(BOLD "║"RESET);
    printf("                                                                    ");
    printf(BOLD "║\n"RESET);

    printf("╚");
    for(int i=0; i<34; i++){
        printf("══");
    }
    printf("╝\n");
    printf("\n");
    printf("Ecco il tuo labirinto, pensi di riuscire ad arrivare alla fine?\n");
    printf(CIANO ITALIC"Inserisci un carattere qualsiasi per continuare: "RESET);
    getchar();
    return;
}

// stampa il labirinto (stampa matrice)
void print_dungeon(char dungeon[][COL]) {
    usleep(10000); 
    for (int i = 0; i < ROW; i++) {
        printf("\n");
        for (int k = 0; k < COL; k++) {
            if(dungeon[i][k] == '$')
                printf(BLUE"%c" RESET, dungeon[i][k]);
            else if(dungeon[i][k] == 'T')
                printf(YELLOW "%c" RESET, dungeon[i][k]);
            else if(dungeon[i][k] == '!')
                printf(RED "%c" RESET, dungeon[i][k]);
            else if(dungeon[i][k] == 'o' || dungeon[i][k] == 'O')
                printf(GREEN "%c" RESET, dungeon[i][k]);
            else if(dungeon[i][k] == ']')
                printf( "%c" RESET, dungeon[i][k]);
            else
                printf("%c", dungeon[i][k]);

        }
    }
    printf("\n\n");
    printf("Trapani in tuo possesso: "BLINK YELLOW"%d\n"RESET, makita_count);
    printf("Il tuo serpente è lungo "BLINK GREEN"%d"RESET" grazie alle monete raccolte!\n", snake_lenght);
    printf("Il tuo punteggio è: "BLINK MAGENTA"%d"RESET" punti!", score);
}

int find_max(int a, int b, int c) {
    int max = a;
    if (b > max) {
        max = b;
    }
    if (c > max) {
        max = c;
    }
    return max;
}

// crea gli elementi del labirinto
void dungeon_elements(char dungeon[][COL]) {

    // monete random
    int r_coin = 15 + rand() % 15;
    // printf("Numero schei: %d\n", r_coin);
    int size_coin = r_coin * 2;
    int r_coin_vctr[size_coin];
    for (int k = 0; k < size_coin; k += 2) {
        r_coin_vctr[k] = rand() % (ROW - 2) + 1;
        r_coin_vctr[k + 1] = rand() % (COL - 2) + 1;
    }

    // trapani random
    int r_makita = 6 + rand() % 6;
    // printf("Numero trapani: %d\n", r_bosch);
    int size_bosch = r_makita * 2;
    int r_bosch_vctr[size_bosch];
    for (int k = 0; k < size_bosch; k += 2) {
        r_bosch_vctr[k] = rand() % (ROW - 2) + 1;
        r_bosch_vctr[k + 1] = rand() % (COL - 2) + 1;
    }

    // allert random
    int r_allert = 5 + rand() % 6;
    // printf("Numero allert: %d\n", r_bosch);
    int size_allert = r_allert * 2;
    int r_allert_vctr[size_allert];
    for (int k = 0; k < size_allert; k += 2) {
        r_allert_vctr[k] = rand() % (ROW) + 1;
        r_allert_vctr[k + 1] = rand() % (COL - 2) + 1;
    }

    int max = find_max(size_coin, size_bosch, size_allert);

    // carica elementi random nel campo
    for (int t = 0; t < max; t += 2) {
        if (t < size_coin)
            dungeon[r_coin_vctr[t]][r_coin_vctr[t + 1]] = '$';
        if (t < size_allert)
            dungeon[r_allert_vctr[t]][r_allert_vctr[t + 1]] = '!';
        if (t < size_bosch)
            dungeon[r_bosch_vctr[t]][r_bosch_vctr[t + 1]] = 'T';
    }

    int rand1 = rand() % ((ROW) / 2) + 1;
    // printf("Numero rand1: %d\n", rand1);
    int rand2 = rand() % ((ROW) / 2) + 1;
    // printf("Numero rand2: %d\n", rand2);
    int rand3 = rand() % ((ROW) / 2) + 1;
    // printf("Numero rand6: %d\n", rand6);
    int rand4 = rand() % ((COL) / 2) + 1;
    // printf("Numero rand3: %d\n", rand3);
    int rand5 = rand() % ((COL) / 2) + 1;
    // printf("Numero rand4: %d\n", rand4);

    // carica muri interni
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (j == 6 && i < rand1) // stampa el in verticale
                dungeon[i][j] = '#';
            if (j == 13 && i > rand2)
                dungeon[i][j] = '#';
            if (j == 25 && i < rand3)
                dungeon[i][j] = '#';
            if (i == 16 && j > rand4 && j < COL - 2) // muro orizzontale
                dungeon[i][j] = '#';
            if (i == 9 && j < rand4 - 3 && j < COL - 1 && j > ROW - 2)
                dungeon[i][j] = '#';
            if (i == 24 && j > rand5 && j < COL - 1)
                dungeon[i][j] = '#';
        }
    }
}

// crea il labirinto
void create_dungeon(char dungeon[][COL]) {
    int head_start = rand() % (ROW - 2) + 1;
    x_head = head_start;
    y_head = 0;
    // printf("i random vale: %d\n", head_start);
    int ifine = rand() % (ROW - 2) + 1;
    x_exit = ifine;
    // printf("j random vale: %d\n", ifine);

    for (int i = 0; i < ROW; i++) {
        for (int k = 0; k < COL; k++) {
            if (i == 0 || i == ROW - 1) {
                dungeon[i][k] = '#';
            } else {
                dungeon[i][k] = ' ';
            }
            if (i > 0 && i < ROW && k == 0 || k == COL - 1) {
                dungeon[i][k] = '#';
                if (i == head_start && k == 0) {
                    // start
                    dungeon[i][k] = 'O';
                }
                if (i == ifine && k == COL - 1) // uscita
                    dungeon[i][k] = ']';
            }
        }
    }
    dungeon_elements(dungeon);
    print_dungeon(dungeon);
    printf("\n");
    //printf("x_head: %d\n", x_head);
    //printf("y_head: %d\n", y_head);
    return;
}