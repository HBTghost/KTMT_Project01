#pragma once

#include "Qfloat.h"
#include "QInt.h"

#include <sstream>

class Console
{
public:

    void run();

private:
    bool modeQInt;

	//chạy chương trình chế độ QInt
    void runQIntMode();
	
	//chạy chương trình chế độ QFloat
    void runQFloatMode();

	//Yêu cầu chuyển đổi hoặc tính toán
    int QIntMenu();

	//chuyển đổi base
    void QIntConverter();

	//tính toán số học
    void QIntArithmetic();

	//yêu cầu đổi bin to dec hay dec to bin
    int QFloatMenu();

	//xử lý yêu cầu của người dùng, tính toán kết quả
    std::string executeCommandLine(std::vector<string> &tokens);

    
};



