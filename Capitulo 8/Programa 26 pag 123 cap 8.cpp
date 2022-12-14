#include <iostream>
#include <random> // Para std::mt19937
#include <ctime>

int main()
{
	// Inicializa mersenne twister
	std::mt19937 mersenne{ static_cast<std::mt19937::result_type(std::time(nullptr)) };

	// cree	un generador de números aleatorios reutilizable que genera números uniformes 1 y 5
	std::uniform_int_distribution die{ 1, 6 };
	// Si su compilador no es compatible con c++17, use esto
	//std::uniform_int_distribution<>die { 1, 6 };

	for (int count { 1 }; count <= 48; ++count)
	{
		std::cout << die(mersenne) << '\t';

		if (count % 6 == 0)
			std::cout << '\n';
	}

	return 0;
}