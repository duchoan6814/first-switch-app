#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <switch.h>
#include "menu_utils.hpp"

bool getInputFormKeyboard(int *out_number);

bool getInputFormKeyboard(int *out_number)
{
    SwkbdConfig kbd;
    Result rc;
    char out_string[256];

    consoleInit(NULL);

    padConfigureInput(1, HidNpadStyleSet_NpadStandard);

    PadState pad;
    padInitializeDefault(&pad);

    rc = swkbdCreate(&kbd, 0);

    if (R_FAILED(rc))
    {
        printf("Failed to create software keyboard: 0x%x\n", rc);
    }

    if (R_SUCCEEDED(rc))
    {
        swkbdConfigSetHeaderText(&kbd, "Enter your name:");
        swkbdConfigSetStringLenMax(&kbd, 255);
        swkbdConfigSetType(&kbd, SwkbdType_NumPad);

        rc = swkbdShow(&kbd, out_string, sizeof(out_string));

        swkbdClose(&kbd);

        if (R_SUCCEEDED(rc))
        {
            *out_number = atoi(out_string);
            return true;
        }
        if (R_FAILED(rc))
        {
            printf("Failed to show software keyboard: 0x%x\n", rc);
            return false;
        }
    }

    return false;
}

int main(int argc, char *argv[])
{
    // int a = 0;
    // int b = 0;
    // int step = 0;
    int activated_item = 0;
    int selected_item = -1;

    consoleInit(NULL);

    padConfigureInput(1, HidNpadStyleSet_NpadStandard);

    PadState pad;
    padInitializeDefault(&pad);

    // printf(
    //     CONSOLE_ESC(1; 1H)
    //         CONSOLE_ESC(1m) "Xin chao ban!, day la mot ung dung don gian tren Nintendo Switch.");
    // printf(
    //     CONSOLE_ESC(3; 1H) "Nhan A de mo ban phim va nhap so thu nhat: ");

    while (appletMainLoop())
    {
        if (selected_item == 2)
            break;

        padUpdate(&pad);

        u64 kDown = padGetButtonsDown(&pad);

        if (kDown & HidNpadButton_Plus)
            break;

        if (selected_item == -1)
        {
            draw_menu(activated_item);
            menu_handle_input(&pad, &activated_item, &selected_item, 3);
        }

        // if (kDown & HidNpadButton_A)
        // {
        //     if (step == 0)
        //     {
        //         if (getInputFormKeyboard(&a))
        //         {
        //             printf(
        //                 CONSOLE_ESC(3; 1H)
        //                     CONSOLE_ESC(2K)

        //                         "So thu nhat la: " CONSOLE_ESC(1; 37; 41m) "%d" CONSOLE_ESC(0m),
        //                 a);
        //             printf(
        //                 CONSOLE_ESC(5; 1H) "Nhan A de mo ban phim va nhap so thu hai: ");
        //             step = 1;
        //         }
        //     }
        //     else if (step == 1)
        //     {
        //         if (getInputFormKeyboard(&b))
        //         {
        //             printf(
        //                 CONSOLE_ESC(5; 1H)
        //                     CONSOLE_ESC(2K)

        //                         "So thu hai la: " CONSOLE_ESC(1; 37; 41m) "%d" CONSOLE_ESC(0m),
        //                 b);
        //             printf(
        //                 CONSOLE_ESC(7; 1H)
        //                     CONSOLE_ESC(2K) "Nhan A de tinh tong hai so.");
        //             step = 2;
        //         }
        //     }
        //     else if (step == 2)
        //     {
        //         int sum = a + b;
        //         printf(
        //             CONSOLE_ESC(7; 1H)
        //                 CONSOLE_ESC(2K)

        //                     CONSOLE_ESC(1; 32; 40m) "Tong cua %d va %d la: %d" CONSOLE_ESC(0m),
        //             a, b, sum);
        //         printf(
        //             CONSOLE_ESC(9; 1H) "Nhan A de nhap lai hai so.");

        //         step = 3;
        //     }
        //     else if (step == 3)
        //     {
        //         a = 0;
        //         b = 0;
        //         step = 0;
        //         printf(
        //             CONSOLE_ESC(3; 1H)
        //                 CONSOLE_ESC(0J));
        //         printf(
        //             CONSOLE_ESC(3; 1H) "Nhan A de mo ban phim va nhap so thu nhat: ");
        //     }
        // }

        consoleUpdate(NULL);
    }

    consoleExit(NULL);
    return 0;
}