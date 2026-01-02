#include <stdio.h>
#include "menu_utils.hpp"
#include "style.hpp"

#include <switch.h>

namespace HoanDev
{
    Menu::Menu(const std::vector<std::string> &options)
        : options(options), activatedItem(0)
    {
    }

    void Menu::draw()
    {
        printf(HOME CLR_SCR);
        printf(BOLD "==== Main Menu ====\n" RESET);

        printf("%s1. Tinh tong hai so%s\n", activatedItem == 0 ? SELECTED_STYLE : UNSELECTED_STYLE, RESET);

        printf("%s2. Danh sach tai khoan%s\n", activatedItem == 1 ? SELECTED_STYLE : UNSELECTED_STYLE, RESET);

        printf("%s3. Thoat ung dung%s\n", activatedItem == 2 ? SELECTED_STYLE : UNSELECTED_STYLE, RESET);
    }

    void Menu::moveUp()
    {
        if (activatedItem > 0)
        {
            activatedItem--;
        }
        else
        {
            activatedItem = options.size() - 1;
        }
    }

    void Menu::moveDown()
    {
        if (activatedItem < options.size() - 1)
        {
            activatedItem++;
        }
        else
        {
            activatedItem = 0;
        }
    }

    size_t Menu::getActivatedItem()
    {
        return static_cast<size_t>(activatedItem);
    }

    void Menu::listenInput(PadState *pad, int &selected_item)
    {
        u64 kDown = padGetButtonsDown(pad);

        if (kDown & HidNpadButton_Down)
        {
            Menu::moveDown();
        }
        else if (kDown & HidNpadButton_Up)
        {
            Menu::moveUp();
        }

        if (kDown & HidNpadButton_A)
        {

            padUpdate(pad);
            selected_item = static_cast<int>(activatedItem);
        }
    }
}
