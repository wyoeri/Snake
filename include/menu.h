#ifndef MENU_H
#define MENU_H

typedef void(*display_menu_text_fun)(void); 
typedef void(*select_menu_items_fun)(int);

// menu cycle
void run_menu(display_menu_text_fun display_menu_text, select_menu_items_fun select_menu_items);

// processes user input in the menu
void choice_menu(int *choice, display_menu_text_fun display_menu_text);

// main menu
void main_menu(void);
void output_main_menu(void);
void choice_main_menu(int choice);

// help menu
void help_menu(void);
void output_help_menu(void);
void choice_help_menu(int choice);

#endif