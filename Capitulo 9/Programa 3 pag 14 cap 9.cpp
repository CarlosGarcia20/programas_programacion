#include <iostream>

int main
{
	int array[5]{7 , 4 , 5}; // Solo se inicializan los primeros 3

	std::cout << array[0] << '\n';
	std::cout << array[1] << '\n';
	std::cout << array[2] << '\n';
	std::cout << array[3] << '\n';
	std::cout << array[4] << '\n';

	return 0;
}