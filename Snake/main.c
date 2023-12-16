#include "dungeon.h"
#include "engine.h"
#include "randomcpu.h"
#include <time.h>


int main() {
  clock_t start,end;
  long double tempo;
  start=clock();
  char dungeon[ROW][COL];       //creazione della matrice
  header_dungeon();             //intestazione del gioco
  clear_screen();
  create_dungeon(dungeon);      //aggiornamento del campo
  initialize_snake();

  if(select_mode())     //selezione modalità di gioco
      move(dungeon, select_move()); //gioco io
  else{
      makita_count+=3;
      move_cpu(dungeon, select_move_cpu()); //gioca random
  }
  deallocate_snake();
  end=clock();
  tempo=((long double)(end-start));
  printf("TEMPO ESECUZIONE: %0.Lf\n", tempo); 
  return 0;
}
