#include "game.h"

#include <time.h>
#include "utils.h"

// main game loop 
void gameLoop(void){
    stateGame state_game;

    initGame(&state_game);
    drawMap(&state_game.m_);
    state_game.fp_ = spawnFood(&state_game.r_, 1, 48, 1, 23);

    state_game.uad_ = RIGHT;

    nodelay(stdscr, TRUE);

    while(!state_game.gameover_){
        drawSnake(&state_snake.ss_);
        
        int ch = getch();
        state_game.ua_ = inputUserAction(ch);

        if(state_game.ua_ == QUIT){
            state_game.gameover_ = true;
            break;
        }

        updateDir(&state_game.uad_, state_game.ua_);

        uint8_t snakeTailY_ = state_game.ss_.snakeY_[state_game.ss_.sizeSnake_ - 1];
        uint8_t snakeTailX_ = state_game.ss_.snakeX_[state_game.ss_.sizeSnake_ - 1];

        mvaddch(snakeTailY_, snakeTailX_, ' ');

        moveSnake(&state_game.ss_, state_snake.uad_);

        drawSnake(&state_snake.ss_);
        drawFood(&state_snake.fp_);

        refresh();
        usleep(100000);
    }
}

// initialisation of the game's starting state
void initGame(stateGame *state_game){
    state_game->gameover_ = false;
    rngSeed(&state_game->r_, (uint32_t)time(NULL));
    mapInitialisation(&state_game->m_);
    state_game->ssp_.startSnakeX_ = 15;
    state_game->ssp_.startSnakeY_ = 15;
    initSnake(&state_game->ss_, &state_game->ssp_);
}