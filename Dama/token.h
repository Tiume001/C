#include <stdbool.h>
#define PROMOTION 'P'
#define DIM (7)
#ifndef PROGETTOFINITO_TOKEN_H
#define PROGETTOFINITO_TOKEN_H
#endif //PROGETTOFINITO_TOKEN_H
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



void copy_eat_data( char *a, char *b);


void build_tower(tavola* t,int x,int y,int x1,int y1,int x2,int y2,  bool *control_bool);


void build_tower2(tavola* t,int x,int y,int x1,int y1,int x2,int y2,  bool *control_bool);


void build_tower3(tavola* t,int x,int y,int x1,int y1,int x2,int y2,  bool *control_bool);

/*pedina singola mangia torre*/
void destroy_build_tower(tavola* t,int x,int y,int x1,int y1,int x2,int y2,  bool *control_bool);

/*torre mangia torre*/
void destroy_build_tower1(tavola *t, int x, int y, int x1, int y1, int x2, int y2,  bool *control_bool);

/*torre mangia torre con 2 mangiate*/
void destroy_build_tower2(tavola *t, int x, int y, int x1, int y1, int x2, int y2,  bool *control_bool);

/*doppia torre mangia una doppia torre*/
void destroy_build_tower3(tavola *t, int x, int y, int x1, int y1, int x2, int y2, bool *control_bool);

/*doppia torre mangia una torre singola*/
void destroy_build_tower4(tavola *t, int x, int y, int x1, int y1, int x2, int y2,  bool *control_bool);

/*pedina singola mangia torre doppia*/
void destroy_build_tower5(tavola *t, int x, int y, int x1, int y1, int x2, int y2,  bool *control_bool);

void promotion(tavola *t, int x, int y, bool *control_bool);

void copy_promotion_data(char *a, const char *b);
