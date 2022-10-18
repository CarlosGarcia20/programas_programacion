#include <iostream>

int getUserInput()
{
	std::cerr<<"Llamada a getUserInput() \n";
	std::cout<<"Ingrese un numero: ";
	int x{};
	std::cin>>x;
	return x;
}

int main()
{
	std::cerr<<"Llamada a main() \n";
	int x{getUserInput() };
	std::cout<<"Usted ingreso: "<<x;
	
	return 0;
}
