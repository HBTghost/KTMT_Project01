#include "QInt.h"

// ============ //

QInt::QInt(string bin) {
	fillBinWithZero(bin, _DEFAULT_SIZE * 8);

	int count = 0;

	for (int i = 0; i < _DEFAULT_SIZE / 4; i++) {
		for (int j = 0; j < 32; j++) {
			if (bin[count++] == '1') {
				this->arr[i] = this->arr[i] | (1 << (31 - j));
			}
		}
	}
}

QInt operator+(QInt a, QInt b) {
	std::string x = a.toBinString();
	std::string y = b.toBinString();

	return QInt(add(x, y));
}
QInt operator-(QInt a, QInt b) {
	std::string x = a.toBinString();
	std::string y = b.toBinString();

	return QInt(minu(x, y));
}
QInt operator*(QInt a, QInt b) {
	std::string x = a.toBinString();
	std::string y = b.toBinString();

	return QInt(multi(x, y));
}
QInt operator/(QInt a, QInt b) {
	std::string x = a.toBinString();
	std::string y = b.toBinString();

	return QInt(divi(x, y));
}

QInt operator|(QInt a, QInt b) {
	QInt result;

	for (int i = 0; i < _DEFAULT_SIZE / 4; i++) {
		result.arr[i] = a.arr[i] | b.arr[i];
	}

	return result;
}
QInt operator&(QInt a, QInt b) {
	QInt result;

	for (int i = 0; i < _DEFAULT_SIZE / 4; i++) {
		result.arr[i] = a.arr[i] & b.arr[i];
	}

	return result;
}
QInt operator^(QInt a, QInt b) {
	QInt result;

	for (int i = 0; i < _DEFAULT_SIZE / 4; i++) {
		result.arr[i] = a.arr[i] ^ b.arr[i];
	}

	return result;
}

QInt QInt::operator~() {
	QInt result;

	for (int i = 0; i < _DEFAULT_SIZE / 4; i++) {
		result.arr[i] = ~this->arr[i];
	}

	return result;
}

QInt& QInt::operator=(const QInt& x) {
	for (int i = 0; i < _DEFAULT_SIZE / 4; i++) {
		this->arr[i] = x.arr[i];
	}
	return *this;
}

bool operator==(QInt& a, QInt& b) {
	for (int i = 0; i < _DEFAULT_SIZE / 4; i++) {
		if (a.arr[i] != b.arr[i]) {
			return false;
		}
	}
	return true;
}
bool operator!=(QInt& a, QInt& b) {
	return !(a == b);
}
bool operator<(QInt& a, QInt& b) {
	std::string x = a.toBinString();
	std::string y = b.toBinString();

	return small(x, y);
}
bool operator>(QInt& a, QInt& b) {
	std::string x = a.toBinString();
	std::string y = b.toBinString();

	return large(x, y);
}
bool operator<=(QInt& a, QInt& b) {
	return !(a > b);
}
bool operator>=(QInt& a, QInt& b) {
	return !(a < b);
}

QInt QInt::operator<<(int x) {
	string a = this->toBinString();

	return QInt(shiftLeft(a, x));
}
QInt QInt::operator>>(int x) {
	string a = this->toBinString();

	return QInt(shiftRight(a, x));
}

QInt QInt::ror(int x) {
	string result;

	string temp = this->toBinString();

	result = strRor(temp, x);

	return QInt(result);
}
QInt QInt::rol(int x) {
	string result;

	string temp = this->toBinString();

	result = strRol(temp, x);

	return QInt(result);
}

std::string QInt::toBinString() {
	string result;

	for (int i = 0; i < _DEFAULT_SIZE / 4; i++) {
		for (int j = 0; j < 32; j++) {
			if ((this->arr[i] & (1 << (31 - j))) == (1 << (31 - j))) {
				result.push_back('1');
			}
			else {
				result.push_back('0');
			}
		}
	}

	return result;
}

// ============ //

void fillBinWithZero(std::string& bin, int bitNum) {
	for (int i = bin.length() + 1; i <= bitNum; i++) {
		bin.insert(0, "0");
	}
}

