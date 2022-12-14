#include <iostream>

int main()
{
	int selection;

	do
	{
		std::cout << "Por favor seleccione una opcion: \n";
		std::cout << "1. Suma\n";
		std::cout << "2.Resta\n";
		std::cout << "3.Multiplicacion\n";
		std::cout << "4.Division\n;
		std::cin >> selection;



	} 
	while (selection != 1 && selection !=2 &&);
		selection != 3 && selection != 4;



		std::cout << "Selecciona una opcion: #" << selection << "\n";

		return 0;

}