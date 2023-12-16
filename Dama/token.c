#include "token.h"
#include "field.h"
#include "control.h"
#include <stdbool.h>



void build_tower(tavola* t,int x,int y,int x1,int y1,int x2,int y2,  bool *control_bool)
{
    t->casella[x2][y2].pedina.colore=t->casella[x][y].pedina.colore;
    t->casella[x2][y2].pedina.tower[0]=t->casella[x1][y1].pedina.colore;
    t->casella[x1][y1].pedina.colore=' ';
    t->casella[x][y].pedina.colore=' ';
    promotion(t, x2, y2, control_bool);
    initialize_eat(t, x, y);
    initialize_eat(t, x1, y1);
}


void build_tower2(tavola* t,int x,int y,int x1,int y1,int x2,int y2,  bool *control_bool)
{
    t->casella[x2][y2].pedina.colore=t->casella[x][y].pedina.colore;
    t->casella[x2][y2].pedina.tower[1]=t->casella[x1][y1].pedina.colore;
    t->casella[x1][y1].pedina.colore=' ';
    t->casella[x][y].pedina.colore=' ';
    promotion(t, x2, y2, control_bool);
    initialize_eat(t, x, y);
    initialize_eat(t, x1, y1);
}


void build_tower3(tavola* t,int x,int y,int x1,int y1,int x2,int y2,  bool *control_bool)
{
    char temp1=' ';
    temp1=t->casella[x][y].pedina.tower[1];
    t->casella[x2][y2].pedina.colore=t->casella[x][y].pedina.colore;
    t->casella[x2][y2].pedina.tower[0]=temp1;
    t->casella[x2][y2].pedina.tower[1]=t->casella[x1][y1].pedina.colore;
    t->casella[x1][y1].pedina.colore=' ';
    t->casella[x][y].pedina.colore=' ';
    promotion(t, x2, y2, control_bool);
    initialize_eat(t, x, y);
    initialize_eat(t, x1, y1);
}

/*pedina singola mangia torre singola*/
void destroy_build_tower(tavola* t,int x,int y,int x1,int y1,int x2,int y2,  bool *control_bool)
{
    char temp=' ';
    t->casella[x2][y2].pedina.colore=t->casella[x][y].pedina.colore;
    temp=t->casella[x1][y1].pedina.tower[0];
    t->casella[x2][y2].pedina.tower[0]=t->casella[x1][y1].pedina.colore;
    t->casella[x1][y1].pedina.colore=temp;
    t->casella[x][y].pedina.colore=' ';
    promotion(t, x2, y2, control_bool);
    initialize_eat(t, x, y);
    initialize_eat(t, x1, y1);
}

/*torre mangia torre*/
void destroy_build_tower1(tavola *t, int x, int y, int x1, int y1, int x2, int y2,  bool *control_bool)
{
    char temp1=' ', temp2=' ';
    temp1=t->casella[x][y].pedina.tower[0];
    temp2=t->casella[x1][y1].pedina.tower[0];
    t->casella[x2][y2].pedina.colore=t->casella[x][y].pedina.colore;
    t->casella[x2][y2].pedina.tower[0]=temp1;
    t->casella[x2][y2].pedina.tower[1]=t->casella[x1][y1].pedina.colore;
    t->casella[x1][y1].pedina.colore=temp2;
    t->casella[x][y].pedina.colore=' ';
    promotion(t, x2, y2, control_bool);
    initialize_eat(t, x1, y1);
    initialize_eat(t, x, y);
}

