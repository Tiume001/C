/*Scrivere una funzione consecutive_numbers che dato un array di interi v ritorni la lunghezza della sequenza di numeri consecutivi contenuta all’interno dell’array.*/

#include <stdio.h>

int MAX(int a, int b)
{
    if (a>b)
        return a;
    else return b;
}

int cons_numbers(int *v, int v_size)
{
    int i, max_cons_numb =1, cons=0, res =1;
    for (i=0; i<v_size-1; i++)
    {
        cons = v[i];
        if (v[i+1] == cons +1)
        {
            max_cons_numb = max_cons_numb +1;
        }
        else
        {
            res = MAX(res, max_cons_numb);
            max_cons_numb =1;
        }
        
    }
    
    return res;
}

int main ()
{
    int v[11]={1,2,3,0,1,2,3,4,1,2,3};
    printf("%d\n", cons_numbers(v, 11));
    return 0;
}
