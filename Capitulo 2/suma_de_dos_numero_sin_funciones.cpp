#include <iostream>

int main()
{
	int x{};
	std::cout<<"Ingrese un entero: ";
	std::cin>>x;
	
	int y{};
	std::cout<<"Ingrese un entero: ";
	std::cin>>y;
	
	std::cout<<x<< " + "<<y<< " = "<< x+y<<'\n';
	
	return 0;
}
