#include <iostream>

enum class Errorcode 
{
	success,
	negative_number
};
Errorcode doSomething(int value)
{
	if (value < 0)
	{ //Devolución anticipada
		return Errorcode::negative_number;

	}
	// Código de la función
	return Errorcode::success;
}

int main()
{
	std::cout << "Ingrese un numero positivo: ";
	int x{};
	std::cin >> x;

	if (doSomething(x) == Errorcode::negative_number)
	{
		std::cout << "Ingresa un numero negativo: !\n";
	}
	else
	{
		std::cout << "Funciono!!!\n";
	}

	return 0;
}