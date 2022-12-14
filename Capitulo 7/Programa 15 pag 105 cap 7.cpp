#include <iostream>
struct point3d
{
	double x;
	double y;
	double z;
};

point3d getzeropoint1()
{
	point3d temp{ 0.0, 0.0, 0.0 };
	return temp;
}

point3d getzeropoint2()
{
	return{ 0.0, 0.0, 0.0 };
}

point3d getzeropoint3()
{
	return {};
}
int main()
{
	point3d zero { getzeropointN() };
	
	if (zero.x == 0.0 && zero.y == 0.0 && zero.z == 0.0)
		std :: cout << "Este punto es cero\n";
	else
		std :: cout << "Este punto no es cero\n";
		
		
	return 0;
}			