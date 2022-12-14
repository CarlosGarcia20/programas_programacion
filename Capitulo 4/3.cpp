#include <iostream>

int main()
{
	unsigned short x {65535}; //Mayor valor posible para unsigned short de 16 bits
	std::cout << "x era: " << x <<'\n';
	
	x = 65536; // 65536 está fuera de nuestro rango
	std::cout << "x es ahora: " << x << '\n';
	
	x = 65537; // 65536 está fuera de nuestro rango
	std::cout << "x es ahora: " << x << '\n';
	
}