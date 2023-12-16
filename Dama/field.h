#define ROSSO 'X'
#define GIALLO 'O'
#define PROMOTION 'P'
#define DIM (7)
#include <stdio.h>
#ifndef PROGETTOFINITO_FIELD_H
#define PROGETTOFINITO_FIELD_H
#endif //PROGETTOFINITO_FIELD_H
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

void print_field(tavola* t);

void initialize_eat(tavola *t, int i, int j);

void initialize_promotion(tavola *t, int i, int j);

void initialize_table(tavola* t);
