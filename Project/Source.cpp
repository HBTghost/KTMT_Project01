#include "QInt.h"
#include "Qfloat.h"


int main(int argc, char const* argv[])
{

	std::string a{
		"01111111111111111111111111111111111111111111111111111111111111111111111111111111111111010101111001110110111100110010000011111111"
	};
	std::string b{
		"00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001001100110011001100110011000110"
	};
	std::string temp{
		"10000000000000000000000000010000000000001000000000000000000000000000000000000000000000000000000000000000000000000000000000000001" };
	std::string dec{ "193284531250891" };
	std::string hex{ "AFCA8FD366CB" };
	QInt qa(a);
	QInt qb(b);
	// QInt bin(dec);

	QInt qc = qa;
	// std::cout << "Output: " << QIntToBinString(qc);
	// std::cout << BinToDec("00000000000000000000000000000000000000000000000000000000000000000000000000000000000010000011011010110011010011101100100101110011") << "\n";

	// std::string testFloat{ "11000101000100101001001000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000" };
	string d = "165465.4552";
	

	// cout << FloatBinToDec(d);



	// std::string testDec("-1234.125");
	// Qfloat fb(testDec);

	//for (int i = -32; i < 33; ++i) {
		//std::cout << "2^" << i << " = " << pow_2_n(i) << "\n";
	//}
	std::cout << FloatDecToBin("123945813528981235.0000000000000000000000000000007888609052210118054117285652827862296732064351090230047702789306640625");
	std::cout << FloatBinToDec("00000000000000001011100001011000000011111000101011001010101011101111001100000000000000000000000000000000000000000000000000000000");


	return 0;
}