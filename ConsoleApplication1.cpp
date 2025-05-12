#include <iostream>
#include <string>


long double addition(long double x, long double y);
long double multiplication(long double x, long double y);
long double division(long double x, long double y);
long double subtraction(long double x, long double y);
long long int factorial(long long int x);
int remainder(int x, int y);


int main()
{
	std::cout << "just enter a number then an operator then another number then press enter to get the answer \n"
		<< "eg : 2+2 = 4 then use any operator then another number\n"
		<< "Recognized operators include: +, -, *, /, !(factorial), r(remainder)\n"
		<< "press c to start over\n";

	char sign{};      
	long double num1{};
	long double num2{};

	int choice{};
	long double result{};

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

		else if (sign == '+' || sign == '/' || sign == '*' || sign == '-' || sign == 'r') // this doesn't feel right but helps me know what operators i have assigned
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
