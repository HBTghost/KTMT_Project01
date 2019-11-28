#include "Console.h"

void Console::run()
{
    while (true) {
        system("cls");
        std::cout << "AVAILABLE MODE: \n";
        std::cout << "  1. QInt\n  2. QFloat\n  0. Exit\n";

        int mode;

        std::cout << "Choose mode: ";
        std::cin >> mode;

        while (mode != 1 && mode != 2 && mode != 0) {
            std::cout << "Invalid mode. Please choose again: ";
            std::cin >> mode;
        }

        if (mode == 1) {
            runQIntMode();
        }
        else if (mode == 2) {
            runQFloatMode();
        }
        else return;
    }

}

void Console::runQIntMode() {
    while (true) {
        int mode = QIntMenu();

        if (mode == 0) {
            return;
        }
        else if (mode == 1) {
            QIntConverter();
        }
        else if (mode == 2) {
            QIntArithmetic();
        }
    }
}

void Console::runQFloatMode()
{
    while (true) {
        int mode = QFloatMenu();

        if (mode == 0) {
            return;
        }

        std::string str;
        std::cout << "Enter number to be converted: ";
        std::cin >> str;

        if (mode == 1) {
            std::cout << FloatBinToDec(str) << std::endl;
        }
        else if (mode == 2) {
            std::cout << FloatDecToBin(str) << std::endl;
        }

        system("pause");
    }
}

int Console::QIntMenu()
{
    system("CLS");
    std::cout << "---------------------QINT MODE----------------------" << std::endl;

    std::cout << " 1. Converter\n ";
    std::cout << "2. Arithmetic\n ";
    std::cout << "0. Return\n";

    int mode;

    std::cout << "Choose mode: ";
    std::cin >> mode;

    while (mode != 1 && mode != 2 && mode != 0) {
        std::cout << "Invalid mode. Please choose again: ";
        std::cin >> mode;
    }

    return mode;
}

int Console::QFloatMenu() {
    system("CLS");
    std::cout << "---------------------QFLOAT MODE----------------------" << std::endl;

    std::cout << " 1. Convert binary to decimal\n ";
    std::cout << "2. Convert decimal to Binary\n ";
    std::cout << "0. Return\n";

    int mode;

    std::cout << "Choose mode: ";
    std::cin >> mode;

    while (mode != 1 && mode != 2 && mode != 0) {
        std::cout << "Invalid mode. Please choose again: ";
        std::cin >> mode;
    }

    return mode;
}

void Console::QIntConverter() {

    std::vector<std::string> tokens;

    system("cls");

    std::cout << "-------------QINT CONVERTER--------------\n" << std::endl;
    std::cout << "BASE:\n ";
    std::cout << "  1. Binary\n ";
    std::cout << "  2. Decimal\n ";
    std::cout << "  3. Hexadecimal\n";

    int base1;

    std::cout << "Choose base to be converted from: ";
    std::cin >> base1;

    while (base1 != 1 && base1 != 2 && base1 != 3) {
        std::cout << "Invalid base. Please choose again: ";
        std::cin >> base1;
    }

    switch (base1) {
    case 1:
        tokens.push_back("2");
        break;
    case 2:
        tokens.push_back("10");
        break;
    case 3:
        tokens.push_back("16");
        break;
    }

    int base2;

    std::cout << "Choose base to be converted to: ";
    std::cin >> base2;

    while ((base2 != 1 && base2 != 2 && base2 !=3) || (base2 == base1)) {
        std::cout << "Invalid base. Please choose again: ";
        std::cin >> base2;
    }

    switch (base2) {
    case 1:
        tokens.push_back("2");
        break;
    case 2:
        tokens.push_back("10");
        break;
    case 3:
        tokens.push_back("16");
        break;
    }

    std::string str;
    std::cout << "Enter number to be converted: ";
    std::cin >> str;

    tokens.push_back(str);

    std::cout << "RESULT: " << executeCommandLine(tokens) << std::endl;

    system("pause");

}

