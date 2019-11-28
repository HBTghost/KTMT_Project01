#include "IOFile.h"

IOFile::IOFile(std::string fname, bool modeQInt) {
	this->readCommandLine(fname);

	this->results = new string[this->commandLine.size()];

	this->modeQInt = modeQInt;

}

IOFile::~IOFile()
{
	if (this->results != nullptr) {
		delete[] this->results;
	}
}

bool IOFile::readCommandLine(std::string fname)
{

	ifstream f(fname);

	if (!f.is_open()) {
		std::cout << "ERROR: can't open " << fname << std::endl;
		return false;;
	}

	

	string temp;

	getline(f, temp, '\n');

	//read all lines in input file
	while (temp != "") {
		this->commandLine.push_back(temp);
		temp.clear();
		getline(f, temp, '\n');
	}

	f.close();
	return true;
}

bool IOFile::writeResults(std::string fname) {
	ofstream f(fname);

	if (!f.is_open()) {
		if (!f.is_open()) {
			std::cout << "ERROR: can't open " << fname << std::endl;
			return false;
		}
	}

	executeAllCommandLine();

	
	for (int i = 0; i < this->commandLine.size(); i++) {
		f << this->results[i] << std::endl;
	}
	
	f.close();
	return true;
}

std::vector<std::string> IOFile::tokenizeCommandLine(int i)
{
	std::vector<std::string> result;

	if (i >= commandLine.size()) {
		std::cout << "\nERROR: tokenizeCommandLine: i is out of range.\n";
		return result;
	}

	std::stringstream cL(this->commandLine[i]);

	std::string intermediate;

	while (getline(cL, intermediate, ' ')) {
		result.push_back(intermediate);
	}

	return result;
}

void IOFile::executeAllCommandLine()
{
	for (int i = 0; i < this->commandLine.size(); i++) {
		executeCommandLine(i);
	}
}

void IOFile::executeCommandLine(int i)
{
	if (i >= commandLine.size()) {
		std::cout << "\nERROR: executeCommandLine: i is out of range.\n";
		return;
	}

	if (modeQInt) {
		executeCommandLineModeQInt(i);
	}
	else {
		executeCommandLineModeQFloat(i);
	}

}

