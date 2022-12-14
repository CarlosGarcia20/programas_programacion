#include <iostream>

int main ()
{
		int x { 5 };
		int y { 7 };
		
		if (! (x > y))
			std :: cout << " X no es mayor que y\n";
		else
			std :: cout << " X es mayor que y\n";
		
		return 0;
}