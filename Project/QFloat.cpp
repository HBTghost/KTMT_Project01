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

std::string FloatBinToDec(std::string bin)
{
<<<<<<< HEAD
	int res = 0;
	string tmp;
	string result;
	int BitZero = FindBitZero(bin);
	int IndexNum = FindIndexNum(bin, res);
	string res_ = pow_2_n(res);
	if (SpecialCase(bin, IndexNum, res + IndexNum))
	{
		return "";
	}
	else
	{
		tmp = addFloatingPoint(bin, IndexNum);
		tmp = addOneInStart(tmp, BitZero);
		result = MultiplyNumberString((toDecString(bin, AfterComma(tmp), BeforeComma(tmp))), res_);
		if (result[(result.length()-1)] == '.')
			result.push_back('0');
	}
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
	string result = { '0' };
	for (int i = 0; i < bin_tmp.length(); i++)
	{
		if (bin_tmp[i] == '1')
			result = AddNumberFloatString(result, pow_2_n(-i - 1));
	}
	return result;
}

int FindIndexNum(std::string bin, int& res)
{
	int k = 0;
	for (int i = 1; i <= 15; i++)
	{
		if (bin[i] == '0')
			k++;
	}
	if (k == 15)
	{
		return 1;
	}
	else
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
}

int CharToIntNum(char n)
{
	int tmp = int(n);
	switch (tmp)
	{
		case 48:
		return 0;
		case 49:
		return 1;
		case 50:
		return 2;
		case 51:
		return 3;
		case 52:
		return 4;
		case 53:
		return 5;
		case 54:
		return 6;
		case 55:
		return 7;
		case 56:
		return 8;
		case 57:
		return 9;
	}
}
char IntToCharNum(int n)
{
	switch (n)
	{
		case 0:
		return 48;
		case 1:
		return 49;
		case 2:
		return 50;
		case 3:
		return 51;
		case 4:
		return 52;
		case 5:
		return 53;
		case 6:
		return 54;
		case 7:
		return 55;
		case 8:
		return 56;
		case 9:
		return 57;
	}
}

std::string AddNumberFloatString(std::string a, std::string b)
{
	string tmp1;
	int res = 0;
	if (a.length() >= b.length())
	{
		for (int i = 0; i < a.length(); i++)
		{
			tmp1.push_back('0');
		}
		for (int i = a.length() - 1; i > b.length() - 1; i--)
		{
			tmp1[i] = a[i];
		}
		tmp1[1] = '.';
		for (int i = b.length() - 1; i > 1; i--)
		{
			int tmp = CharToIntNum(a[i]) + CharToIntNum(b[i]);
			if (tmp + res >= 10)
			{
				tmp1[i] = (IntToCharNum((tmp + res) % 10));
				res = tmp / 10;
			}
			else
			{
				tmp1[i] = IntToCharNum(tmp + res);
				res = 0;
			}
		}
	}
	else
	{
		for (int i = 0; i < b.length(); i++)
		{
			tmp1.push_back('0');
		}
		for (int i = b.length() - 1; i > a.length() - 1; i--)
		{
			tmp1[i] = b[i];
		}
		tmp1[1] = '.';
		for (int i = a.length() - 1; i > 1; i--)
		{
			int tmp = CharToIntNum(a[i]) + CharToIntNum(b[i]);
			if (tmp + res >= 10)
			{
				tmp1[i] = (IntToCharNum((tmp + res) % 10));
				res = tmp / 10;
			}
			else
			{
				tmp1[i] = IntToCharNum(tmp + res);
				res = 0;
			}
		}
	}
	return tmp1;
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
=======
	while (bin.size() < 128) {
		bin += "0";
>>>>>>> 64f8f1e205d18b02f8efc3a4572e22a548a441af
	}
	std::string sign = bin[0] > '0' ? "-" : "";
	std::string ex = bin.substr(1, 15);
	std::string val = bin.substr(16);

	if (ex.find_first_of('0') == std::string::npos) {
		if (val.find_first_of('1') == std::string::npos) {
			return "infinity";
		}
		else {
			return "NaN";
		}
	}

	int expo = std::stoi(BinToDec(bin.substr(1, 15))) - std::stoi(pow_2_n(14)) + 1;
	expo -= val.size();
	if (ex.find_first_of('1') == std::string::npos) {
		if (val.find_first_of('1') == std::string::npos) {
			return "0";
		}
		val.insert(0, "0");
		expo++;
	}
	else {
		val.insert(0, "1");
	}
	return sign + MultiplyNumberString(BinToDec(val), pow_2_n(expo));
}



////////////////////////////////////////////////////////
std::string FloatDecToBin(std::string bin)
{
	string BeforeComma, AfterComma, tmp, Index, sign;
	int IndexN;
	if (SpecialCaseDecToBin(bin))
	{
		return "\nEnd";
	}
	else
	{
		BeforeComma = ConvertBefore(CutBefore(bin));
		AfterComma = ConvertAfter(CutAfter(bin));
		tmp = Standardized(BeforeComma, AfterComma, IndexN);
		Index = IndexNum(IndexN);
		sign = Sign(bin);
		return toBinString(sign, Index, tmp);
	}
}

