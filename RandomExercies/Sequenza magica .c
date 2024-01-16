/*     La sequenza magica è definita come segue:
 1- Ogni elemento della sequenza magica è una sequenza di numeri interi che inizia e finisce con 1.
 2- Ogni elemento è ottenuto innanzitutto dalla somma degli elementi adiacenti della sequenza precedente, e dopodiché inserendo un 1 all’inizio e alla fine della sequenza i primi 4 elementi della sequenza magica sono definiti come segue:
 1st:          1 1
               \+/
 2nd:        1  2  1
             \+/ \+/
 3rd:      1  3   3  1
           \+/ \+/ \+/
 4th     1  4   6   4  1
 
 Scrivere quindi una funzione magic_sequence che dato un intero n ritorni un array contenente la lista di interi corrispondenti all’ennesimo elemento della sequenza magica; un argomento di tipo puntatore a intero viene usato per memorizzare la lunghezza dell’array restituito.     */

#include <stdio.h>

unsigned *magic_seq(unsigned n, int *v_size)
{
    
    
    
    
    
    
}
int main()
{
    int i, v_size;
    unsigned *res = magic_seq(5, &v_size);
    for(i=0;i<v_size;i++)
    printf("%d ", res[i]);
    
    return 0;
}
