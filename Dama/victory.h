#include <stdbool.h>
#define PROMOTION 'P'
#define DIM (7)
#define ROSSO 'X'
#define GIALLO 'O'
#ifndef PROGETTOFINITO_VICTORY_H
#define PROGETTOFINITO_VICTORY_H
#endif //PROGETTOFINITO_VICTORY_H
#ifndef strcut
#define strcut
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

int control_victory(tavola *t, bool *control_bool);