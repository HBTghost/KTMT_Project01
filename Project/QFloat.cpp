#include "QFloat.h"
#include "QInt.h"
#include <math.h>

using namespace std;

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
