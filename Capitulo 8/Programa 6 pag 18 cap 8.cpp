#include <iostream>

int main()
{
	std::cout << "Ingresaste un numero: ";
	int x{};
	std::cin >> x;

	if (x >= 10) // if exterior
		if (x <= 20) // if inferior
			std::cout << x << "esta entre 10 y 20";

	// este else a que if le corresponde?
		else
			std::cout << x << "es mayor que 20\n";

	return 0;
}