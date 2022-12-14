#include <iostream>
#include <string>

int main()
{
	std :: string str{ "El arroz se esta cocinando" };
	
	str.erase(4, 11);
	
	std :: cout << str << '\n';
	
	return 0;
	
	// La función de erase en c++ se usa para eliminar los elementos de un contenedor desde la posición o un rango especificado en este caso estariamos borrando el rango de 4 a 11
}