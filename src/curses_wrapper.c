#include "curses_wrapper.h"

/*
    initialising the ncurses library 
    and configuring the terminal settings for the game 
*/
void setupTerminal(void){
    initscr(); // initializing curses
    cbreak(); // disabling string buffering
    noecho(); // Disable the display of entered characters so that the game screen remains clear
    curs_set(0); // hide the cursor 
    keypad(stdscr, TRUE); // enabling the use of function keys (such as the arrow keys) 
}