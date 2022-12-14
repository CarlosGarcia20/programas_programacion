#include <iostream>

int main ()
{
		std :: cout << "Ingrese un entero: ";
		int x {};
		std :: cin >> x;
		
		std :: cout << "Ingrese un entero: ";
		int y {};
		std :: cin >> y;
		
		if (x == y)
			std :: cout << x << " Igual " << y << '\n';
		if (x != y)
			std :: cout << x << " No es igual " << y << '\n';
		if (x > y)
			std :: cout << x << " Es mayor que " << y << '\n';
		if (x < y)
			std :: cout << x << " Es menor que " << y << '\n';
		if (x >= y)
			std :: cout << x << " Es mayor o igual que " << y << '\n';
		if (x <= y)
			std :: cout << x << " Es menor o igual que " << y << '\n';
		
		return 0;
}