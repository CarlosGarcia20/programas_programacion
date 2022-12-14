#include <algorithm> // std :: swap
#include <iostream>

int main()
{
	int x{ 2 };
	int y{ 4 };
	std::cout << "Antes del intercambio: x = " << x << ", y = " << y << '\n';
	std::swap(x, y);
	std::cout << "Despues del intercambio: x = " << x << ", y = " << y << '\n';

}