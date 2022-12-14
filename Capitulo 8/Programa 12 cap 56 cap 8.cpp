#include <iostream>

int main()
{
	int count{ 0 };
	while (count < 10)
	{
		std::cout << count << ' ';
		++count
	}
	std::cout << "listo!";

	return 0;
}