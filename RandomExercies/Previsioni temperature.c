/*Scrivere una funzione temperature che dati due array di interi p e t, contenenti rispettivamente le previsioni delle temperature previste per un certo numero di giorni n e le temperature reali osservate in quei giorni, ritorni il numero di giorni in cui le previsioni non sono state accurate. Una previsione non è accurata se il suo scarto, in valore assoluto, supera una certa soglia treshold, anch’essa passata come parametro alla funzione.*/

#include <stdio.h>

int temperature(int *p, int *t, int v_size, int treshold)
{
    int i, res=0;
    for (i=0; i<v_size; i++)
    {
        if (p[i]-t[i] > treshold)
            res = res +1;
        if (t[i]-p[i] > treshold)
            res = res +1;
    }
    return res;
}

int main()
{
    int t [6] = {25, 26, 28, 31, 27, 25};    //previsioni
    int p [6] = {26, 27, 27, 27, 28, 29};    //temperature reali
    printf("temperature(p, t, 6, 3): %d\n", temperature(p, t, 6, 3));
    
    return 0;
}
