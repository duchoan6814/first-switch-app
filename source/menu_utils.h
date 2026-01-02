#ifndef MENU_UTILS_H
#define MENU_UTILS_H

#include <switch.h>

void draw_menu(int activated_item);
void menu_handle_input(PadState *pad, int *activated_item, int *selected_item, int num_items);

#endif