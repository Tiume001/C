#include "field.h"

void print_field(tavola* t)
{
    int i;
    int j;
    int c;
    int m;
    int k;
    int l;
    int h=0;
    for(l=0;l<DIM;l++){
        printf("|   %d   ", l);
    }
    printf("|");
    printf("\n");
    printf("+");
    for(k=0;k<55;k++)
        printf("-");
    printf("+");
    for(i=0;i<DIM;i++)
    {
        for(m=0;m<4;m++)
        {
            printf("|");
            if(i==0 && m==0)
                printf("\b");
            for(j=0;j<8;j++)
            {
                for(c=0;c<DIM;c++)
                {
                    if(c==0 && m==1 && j<DIM)
                    {
                        if(t->casella[i][j].pedina.tower[0]!=' ')
                        {
                            printf("%c", t->casella[i][j].pedina.tower[0]);
                        }
                        else if(t->casella[i][j].pedina.tower[0]==' ')
                        {
                            printf(" ");
                        }
                    }
                    if(c==1 && m==1 && j<DIM)
                    {
                        if(t->casella[i][j].pedina.tower[1]!=' ')
                        {
                            printf("%c", t->casella[i][j].pedina.tower[1]);
                        }
                        else if(t->casella[i][j].pedina.tower[1]==' ')
                        {
                            printf(" ");
                        }
                    }
                    if(c==6 && m==3 && j<DIM)
                    {
                        if(t->casella[i][j].pedina.promossa[0]!=' ')
                        {
                            printf("%c", t->casella[i][j].pedina.promossa[0]);
                        }
                        else if(t->casella[i][j].pedina.promossa[0]==' ')
                        {
                            printf(" ");
                        }
                    }
                    if(c==3 && m==2 && i%2==0 && j<DIM)
                    {
                        if (j % 2 == 0)
                            printf("%c", t->casella[i][j].pedina.colore);
                        else
                            printf("#");
                    }
                    else if(c==3 && m==2 && i%2!=0 && j<DIM)
                    {
                        if (j % 2 != 0 && j<DIM)
                            printf("%c", t->casella[i][j].pedina.colore);
                        else
                            printf("#");
                    }
                    else if (j<DIM)
                    {
                        if(i%2!=0 && j%2==0 && m!=0 && c<DIM)
                        {
                            if(((c==0 || c==1) && m==1) || (c==6 && m==3))
                            {
                                printf("\b");
                            }
                            printf("#");
                        }
                        else if(i%2==0 && j%2!=0 && m!=0 && c<DIM)
                        {
                            if(((c==0 || c==1) && m==1) || (c==6 && m==3))
                            {
                                printf("\b");
                            }
                            printf("#");
                        }
                        else
                        {
                            if(c==6 && m==1)
                            {
                                printf("\b\b");
                            }
                            if(c==1 && m==3)
                            {
                                printf("\b");
                            }
                            printf(" ");
                        }
                    }
                    else if(j==DIM && m==2 && c==0)
                    {
                        if(i<DIM && h<DIM){
                            printf(" %d",h++);
                        }
                    }
                }
                if (m != 0 && j<DIM)
                    printf("|");
            }
            printf("\n");
        }
        printf("|");
        for(k=0;k<55 && i<6;k++){
            printf("-");
        }
    }
    printf("\b");
    printf("+");
    for(k=0;k<55;k++)
        printf("-");
    printf("+");
    printf("\n");
}


void initialize_eat(tavola *t, int i, int j)
{
    t->casella[i][j].pedina.tower[0]=' ';
    t->casella[i][j].pedina.tower[1]=' ';
}

void initialize_promotion(tavola *t, int i, int j)
{
    t->casella[i][j].pedina.promossa[0]=' ';
}

void initialize_table(tavola* t)
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<DIM;j++)
        {
            t->casella[i][j].pedina.colore=ROSSO;
            initialize_eat(t, i, j);
            initialize_promotion(t, i, j);
        }
    }
    for(j=0;j<DIM;j++)
    {
        t->casella[3][j].pedina.colore=' ';
        initialize_eat(t, 3, j);
        initialize_promotion(t, 3, j);
    }
    for(i=4;i<DIM;i++)
    {
        for(j=0;j<DIM;j++)
        {
            t->casella[i][j].pedina.colore=GIALLO;
            initialize_eat(t, i, j);
            initialize_promotion(t, i, j);
        }
    }
}


