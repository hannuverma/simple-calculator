#include <iostream>
#include <string>
#include <fstream>

constexpr auto textFile = "suggestions.txt";
constexpr auto password = "hannu";

std::ofstream writeFile(const std::string& fileName, std::string input);
std::ifstream readFile(const std::string& fileName);
std::ofstream deleteData(const std::string& fileName);
bool isFileEmpty(const std::string& fileName);

long double addition(long double x, long double y);
long double multiplication(long double x, long double y);
long double division(long double x, long double y);
long double subtraction(long double x, long double y);
long double power(long double x, long double y);
long long int factorial(long long int x);
int remainder(int x, int y);


int main()
{
	std::cout << "just enter a number then an operator then another number then press enter to get the answer \n"
			  << "eg : 2+2 = 4 then use any operator then another number\n"
			  << "Recognized operators include: +, -, *, /, !(factorial), r(remainder)\n"
			  << "press c to start over\n"
			  << "enter '1s' if you want me to add a new operator or something\n";

	std::string suggestion{};
	char sign{};      
	long double num1{};
	long double num2{};

	int choice{};
	long double result{};

	std::string UIPassword{};
	bool doneOnce{ false };

	while (true)
	{

		if (!doneOnce)//we dont have the previous number as the num1
		{
			std::cin >> num1 >> sign; // take number one then sign then number 2
		}
		else // we are using the previous result as the num1
		{
			num1 = result;
			std::cin >> sign;

		}

		if (sign == '!')
		{
			result = factorial(static_cast<long long int>(num1));
			doneOnce = true;
		}

		else if (sign == 'c')//restart
		{
			doneOnce = false;

			result = 0;

		}

		else if (sign == '+' || sign == '/' || sign == '*' || sign == '-' || sign == 'r' || sign == '^') // this doesn't feel right but helps me know what operators i have assigned
		{
			std::cin >> num2; // take the num2 here because we dont want num2 for factorial

			doneOnce = true;

			if (sign == '+')
			{
				result = addition(num1, num2);
			}
			else if (sign == '*')
			{
				result = multiplication(num1, num2);
			}
			else if (sign == '/')
			{
				result = division(num1, num2);
			}
			else if (sign == '-')
			{
				result = subtraction(num1, num2);
			}

			else if (sign == 'r')
			{
				result = remainder(static_cast<int>(num1), static_cast<int>(num2)); //for remainder we need only integer 

				doneOnce = false;
				std::cout << '\n'; 
			}
			else if (sign == '^')
			{
				if (pow(num1, num2) >= 9223372036854775808)
				{
					std::cout << "out of bounds!!!";
				}
				else
				{
					result = power(num1, num2);
				}

			}

		}

		else if (sign == 's' || sign == 'S')
		{
			std::cout << "enter what you want: ";
			std::getline(std::cin >> std::ws, suggestion);


			writeFile(textFile, suggestion);
		}

		else if (sign == 'z')
		{
			std::cout << "Enter your password to read the file: ";
			std::getline(std::cin >> std::ws, UIPassword);

			if (UIPassword == password)
			{
				if (isFileEmpty(textFile))
				{
					std::cout << "No suggestions yet!\n";
				}
				else
				{
					readFile(textFile);
				}


			}

			else
			{
				std::cout << "WRONG PASSWORD!!\n";
			}

		}

		else if (sign == 'd')
		{
			std::cout << "Enter your password to delete the file: ";
			std::getline(std::cin >> std::ws, UIPassword);

			if (UIPassword == password)
			{
				deleteData(textFile);

				if (isFileEmpty)
				{
					std::cout << "file's contents deleted successfully\n";
				}

				else
				{
					std::cout << "Couldn't delete the file's contents!\n";
				}
			}

			else
			{
				std::cout << "WRONG PASSWORD!!\n";
			}

		}

		else 
		{
			std::cout << "Unkown operator: " << sign << '\n';
			std::cin.clear();
			std::cin.ignore(10000, '\n'); 

			doneOnce = false;
		}
	}
}
