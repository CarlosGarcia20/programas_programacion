#include <iostream>

int add(int x, int y);

int main()
{
	std::cout<<"La suma de 3 y 4 es: "<<add(3, 4)<<'\n';
	return 0;
}

int add(int x, int y)
{
	return x+y;
}


