#include <iostream>

int main ()
{
	enum class color
	{
		red,
		blue
	};
	
	color color{ color::red };
	
	if (color == color::red) // es correcto
		std :: cout << "El color es rojo\n";
	else if (color == color::blue)
		std :: cout << "El color es azul\n";
		
	return 0;
}