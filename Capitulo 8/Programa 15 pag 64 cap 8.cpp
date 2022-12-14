#include <iostream>

int main
{
	int count{ 1 };
	int sum{ 0 };

	while (count <= 5)
	{
		int x{}; // Se crea en cada iteración

		std::cout << "Ingrese un entero #" << count << ':';
		std::cin >> x;
		sum += x;
		++count;
		//	x se destruye

		std::cout << "La suma de todos los numeros ingresados es: " << sum << '\n';

		return 0;
	}
}