#include <cmath> // Para std :: abs ()

// Epsilon es un valor absoluto
bool isAlmostEqual (double a, double b, double epsilon)
{
		// Si la distancia entre a b es menor que epsilon, entonces a y b están "lo suficiente cerca"
		return std::abs (a - b) <= epsilon;
}