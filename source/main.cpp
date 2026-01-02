#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory>

#include <switch.h>
#include "menu_utils.hpp"
#include "sum_utils.hpp"
#include "style.hpp"

int main(int argc, char *argv[])
{
    SwkbdConfig kbd;
    Result rc;

    int selected_item = -1;

    std::unique_ptr<HoanDev::Menu> mainMenu = std::make_unique<HoanDev::Menu>(std::vector<std::string>{"Tinh tong hai so", "Danh sach tai khoan", "Thoat ung dung"});
    std::unique_ptr<HoanDev::SumFeature> sumFeature;

    rc = swkbdCreate(&kbd, 0);

    if (R_FAILED(rc))
    {
        printf("Failed to create software keyboard: 0x%x\n", rc);
    }

    consoleInit(NULL);

    padConfigureInput(1, HidNpadStyleSet_NpadStandard);

    PadState pad;
    padInitializeDefault(&pad);

    while (appletMainLoop())
    {
        if (selected_item == 2)
            break;

        padUpdate(&pad);

        u64 kDown = padGetButtonsDown(&pad);

        if (kDown & HidNpadButton_Plus)
            break;

        if (selected_item == -1 && mainMenu)
        {
            mainMenu->draw();
            mainMenu->listenInput(&pad, selected_item);
        }
        else if (selected_item == -1 && !mainMenu)
        {
            mainMenu = std::make_unique<HoanDev::Menu>(std::vector<std::string>{"Tinh tong hai so", "Danh sach tai khoan", "Thoat ung dung"});
        }
        else if (selected_item != -1 && mainMenu)
        {
            mainMenu.reset();
        }

        if (selected_item == 0 && !sumFeature)
        {
            sumFeature = std::make_unique<HoanDev::SumFeature>();
        }
        else if (selected_item == 0 && sumFeature)
        {
            sumFeature->draw();
            sumFeature->handleInput(&pad, selected_item);
        }
        else if (selected_item != 0 && sumFeature)
        {
            sumFeature.reset();
        }

        consoleUpdate(NULL);
    }

    consoleExit(NULL);
    return 0;
}