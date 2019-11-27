#pragma once
#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <vector>
#include <stdint.h>

using namespace std;

#define _BIT_UINT32_    32 //Kiểu __int32 gồm có 32 bit.
#define _DEFAULT_SIZE   16  //Kích thước byte mặc định của kiểu QInt theo yêu cầu (16 byte)

class QInt
{
public:
	QInt() = default;
	QInt(std::string bin);
	~QInt() = default;

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

	QInt ror(int x);
	QInt rol(int x);

	std::string toBinString();

private:
	int arr[4] = { 0 };
};

void scan(QInt& x);

void print(QInt x);

void fillBinWithZero(std::string& bin, int bitNum);

std::string fill(std::string obj, int size);

std::string add(std::string a, std::string b);

std::string com1(std::string obj);

std::string com2(std::string obj);

std::string minu(std::string a, std::string b);

std::string multi(std::string a, std::string b);

bool large(std::string a, std::string b);

bool small(std::string a, std::string b);

std::string divi(std::string a, std::string b);

std::string shiftLeft(std::string obj, int num);

std::string shiftRight(std::string obj, int num);

std::string strRor(std::string obj, int num);

std::string strRol(std::string obj, int num);

std::string SubNumberString(std::string a, std::string b);

std::string AddNumberString(std::string a, std::string b);

std::string DivBy2(std::string src);

int digit(int by);

string divide(string number, int divisor);

// decimal string to binary string
std::string DecToBin(std::string dec);

//binary string to decimal string
std::string BinToDec(std::string bin);

std::string clean(std::string obj);

std::string GetHexFromBin(std::string bin);

std::string BinToHex(std::string bin);

std::string GetBinFromHex(std::string hex);

std::string HexToBin(std::string hex);

std::string DecToHex(std::string bin);

std::string HexToDec(std::string hex);

std::string pow_2_n(int n);