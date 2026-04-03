#include "utils.h"

#include <stdio.h>

// error messages
void msg_input_error(void){
    printf("%sPlease enter a valid value!%s\n", RED, RESET_COLOR);
} 

// messages before entering values
void msg_selection(void){
    printf("Select an option: ");
}

// checking numbers
bool check_number_i(int *x){
    if(scanf("%d", x) != 1){
        while(getchar() != '\n');
        return false;
    }
    return true;
}

// other
void clear_screen(void){
    printf("\033[2J\033[H");
}

void clear_buffer(void){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}