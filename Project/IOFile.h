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

	// Lưu kết quả vào file output
	bool writeResults(std::string fname);

private:

	// QInt: 1, QFloat: 0
	bool modeQInt;

	std::vector<std::string> commandLine;

	string* results;

	// Đọc các dòng trong file input
	bool readCommandLine(std::string fname);

	// Thực thi tất cả các dòng lệnh của file input
	void executeAllCommandLine();

	// Thực thi dòng lệnh thứ i của file input
	void executeCommandLine(int i);

	// Thực thi dòng lệnh thứ i của file input trong chế độ QInt
	void executeCommandLineModeQInt(int i);

	// Thực thi dòng lệnh thứ i của file input trong chế độ QFloat
	void executeCommandLineModeQFloat(int i);

	// Tách dòng lệnh thành từng chuỗi
	std::vector<std::string> tokenizeCommandLine(int i);

};
