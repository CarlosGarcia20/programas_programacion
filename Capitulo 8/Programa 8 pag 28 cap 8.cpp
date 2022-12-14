#include <iostream>

int main()
{
	std::cout << "Ingrese de 0 a 1: ";
	int x{};
	std::cin >> x;
	if (x = 0)
		std::cout << "Ingresaste 0\n";
	else
		std::cout << "Ingresaste 1\n";

	return 0;
}