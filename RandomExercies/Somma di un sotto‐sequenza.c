/*Scrivere una funzione contiguous_subset_sum che dato un array di interi v computi la sotto‐ sequenza dell’array avente la più grande somma dei suoi elementi, e ritorni tale somma.*/

#include <stdio.h>

/*int SUM_tot(int *v, int v_size)
{
    int sum =0,i;
    for (i=0; i<v_size; i++)
    {
        sum = sum + v[i];
    }
    return sum;
}*/


int contiguous_subset_sum(int *v, int v_size)
{
    int i, sum =0, res =0;
    if (v_size ==0)
        return 0;
    
    for (i=0; i<v_size; i++)
    {
        if (sum >0)
            sum = sum + v[i];
        else sum = v[i];
        
        if (sum > res)
            res = sum;
    }
    return res;
}



int main()
{
    int v[9]={5,-4,3,2,-1,0,1,8,-3};
    //printf("%d\n", SUM_tot(v, 9));
    printf("%d\n", contiguous_subset_sum(v, 9));
    return 0;
}
