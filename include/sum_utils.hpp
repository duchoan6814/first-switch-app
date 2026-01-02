#ifndef SUM_UTILS_H
#define SUM_UTILS_H

#include <switch.h>

namespace HoanDev
{
    class SumFeature
    {
    private:
        int step;
        int num1;
        int num2;
        int result;
        static bool getInputFormKeyboard(int *number);

    public:
        SumFeature();
        void draw();
        void handleInput(PadState *pad, int &selected_item);
        void setNum1(int number);
        void setNum2(int number);
        int getStep() const;
        int getNum1() const;
        int getNum2() const;
        int getResult() const;
    };

}

#endif