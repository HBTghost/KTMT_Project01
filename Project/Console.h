#pragma once

#include "QFloat.h"
#include "QInt.h"

#include <sstream>

class Console
{
public:

    void run();

private:
    bool modeQInt;

    void runQIntMode();

    void runQFloatMode();

    int QIntMenu();

    void QIntConverter();

    void QIntArithmetic();

    int QFloatMenu();

    std::string executeCommandLine(std::vector<string> &tokens);

    
};



