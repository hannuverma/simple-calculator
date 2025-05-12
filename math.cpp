#include <iostream>

long double addition(long double x, long double y)
{
	std::cout << x + y;

	return x + y;
}

long double multiplication(long double x, long double y)
{
	std::cout << x * y;

	return x * y;

}

long double division(long double x, long double y)
{
	std::cout << x / y;

	return x / y;

}

long double subtraction(long double x, long double y)
{
	std::cout << x - y;
	return x - y;


}

int remainder(int x, int y)
{
	std::cout << x % y;
	return 0;
}

long long int factorial(long long int x)
{
	long long int y{ x };


	while (y > 1)
	{
		y--;


		if (x * y >= 9223372036854775808)
		{
			std::cout << "out of bounds!!!";

			return 0;
		}
		else
		{
			x *= y;

		}

	}

	std::cout << x;

	return x;


}