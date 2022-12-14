#include <iostream>

int main ()
{
		int x { 1 };
		int y { 2 };
			
		std :: cout << (++x, ++y); // Incrementa x (y) y, luego evalúa el de la derecha
		
		return 0;
}