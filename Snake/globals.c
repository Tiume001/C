//
// Created by Administrator on 17/03/2023.
//

#include "globals.h"

const int ROW = 20;   // NUMERO COLONNE DEL DUNGEON
const int COL = 30;   // NUMERO COLONNE DEL DUNGEON
int x_head;           // coordinata righe testa
int y_head;           // coordinata colonne testa
int x_exit;
int makita_count = 0; // contatore trapani
int snake_lenght = 0; // lunghezza del serpente
int score = 1000;     // punteggio di partenza
int enemy_count= 0;   // contatore nemici raccolti
int move_count = 1;   // contatore delle mosse