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

bool SpecialCaseDecToBin(std::string bin);

std::string calAfterComma(std::string bin_tmp);

int FindBitZero(std::string bin);

int FindIndexNum(std::string bin, int& res);

int CharToIntNum(char n);

char IntToCharNum(int n);

std::string AddNumberFloatString(std::string a, std::string b);

std::string addFloatingPoint(std::string bin, int IndexNum);

std::string addOneInStart(std::string bin_tmp, int BitZero);

std::string BeforeComma(std::string bin_tmp);

std::string AfterComma(std::string bin_tmp);

std::string AfterCommaDec(std::string bin_tmp);

std::string toDecString(std::string bin, std::string afterComma, std::string BeforeComma);

bool SpecialCase(std::string bin, int IndexNum, int res);

bool Zero(std::string bin);
////////////////////////////////////////////////////
std::string CutBefore(std::string bin);

std::string CutAfter(std::string bin);

std::string ConvertBefore(std::string before);

std::string ConvertAfter(std::string after);

std::string cleanFloat(std::string num);

std::string MultiplyNumberString(std::string a, std::string b);

std::string Standardized(std::string before, std::string after, int& IndexNum);

std::string IndexNum(int IndexNum);

std::string Sign(std::string bin);

std::string toBinString(std::string sign, std::string index, std::string significand);

std::string toDec(std::string bin);
std::string toBin(std::string dec);