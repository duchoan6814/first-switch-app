#include <stdio.h>
#include <stdlib.h>
#include "style.hpp"
#include "sum_utils.hpp"
#include <switch.h>

namespace HoanDev
{

    SumFeature::SumFeature() : step(0), num1(0), num2(0), result(0) {};

    void SumFeature::draw()
    {
        printf(HOME CLR_SCR);
        printf(BOLD "\x1b[1;1HTinh tong hai so:" RESET);

        if (step == 0)
        {
            printf("\x1b[3;1HNhan A de nhap so thu nhat:");
        }
        else if (step == 1)
        {
            printf("\x1b[3;1H\x1b[2KSo thu nhat:%s %d" RESET, BOLD OCEAN_BG, num1);
            printf("\x1b[5;1HNhan A de nhap so thu hai:");
        }
        else if (step == 2)
        {
            printf("\x1b[5;1H\x1b[2KSo thu hai:%s %d" RESET, BOLD OCEAN_BG, num2);
            printf("\x1b[7;1HNhan A de tinh tong:");
        }
        else if (step == 3)
        {
            printf("\x1b[7;1H\x1b[2KTong:%s %d" RESET, BOLD OCEAN_BG, result);
            printf("\x1b[9;1HNhan A de tinh lai hoac B de thoat:");
        }
    }

    bool SumFeature::getInputFormKeyboard(int *number)
    {
        Result rc;
        char out_string[256];
        SwkbdConfig kbd;

        rc = swkbdCreate(&kbd, 0);

        if (R_FAILED(rc))
        {
            printf("Failed to create software keyboard: 0x%x\n", rc);
            return false;
        }

        swkbdConfigSetHeaderText(&kbd, "Nhap so:");
        swkbdConfigSetStringLenMax(&kbd, 255);
        swkbdConfigSetType(&kbd, SwkbdType_NumPad);

        rc = swkbdShow(&kbd, out_string, sizeof(out_string));

        swkbdClose(&kbd);

        if (R_SUCCEEDED(rc))
        {
            *number = atoi(out_string);
            return true;
        }
        if (R_FAILED(rc))
        {
            printf("swkbdShow failed: 0x%x\n", rc);
            return false;
        }

        return false;
    }

    void SumFeature::handleInput(PadState *pad, int &selected_item)
    {

        u64 kDown = padGetButtonsDown(pad);

        if (kDown & HidNpadButton_B)
        {
            num1 = 0;
            num2 = 0;
            result = 0;
            step = 0;

            selected_item = -1;
        }

        if (kDown & HidNpadButton_A)
        {
            if (step == 0)
            {
                bool success = getInputFormKeyboard(&num1);
                if (!success)
                {
                    // TODO handle error
                    printf("Error getting input from keyboard 1\n");
                    return;
                }
                step = 1;
            }
            else if (step == 1)
            {
                bool success = getInputFormKeyboard(&num2);
                if (!success)
                {
                    // TODO handle error
                    printf("Error getting input from keyboard 2\n");
                    return;
                }
                step = 2;
            }
            else if (step == 2)
            {
                // Calculate sum
                result = num1 + num2;

                step = 3;
            }
            else if (step == 3)
            {
                // Reset to step 0
                step = 0;
                num1 = 0;
                num2 = 0;
                result = 0;
            }
        }
    }

    void SumFeature::setNum1(int number)
    {
        num1 = number;
    }
    void SumFeature::setNum2(int number)
    {
        num2 = number;
    }
    int SumFeature::getStep() const
    {
        return step;
    }
    int SumFeature::getNum1() const
    {
        return num1;
    }
    int SumFeature::getNum2() const
    {
        return num2;
    }
    int SumFeature::getResult() const
    {
        return result;
    }
}
