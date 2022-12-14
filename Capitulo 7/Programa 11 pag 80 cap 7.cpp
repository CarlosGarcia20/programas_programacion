#include <iostream>

int main ()
{
	enum color
	{
		color_red,
		color_blue
	};
	
	enum fruit 
	{
		fruit_banana,
		fruit_apple
	};
	
	color color{ color_red };
	fruit fruit{ fruit_banana };
	
	if (color == fruit ) // El compilador comparará a y b como int
		std :: cout << "color y fruta son iguales\n"; // Y son iguales !
	else
		std :: cout << "color y fruta no son iguales\n";
		
		
	return 0;	
}