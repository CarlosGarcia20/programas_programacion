#include <iostream>

void addandprint(auto x, auto y)
{
	std::cout << x | y;
}

int main()
{
	addandprint(2,3);
	addandprint(4.5,6.7);
}