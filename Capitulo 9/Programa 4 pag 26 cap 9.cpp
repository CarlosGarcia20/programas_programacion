#include <iostream>
void passValue(int value) // El valor es una copia del argumento
{
	value = 99; // Así que cambiarlo aquí no cambiará el valor 
}
void passArray(int prime[5]) // prime es el arreglo real
{
	prime[0] = 11; // Así que cambiarlo aquí cambirá el argumento original
	prime[1] = 7;
	prime[2] = 5;
	prime[3] = 3;
	prime[4] = 2;
}
int main
{
	int value{ 1 };
	std::cout << "antes de Passvalue: " << value << '\n';
	passValue(value);
	std::cout << "despues de Passvalue: " << value << '\n';

	int prime[5]{ 2, 3, 5, 7, 11 };
	std::cout << "antes de PassArray: " << prime[0] << " " << prime[1] << " " << prime[2] << " " << prime[3] << " " << prime[4] << '\n';
	passArray(prime);
	std::cout << "despues de PassArray: " << prime[0] << " " << prime[2] << " " << prime[3] << " " << prime[4] << '\n';

	return 0;
}