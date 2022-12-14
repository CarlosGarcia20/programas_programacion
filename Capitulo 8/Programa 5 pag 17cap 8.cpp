#include <iostream>

int main()
{
	std::cout << " Ingresaste un numero positivo entre 0 y 9999: ";
	int x{};
	std::cin >> x;

	if (x < 0)
		std::cout << x << " es negativo";
	else if (x < 10)
		std::cout << x << " tiene un digito\n";
	else if (x < 100)
		std::cout << x << " tiene 2 digitos\n";
	else if (x < 1000)
		std::cout << x << " tiene 3 digitos";
	else if (x < 10000)
		std::cout << x << " tiene 4 digitos";
	else
		std::cout << x << " es mayor que 1999\n"



}