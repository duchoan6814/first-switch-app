#include <stdio.h>
#include "menu_utils.h"

#include <switch.h>

#define HOME "\x1b[1;1H"
#define SELECTED "\x1b[1;32;40m"
#define RESET "\x1b[0m"
#define BOLD "\x1b[1m"

void draw_menu(int activated_item)
{
    printf(HOME);
    printf(BOLD "==== Main Menu ====\n" RESET);

    if (activated_item == 0)
    {
        printf(SELECTED "1. Tinh tong hai so" RESET "\n");
    }
    else
    {
        printf("1. Tinh tong hai so\n");
    }

    if (activated_item == 1)
    {
        printf(SELECTED "2. Danh sach tai khoan" RESET "\n");
    }
    else
    {
        printf("2. Danh sach tai khoan\n");
    }

    if (activated_item == 2)
    {
        printf(SELECTED "3. Thoat ung dung" RESET "\n");
    }
    else
    {
        printf("3. Thoat ung dung\n");
    }
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