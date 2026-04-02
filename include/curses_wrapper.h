#ifndef CURSES_WRAPPER_H
#define CURSES_WRAPPER_H

#ifdef _WIN32
    #include "curses.h"
#else
    #include "ncurses.h"
#endif

/*
    initialising the ncurses library 
    and configuring the terminal settings for the game 
*/
void setupTerminal(void);

#endif