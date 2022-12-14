#include <iostream>

int main()
{

	int prime[5]{}; // Almacena los primeros 5 numeros primos
	prime[0] = 2; // El primer indice tiene 0
	prime[1] = 3;
	prime[2] = 5;
	prime[3] = 7;
	prime[4] = 11; // El ultimo elemento tiene indice 4 (longitud de matriz -1)

	std::cout << "El numero mas bajo es: " << prime[0] << '\n';
	std::cout << "La suma  de los primeros 5 numeros es: " << prime[0] + prime[1] + prime[2] + prime[3] + prime[4] << '\n'

	
	return 0;
}