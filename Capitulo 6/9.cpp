#include <iostream>

const int g_x;
constexpr int g_w;

const int g_y {1};
constexpr int g_z {2};

void dosomething()
{
	std::cout << g_y << '\n';
	std::cout << g_z << '\n';
}

int main()
{
	dosomething();
	std::cout << g_y << '\n';
	std::cout << g_z << '\n';
	
	return 0;
}