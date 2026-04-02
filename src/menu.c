#include "menu.h"

#include <stdio.h>
#include <stdbool.h>
#include "utils.h"
#include "version.h"
#include "game.h"

// menu cycle
void run_menu(display_menu_text_fun display_menu_text, select_menu_items_fun select_menu_items){
    int choice = 0;
    clear_screen();
    while(true){
        choice_menu(&choice, display_menu_text);

        if(choice == 0){clear_screen(); break;}

        select_menu_items(choice);
    }
}

// processes user input in the menu
void choice_menu(int *choice, display_menu_text_fun display_menu_text){
    while(true){
        display_menu_text();
        msg_selection();
        if(!check_number_i(choice)){
            clear_screen();
            msg_input_error();
            continue;
        }
        break;
    }
}

// main menu
void main_menu(void){
    run_menu(output_main_menu, choice_main_menu);
}

void output_main_menu(void){
    printf("%sSnake%s\n", BOLD_TEXT, RESET_TEXT);
    printf("1. Start\n");
    printf("2. Help\n");
    printf("0. Exit the game\n");
}

void choice_main_menu(int choice){
    switch(choice){
        case 1:{
            gameLoop();
            break;
        }
        case 2:{
            help_menu();
            break;
        }
        default:{
            msg_input_error();
        }
    }
}

// help menu
void help_menu(void){
    run_menu(output_help_menu, choice_help_menu);
}

void output_help_menu(void){
    printf("%sHelp%s\n", BOLD_TEXT, RESET_TEXT);
    printf("Description:\n");
    printf("%sClassic Snake game where you control a growing snake.\nEat food to increase your score and length,\nbut avoid walls and your own tail, or the game ends.%s\n", GREEN, RESET_COLOR);
    printf("Control:\n");
    printf("%sUse the WASD keys to control the game. Press Q or q to exit the game.%s\n", GREEN, RESET_COLOR);
    printf("Version:\n");
    printf("%s%s%s\n", GREEN, VERSION, RESET_COLOR);
    printf("Creator:\n");
    printf("%swyoeri%s\n", GREEN, RESET_COLOR);
    printf("More information:\n");
    printf("%shttps://github.com/wyoeri/Snake%s\n", GREEN, RESET_COLOR);
    printf("0. Go to the main menu\n");
}

void choice_help_menu(int choice){
    switch(choice){
        default:{
            msg_input_error();
        }
    }
}