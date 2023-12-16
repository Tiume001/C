#include "control.h"

bool control_3(tavola* t,int x2,int y2)
{
    /*se casella +1 o +2 è libera*/
    if(t->casella[x2][y2].pedina.colore==' ')
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool control(int x,int y,int x1,int y1)
{
    /*se coordinate di arrivo sono comprese nella tabella*/
    if((x>=0 && x<=6) && (y>=0 && y<=6) && (x1>=0 && x1<=6) && (y1>=0 && y1<=6) && (x1!=x) && (y1!=y))
    {
        return true;
    }
    else
    {
        printf("Pedina fuori campo!\n");
        return false;
    }
}


bool control_2(tavola* t, int x, int y, int x1, int y1,int x2,int y2)
{

    if (control(x, y, x1, y1) && (x2 >= 0 && x2 <= 6) && (y2 >= 0 && y2 <= 6)) {
        if (t->casella[x][y].pedina.colore == ROSSO) {
            /*se c'è pedina opposta in +1 e +2 è libero*/
            if (t->casella[x1][y1].pedina.colore == GIALLO && control_3(t, x2, y2)) {
                return true;
            } else {
                printf("Mossa non consentita!\n");
                return false;
            }
        } else {
            if (t->casella[x1][y1].pedina.colore == ROSSO && control_3(t, x2, y2)) {
                return true;
            } else {
                printf("Mossa non consentita!\n");
                return false;
            }
        }
    } else {
        printf("Mossa non consentita\n");
        return false;
    }
}


bool control_eat_1(const tavola *t, const int x, const int y)
{
    if(t->casella[x][y].pedina.tower[0]!=' '){
        return true;
    }
    else
    {
        return false;
    }
}


bool control_eat_2(tavola *t, int x, int y)
{
    if(t->casella[x][y].pedina.tower[1]!=' '){
        return true;
    }
    else
    {
        return false;
    }
}


bool control_tower(tavola *t, int x1, int y1)
{
    if(t->casella[x1][y1].pedina.tower[0]!=' ')
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool control_move(tavola *t, int x, int y, int x1){
    if((x<x1 && t->casella[x][y].pedina.colore==ROSSO) || (x>x1 && t->casella[x][y].pedina.colore==GIALLO))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool control_turn(tavola* t, int x, int y, int x1, int y1, const bool* control_bool)
{
    if((t->casella[x][y].pedina.colore==GIALLO && *control_bool==true) || (t->casella[x][y].pedina.colore==ROSSO && *control_bool==false))
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool control_promozione(tavola* t, int x, int y, const bool* control_bool)
{
    if((*control_bool==false && x==6) || (*control_bool==true && x==0))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool control_if_token_is_promoted(tavola *t, int x, int y)
{
    if(t->casella[x][y].pedina.promossa[0]!=' '){
        return true;
    }
    else
    {
        return false;
    }
}

bool control_tiles(tavola *t, bool *control_bool)
{
    int i, j;
    for(i=0;i<DIM;i++)
    {
        for(j=0;j<DIM;j++)
        {
            if((t->casella[i][j].pedina.colore==ROSSO && *control_bool)||(t->casella[i][j].pedina.colore==GIALLO && !*control_bool))
            {
                return true;
            }

        }
    }
    return false;
}
