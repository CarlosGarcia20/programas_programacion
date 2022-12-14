#include <iostream>

int main()
{
	double batteryLifeInHours[3]{}; // Almacena 3 doubles
	batteryLifeInHours[0] = 2.0;
	batteryLifeInHours[1] = 3.0;
	batteryLifeInHours[2] = 4.3;

	std::cout << "La duracion media de la bateria es: " <<
	(batteryLifeInHours[0] + batteryLifeInHours[1] + batteryLifeInHours[2]) / 3.0 << "hora(s)\n";

	return 0;
}