#include "move.h"
#include "token.h"
#include "field.h"
#include "control.h"

void make_move(tavola* t,bool* control_bool) {
    int x, y, x1, y1, x2, y2;
    if (*control_bool == false)
    {
        printf("Turno X:\n");
    }
    else
    {
        printf("Turno O:\n");
    }
    printf("Inserisci coordinate pedina che vuoi muovere, riga: ");
    scanf("%d", &x);
    printf("colonna: ");
    scanf("%d", &y);
    printf("Dove vuoi muovere pedina? Inserisci riga: ");
    scanf(" %d", &x1);
    printf("Dove vuoi muovere pedina? Inserisci colonna: ");
    scanf(" %d", &y1);
    if (x1 == x + 1)
    {
        if (y1 == y + 1)
        {
            x2 = x + 2;
            y2 = y + 2;
        }
        else
        {
            x2 = x + 2;
            y2 = y - 2;
        }
    }
    else if (x1 == x - 1)
    {
        if (y1 == y + 1)
        {
            x2 = x - 2;
            y2 = y + 2;
        }
        else
        {
            x2 = x - 2;
            y2 = y - 2;
        }
    }

    if((control_move(t, x, y, x1) && !control_if_token_is_promoted(t, x, y)) || (!control_move(t, x, y, x1) && control_if_token_is_promoted(t, x, y)))
    {
        if (control_turn(t, x, y, x1, y1, control_bool))
        {
            /*promozione torri e mangiare*/
            if (control_2(t, x, y, x1, y1, x2, y2))
            {
                /*torri che mangiano singole*/
                if (!control_tower(t, x1, y1))
                {
                    if (!control_eat_1(t, x, y) && !control_eat_2(t, x, y))
                    {
                        build_tower(t, x, y, x1, y1, x2, y2, control_bool);
                        if(control_if_token_is_promoted(t, x, y))
                        {
                            copy_promotion_data(t->casella[x2][y2].pedina.promossa, t->casella[x][y].pedina.promossa);
                        }
                        initialize_promotion(t, x, y);
                    } else if (control_eat_1(t, x, y) && !control_eat_2(t, x, y)) {
                        copy_eat_data(t->casella[x2][y2].pedina.tower, t->casella[x][y].pedina.tower);
                        build_tower2(t, x, y, x1, y1, x2, y2, control_bool);
                        if (control_if_token_is_promoted(t, x, y))
                        {
                            copy_promotion_data(t->casella[x2][y2].pedina.promossa, t->casella[x][y].pedina.promossa);
                        }
                        initialize_promotion(t, x, y);
                    } else if (control_eat_1(t, x, y) && control_eat_2(t, x, y))
                    {
                        build_tower3(t, x, y, x1, y1, x2, y2, control_bool);
                        if (control_if_token_is_promoted(t, x, y))
                        {
                            copy_promotion_data(t->casella[x2][y2].pedina.promossa, t->casella[x][y].pedina.promossa);
                        }
                        initialize_promotion(t, x, y);
                    }
                }
                    /*posizione di arrivo c'è torre*/
                else if (control_tower(t, x1, y1))
                {
                    if (!control_tower(t, x, y) && control_eat_1(t, x1, y1) && !control_eat_2(t, x1, y1))
                    {
                        destroy_build_tower(t, x, y, x1, y1, x2, y2, control_bool);
                        if (control_if_token_is_promoted(t, x, y))
                        {
                            copy_promotion_data(t->casella[x2][y2].pedina.promossa, t->casella[x][y].pedina.promossa);
                        }
                        initialize_promotion(t, x, y);
                    }
                    else if (!control_tower(t, x, y) && control_eat_1(t, x1, y1) && control_eat_2(t, x1, y1) && control_eat_1(t, x1, y1) && control_eat_2(t, x1, y1))
                    {
                        destroy_build_tower5(t, x, y, x1, y1, x2, y2, control_bool);
                        if (control_if_token_is_promoted(t, x, y))
                        {
                            copy_promotion_data(t->casella[x2][y2].pedina.promossa, t->casella[x][y].pedina.promossa);
                        }
                        initialize_promotion(t, x, y);
                    }
                    else if (control_tower(t, x, y) && control_eat_1(t, x, y) && !control_eat_2(t, x, y) && control_eat_1(t, x1, y1) && !control_eat_2(t, x1, y1))
                    {
                        destroy_build_tower1(t, x, y, x1, y1, x2, y2, control_bool);
                        if (control_if_token_is_promoted(t, x, y))
                        {
                            copy_promotion_data(t->casella[x2][y2].pedina.promossa, t->casella[x][y].pedina.promossa);
                        }
                        initialize_promotion(t, x, y);
                    }
                    else if (control_tower(t, x, y) && control_eat_1(t, x, y) && !control_eat_2(t, x, y) && control_eat_1(t, x1, y1) && control_eat_2(t, x1, y1))
                    {
                        destroy_build_tower2(t, x, y, x1, y1, x2, y2, control_bool);
                        if (control_if_token_is_promoted(t, x, y))
                        {
                            copy_promotion_data(t->casella[x2][y2].pedina.promossa, t->casella[x][y].pedina.promossa);
                        }
                        initialize_promotion(t, x, y);
                    }
                    else if(control_tower(t, x, y) && control_eat_1(t, x, y) && control_eat_2(t, x, y) && control_eat_1(t, x1, y1) && control_eat_2(t, x1, y1))
                    {
                        printf("Pedina eliminata\n");
                        destroy_build_tower3(t, x, y, x1, y1, x2, y2, control_bool);
                        if (control_if_token_is_promoted(t, x, y))
                        {
                            copy_promotion_data(t->casella[x2][y2].pedina.promossa, t->casella[x][y].pedina.promossa);
                        }
                    }
                    else if (control_tower(t, x, y) && control_eat_1(t, x, y) && control_eat_2(t, x, y) && control_eat_1(t, x1, y1) && !control_eat_2(t, x1, y1))
                    {
                        printf("Pedina eliminata\n");
                        destroy_build_tower4(t, x, y, x1, y1, x2, y2, control_bool);
                        if (control_if_token_is_promoted(t, x, y))
                        {
                            copy_promotion_data(t->casella[x2][y2].pedina.promossa, t->casella[x][y].pedina.promossa);
                        }
                        initialize_promotion(t, x, y);
                    }
                }
                if (*control_bool == true)
                {
                    *control_bool = false;
                }
                else
                {
                    *control_bool = true;
                }
            }
            else if (control(x, y, x1, y1) && control_3(t, x1, y1))
            {
                copy_eat_data(t->casella[x1][y1].pedina.tower, t->casella[x][y].pedina.tower);
                t->casella[x1][y1].pedina.colore = t->casella[x][y].pedina.colore;
                t->casella[x][y].pedina.colore = ' ';
                promotion(t, x1, y1, control_bool);
                initialize_eat(t, x, y);
                if (control_if_token_is_promoted(t, x, y))
                {
                    copy_promotion_data(t->casella[x1][y1].pedina.promossa, t->casella[x][y].pedina.promossa);
                }
                initialize_promotion(t, x, y);
                if (*control_bool == true)
                {
                    *control_bool = false;
                }
                else
                {
                    *control_bool = true;
                }
            }
        }
    }
    else
    {
        printf("Mossa non consentita!\n");
    }
    print_field(t);
}
