/*Siano in e out due array che memorizzano il flusso di cassa in migliaia di dollari della NewCola per ognigiornodell’ultimoperiodo. (Assumiamo che in e out siano array di float e che abbiano la stessa lunghezza maggiore di zero). Scrivere una funzione my_fun che dati in input i due array e la loro lunghezza, restituisca il numero di giorni in cui il flusso di cassa (𝑖𝑛[𝑖] − 𝑜𝑢𝑡[𝑖]) è negativo.*/

#include <stdio.h>

int my_fun(float *in, float *out, int v_size)
{
    int i, res =0, res1 =0;
    for (i=0; i<v_size; i++)
    {
        res = in[i] - out[i];
        if (res < 0)
        {
            res1 = res1 +1;
        }
    }
    return res1;
}

int main()
{
    float in[] = {10.0f, 28.0f, 21.0f, 15.0f};
    float out[] = {2.0f, 33.0f, 25.0f, 20.0f};
    printf("%d\n", my_fun(in, out, 4));
    
    return 0;
}
