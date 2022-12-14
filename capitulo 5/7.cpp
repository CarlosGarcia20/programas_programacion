#include <iostream>

int main ()
{
		int x { 5 };
		int y { 5 };
		std :: cout << x << ' ' << y << '\n';
		std :: cout << ++x << ' ' << --y << '\n'; // Prefix
		std :: cout << x << ' ' << y << '\n';
		std :: cout << x++ << ' ' << y-- << '\n'; // Postfix
		std :: cout << x << ' ' << y << '\n';
		
		return 0;
}