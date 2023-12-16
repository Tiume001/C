#include <stdio.h>
#include <stdbool.h>
#include "field.h"
#include "control.h"
#include "move.h"
#include "token.h"
#include "victory.h"
#define ROSSO 'X'
#define GIALLO 'O'
#define PROMOTION 'P'
#define DIM (7)

int main()
{
    int exit=0;
    bool control_bool = false;
    tavola Tavola_Laska;
    initialize_table(&Tavola_Laska);
    print_field(&Tavola_Laska);
    while(exit==0){
        do
        {
            make_move(&Tavola_Laska, &control_bool);
        }
        while(control_victory(&Tavola_Laska, &control_bool)!=0);
        if(control_bool)
        {
            printf("O ha vinto!!!");
            exit=1;
        }
        else if(!control_bool)
        {
            printf("X ha vinto!!");
            exit=1;
        }
    }
    return 0;
}

