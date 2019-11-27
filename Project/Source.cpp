#include "IOFile.h"


int main(int argc, char const* argv[])
{

	std::vector<std::string> test;

	test[2] = "2222";

	for (int i = 0; i < test.size(); i++) {
		std::cout << test[i];
	}

	return 0;
}