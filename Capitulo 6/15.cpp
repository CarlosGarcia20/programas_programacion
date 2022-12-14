#include <iostream>
namespace constants
{
	constexpr double gravity {9.8};
}

double instantvelocity (int time)
{
	return constants::gravity * time;
}

int main()
{
	std::cout <<instantvelocity(5);
}