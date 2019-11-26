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

std::string calBeforeComma(std::string bin_tmp);

float calAfterComma(std::string bin_tmp);

int FindBitZero(std::string bin);

int FindIndexNum(std::string bin);

std::string addFloatingPoint(std::string bin, int IndexNum);

std::string addOneInStart(std::string bin_tmp, int BitZero);

std::string BeforeComma(std::string bin_tmp);

float AfterComma(std::string bin_tmp);

std::string toDecString(std::string bin, float afterComma, std::string BeforeComma);