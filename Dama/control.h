#define ROSSO 'X'
#define GIALLO 'O'
#define PROMOTION 'P'
#define DIM (7)
#include <stdio.h>
#ifndef PROGETTOFINITO_CONTROL_H
#define PROGETTOFINITO_CONTROL_H
#endif //PROGETTOFINITO_CONTROL_H
#include <stdio.h>
#include <stdbool.h>
#ifndef strcut
#define strcut
#define ROSSO 'X'
#define GIALLO 'O'
#define DIM (7)
#include <stdio.h>

typedef struct pedina
{
    char colore; /*r,g*/
    char promossa[1];
    char tower[2];
}pedina;


typedef struct casella
{
    pedina pedina;

}casella;


typedef struct tavola
{
    casella casella[DIM][DIM];
}tavola;

#endif


bool control_3(tavola* t,int x2,int y2);

bool control(int x,int y,int x1,int y1);

bool control_2(tavola* t, int x, int y, int x1, int y1,int x2,int y2);

bool control_eat_1(const tavola *t, int x, int y);

bool control_eat_2(tavola *t, int x, int y);

bool control_tower(tavola *t, int x1, int y1);

bool control_turn(tavola* t, int x, int y, int x1, int y1, const bool* control_bool);

bool control_promozione(tavola* t, int x, int y, const bool* control_bool);

bool control_if_token_is_promoted(tavola *t, int x, int y);

bool control_move(tavola *t, int x, int y, int x1);

bool control_tiles(tavola *t, bool *control_bool);