std::string SubNumberString(std::string a, std::string b) {
	int re = 0;
	bool neg = false;

	//Thêm các số 0 vào đầu mỗi chuỗi.
	if (a.size() > b.size()) {
		while (a.size() != b.size()) {
			b.insert(b.begin(), '0');
		}
	}
	else {
		while (a.size() != b.size()) {
			a.insert(a.begin(), '0');
		}
	}

	//Kiểm tra a hay b lớn hơn và chuyển a thành số lớn hơn.
	if (strcmp(a.c_str(), b.c_str()) < 0) {
		std::swap(a, b);
		neg = true; //a < b => a - b < 0
	}

	//Thực hiện phép trừ.
	for (std::size_t i = a.size() - 1; i > -1; i--) {
		if ((a[i] - re) < b[i]) {
			a[i] = (10 + a[i] - b[i] - re) + '0';
			re = 1;
		}
		else {
			a[i] = a[i] - b[i] - re + '0';
			re = 0;
		}
	}

	a.erase(0, a.find_first_not_of("0"));

	//Nếu vẫn còn dư (re != 0)
	if (neg == true) {
		a.insert(a.begin(), '-');
	}

	return a;
}

std::string AddNumberString(std::string a, std::string b) {
	if (a[0] == '-' && b[0] != '-') {
		a.erase(a.begin());
		a = SubNumberString(b, a);
	}
	else {
		if (b[0] == '-' && a[0] != '-') {
			b.erase(b.begin());
			a = SubNumberString(a, b);
		}
		else
		{
			int Temp = 0;
			bool Negative = false;

			if (a[0] == '-' && b[0] == '-') {
				Negative = true;
			}

			//Thêm các số 0 vào đầu mỗi chuỗi.
			if (a.size() > b.size()) {
				while (a.size() != b.size()) {
					b.insert(b.begin(), '0');
				}
			}
			else {
				while (a.size() != b.size()) {
					a.insert(a.begin(), '0');
				}
			}

			// Tiến hành cộng.
			for (int i = a.size() - 1; i > -1; i--) {
				Temp = Temp + a[i] + b[i] - 2 * '0';
				a[i] = (Temp % 10) + '0';
				Temp = Temp / 10;
			}

			//Nếu vẫn còn dư (Temp != 0)
			if (Temp != 0) {
				a.insert(a.begin(), Temp + '0');
				Temp = 0;
			}
		}
	}

	//Xóa các số 0 thừa.
	// while (a[0] == '0')
	// {
	//     a.erase(a.begin());
	// }
	a.erase(0, a.find_first_not_of("0"));

	return a;
}

std::string DivBy2(std::string src) {
	std::string res{ "" };
	int temp{ 0 };

	if ((src == "1") || (src == "-1")) {
		return "0";
	}

	for (int i = 0; i < src.size(); i++) {
		temp = temp * 10 + (src[i] - '0');

		if (i > 0 || (i == 0 && temp >= 2)) {
			res.push_back((temp / 2) + '0');
		}
		temp %= 2;
	}


	return res;
}

int digit(int by) {
	int res = 1;
	while (by /= 10) {
		++res;
	}
	return res;
}

string divide(string number, int divisor) {
	// As result can be very large store it in string 
	string ans;

	// Find prefix of number that is larger 
	// than divisor. 
	int idx = 0;
	int temp = number[idx] - '0';
	while (temp < divisor)
		temp = temp * 10 + (number[++idx] - '0');

	// Repeatedly divide divisor with temp. After  
	// every division, update temp to include one  
	// more digit. 
	while (number.size() > idx)
	{
		// Store result in answer i.e. temp / divisor 
		ans += (temp / divisor) + '0';

		// Take next digit of number 
		temp = (temp % divisor) * 10 + number[++idx] - '0';
	}

	// If divisor is greater than number 
	if (ans.length() == 0)
		return "0";

	// else return ans 
	return ans;
}

std::string DecToBin(std::string dec) {
	std::string res;
	bool neg = false;

	if (dec[0] == '-') { // Kiểm tra số âm.
		dec.erase(dec.begin());
		neg = true;
	}

	while (dec != "") {
		res.insert(res.begin(), ((dec[dec.size() - 1] - '0') % 2) + '0');
		dec = DivBy2(dec);
	}

	//fil 128 bits
	fillBinWithZero(res, _DEFAULT_SIZE * 8);

	//chuyển về số bù 2 nếu âm
	if (neg == true) {
		res = com2(res);
	}

	return res;
}

