#include <iomanip> // para std::setpresicion ()
#include <iostream>

int main()
{
	std :: cout << std :: setprecision (16); // muestra 16 digitos de precisión
	std :: cout << 3.33333333333333333333333333333333333333f <<'\n'; //f sufujo significa float
	std :: cout << 3.3333333333333333333333333333333333333333 <<'\n'; //sin sufujo significa double
	return 0;
}