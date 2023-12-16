#include <stdio.h>

int controlla(char board [3][3])
{     //0->nulla, 1->win giocatore x, 2->win giocatore o, 3->draw;
    int i, j;
    //GIOCATORE X !!!!
    for (i=0; i<3; ++i)
    {
        if (board[i][i] != 'X')     //pos: [0][0], [1][1], [2][2].
        {
            break;
        }
    }
    if (i == 3)
    {
        return 1;  //il giocatore X ha vinto;
    }
    for (i=0; i<3; ++i)
    {
        if (board[i][2-i] != 'X')     //diagonale
        {
            break;
        }
    }
    if (i == 3)
    {
        return 1;
    }
    for (j=0; j<3; ++j)
    {
        for(i=0; i<3; ++i)
        {
            if (board[j][i] != 'X')
            {
                break;
            }
        }
        if (i == 3)
        {
            return 1;
        }
    }
    for (j=0; j<3; ++j)
    {
        for(i=0; i<3; ++i)
        {
            if (board[i][j] != 'X')
            {
                break;
            }
        }
        if (i == 3)
        {
            return 1;
        }
    }
    //GIOCATORE 0 !!!
    for (i=0; i<3; ++i)
    {
        if (board[i][i] != 'O')     //pos: [0][0], [1][1], [2][2].
        {
            break;
        }
    }
    if (i == 3)
    {
        return 2;      //il giocatore O ha vinto;
    }
    for (i=0; i<3; ++i)
    {
        if (board[i][2-i] != 'O')     //diagonale
        {
            break;
        }
    }
    if (i == 3)
    {
        return 2;
    }
    for (j=0; j<3; ++j)
    {
        for(i=0; i<3; ++i)
        {
            if (board[j][i] != 'O')
            {
                break;
            }
        }
        if (i == 3)
        {
            return 2;
        }
    }
    for (j=0; j<3; ++j)
    {
        for(i=0; i<3; ++i)
        {
            if (board[i][j] != 'O')
            {
                break;
            }
        }
        if (i == 3)
        {
            return 2;
        }
    }
    //PAREGGIO !!!
    for (i=0; i<3; ++i)
    {
        for (j=0; j<3; ++j)
        {
            if (board[i][j] == '-')
            {
                break;
            }
        }
        if (j != 3)
        {
            return 0;
        }
    }
    return 3;
}

void show(char board[3][3])
{
    for (int i=0; i<3; ++i)
    {
        printf ("%c %c %c\n", board[i][0], board[i][1], board[i][2]);
    }
    return;
}

int main()
{
    char board [3][3];
    int r, c, t, i , j;
    for (i=0; i<3; ++i)
    {
        for (j=0; j<3; ++j)
        {
            board[i][j] = '-';
        }
    }
    while(1)
    {
        show(board);
        printf ("it's your turn! put your row, space-bar, col value here: ");
        scanf("%d %d", &r, &c);
        board[r][c] = 'X';
        t = controlla(board);
        if (t == 1)
        {
            printf("ha vinto il giocatore X\n");
            break;
        }
        else if (t == 2)
        {
            printf ("ha vinto il giocatore O\n");
            break;
        }
        else if (t == 3)
        {
            printf ("pareggio\n");
            break;
        }
        show(board);
        printf ("it's your turn! put your row, space-bar, col value here: ");
        scanf("%d %d", &r, &c);
        board[r][c] = 'O';
        t = controlla(board);
        if (t == 1)
        {
            printf("ha vinto il giocatore X\n");
            break;
        }
        else if (t == 2)
        {
            printf ("ha vinto il giocatore O\n");
            break;
        }
        else if (t == 3)
        {
            printf ("pareggio\n");
            break;
        }
    }
    return 0;
}
