/*Ipotizziamo di avere un software che fa previsioni sul tasso di cambio giornaliero di una determinata valuta e che restituisca un array p di dimensione n per una determinata serie di giorni. Ipotizziamo anche di avere il valore reale del tasso di cambio di quei giorni in un array chiamato t. Scrivere una funzione che prenda in input p e t (ipotizzando che abbiano la stessa grandezza n e che contengano valori di tipo float) e che restituisca il mean squared error (MSE) per verificare la qualità delle nostre previsioni. MSE è calcolato come:
 MSE(𝑝, 𝑡) = ∑𝑖 (𝑝[𝑖] − 𝑡[𝑖])2 / 𝑛
 */

#include <stdio.h>
#include <math.h>

float mse(float *p, float *t, float v_size)
{
    int i;
    float sq = 0.0;
    for (i=0; i<v_size; i++)
    {
        sq = pow(p[i]-t[i], 2);
    }
    return sq / v_size;
}

int main()
{
    float t[] = {1.f, 3.f};    //valore reale del tasso di cambio di 2 giori
    float p[] = {1.f, 5.f};
    printf("%.f\n", mse(p, t, 2));
    
    
    
    return 0;
}
