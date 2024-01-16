/*  Scrivere una funzione tri_sum che dato un array di interi v di dimensione v_size, ritorni 1 contiene 3 elementi tali che la loro somma sia 0, e che ritorni 0 altrimenti. Assumiamo che v abbia almeno 3 elementi  */

#include <stdio.h>

/*int sum_tot(int *v, int v_size)
{
    int i, sum=0;
    for (i=0; i<v_size; i++)
    {
        sum = sum + v[i];
    }
    return sum;
}*/

int tri_sum(int *v, int v_size)
{
    int i,x,y;
    for (i=0; i<v_size; i++)
    {
        for (x=i+1; x<v_size; x++)
        {
            for (y=x+1; y<v_size; y++)
            {
                if ((v[i] + v[x] + v[y]) ==0)
                    return 1;         //ho trovato i 3 elemneti
            }
        }
        
    }
    return 0;  //esco dal ciclo , non ho trovato 3 elementi cui la loro somma fa 0
}
int main()
{
    int v[5]={7,-2,4,3,-1};
    printf("tri_sum({-1,-2,4,7,3}) = %d\n", tri_sum(v, 5));
    //printf("sum tot = %d\n", sum_tot(v, 5));
    return 0;
}