void Console::QIntArithmetic() {

    std::vector<std::string> tokens;

    system("cls");

    std::cout << "-------------QINT ARITHMETIC OPERATIONS--------------\n" << std::endl;
    std::cout << "BASE:\n ";
    std::cout << "  1. Binary\n ";
    std::cout << "  2. Decimal\n ";
    std::cout << "  3. Hexadecimal\n";

    int base;

    std::cout << "Choose base: ";
    std::cin >> base;

    while (base != 1 && base != 2 && base != 3) {
        std::cout << "Invalid base. Please choose again: ";
        std::cin >> base;
    }

    switch (base) {
    case 1:
        tokens.push_back("2");
        std::cout << "You have chosen base 2\n";
        break;
    case 2:
        tokens.push_back("10");
        std::cout << "You have chosen base 10\n";
        break;
    case 3:
        tokens.push_back("16");
        std::cout << "You have chosen base 16\n";
        break;
    }

    std::string num1, num2, op;

    std::vector<std::string> aOps = { "+", "-", "*", "/", "&", "|", "^", "<<", ">>", "rol", "ror", "<", ">", "<=", ">=", "==","~" };

    std::cout << "\nARITHMETIC OPERATION: " << std::endl;
    
    for (int i = 0; i < aOps.size(); i++) {
        std::cout << i << ". " << aOps[i] << std::endl;
    }
    
    int opMode;

    std::cout << "Choose arithmetic operation: ";
    std::cin >> opMode;

    while (opMode < 0 || opMode > 17) {
        std::cout << "Invalid operation. Please choose again: ";
        std::cin >> opMode;
    }

    op = aOps[opMode];

    if (op == "~") {
        tokens.push_back(op);

        std::cout << "Enter number: ";

        std::cin >> num1;

        tokens.push_back(num1);
    }
    else {
        std::cout << "Enter first number: ";

        std::cin >> num1;

        tokens.push_back(num1);

        tokens.push_back(op);

        std::cout << "Enter second number: ";

        std::cin >> num2;

        tokens.push_back(num2);
    }

    std::cout << "RESULT: " << executeCommandLine(tokens) << std::endl;

    system("pause");

}

