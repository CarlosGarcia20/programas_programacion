//Conversión de entero a booleano
#include <iostream>

int main()
{
	bool b{};
	std::cout << 'ingrese un valor boolean: ';
	std::cin >> b;
	std::cout << 'ingresaste: '<< b << '\n';

	return 0;
}
//En este caso, debido a que ingresamos verdadero, std::cin falló silenciosamente.