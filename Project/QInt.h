#pragma once
#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <vector>
#include <stdint.h>
#include <algorithm>

using namespace std;

#define _BIT_UINT32_    32 //Kiểu __int32 gồm có 32 bit.
#define _DEFAULT_SIZE   16  //Kích thước byte mặc định của kiểu QInt theo yêu cầu (16 byte)

class QInt
{
public:
	// Constructor
	QInt() = default;
	// Construct from string contain 128 bit
	QInt(std::string bin);

	// Destructor
	~QInt() = default;

	// Binary operators
	friend QInt operator+(QInt a, QInt b);
	friend QInt operator-(QInt a, QInt b);
	friend QInt operator*(QInt a, QInt b);
	friend QInt operator/(QInt a, QInt b);

	friend QInt operator|(QInt a, QInt b);
	friend QInt operator&(QInt a, QInt b);
	friend QInt operator^(QInt a, QInt b);

	QInt operator~();

	QInt& operator=(const QInt& x);

	friend bool operator==(QInt& a, QInt& b);
	friend bool operator!=(QInt& a, QInt& b);
	friend bool operator>(QInt& a, QInt& b);
	friend bool operator<(QInt& a, QInt& b);
	friend bool operator<=(QInt& a, QInt& b);
	friend bool operator>=(QInt& a, QInt& b);

	QInt operator<<(int x);
	QInt operator>>(int x);

	// Roll right (left) x bit
	QInt ror(int x);
	QInt rol(int x);

	// Get 128 bit into string
	std::string toBinString();

private:
	int arr[4] = { 0 };
};

// Decimal Integer to QInt
void ScanQInt(QInt& x);

// Print Decimal Integer from QInt
void PrintQInt(QInt x);

// Add 0 at head until bin.size() == bitNum
void fillBinWithZero(std::string& bin, int bitNum);

// Add 0 at head until obj.size() == size
std::string fill(std::string obj, int size);

// Summation 2 Two's Complement 128 bit
std::string add(std::string a, std::string b);

// Get One's Complement 128 bit from bit string
std::string com1(std::string obj);

// Get Two's Complement 128 bit from bit string
std::string com2(std::string obj);

// Subtraction 2 Two's Complement 128 bit
std::string minu(std::string a, std::string b);

// Multiplication 2 Two's Complement 128 bit
std::string multi(std::string a, std::string b);

// Is a larger than b? Comparion Two's Complement 128 bit
bool large(std::string a, std::string b);

// Is a smaller than b? Comparion Two's Complement 128 bit
bool small(std::string a, std::string b);

// Division 2 Two's Complement 128 bit
std::string divi(std::string a, std::string b);

// Two's Complement 128 bit Shift Left num bits
std::string shiftLeft(std::string obj, int num);

// Two's Complement 128 bit Shift Right num bits
std::string shiftRight(std::string obj, int num);

// Two's Complement 128 bit Roll Right num bits
std::string strRor(std::string obj, int num);

// Two's Complement 128 bit Roll Left num bits
std::string strRol(std::string obj, int num);

// Subtraction 2 Decimal Integer
std::string SubNumberString(std::string a, std::string b);

// Summation 2 Decimal Integer
std::string AddNumberString(std::string a, std::string b);

// Division Decimal Integer by 2
std::string DivBy2(std::string src);

// decimal string to binary string
std::string DecToBin(std::string dec);

//binary string to decimal string
std::string BinToDec(std::string bin);

// Remove all "0" from head of Two's Complement 128 bit
std::string clean(std::string obj);

// Get Hexadecimal from Binary 4 bit
std::string GetHexFromBin(std::string bin);

// Get Hexadecimal from Binary 128 bit
std::string BinToHex(std::string bin);

// Get Binary 4 bit from Hexadecimal
std::string GetBinFromHex(std::string hex);

// Get Binary 128 bit from Hexadecimal
std::string HexToBin(std::string hex);

// Get Two's Complement Hexadecimal 32 digits from Decimal Integer
std::string DecToHex(std::string bin);

// Get Decimal Integer from Two's Complement Hexadecimal 32 digits
std::string HexToDec(std::string hex);

// Get 2 pow n with any n in Z
std::string pow_2_n(int n);