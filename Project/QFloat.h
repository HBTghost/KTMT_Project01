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


bool SpecialCaseDecToBin(std::string bin);

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