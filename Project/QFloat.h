#pragma once
#include <iostream>
#include <string>
using namespace std;

class Qfloat
{
public:
	Qfloat() = default;
	Qfloat(std::string bin);
	~Qfloat() = default;
	std::string toBinString();
private:
	int arr[4] = { 0 };
};

std::string FloatBinToDec(std::string bin);
std::string FloatDecToBin(std::string bin);


///////////////////////////////////////////////////
std::string calBeforeComma(std::string bin_tmp);

std::string calAfterComma(std::string bin_tmp);

int FindBitZero(std::string bin);

int FindIndexNum(std::string bin, int &res);

std::string addFloatingPoint(std::string bin, int IndexNum);

std::string addOneInStart(std::string bin_tmp, int BitZero);

std::string BeforeComma(std::string bin_tmp);

std::string AfterComma(std::string bin_tmp);

std::string toDecString(std::string bin, std::string afterComma, std::string BeforeComma);


////////////////////////////////////////////////////
std::string CutBefore(std::string bin);

std::string CutAfter(std::string bin);

std::string ConvertBefore(std::string before);

std::string ConvertAfter(std::string after);