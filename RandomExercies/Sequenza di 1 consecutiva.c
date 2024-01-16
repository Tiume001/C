/*Scrivere una funzione consecutive_ones che dato un array di interi v e un intero n ritorni 1 se l’array contiene una sequenza consecutiva di 1 lunga n, 0 altrimenti.*/
#include <stdio.h>

int consecutive_ones(int *v, unsigned v_size, unsigned n)
{
    int i, res =0;
    for (i=0; i<v_size; i++)
    {
        if (res == n)
        {
            return 1;
        }
        if (v[i]==1)
        {
            res = res +1;
        }
        else res =0;
        
    }

    return 0;
}

int main()
{
    int v[10] ={1,2,3,4,1,1,1,2,3,4};
    unsigned n = 3;
    printf("%d\n", consecutive_ones(v, 10, n));
    
    
    
    return 0;
}