bool SpecialCaseDecToBin(std::string bin)
{
	if (bin[0] == '0')
	{
		cout << "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
		return true;
	}
	return false;
}

std::string CutBefore(std::string bin)
{
	if (bin[0] == '-')
	{
		string tmp;
		for (int i = 1; i < bin.length(); i++)
		{
			if (bin[i] != '.')
			{
				tmp.push_back(bin[i]);
			}
			else break;
		}
		return tmp;
	}
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
	tmp.push_back('0');
	tmp.push_back('.');
	for (int i = 0; i < bin.length(); i++)
	{
		if (bin[i] == '.')
		{
			for (int j = i + 1; j < bin.length(); j++)
			{
				tmp.push_back(bin[j]);
			}
			break;
		}
	}
	return tmp;
}

std::string ConvertBefore(std::string before)
{
	string tmp, result;
	while (before != "") 
	{
		tmp.insert(tmp.begin(), ((before[before.size() - 1] - '0') % 2) + '0');
		before = DivBy2(before);
	}
	for (int i = 0; i < tmp.length(); i++)
	{
		if (tmp[i] == '1')
		{
			for (int j = i; j < tmp.length(); j++)
			{
				result.push_back(tmp[j]);
			}
			break;
		}
	}
	return result;
}

std::string cleanFloat(std::string num) {
	int lzero = num.find_first_not_of('0');
	int rzero = num.find_last_not_of('0');
	int dot = num.find_first_not_of('.');

	num.erase(rzero + 1, num.size());
	if (lzero < dot - 1) {
		num = clean(num);
	}

	return num;
}

std::string MultiplyNumberString(std::string a, std::string b) {

	std::string buf = "";

	if (a[0] == '-' || b[0] == '-') {
		if (a[0] != b[0]) {
			buf = '-';
		}
		if (a[0] == '-') {
			a.erase(a.begin());
		}
		if (b[0] == '-') {
			b.erase(b.begin());
		}
	}

	int own{ 0 };
	bool as = (a.find_first_of('.') != std::string::npos);
	bool bs = (b.find_first_of('.') != std::string::npos);

	if (as) {
		a = cleanFloat(a);
		int dot = a.find_first_of(".");
		own += (a.size() - dot - 1);
		a.erase(dot, 1);
		a.erase(0, a.find_first_not_of('0'));
	}
	if (bs) {
		b = cleanFloat(b);
		int dot = b.find_first_of(".");
		own += (b.size() - dot - 1);
		b.erase(dot, 1);
		b.erase(0, b.find_first_not_of('0'));
	}

	std::string Result = "0";
	std::string TempStr;
	int Temp = 0;

	for (int i = 0; i < b.size(); i++) {
		for (int j = a.size() - 1; j > -1; j--) {
			Temp = Temp + (a[j] - '0') * (b[b.size() - i - 1] - '0');
			TempStr.push_back((Temp % 10) + '0');
			Temp = Temp / 10;
		}
		if (Temp != 0) { //Nếu vẫn còn Temp.
			TempStr.push_back(Temp + '0');
			Temp = 0;
		}

		//Đảo chuỗi.
		reverse(TempStr.begin(), TempStr.end());

		//Thêm các số 0 cần thiết vào sau.
		for (int j = 0; j < i; j++) {
			TempStr.push_back('0');
		}

		//Cộng Result và Temp.
		Result = AddNumberString(Result, TempStr);
		TempStr.clear(); //Dọn chuỗi tạm để dùng cho các bước tiếp theo.
	}

	if (own >= Result.size()) {
		Result = fill(Result, own);
		Result.insert(0, "0.");
	}
	else {
		Result.insert(Result.size() - own, ".");
	}

	// while (Result[Result.size()-1] == '0' && own > 0) {
	// 	--own;
	// 	Result.pop_back();
	// }

	// if (own > 0) {
	// 	buf += "0.";
	// 	while (--own > 0) {
	// 		buf += "0";
	// 	}
	// 	return buf + Result;
	// }

	return buf + Result;
}

std::string ConvertAfter(std::string after)
{
	string result;
	string tmp = after;
	for (int i = 0; i < 112; i++)
	{
		tmp = MultiplyNumberString(tmp, "2");
		if (tmp[0] == '1')
		{
			result.push_back('1');
			tmp[0] = '0';
		}
		else
		{
			result.push_back('0');
		}
	}
	return result;
}

