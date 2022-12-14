#include <iostream>

int main ()
{
	enum class color
	{
		red,
		blue
	};
	
	color color{ color::blue };
	
	std :: cout << color; //No funciona porque no hay una conversión automatica
	std :: cout << static_cast<int>(color);//Imprimirá 1
	
	return 0;