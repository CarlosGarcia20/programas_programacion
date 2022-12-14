#include <iostream>
double getDouble()
{
	std::cout << "Ingrese un valor doble: ";
	double x{}; std::cin >> x;
	return x;
}
char getOperator()
{
	std::cout << "Ingrese uno de los siguientes +, -, *, or /: ";
	char op{}; std::cin >> op;
	return op;
}
void printResult(double x, char operation, double y)
{
	switch (operation)
	{
	case '+': std::cout << x << " x " << y << " is " << x + y << '\n'; break;
	case '-': std::cout << x << " x " << y << " is " << x - y << '\n'; break;
	case '*': std::cout << x << " x " << y << " is " << x * y << '\n'; break;
	case '/': std::cout << x << " x " << y << " is " << x / y << '\n'; break;
	}
}

int main()
{
	double x{ getDouble() }; char operation{ getOperator() };
	double y{ getDouble() };

	printResult(x, operation, y);
	return 0;
}