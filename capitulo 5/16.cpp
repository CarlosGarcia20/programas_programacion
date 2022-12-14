#include <cmath> // std :: abs
#include <algorithm> // std :: max

// Regresa true ssi la diferencia entre a y b está dentro del porcentaje epsilon del número mayor de a y b
bool approximatelyEqual (double a, double b, double epsilon)
{
		return (std :: abs (a - b) <= (std :: max (std :: abs(a), std :: abs (b)) * epsilon));
}

int main ()
{
		// a está muy cerca de 1.0, pero tiene errores de redondeo, por lo que es un poco menor que 1.0
		double a { 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 };
		
		// Primero, comparemos a (casi 1.0) con 1.0.
		std :: cout << approximatelyEqual (a, 1.0, 1e-8) << '\n',
		
		// Segundo, comparemos a 1.0 (casi 0.0) con 0.0
		std :: cout << approximatelyEqual (a - 1.0, 0.0, 1e-8) << '\n';
		
		return 0;
}