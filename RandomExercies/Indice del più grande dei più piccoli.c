/*Scrivere una funzione largest_smaller_index che dato un array di interi positivi v e un intero positivo n, ritorni l’indice del più grande elemento in v, elem, che sia però inferiore a n; ovvero elem
 < n. Se non esiste un elemento che rispetta la condizione sopracitata, la funzione deve ritornare -1.*/

#include <stdio.h>

int largest_smaller_index (int *v, int v_size, int n)
{
    int i , elem = 0, max =0, res =0;
    for (i=0; i<v_size; i++)
    {
        if (v[i] > max && elem < n)
        {
            max = v[i];
            res = i;
        }
    }
    return res;
}

int main()
{
    int v[7]={13,21,14,1,3,7,14};
    printf("The index of the largest number that is smaller of 22 in v is: %d\n", largest_smaller_index(v, 7, 22));
    return 0;
}
