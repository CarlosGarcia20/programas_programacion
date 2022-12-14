#include <iostream>

int main()
{
	while (true) //
	{
		std::cout << "Ingrese 0 para salir, otra cosa para continuar: ";
		int num{};
		std::cin >> num;

		if (num == 0)
			break;
	}

	std::cout << "Ya salimos!!!\n";

	return 0;
}