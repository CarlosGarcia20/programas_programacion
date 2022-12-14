#include <cmath> // std :: abs
#include <algorithm> // std :: max

// Regresa true ssi la diferencia entre a y b está dentro del porcentaje epsilon del número mayor de a y b
bool approximatelyEqual (double a, double b, double epsilon)
{
		return (std :: abs (a - b) <= (std :: max (std :: abs (a), std :: abs(b)) * epsilon));
}

bool approximatelyEqualAbsRel (double a, double b, double absepsilon, double relepsilon)
{
		// Comprueba si los numeros están realmente cerca; es necesario cuando se comparan números cercanos a 0
		double diff { std :: abs (a - b) };
		if (diff <= absepsilon)
			return true;
		
		// De lo contrario, recurra al algoritmo de Knuth
		return (diff <= (std :: max(std :: abs (a), std :: abs (b)) * relepsilon));
		
}

int main ()
{
		std :: cout << approximatelyEqual (a, 1.0, 1e-8) << '\n';
		std :: cout << approximatelyEqual (a - 1.0, 0.0, 1e-8) << '\n';
		std :: cout << approximatelyEqualAbsRel (a - 1.0, 0.0, 1e-12, 1e-8) << '\n';
}