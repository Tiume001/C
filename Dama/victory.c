#include "victory.h"
#include <stdio.h>
#include <stdbool.h>
#include "field.h"
#include "control.h"
#include "move.h"
#include "token.h"

int control_victory(tavola *t, bool *control_bool){
    int row, col, l;
    int coordinate[8][2]={ {1, 1}, {1, -1}, {-1, 1}, {-1, -1}, {2, 2}, {2, -2}, {-2, 2}, {-2, -2} };
    int count=0;
    for(row=0;row<DIM;row++){
        for(col=0;col<DIM;col++){
            for(l=0;l<8;l++){
                if((control_if_token_is_promoted(t, row, col) || control_move(t, row, col, row+coordinate[l<4][0])) && control_turn(t, row, col, row+coordinate[l<4][0], col+coordinate[l<4][1], control_bool)
                   && control_2(t, row, col, row+coordinate[l<4][0], col+coordinate[l<4][1],row+coordinate[l>3][0], col+coordinate[l>3][1]))
                {
                    ++count;
                }
            }
        }
    }
    if(count==0)
    {
        return count;
    }
    else
    {
        return 1;
    }
}
