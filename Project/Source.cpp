#include "IOFile.h"

int main(int argc, char const* argv[])
{
	// std::cout << toDec("0100000000001101001011101110010100000000000000000000000000000000000000000000000000000001")<< "\n";
	std::cout << toBin(pow_2_n(16383)) << "\n";
	// std::cout << toDec(toBin("0.0625")) << "\n";
	// std::cout << toBin("-2948.13480134625") << "\n";
	return 0;
}
