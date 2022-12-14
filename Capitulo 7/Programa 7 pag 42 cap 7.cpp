#include <iostream>

int getuserinput()
{
	int i{};
	std :: cin >> i;
	return i;
}

int main ()
{
	std :: cout << "¿Cuántas manzanas te comiste hoy? \n";
	
	if (int iAppleEaten{ getuserinput() }; iAppleEaten <= 2)
	{
		std :: cout << "Yummy\n";
	}
	else
	{
	   std :: cout << iAppleEaten << " Son muchas|\n";
	}
	
	return 0;
}