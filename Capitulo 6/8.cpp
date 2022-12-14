#include <iostream>

int g_x{};

void dosomething()
{
	g_x = 3;
	std::cout << g_x << '\n';
}

int main()
{
	dosomething();
	std::cout << g_x << '\n';
	
	g_x = 5;
	std::cout << g_x<< '\n';
	return 0;
}