#ifndef CURSES_WRAPPER_H
#define CURSES_WRAPPER_H

#ifdef _WIN32
    #include "curses.h"
#else
    #include "ncurses.h"
#endif

#endif