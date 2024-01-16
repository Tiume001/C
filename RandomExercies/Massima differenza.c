/*Siano in e out due array che memorizzano la quantità in Kg di ciliege rispettivamente raccolte e vendute dal coltivatore Claude ogni giorno nell’ultimo periodo. (Assumiamo che in e out siano array di float e che abbiano la stessa lunghezza maggiore di zero). Scrivere una funzione my_fun che dati in input i due array e la loro lunghezza, restituisca la massima differenze tra i due quantitativi, definita come segue:  𝑀𝐷(𝑖𝑛, 𝑜𝑢𝑡) = max(𝑖𝑛[𝑖] − 𝑜𝑢𝑡[𝑖]) */

#include <stdio.h>

float dif (float *in, float *out, int v_size)
{
    int i, res1 =0, max =0;
    for (i=0; i<v_size; i++)
    {
        res1= in[i]-out[i];
        if (res1 > max)
            max = res1;
    }
    return max;
}

int main()
{
    float in[] = {10.0f, 33.0f, 25.0f};
    float out[] = {2.0f, 28.0f, 21.0f};
    
    printf("%.2f\n", dif(in, out, 3));
    
    
    
    
    return 0;
}
