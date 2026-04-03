#include "game.h"

#include <time.h>
#include <memory.h>
#include <unistd.h>
#include "utils.h"
#include "curses_wrapper.h"
#include "draw.h"

// main game loop 
void gameLoop(void){
    stateGame game;

    initGame(&game);
    drawMap(&game.m_);
    game.food_pos_ = spawnFood(&game.r_, MIN_Y, MAX_Y, MIN_X, MAX_X);

    while(!game.gameover_){
        drawSnake(&game.state_snake_);
        drawFood(&game.food_pos_);

        displayScore(&game);
        displaySizeSnake(&game);

        int ch = getch();
        game.user_action_ = inputUserAction(ch);

        if(game.user_action_ == QUIT){
            game.gameover_ = true;
            break;
        }

        updateDir(&game.user_action_dir_, game.user_action_);

        // calculating the tail length
        uint8_t snakeTailY_ = game.state_snake_.snakeY_[game.state_snake_.sizeSnake_ - 1];
        uint8_t snakeTailX_ = game.state_snake_.snakeX_[game.state_snake_.sizeSnake_ - 1];

        moveSnake(&game.state_snake_, game.user_action_dir_);

        if(checkCollidedSnakeWall(&game) || checkCollidedSnakeHeadBody(&game.state_snake_)){
            game.gameover_ = true;
            break;
        }

        /*
        After the snake moves, its tail leaves the previous cell.
        If that cell was a wall, redraw the wall ('#'), otherwise clear it (' ').
        */
        if(game.m_.map_[snakeTailY_][snakeTailX_] == 1){
            mvaddch(snakeTailY_, snakeTailX_, '#');    
        }
        else{
            mvaddch(snakeTailY_, snakeTailX_, ' ');
        }

        if(checkCollidedSnakeFood(&game) && game.state_snake_.sizeSnake_ < MAX_SIZE_SNAKE){
            // adding a new segment at the end
            game.state_snake_.snakeY_[game.state_snake_.sizeSnake_] = snakeTailY_;
            game.state_snake_.snakeX_[game.state_snake_.sizeSnake_] = snakeTailX_;

            game.state_snake_.sizeSnake_++;

            game.food_pos_ = checkSpawnFoodSnakeBody(&game, &game.state_snake_);
            game.score_ += 10;
        }

        // screen refresh(for optimisation, only updated sections are refreshed)
        refresh();
    }
    endwin(); // reset ncurses settings; restore the terminal to its default state
    clear_screen();
    clear_buffer(); // clearing the buffer of any remaining user input
    gameover(&game); // display statistics before returning to the main menu
}

// display statistics before returning to the menu
void gameover(stateGame *game){
    printf("%sGame over!%s\n", RED, RESET_COLOR);
    printf("Your game results:\n");
    printf("1. Score: %s%d%s\n", GREEN, game->score_, RESET_COLOR);
    printf("2. Size snake: %s%d%s\n", GREEN, game->state_snake_.sizeSnake_, RESET_COLOR);

    if(game->state_snake_.sizeSnake_ == 1280){
        printf("How did you manage that? Well done!\n");
    }

    printf("Press any button to return to the main menu\n");
    getchar();
    clear_screen();
}

// initialisation of the game's starting state
void initGame(stateGame *game){
    // clearing the structure, setting all fields to zero 
    memset(game, 0, sizeof(stateGame));

    // initialization of the generator
    rngSeed(&game->r_, (uint32_t)time(NULL));

    setupTerminal();
    timeout(VALUETIMEOUT);

    initMap(&game->m_);

    game->user_action_dir_ = RIGHT;
    game->start_snake_pos_.startSnakeX_ = 15;
    game->start_snake_pos_.startSnakeY_ = 15;
    initSnake(&game->state_snake_, &game->start_snake_pos_);

    game->score_ = 0;
    game->gameover_ = false;
}

// checking whether the snake collides with anything
bool checkCollidedSnakeWall(stateGame *game){
    uint8_t headSnakeX = game->state_snake_.snakeX_[0];
    uint8_t headSnakeY = game->state_snake_.snakeY_[0];
    return game->m_.map_[headSnakeY][headSnakeX] == 1;
}

bool checkCollidedSnakeFood(stateGame *game){
    return game->state_snake_.snakeX_[0] == game->food_pos_.foodX_ && game->state_snake_.snakeY_[0] == game->food_pos_.foodY_;
}

bool checkCollidedSnakeHeadBody(stateSnake *snake){
    uint8_t headSnakeX = snake->snakeX_[0];
    uint8_t headSnakeY = snake->snakeY_[0];
    for(uint16_t i = 1; i < snake->sizeSnake_; i++){
        if(snake->snakeX_[i] == headSnakeX && snake->snakeY_[i] == headSnakeY){
            return true;
        }
    }
    return false;
}

foodPosition checkSpawnFoodSnakeBody(stateGame *game, stateSnake *snake){
    bool valid;
    foodPosition food;

    do{
        valid = true;

        food = spawnFood(&game->r_, MIN_Y, MAX_Y, MIN_X, MAX_X);

        for(uint16_t i = 0; i < game->state_snake_.sizeSnake_; i++){
            if(snake->snakeX_[i] == food.foodX_ && snake->snakeY_[i] == food.foodY_){
                valid = false;
                break;
            }
        }
    } while(!valid);

    return food;
}

// statistical output
void displayScore(stateGame *game){
    mvprintw(25, 0, "Score: %d\n", game->score_);
}

void displaySizeSnake(stateGame *game){
    mvprintw(26, 0, "Size snake: %d\n", game->state_snake_.sizeSnake_);
}