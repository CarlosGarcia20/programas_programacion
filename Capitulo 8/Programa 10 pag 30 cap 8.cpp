#include <iostream>
enum class Color
{
	black,
	white,
	red,
	green,
	blue
};

void printColor(Color color)
{
	if (color == Color::black)
		std::cout << "black";
	else if (color == Color::white)
		std::cout << "white";
	else if (color == Color::red)
		std::cout << "red";
	else if (color == Color::green)
		std::cout << "green";
	else if (color == Color::blue)
		std::cout << "blue";
	else
		std::cout << "Desconocido";
}

int main()
{
	printColor(Color::green);

	return 0;
}