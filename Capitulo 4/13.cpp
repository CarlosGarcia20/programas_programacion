#include <iostream>

int main()
{
	double zero {0.0};
	double posinf { 5.0 / zero }; // infinito positivo
	std::cout << posinf << '\n';
	
	double neginf { -5.0 / zero }; // infinito negativo
	std::cout << neginf << '\n';
	
	double nan { zero / zero }; // no es un número (matematico inválido)
	std::cout << nan << '\n';
	
	return 0;
}