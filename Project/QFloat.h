#pragma once
#include <iostream>
#include <string>
using namespace std;

class Qfloat
{
public:
    // Constructor
    Qfloat() = default;
    // Constructor from string contain 128 bit
    Qfloat(std::string bin);

    // Destructor
    ~Qfloat() = default;

    // Get 128 bit into string
    std::string toBinString();
private:
    int arr[4] = { 0 };
};

// Decimal Float to Qfloat
void ScanQfloat(Qfloat &x);

// Print Decimal Float from Qfloat
void PrintQfloat(Qfloat x);

// Clean 0 in float, like 00000.18407000 to 0.18407, or 031.0000 to 31.0
std::string cleanFloat(std::string num);

// Multiplication 2 Decimal Float
std::string MultiplyNumberString(std::string a, std::string b);

// Get Decimal Float from Binary 128 bit
std::string FloatBinToDec(std::string bin);

// Get Binary 128 bit from Decimal Float
std::string FloatDecToBin(std::string dec);