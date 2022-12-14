#include <iomanip> // para std::setpresicion ()
#include <iostream>

int main()
{
	double d{0.1};
	std::cout << d << '\n'; //presicion por default a 6
	std::cout << std::setprecision(17);
	std::cout << d << '\n';
	return 0;
}