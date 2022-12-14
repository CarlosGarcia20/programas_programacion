// Si desea que std::cout imprima “true" o “false" en lugar de 0 o 1,
// puede usar std::boolalpha. Ejemplo:
#include <iostream>

int main()
{
	std::cout << true << '\n'; 
	std::cout << false << '\n'; 
	
	std::cout << std::boolalpha; //imprime bools como true or false
	
	std::cout << true << '\n'; 
	std::cout << false << '\n'; 
	return 0;
}
