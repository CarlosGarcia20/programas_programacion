#include <iostream>

int main ()
{
	bool inbigClassroom { false };
	const int classSize { inbigClassroom ? 30 : 20 };
	std :: cout << "El numero de alumnos de la clase es: " << classSize;
	
	return 0;	
}