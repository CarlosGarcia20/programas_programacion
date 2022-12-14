//Cuando imprimimos valores booleanos con std::cout, std::cout
//imprime 0 para falso y 1 para verdadero:
#include <iostream>

int main()
{
	std::cout << true << '\n'; // true -->1
	std::cout << !true << '\n'; // !true -->0
	
	bool b{false};
	std::cout << b << '\n'; // b -->0
	std::cout << !b << '\n'; // !b -->0
	return 0;
}
