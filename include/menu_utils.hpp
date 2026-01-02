#ifndef MENU_UTILS_H
#define MENU_UTILS_H

#include <vector>
#include <string>
#include <switch.h>

namespace HoanDev
{
    class Menu
    {
    private:
        std::vector<std::string> options;
        size_t activatedItem;
        PadState pad;

    public:
        Menu(const std::vector<std::string> &menu_options);
        void draw();
        void moveUp();
        void moveDown();
        size_t getActivatedItem();
        void listenInput(PadState *pad, int &selected_item);
    };
}

#endif