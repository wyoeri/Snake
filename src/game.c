#include "game.h"

#include <time.h>
#include <memory.h>
#include <unistd.h>
#include "utils.h"
#include "curses_wrapper.h"

// main game loop 
void gameLoop(void){
    stateGame state_game;

    initGame(&state_game);
    drawMap(&state_game.m_);
    state_game.fp_ = spawnFood(&state_game.r_, 1, 48, 1, 23);

    timeout(VALUETIMEOUT);

    while(!state_game.gameover_){
        drawSnake(&state_game.ss_);
        
        int ch = getch();
        state_game.ua_ = inputUserAction(ch);

        if(state_game.ua_ == QUIT){
            state_game.gameover_ = true;
            break;
        }

        updateDir(&state_game.uad_, state_game.ua_);

        if(checkCollidedSnakeWall(&state_game)){
            state_game.gameover_ = true;
            break;
        }

        uint8_t snakeTailY_ = state_game.ss_.snakeY_[state_game.ss_.sizeSnake_ - 1];
        uint8_t snakeTailX_ = state_game.ss_.snakeX_[state_game.ss_.sizeSnake_ - 1];

        mvaddch(snakeTailY_, snakeTailX_, ' ');

        moveSnake(&state_game.ss_, state_game.uad_);

        if(state_game.ss_.snakeX_[0] == state_game.fp_.foodX_ && state_game.ss_.snakeY_[0] == state_game.fp_.foodY_){
            state_game.score_ += 10;
            state_game.fp_ = spawnFood(&state_game.r_, 1, 48, 1, 23);
            state_game.ss_.sizeSnake_++;
        }

        drawSnake(&state_game.ss_);
        drawFood(&state_game.fp_);


        refresh();
    }
    endwin();
    clear_screen();
}

// initialisation of the game's starting state
void initGame(stateGame *state_game){
    memset(state_game, 0, sizeof(stateGame));

    state_game->uad_ = RIGHT;

    setupTerminal();

    rngSeed(&state_game->r_, (uint32_t)time(NULL));

    mapInitialisation(&state_game->m_);

    state_game->ssp_.startSnakeX_ = 15;
    state_game->ssp_.startSnakeY_ = 15;
    initSnake(&state_game->ss_, &state_game->ssp_);

    state_game->score_ = 0;
    state_game->gameover_ = false;
}

// checking whether the snake has collided with the wall
bool checkCollidedSnakeWall(stateGame *state_game){
    uint8_t headSnakeX = state_game->ss_.snakeX_[0];
    uint8_t headSnakeY = state_game->ss_.snakeY_[0];

    if(state_game->m_.map_[headSnakeY][headSnakeX] == 1){
        return true;
    }

    return false;
}