#include <iostream>
int getinteger()
{
	static bool s_isfirstcall{true};
	if (s_isfirstcall)
	{
		std::cout << "igrese un entero: ";
		s_isfirstcall = false;
	}
	else 
	{
		std::cout << "ingrese otro entero: ";
	}
	int i{};
	std::cin >> i;
	return i;
}

int main()
{
	int a{getinteger()};
	int b{getinteger()};
	std::cout << a << " + " << b <<" = "<<(a+b) << '\n';
	return 0; 
}