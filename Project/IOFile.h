#pragma once

#include "QFloat.h"
#include "QInt.h"

#include <fstream>
#include <sstream>
#include <string>
#include <vector>

class IOFile
{
public:

	IOFile(std::string fname, bool modeQInt);

	~IOFile();


private:

	//QInt: 1, QFloat: 0
	bool modeQInt;

	std::vector<std::string> commandLine;

	string* results;

	//đọc các dòng trong file input
	bool readCommandLine(std::string fname);

	//lưu kết quả vào file output
	bool writeResults(std::string fname);

	//thực thi tất cả các dòng lệnh của file input
	void executeAllCommandLine();

	//thực thi dòng lệnh thứ i của file input
	void executeCommandLine(int i);

	//thực thi dòng lệnh thứ i của file input trong chế độ QInt
	void executeCommandLineModeQInt(int i);

	//thực thi dòng lệnh thứ i của file input trong chế độ QFloat
	//void executeCommandLineModeQFloat(int i);

	//Tách dòng lệnh thành từng chuỗi
	std::vector<std::string> tokenizeCommandLine(int i);

};