std::string Standardized(std::string before, std::string after, int& IndexNum)
{
	string result, tmp1, tmp2;
	for (int i = 0; i < before.length(); i++)
	{
		tmp1.push_back(before[i]);
	}
	tmp1.push_back('.');
	for (int i = 0; i < after.length(); i++)
	{
		tmp1.push_back(after[i]);
	}
	int tmp = before.length();
	if (before[0] == NULL)
	{
		tmp2.push_back('0');
		for (int i = 0; i < 113; i++)
		{
			tmp2.push_back(tmp1[i]);
		}
		for (int i = 0; i < 113; i++)
		{
			if (tmp2[i] == '.')
			{
				for (int j = i + 1; i < tmp2.length(); j++)
				{
					if (tmp2[j] == '1')
					{
						IndexNum = -(j - i);
						break;
					}
				}
				break;
			}
		}
	}
	else
	{
		for (int i = 0; i < 113; i++)
		{
			tmp2.push_back(tmp1[i]);
		}
		for (int i = 0; i < 113; i++)
		{
			if (tmp2[i] == '.')
			{
				IndexNum = i - 1;
				break;
			}
		}
	}
	for (int i = 0; i < 113; i++)
	{
		if (tmp2[i] == '1')
		{
			for (int j = i + 1; j < 113 - i; j++)
			{
				if (tmp2[j] != '.')
				{
					result.push_back(tmp2[j]);
				}
			}
			break;
		}
	}
	return result;
}

std::string IndexNum(int IndexNum)
{
	string result;
	int tmp = pow(2, 14) + IndexNum - 1;
	int i = 0;
	int binaryNum[15];
	while (tmp > 0)
	{
		binaryNum[i] = tmp % 2;
		tmp = tmp / 2;
		i++;
	}
	for (int k = 14; k >= 0; k--)
	{
		if (binaryNum[k] == 1)
		{
			result.push_back('1');
		}
		else
			result.push_back('0');

	}
	return result;
}

std::string Sign(std::string bin)
{
	if (bin[0] == '-')
		return "1";
	else return "0";
}

std::string toBinString(std::string sign, std::string index, std::string significand)
{
	string result;
	result.push_back(sign[0]);
	for (int i = 0; i < 15; i++)
	{
		result.push_back(index[i]);
	}
	for (int i = 0; i < significand.length(); i++)
	{
		result.push_back(significand[i]);
	}
	if (result.length() < 128)
	{
		for (int i = result.length(); i < 128; i++)
		{
			result.push_back('0');
		}
	}
	return result;
}

std::string toDec(std::string bin) {
	while (bin.size() < 128) {
		bin += "0";
	}
	std::string sign = bin[0] > '0' ? "-" : "";
	std::string ex = bin.substr(1, 15);
	std::string val = bin.substr(16);

	if (ex.find_first_of('0') == std::string::npos) {
		if (val.find_first_of('1') == std::string::npos) {
			return "infinity";
		}
		else {
			return "NaN";
		}
	}

	int expo = std::stoi(BinToDec(bin.substr(1, 15))) - std::stoi(pow_2_n(14)) + 1;
	expo -= val.size();
	if (ex.find_first_of('1') == std::string::npos) {
		if (val.find_first_of('1') == std::string::npos) {
			return "0";
		}
		val.insert(0, "0");
		expo++;
	}
	else {
		val.insert(0, "1");
	}
	std::string res = cleanFloat(sign + MultiplyNumberString(BinToDec(val), pow_2_n(expo)));
	if (res[res.size()-1] == '.') {
		res += "0";
	}
	return res;
}

std::string toBin(std::string dec) {
	if (dec == "0") {
		return fill("0", 128);
	}
	else if (dec == "infinity") {
		return "0111111111111111" + fill("0", 112);
	}
	else if (dec == "NaN") {
		return "01111111111111111" + fill("0", 111);
	}

	std::string sign;
	if (dec[0] == '-') {
		sign = "1";
		dec.erase(dec.begin());
	}
	else {
		sign = "0";
	}

	std::string lg, sm;
	if (dec.find_first_of('.') == std::string::npos) {
		lg = dec;
		sm = "1.0";
	}
	else {
		lg = dec.substr(0, dec.find_first_of('.'));
		sm = "0" + dec.substr(dec.find_first_of('.'));
	}
	std::string val = clean(DecToBin(lg));

	int ex = val.size()-1;
	int max = std::stoi(pow_2_n(14)) + 110;

	for (std::size_t i = 0; i < max && sm != "1.0"; ++i) {
		sm[0] = '0';
		sm = MultiplyNumberString(sm, "2");
		val.push_back(sm[0]);
	}

	if (lg == "0") {
		int one = val.find_first_of('1');
		if (one != std::string::npos) {
			ex -= one;
			if (abs(ex) <= max - 112) {
				val = val.substr(one);
			}
			else if (abs(ex) <= max ) {
				val = val.substr(max-112);
				ex = 111-max;
			}
		}
		else {
			return fill("0", 128);
		}
	}

	ex += std::stoi(pow_2_n(14))-1;
	if (ex >= std::stoi(pow_2_n(15))-1) {
		return "infinity";
	}
	std::string expo = DecToBin(std::to_string(ex));

	val.erase(val.begin());
	while (val.size() < 112) {
		val += "0";
	}
	return sign + expo.substr(expo.size() -15, expo.size()) +"."+ val.substr(0, 112);
}
