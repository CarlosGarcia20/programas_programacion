#include <iostream>
#include <math.h> // Para std::sqtr()

int main()
{
	double x;

tryagain: // Etiqueta de salto
	std::cout << "Ingrese un numero no negativo: ";
	std::cin >> x;

	if (x < 0.0)
		goto tryagain; // Aquí usamos goto

	std::cout << "La raiz cuadrada de: " << x << " es: " << std::sqrt(x) << std::endl;
	return 0;
}