std::string BinToDec(std::string bin) {
	bin = fill(bin, 128);
	if (bin.empty()) {
		return "";
	}

	string result = "0";

	bool negative;

	//kiểm tra số âm
	if (bin[0] == '1') {
		negative = true;
		bin = com2(bin);
	}
	else {
		negative = false;
	}

	// tính giá trị
	for (int i = 1; i < bin.length(); i++) {
		if (bin[i] == '1') {
			// result = AddNumberString(result, t.p[bin.length() - i - 1]);
			result = AddNumberString(result, pow_2_n(bin.length() - i - 1));
		}
	}

	//thêm dấu nếu âm
	if (negative) {
		result.insert(0, "-");
	}

	return result;
}


std::string fill(std::string obj, int size) {
	int more = size - obj.size();
	if (more <= 0) {
		return obj;
	}
	std::string res;
	for (std::size_t i = 0; i < more; ++i) {
		res.push_back('0');
	}
	return res + obj;
}

std::string add(std::string a, std::string b) {
	a = fill(a, 128);
	b = fill(b, 128);
	int temp = 0;
	std::string res;
	for (int i = a.size() - 1; i >= 0; --i) {
		temp = temp + (a[i] - '0') + (b[i] - '0');
		res.insert(res.begin(), (temp % 2) + '0');
		temp /= 2;
	}
	return res;
}

std::string com1(std::string obj) {
	obj = fill(obj, 128);
	for (std::size_t i = 0; i < obj.size(); ++i) {
		obj[i] = (obj[i] == '0' ? '1' : '0');
	}
	return obj;
}

std::string com2(std::string obj) {
	obj = com1(obj);
	std::string one{ "1" };
	return add(fill(one, 128), obj);
}

std::string minu(std::string a, std::string b) {
	return add(a, com2(b));
}

std::string multi(std::string a, std::string b) {
	a = fill(a, 128);
	b = fill(b, 128);

	std::string zero = fill("", 128);
	bool both = a[0] == b[0];
	if (a[0] > '0') {
		a = com2(a);
	}
	if (b[0] > '0') {
		b = com2(b);
	}

	// a = a.erase(0, a.find_first_of('1')); // 1111
	b = b.erase(0, b.find_first_of('1')); // 1111

	std::string res{ "0" };
	std::string tem;
	for (int i = b.size() - 1; i >= 0; --i) {
		if (b[i] > '0') {
			res = add(res, a.substr(a.size() - 128));
		}
		a.push_back('0');
	}

	if (!both) {
		res = com2(res);
	}
	return res;
}

bool large(std::string a, std::string b) {
	a = fill(a, 128);
	b = fill(b, 128);

	int a1 = a.find_first_of('1');
	int b1 = b.find_first_of('1');

	if (a[0] == b[0]) {
		if (a1 != b1) {
			if (b1 < 0) {
				return true;
			}
			if (a1 < 0) {
				return false;
			}
			return a1 < b1;
		}
		return a.substr(a1) > b.substr(b1);
	}

	return !b1;
}
bool small(std::string a, std::string b) {
	a = fill(a, 128);
	b = fill(b, 128);

	int a1 = a.find_first_of('1');
	int b1 = b.find_first_of('1');

	if (a[0] == b[0]) {
		if (a1 != b1) {
			if (a1 < 0) {
				return true;
			}
			if (b1 < 0) {
				return false;
			}
			return a1 > b1;
		}
		else {
			return a.substr(a1) < b.substr(b1);
		}
	}

	return !a1;
}