/*torre mangia torre con 2 mangiate*/
void destroy_build_tower2(tavola *t, int x, int y, int x1, int y1, int x2, int y2,  bool *control_bool)
{
    char temp1=' ', temp2=' ', temp3=' ';
    temp1=t->casella[x][y].pedina.tower[0];
    temp2=t->casella[x1][y1].pedina.tower[0];
    temp3=t->casella[x1][y1].pedina.tower[1];
    t->casella[x2][y2].pedina.colore=t->casella[x][y].pedina.colore;
    t->casella[x2][y2].pedina.tower[0]=temp1;
    t->casella[x2][y2].pedina.tower[1]=t->casella[x1][y1].pedina.colore;
    t->casella[x1][y1].pedina.colore=temp3;
    t->casella[x1][y1].pedina.tower[0]=temp2;
    t->casella[x][y].pedina.colore=' ';
    promotion(t, x2, y2, control_bool);
    initialize_eat(t, x, y);
}

/*doppia torre mangia una doppia torre*/
void destroy_build_tower3(tavola *t, int x, int y, int x1, int y1, int x2, int y2,  bool *control_bool)
{
    char temp1=' ', temp2=' ', temp3=' ', temp4=' ';
    temp1=t->casella[x][y].pedina.tower[0];
    temp2=t->casella[x][y].pedina.tower[1];
    temp3=t->casella[x1][y1].pedina.tower[0];
    temp4=t->casella[x1][y1].pedina.tower[1];
    t->casella[x2][y2].pedina.colore=t->casella[x][y].pedina.colore;
    t->casella[x2][y2].pedina.tower[0]=temp2;
    t->casella[x2][y2].pedina.tower[1]=t->casella[x1][y1].pedina.colore;
    t->casella[x1][y1].pedina.colore=temp4;
    t->casella[x1][y1].pedina.tower[0]=temp3;
    t->casella[x1][y1].pedina.tower[1]=' ';
    t->casella[x][y].pedina.colore=' ';
    promotion(t, x2, y2, control_bool);
    initialize_eat(t, x, y);
}

/*doppia torre mangia una torre singola*/
void destroy_build_tower4(tavola *t, int x, int y, int x1, int y1, int x2, int y2,  bool *control_bool)
{
    char temp1=' ', temp2=' ';
    temp1=t->casella[x][y].pedina.tower[1];
    temp2=t->casella[x1][y1].pedina.tower[0];
    t->casella[x2][y2].pedina.colore=t->casella[x][y].pedina.colore;
    t->casella[x2][y2].pedina.tower[0]=temp1;
    t->casella[x2][y2].pedina.tower[1]=t->casella[x1][y1].pedina.colore;
    t->casella[x1][y1].pedina.colore=temp2;
    t->casella[x][y].pedina.colore=' ';
    promotion(t, x2, y2, control_bool);
    initialize_eat(t, x, y);
    initialize_eat(t, x1, y1);
}

/*pedina singola mangia torre doppia*/
void destroy_build_tower5(tavola *t, int x, int y, int x1, int y1, int x2, int y2, bool *control_bool){
    char temp1=' ', temp2=' ';
    temp1=t->casella[x1][y1].pedina.tower[0];
    temp2=t->casella[x1][y1].pedina.tower[1];
    t->casella[x2][y2].pedina.colore=t->casella[x][y].pedina.colore;
    t->casella[x2][y2].pedina.tower[0]=t->casella[x1][y1].pedina.colore;
    t->casella[x1][y1].pedina.colore=temp2;
    t->casella[x1][y1].pedina.tower[0]=temp1;
    t->casella[x1][y1].pedina.tower[1]=' ';
    t->casella[x][y].pedina.colore=' ';
    promotion(t, x2, y2, control_bool);
    initialize_eat(t, x, y);
}

void promotion(tavola *t, int x, int y, bool *control_bool)
{
    if(control_promozione(t, x, y, control_bool))
    {
        printf("La tua pedina è stata promossa!\n");
        t->casella[x][y].pedina.promossa[0]=PROMOTION;
    }
}

void copy_promotion_data(char *a, const char *b){
    char a1 = b[0];
    a[0] = a1;
}

void copy_eat_data( char *a, char *b)
{
    char a1 = b[0];
    char b1= b[1];

    a[0] = a1;
    a[1] = b1;
}
