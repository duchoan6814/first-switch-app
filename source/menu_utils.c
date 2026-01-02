#include <stdio.h>
#include "menu_utils.h"
#include "style.h"

#include <switch.h>

void draw_menu(int activated_item)
{
    printf(HOME);
    printf(BOLD "==== Main Menu ====\n" RESET);

    printf("%s1. Tinh tong hai so%s\n", activated_item == 0 ? SELECTED_STYLE : UNSELECTED_STYLE, RESET);

    printf("%s2. Danh sach tai khoan%s\n", activated_item == 1 ? SELECTED_STYLE : UNSELECTED_STYLE, RESET);

    printf("%s3. Thoat ung dung%s\n", activated_item == 2 ? SELECTED_STYLE : UNSELECTED_STYLE, RESET);
}

void menu_handle_input(PadState *pad, int *activated_item, int *selected_item, int num_items)
{
    u64 kDown = padGetButtonsDown(pad);

    if (kDown & HidNpadButton_Down)
    {
        if (*activated_item < num_items - 1)
        {
            (*activated_item)++;
        }
        else
        {
            *activated_item = 0;
        }
    }
    else if (kDown & HidNpadButton_Up)
    {
        if (*activated_item > 0)
        {
            (*activated_item)--;
        }
        else
        {
            *activated_item = num_items - 1;
        }
    }

    if (kDown & HidNpadButton_A)
    {
        *selected_item = *activated_item;
    }
}