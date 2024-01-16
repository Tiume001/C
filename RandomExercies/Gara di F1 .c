/*A termine di una gara di Formula 1, vengono registrati i tempi sul giro di due piloti A e B, rispettivamente in due array di interi: a e b, di dimensione n. Scrivere una funzione f1_race che dati due array di interi a e b, trovi il numero di giri che sono stati necessari al pilota A per ottenere più di t secondi di vantaggio su B, anche t viene passato come parametro alla funzione. Se A non raggiunge mai il vantaggio desiderato la funzione ritorna -1.*/

#include <stdio.h>
#include <stdlib.h>

int f1_race(int *a, int *b, int giri_corsa, int sec)
{
    int i, res=0, sec_acc =0;
    for (i=0; i<giri_corsa; i++)
    {
        sec_acc = sec_acc + abs(a[i]-b[i]);
        if (sec_acc > sec )
            res = i-1;
    }
    return res;
}
int main()
{
    int a[5] = {100, 98, 100, 99, 101};
    int b[5] = {105, 102, 105, 95, 95};
    printf("f1_race(a, b, 10, 5): %d\n", f1_race(a, b, 5, 10));
    
    return 0;
}
