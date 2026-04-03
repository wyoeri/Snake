#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>

// text colors 
#define GREEN "\033[32m"
#define RED "\033[31m"

// reset changes
#define RESET_COLOR "\033[0m"
#define RESET_TEXT "\033[0m"

// text formatting
#define BOLD_TEXT "\033[1m"

// error messages
void msg_input_error(void);

// messages before entering values
void msg_selection(void);

// checking numbers
bool check_number_i(int *x);

// other
void clear_screen(void);
void clear_buffer(void);

#endif