void IOFile::executeCommandLineModeQInt(int i)
{
	std::vector<std::string> tokens = this->tokenizeCommandLine(i);
	
	//----BINARY--------------
	if (tokens[0] == "2") {
		if (tokens[1] == "10") {

			this->results[i] = BinToDec(tokens[2]);

			return;
		}
		if (tokens[1] == "16") {
			this->results[i] = BinToHex(tokens[2]);
			return;
		}
		if (tokens[1] == "~") {
			QInt x(tokens[2]);
			
			x = ~x;

			this->results[i] = x.toBinString();

			return;
		}

		if (tokens[2] == "<<") {
			QInt x(tokens[1]);
			x = x << stoi(tokens[3]);
			this->results[i] = x.toBinString();
			return;
		}
		if (tokens[2] == ">>") {
			QInt x(tokens[1]);
			x = x >> stoi(tokens[3]);
			this->results[i] = x.toBinString();
			return;
		}
		if (tokens[2] == "rol") {
			QInt x(tokens[1]);
			x = x.rol(stoi(tokens[3]));
			this->results[i] = x.toBinString();
			return;
		}
		if (tokens[2] == "ror") {
			QInt x(tokens[1]);
			x = x.ror(stoi(tokens[3]));
			this->results[i] = x.toBinString();
			return;
		}

		QInt a(tokens[1]), b(tokens[3]);

		if (tokens[2] == "<") {
			if (a < b) {
				this->results[i] = "TRUE";
			}
			else {
				this->results[i] = "FALSE";
			}

			return;
		}
		if (tokens[2] == "<=") {
			if (a <= b) {
				this->results[i] = "TRUE";
			}
			else {
				this->results[i] = "FALSE";
			}

			return;
		}
		if (tokens[2] == ">") {
			if (a > b) {
				this->results[i] = "TRUE";
			}
			else {
				this->results[i] = "FALSE";
			}

			return;
		}
		if (tokens[2] == ">=") {
			if (a >= b) {
				this->results[i] = "TRUE";
			}
			else {
				this->results[i] = "FALSE";
			}

			return;
		}
		if (tokens[2] == "==") {
			if (a == b) {
				this->results[i] = "TRUE";
			}
			else {
				this->results[i] = "FALSE";
			}

			return;
		}
		if (tokens[2] == "!=") {
			if (a != b) {
				this->results[i] = "TRUE";
			}
			else {
				this->results[i] = "FALSE";
			}

			return;
		}

		if (tokens[2] == "+") {
			QInt res = a + b;
			this->results[i] = res.toBinString();
			return;
		}
		if (tokens[2] == "-") {
			QInt res = a - b;
			this->results[i] = res.toBinString();
			return;
		}
		if (tokens[2] == "*") {
			QInt res = a * b;
			this->results[i] = res.toBinString();
			return;
		}
		if (tokens[2] == "/") {
			QInt res = a / b;
			this->results[i] = res.toBinString();
			return;
		}
		if (tokens[2] == "&") {
			QInt res = a & b;
			this->results[i] = res.toBinString();
			return;
		}
		if (tokens[2] == "|") {
			QInt res = a | b;
			this->results[i] = res.toBinString();
			return;
		}
		if (tokens[2] == "^") {
			QInt res = a ^ b;
			this->results[i] = res.toBinString();
			return;
		}
	}

	//------DECIMAL---------------------//
	
	if (tokens[0] == "10") {
		if (tokens[1] == "2") {

			this->results[i] = DecToBin(tokens[2]);

			return;
		}
		if (tokens[1] == "16") {
			this->results[i] = DecToHex(tokens[2]);
			return;
		}
		if (tokens[1] == "~") {
			QInt x(DecToBin(tokens[2]));

			x = ~x;

			this->results[i] = BinToDec(x.toBinString());

			return;
		}

		if (tokens[2] == "<<") { 
			QInt x(DecToBin(tokens[1]));
			x = x << stoi(tokens[3]);
			this->results[i] = BinToDec(x.toBinString());
			return;
		}
		if (tokens[2] == ">>") {
			QInt x(DecToBin(tokens[1]));
			x = x >> stoi(tokens[3]);
			this->results[i] = BinToDec(x.toBinString());
			return;
		}
		if (tokens[2] == "rol") {
			QInt x(DecToBin(tokens[1]));
			x = x.rol(stoi(tokens[3]));
			this->results[i] = BinToDec(x.toBinString());
			return;
		}
		if (tokens[2] == "ror") {
			QInt x(DecToBin(tokens[1]));
			x = x.ror(stoi(tokens[3]));
			this->results[i] = BinToDec(x.toBinString());
			return;
		}

		QInt a(DecToBin(tokens[1])), b(DecToBin(tokens[3]));

		if (tokens[2] == "<") {
			if (a < b) {
				this->results[i] = "TRUE";
			}
			else {
				this->results[i] = "FALSE";
			}

			return;
		}
		if (tokens[2] == "<=") {
			if (a <= b) {
				this->results[i] = "TRUE";
			}
			else {
				this->results[i] = "FALSE";
			}

			return;
		}
		if (tokens[2] == ">") {
			if (a > b) {
				this->results[i] = "TRUE";
			}
			else {
				this->results[i] = "FALSE";
			}

			return;
		}
		if (tokens[2] == ">=") {
			if (a >= b) {
				this->results[i] = "TRUE";
			}
			else {
				this->results[i] = "FALSE";
			}

			return;
		}
		if (tokens[2] == "==") {
			if (a == b) {
				this->results[i] = "TRUE";
			}
			else {
				this->results[i] = "FALSE";
			}

			return;
		}
		if (tokens[2] == "!=") {
			if (a != b) {
				this->results[i] = "TRUE";
			}
			else {
				this->results[i] = "FALSE";
			}

			return;
		}

		if (tokens[2] == "+") {
			QInt res = a + b;
			this->results[i] = BinToDec(res.toBinString());
			return;
		}
		if (tokens[2] == "-") {
			QInt res = a - b;
			this->results[i] = BinToDec(res.toBinString());
			return;
		}
		if (tokens[2] == "*") {
			QInt res = a * b;
			this->results[i] = BinToDec(res.toBinString());
			return;
		}
		if (tokens[2] == "/") {
			QInt res = a / b;
			this->results[i] = BinToDec(res.toBinString());
			return;
		}
		if (tokens[2] == "&") {
			QInt res = a & b;
			this->results[i] = BinToDec(res.toBinString());
			return;
		}
		if (tokens[2] == "|") {
			QInt res = a | b;
			this->results[i] = BinToDec(res.toBinString());
			return;
		}
		if (tokens[2] == "^") {
			QInt res = a ^ b;
			this->results[i] = BinToDec(res.toBinString());
			return;
		}
	}

	//------HEXADECIMAL------------

	if (tokens[0] == "16") {
		if (tokens[1] == "2") {

			this->results[i] = HexToBin(tokens[2]);

			return;
		}
		if (tokens[1] == "10") {
			this->results[i] = HexToDec(tokens[2]);
			return;
		}
		if (tokens[1] == "~") {
			QInt x(HexToBin(tokens[1]));

			x = ~x;

			this->results[i] = BinToHex(x.toBinString());

			return;
		}

		if (tokens[2] == "<<") {
			QInt x(HexToBin(tokens[1]));
			x = x << stoi(tokens[3]);
			this->results[i] = BinToHex(x.toBinString());
			return;
		}
		if (tokens[2] == ">>") {
			QInt x(HexToBin(tokens[1]));
			x = x >> stoi(tokens[3]);
			this->results[i] = BinToHex(x.toBinString());
			return;
		}
		if (tokens[2] == "rol") {
			QInt x(HexToBin(tokens[1]));
			x = x.rol(stoi(tokens[3]));
			this->results[i] = BinToHex(x.toBinString());
			return;
		}
		if (tokens[2] == "ror") {
			QInt x(HexToBin(tokens[1]));
			x = x.ror(stoi(tokens[3]));
			this->results[i] = BinToHex(x.toBinString());
			return;
		}

		QInt a(HexToBin(tokens[1])), b(HexToBin(tokens[3]));

		if (tokens[2] == "<") {
			if (a < b) {
				this->results[i] = "TRUE";
			}
			else {
				this->results[i] = "FALSE";
			}

			return;
		}
		if (tokens[2] == "<=") {
			if (a <= b) {
				this->results[i] = "TRUE";
			}
			else {
				this->results[i] = "FALSE";
			}

			return;
		}
		if (tokens[2] == ">") {
			if (a > b) {
				this->results[i] = "TRUE";
			}
			else {
				this->results[i] = "FALSE";
			}

			return;
		}
		if (tokens[2] == ">=") {
			if (a >= b) {
				this->results[i] = "TRUE";
			}
			else {
				this->results[i] = "FALSE";
			}

			return;
		}
		if (tokens[2] == "==") {
			if (a == b) {
				this->results[i] = "TRUE";
			}
			else {
				this->results[i] = "FALSE";
			}

			return;
		}
		if (tokens[2] == "!=") {
			if (a != b) {
				this->results[i] = "TRUE";
			}
			else {
				this->results[i] = "FALSE";
			}

			return;
		}

		if (tokens[2] == "+") {
			QInt res = a + b;
			this->results[i] = BinToHex(res.toBinString());
			return;
		}
		if (tokens[2] == "-") {
			QInt res = a - b;
			this->results[i] = BinToHex(res.toBinString());
			return;
		}
		if (tokens[2] == "*") {
			QInt res = a * b;
			this->results[i] = BinToHex(res.toBinString());
			return;
		}
		if (tokens[2] == "/") {
			QInt res = a / b;
			this->results[i] = BinToHex(res.toBinString());
			return;
		}
		if (tokens[2] == "&") {
			QInt res = a & b;
			this->results[i] = BinToHex(res.toBinString());
			return;
		}
		if (tokens[2] == "|") {
			QInt res = a | b;
			this->results[i] = BinToHex(res.toBinString());
			return;
		}
		if (tokens[2] == "^") {
			QInt res = a ^ b;
			this->results[i] = BinToHex(res.toBinString());
			return;
		}
	}
}

void IOFile::executeCommandLineModeQFloat(int i)
{
	std::vector<std::string> tokens = this->tokenizeCommandLine(i);

	if (tokens[0] == "2") {
		this->results[i] = FloatBinToDec(tokens[1]);
	}
	else if (tokens[0] == "10") {
		this->results[i] = FloatDecToBin(tokens[1]);
	}
}