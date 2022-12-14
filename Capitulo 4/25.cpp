#include <iostream>

bool isAllowedtotakeFunRide()
{
	std::cout << "¿Que tan alto eres? (cm)\n";
	
	double height {};
	std::cin >> height;
	
	if (height > 140)
		return true;
	else
		return false;
}

int main()
{
	if (isAllowedtotakeFunRide())
		std::cout << "Diviertete! \n";
	else
		std::cout << "Lo siento, eres demasidad@ pequeñ@ \n";
	
	return 0;
}