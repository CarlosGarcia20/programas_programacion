#include "constants.h"
#include <iostream>
double getIntitialHeight()
{
	std::cout << "Ingrese la altura de la torre en metros: ";
	double intitialheight{}; std::cin >> intitialheight; return intitialheight;
}
double calculateheight(double initialHeight, int secondsPassed)
{
	double distanceFallen{ (myConstants::gravity * secondsPassed * secondsPassed) / 2.0 };
	double currentHeight{ initialHeight - distanceFallen }; return currentHeight;
}

void printHeight(double height, int secondspassed)
{
	if (height > 0.0) {
		std::cout << "En " << secondspassed << " Segundos, la pelota esta a la altura	de:\t" << height << " metros\n"; }
	else std::cout << "En " << secondspassed << " Segundos, la pelota esta en el suelo.\n";
}

void calculateAndPrintHeight(double initialheight, int secondspassed)

{double height{ calculateheight(initialheight,secondspassed) }; printHeight(height, secondspassed);}

int main()
{
	const double initialHeight{ getIntitialHeight() };
	calculateAndPrintHeight(initialHeight, 0);
	calculateAndPrintHeight(initialHeight, 1);
	calculateAndPrintHeight(initialHeight, 2);
	calculateAndPrintHeight(initialHeight, 3);
	calculateAndPrintHeight(initialHeight, 4);
	calculateAndPrintHeight(initialHeight, 5);

	return 0;
}
}
}
}
}
}