//
// Created by Administrator on 17/03/2023.
//
#include <stdio.h>

#ifndef MAIN_C_MACRO_H
#define MAIN_C_MACRO_H

#endif //MAIN_C_MACRO_H


//define per codici di escape ANSI terminale
#define RESET      "\033[0m"
#define BOLD       "\033[1m"
#define SFUMATO    "\033[2m"
#define ITALIC     "\033[3m"
#define UNDERLINE  "\033[4m"
#define BLINK      "\x1b[5m"

#define BLACK      "\033[30m"
#define RED        "\033[31m"
#define GREEN      "\033[32m"
#define YELLOW     "\033[33m"
#define BLUE       "\033[34m"
#define MAGENTA    "\033[35m"
#define CIANO      "\033[36m"
#define WHITE      "\033[37m"

#define BG_BLACK    "\033[40m"
#define BG_RED      "\033[41m"
#define BG_GREEN    "\033[42m"
#define BG_YELLOW   "\033[43m"
#define BG_BLUE     "\033[44m"
#define BG_MAGENTA  "\033[45m"
#define BG_CIANO    "\033[46m"
#define BG_WHITE    "\033[47m"

// define per identificare i componenti del mio labirinto
#define MAKITA 'T'
#define WALL '#'
#define FOOD '$'
#define ENEMY '!'
#define BODY 'o'
#define END ']'
