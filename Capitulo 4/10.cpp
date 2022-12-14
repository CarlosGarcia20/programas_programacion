#include <iomanip> // para std::setpresicion ()
#include <iostream>

int main()
{
	float f { 123456789.0f }; //f tiene 10 digitos significativos
	std::cout << std::setprecision(9); //se establece la precision a 9
	std::cout << f << '\n';
	return 0;
}