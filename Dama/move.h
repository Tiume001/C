#include <stdio.h>
#include <stdbool.h>
#ifndef PROGETTOFINITO_MOVE_H
#define PROGETTOFINITO_MOVE_H
#endif //PROGETTOFINITO_MOVE_H
#ifndef strcut
#define strcut
#define ROSSO 'X'
#define GIALLO 'O'
#define PROMOTION 'P'
#define DIM (7)

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

void make_move(tavola* t,bool* control_bool);