std::string divi(std::string a, std::string b) {
	a = fill(a, 128);
	b = fill(b, 128);

	std::string zero = fill("", 128);
	bool both = a[0] == b[0];
	if (a[0] > '0') {
		int lenA = a.size() - a.find_first_of('1'); // 4
		int lenB = b.size() - b.find_first_of('1'); // 2
		a = a.erase(0, a.find_first_of('1')); // 1111
		b = b.erase(0, b.find_first_of('1')); // 1111
		// std::string b1 = b.erase(0, b.find_first_of('1'));
		int delta = lenA - lenB; // 2

		std::string temp1 = a.substr(0, lenB); // 11
		std::string res = (!small(temp1, b) ? "1" : "0"); // 1
		std::string temp2, tmp;
		for (int i = 0; i < delta; ++i) {
			temp2 = (res[res.size() - 1] > '0') ? b : zero; // 11 00
			tmp = a.substr(lenB + i, 1);
			temp1 = minu(temp1, temp2) + tmp; // 01 011
			temp1.erase(0, 1);
			res.push_back(!small(temp1, b) ? '1' : '0'); // 10
		}

		res = fill(res, 128);
		if (!both) {
			res = com2(res);
		}
		return res;
	}
}

std::string shiftLeft(std::string obj, int num) {
	obj = fill(obj, 128);

	for (int i = 0; i < num; ++i) {
		obj += "0";
	}

	return obj[0] + obj.substr(num + 1);
}

std::string shiftRight(std::string obj, int num) {
	obj = fill(obj, 128);

	for (int i = 0; i < num; ++i) {
		obj.insert(obj.begin(), obj[0]);
	}

	return obj.substr(0, 128);
}

std::string strRor(std::string obj, int num) {
	obj = obj.substr(128 - num) + obj;

	return obj.substr(0, 128);
}

std::string strRol(std::string obj, int num) {
	obj += obj.substr(0, num);

	return obj.substr(num);
}

std::string clean(std::string obj) {
	return obj.substr(obj.find_first_not_of('0'));
}

std::vector<std::string> binCase{ "0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111" };
std::vector<std::string> hexCase{ "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F" };

std::string GetHexFromBin(std::string bin) {
	bin = fill(bin, 4);
	for (std::size_t i = 0; i < binCase.size(); ++i) {
		if (bin == binCase[i]) {
			return hexCase[i];
		}
	}
	return "";
}


std::string BinToHex(std::string bin) {
	std::string res;
	bin = fill(bin, 128);
	for (std::size_t i = 0; i < 128; i += 4) {
		res += GetHexFromBin(bin.substr(i, 4));
	}
	return clean(res);
}

std::string GetBinFromHex(std::string hex) {
	for (std::size_t i = 0; i < hexCase.size(); ++i) {
		if (hex == hexCase[i]) {
			return binCase[i];
		}
	}
	return "";
}

std::string HexToBin(std::string hex) {
	std::string res;
	// hex = fill(hex, 32);
	for (std::size_t i = 0; i < hex.size(); ++i) {
		res += GetBinFromHex(hex.substr(i, 1));
	}
	return res;
}

std::string DecToHex(std::string dec) {
	std::string bin = DecToBin(dec);

	return BinToHex(bin);
}

std::string HexToDec(std::string hex) {
	std::string bin = HexToBin(hex);

	return BinToDec(bin);
}

std::string pow_2_n(int n) {
	FILE* fout;
	fopen_s(&fout, "buf.txt", "w");
	int i, j, blen = n / 32 + 1, dlen = n / 29 + 1;
	uint32_t* bin = new uint32_t[blen];
	uint32_t* dec = new uint32_t[dlen];
	uint64_t num;

	for (i = 0; i < blen; i++) {
		bin[i] = 0;
	}
	bin[n / 32] = (uint32_t)1 << (n % 32);

	for (j = 0; blen > 0; ) {
		for (num = 0, i = blen; i-- > 0;) {
			num = (num << 32) | bin[i];
			bin[i] = num / 1000000000;
			num = num % 1000000000;
		}
		dec[j++] = (uint32_t)num;
		while (blen > 0 && bin[blen - 1] == 0) {
			blen--;
		}
	}

	fprintf(fout, "%u", dec[--j]);
	while (j-- > 0)
		fprintf(fout, "%09u", dec[j]);

	fclose(fout);
	delete[] bin;
	delete[] dec;

	std::ifstream fin;
	fin.open("buf.txt");
	std::string ss;
	getline(fin, ss);
	fin.close();

	return ss;
}