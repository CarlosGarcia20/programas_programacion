#include <iostream>

int main()
{
	int sum{ 0 };
	for (int count{ 0 }; count < 10; ++count)
	{
		std::cout << "Ingrese un numero a sumar o 0 para salir: ";
		int num;
		std::cin >> num;

		if (num == 0)
			break;
		sum += num;
	
	
	}

	std::cout << "La suma de todos los numeros ingresados es: " << sum << "\n";

	return 0;
}