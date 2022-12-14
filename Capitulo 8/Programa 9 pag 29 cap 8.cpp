#include <iostream>
#include <string>

int main()

	std::cout << "Nombre: ";
	std::cin >> firstname;

	std::cout << "Apeliido: ";
	std::cin >> lastname;

	if (std::string fullname{ firstname + ' ' + lastname }; fullname.length() > 20)
	{
		std :: cout	<< ' " ' << fullname <<	"\"es demasiado largo!\n;
	}
	else
	{
		std::cout << "Tu nombre es: " << fullname << '\n';
	}

	// Aquí ya no se ocupa la variable @fullname

	return 0;
}