std::string Console::executeCommandLine(std::vector<string> &tokens) {

    //----BINARY--------------
    if (tokens[0] == "2") {
        if (tokens[1] == "10") {
            return BinToDec(tokens[2]);
        }
        if (tokens[1] == "16") {
            return BinToHex(tokens[2]);
        }
        if (tokens[1] == "~") {
            QInt x(tokens[2]);

            x = ~x;

            return x.toBinString();

        }

        if (tokens[2] == "<<") {
            QInt x(tokens[1]);
            x = x << stoi(tokens[3]);
            return x.toBinString();

        }
        if (tokens[2] == ">>") {
            QInt x(tokens[1]);
            x = x >> stoi(tokens[3]);
            return x.toBinString();

        }
        if (tokens[2] == "rol") {
            QInt x(tokens[1]);
            x = x.rol(stoi(tokens[3]));
            return x.toBinString();

        }
        if (tokens[2] == "ror") {
            QInt x(tokens[1]);
            x = x.ror(stoi(tokens[3]));
            return x.toBinString();
        }

        QInt a(tokens[1]), b(tokens[3]);

        if (tokens[2] == "<") {
            if (a < b) {
                return "TRUE";
            }
            else {
                return "FALSE";
            }

        }
        if (tokens[2] == "<=") {
            if (a <= b) {
                return"TRUE";
            }
            else {
                return "FALSE";
            }


        }
        if (tokens[2] == ">") {
            if (a > b) {
                return"TRUE";
            }
            else {
                return"FALSE";
            }


        }
        if (tokens[2] == ">=") {
            if (a >= b) {
                return "TRUE";
            }
            else {
                return"FALSE";
            }


        }
        if (tokens[2] == "==") {
            if (a == b) {
                return"TRUE";
            }
            else {
                return"FALSE";
            }


        }
        if (tokens[2] == "!=") {
            if (a != b) {
                return"TRUE";
            }
            else {
                return"FALSE";
            }


        }

        if (tokens[2] == "+") {
            QInt res = a + b;
            return res.toBinString();

        }
        if (tokens[2] == "-") {
            QInt res = a - b;
            return res.toBinString();

        }
        if (tokens[2] == "*") {
            QInt res = a * b;
            return res.toBinString();

        }
        if (tokens[2] == "/") {
            QInt res = a / b;
            return res.toBinString();

        }
        if (tokens[2] == "&") {
            QInt res = a & b;
            return res.toBinString();

            if (tokens[2] == "|") {
                QInt res = a | b;
                return res.toBinString();

            }
            if (tokens[2] == "^") {
                QInt res = a ^ b;
                return res.toBinString();

            }
        }
    }

        //------DECIMAL---------------------//

        if (tokens[0] == "10") {
            if (tokens[1] == "2") {

                return DecToBin(tokens[2]);

            }
            if (tokens[1] == "16") {
                return DecToHex(tokens[2]);

            }
            if (tokens[1] == "~") {
                QInt x(DecToBin(tokens[2]));

                x = ~x;

                return BinToDec(x.toBinString());

            }

            if (tokens[2] == "<<") {
                QInt x(DecToBin(tokens[1]));
                x = x << stoi(tokens[3]);
                return BinToDec(x.toBinString());

            }
            if (tokens[2] == ">>") {
                QInt x(DecToBin(tokens[1]));
                x = x >> stoi(tokens[3]);
                return BinToDec(x.toBinString());

            }
            if (tokens[2] == "rol") {
                QInt x(DecToBin(tokens[1]));
                x = x.rol(stoi(tokens[3]));
                return BinToDec(x.toBinString());

            }
            if (tokens[2] == "ror") {
                QInt x(DecToBin(tokens[1]));
                x = x.ror(stoi(tokens[3]));
                return BinToDec(x.toBinString());

            }

            QInt a(DecToBin(tokens[1])), b(DecToBin(tokens[3]));

            if (tokens[2] == "<") {
                if (a < b) {
                    return "TRUE";
                }
                else {
                    return "FALSE";
                }

                
            }
            if (tokens[2] == "<=") {
                if (a <= b) {
                    return "TRUE";
                }
                else {
                    return "FALSE";
                }

                
            }
            if (tokens[2] == ">") {
                if (a > b) {
                    return "TRUE";
                }
                else {
                    return "FALSE";
                }

                
            }
            if (tokens[2] == ">=") {
                if (a >= b) {
                    return  "TRUE";
                }
                else {
                    return  "FALSE";
                }

                
            }
            if (tokens[2] == "==") {
                if (a == b) {
                    return "TRUE";
                }
                else {
                    return "FALSE";
                }

                
            }
            if (tokens[2] == "!=") {
                if (a != b) {
                    return "TRUE";
                }
                else {
                    return "FALSE";
                }

                
            }

            if (tokens[2] == "+") {
                QInt res = a + b;
                return BinToDec(res.toBinString());

            }
            if (tokens[2] == "-") {
                QInt res = a - b;
                return BinToDec(res.toBinString());

            }
            if (tokens[2] == "*") {
                QInt res = a * b;
                return BinToDec(res.toBinString());

            }
            if (tokens[2] == "/") {
                QInt res = a / b;
                return BinToDec(res.toBinString());

            }
            if (tokens[2] == "&") {
                QInt res = a & b;
                return BinToDec(res.toBinString());

            }
            if (tokens[2] == "|") {
                QInt res = a | b;
                return BinToDec(res.toBinString());

            }
            if (tokens[2] == "^") {
                QInt res = a ^ b;
                return BinToDec(res.toBinString());

            }
        }

        //------HEXADECIMAL------------

        if (tokens[0] == "16") {
            if (tokens[1] == "2") {

                return HexToBin(tokens[2]);

            }
            if (tokens[1] == "10") {
                return HexToDec(tokens[2]);

            }
            if (tokens[1] == "~") {
                QInt x(HexToBin(tokens[1]));

                x = ~x;

                return BinToHex(x.toBinString());


            }

            if (tokens[2] == "<<") {
                QInt x(HexToBin(tokens[1]));
                x = x << stoi(tokens[3]);
                return BinToHex(x.toBinString());

            }
            if (tokens[2] == ">>") {
                QInt x(HexToBin(tokens[1]));
                x = x >> stoi(tokens[3]);
                return BinToHex(x.toBinString());

            }
            if (tokens[2] == "rol") {
                QInt x(HexToBin(tokens[1]));
                x = x.rol(stoi(tokens[3]));
                return BinToHex(x.toBinString());

            }
            if (tokens[2] == "ror") {
                QInt x(HexToBin(tokens[1]));
                x = x.ror(stoi(tokens[3]));
                return BinToHex(x.toBinString());

            }

            QInt a(HexToBin(tokens[1])), b(HexToBin(tokens[3]));

            if (tokens[2] == "<") {
                if (a < b) {
                    return "TRUE";
                }
                else {
                    return "FALSE";
                }


            }
            if (tokens[2] == "<=") {
                if (a <= b) {
                    return"TRUE";
                }
                else {
                    return "FALSE";
                }


            }
            if (tokens[2] == ">") {
                if (a > b) {
                    return"TRUE";
                }
                else {
                    return"FALSE";
                }


            }
            if (tokens[2] == ">=") {
                if (a >= b) {
                    return"TRUE";
                }
                else {
                    return "FALSE";
                }


            }
            if (tokens[2] == "==") {
                if (a == b) {
                    return"TRUE";
                }
                else {
                    return "FALSE";
                }


            }
            if (tokens[2] == "!=") {
                if (a != b) {
                    return"TRUE";
                }
                else {
                    return "FALSE";
                }


            }

            if (tokens[2] == "+") {
                QInt res = a + b;
                return BinToHex(res.toBinString());

            }
            if (tokens[2] == "-") {
                QInt res = a - b;
                return BinToHex(res.toBinString());
            }
            if (tokens[2] == "*") {
                QInt res = a * b;
                return BinToHex(res.toBinString());
            }
            if (tokens[2] == "/") {
                QInt res = a / b;
                return BinToHex(res.toBinString());
            }
            if (tokens[2] == "&") {
                QInt res = a & b;
                return BinToHex(res.toBinString());
            }
            if (tokens[2] == "|") {
                QInt res = a | b;
                return BinToHex(res.toBinString());
            }
            if (tokens[2] == "^") {
                QInt res = a ^ b;
                return BinToHex(res.toBinString());
            }
        }
}

