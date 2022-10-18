#include <iostream>

#define ENABLE_DEBUG //comenta para deshabilitar la depuración

int getUserInput()
{
	#ifdef ENABLE _DEBUG
		std::cerr<<"Llamada a getUserInput () \n";
	#endif
		std::cout<<"Ingrese un numero: ";
		int x{};
		std::cin>>x;
		return x;
}

int main()
{
	#ifdef ENABLE _DEBUG
		std::cerr<<"Llamada a main () \n";
	#endif
	int x{getUserInput() };
	std::cout<<"Tu ingresaste: "<<x;
}
