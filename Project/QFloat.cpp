#include "QFloat.h"
#include "QInt.h"
#include <math.h>

using namespace std;




Qfloat::Qfloat(string bin)
{
	int count = 0;
	for (int i = 3; i >= 0; i--)
	{
		for (int j = 31; j >= 0; j--)
		{
			if (bin[127 - count] == '1')
			{
				this->arr[i] = this->arr[i] | (1 << (31 - j));
			}
			count++;
		}
	}
}


std::string Qfloat::toBinString()
{
	string result;
	int count = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			if (((this->arr[i] & (1 << (31 - j))) >> (31 - j)) == 1)
			{
				result[count] = '1';
			}
			else result[count] = '0';
			count++;
		}
	}
	cout << result;
	return result;
}

int FindBitZero(std::string bin)
{
	for (int i = 15; i < 128; i++)
	{
		if (bin[i] == '0')
		{
			if (i = 127) return 127;
			for (int j = i + 1; j < 128; j++)
			{
				if (bin[j] == '1')
					break;
				else if (j == 127)
					return i - 1;
			}
		}
	}
}



std::string calBeforeComma(std::string bin_tmp)
{
	string result;
	for (int i = 0; i < bin_tmp.length(); i++)
	{
		if (bin_tmp[i] == '1')
		{
			result = AddNumberString(result, pow_2_n(bin_tmp.length() - i - 1));
		}
	}
	return result;
}

std::string FloatBinToDec(std::string bin)
{
	int res = 1;
	string tmp;
	int BitZero = FindBitZero(bin);
	int IndexNum = FindIndexNum(bin,res);
	tmp = addFloatingPoint(bin, IndexNum);
	tmp = addOneInStart(tmp, BitZero);
	string result;
	result=toDecString(bin, AfterComma(tmp), BeforeComma(tmp));
	return result;
}

int calIndexNum(std::string bin_temp)
{
	int tmp = 0;
	for (int i = 0; i < 15; i++)
	{
		if (bin_temp[i] == '1')
			tmp += pow(2, 14 - i);
	}
	return tmp;
}

std::string calAfterComma(std::string bin_tmp)
{
	string result;
	for (int i = 0; i < bin_tmp.length(); i++)
	{
		if (bin_tmp[i] == '1')
			result = AddNumberString(result, pow_2_n(-i));
	}
	return result;
}

int FindIndexNum(std::string bin, int& res)
{
	std::string tmp;
	int sign = 0;
	int count = 0;
	for (int i = 1; i < 16; i++)
	{
		tmp.push_back(bin[i]);
	}
	sign = calIndexNum(tmp);
	int result = sign - pow(2, 14) + 1;
	if (result > 112)
	{
		res = result - 112;
		return 112;
	}
	else return result;
}

std::string addFloatingPoint(std::string bin, int IndexNum)
{
	string tmp;
	for (int j = 16; j < 128; j++)
	{
		tmp.push_back(bin[j]);
	}
	tmp.push_back('0');
	if (IndexNum > 0)
	{
		for (int k = 112; k > IndexNum; k--)
		{
			tmp[k] = tmp[k - 1];
		}
		tmp[IndexNum] = '.';
	}
	else
	{
		for (int k = 112; k > 112 - abs(IndexNum); k--)
		{
			tmp[k] = tmp[k - 1];
		}
		tmp[111 - abs(IndexNum)] = '.';
	}
	return tmp;
}

std::string addOneInStart(std::string bin_tmp, int BitZero)
{
	string tmp;
	for (int k = 0; k <= BitZero - 15; k++)
	{
		tmp.push_back(bin_tmp[k]);
	}
	tmp.push_back('0');
	for (int j = tmp.length(); j > 0; j--)
	{
		tmp[j] = tmp[j - 1];
	}
	tmp[0] = '1';
	return tmp;
}

std::string BeforeComma(std::string bin_tmp)
{
	string tmp;
	for (int i = 0; i < bin_tmp.length(); i++)
	{
		if (bin_tmp[i] != '.')
		{
			tmp.push_back(bin_tmp[i]);
		}
		else break;
	}
	if (tmp.length() < 15)
	{
		for (int i = 0; i = 15 - tmp.length(); i++)
		{
			tmp.push_back('0');
			for (int j = tmp.length(); j > 0; j--)
			{
				tmp[j] = tmp[j - 1];
			}
			tmp[0] = '0';
		}
	}
	string result = calBeforeComma(tmp);
	return result;
}


std::string AfterComma(std::string bin_tmp)
{
	int pivot = 0;
	string tmp;
	for (int i = bin_tmp.length(); i >= 0; i--)
	{
		if (bin_tmp[i] == '.')
		{
			pivot = i;
			break;
		}
	}
	for (int i = pivot; i < bin_tmp.length(); i++)
	{
		tmp.push_back(bin_tmp[i]);
	}
	return calAfterComma(tmp);
}

std::string toDecString(std::string bin, std::string afterComma, std::string BeforeComma)
{
	string tmp, result;
	if (bin[0] == '1')
		result.push_back('-');
	for (int i = 0; i < BeforeComma.length(); i++)
	{
		result.push_back(BeforeComma[i]);
	}
	for (int i = 1; i < tmp.length(); i++)
	{
		result.push_back(tmp[i]);
	}
	return result;
}





////////////////////////////////////////////////////////
std::string FloatDecToBin(std::string bin)
{
	string BeforeComma, AfterComma, tmp;
	BeforeComma = CutBefore(bin);
	AfterComma = CutAfter(bin);
	return BeforeComma;
}



std::string CutBefore(std::string bin)
{
	string tmp;
	for (int i = 0; i < bin.length(); i++)
	{
		if (bin[i] != '.')
		{
			tmp.push_back(bin[i]);
		}
		else break;
	}
	return tmp;
}

std::string CutAfter(std::string bin)
{
	string tmp;
	for (int i = 0; i < bin.length(); i++)
	{
		if (bin[i] == '.')
		{
			tmp.push_back(bin[i]);
		}
	}
	return tmp;
}

std::string ConvertBefore(std::string before)
{
	return BinToDec(before);
}
std::string ConvertAfter(std::string after)
{

}
