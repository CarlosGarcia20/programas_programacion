#include <iomanip> // para std::setprecision()
#include <iostream>

int main()
{
	std::cout << std::setprecision(17);
	
	double d1{1.0};
	std::cout << d1 << '\n';
	
	double d2{0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1}; //debería ser igual a 1.0
	std::cout << d2 << '\n';
}