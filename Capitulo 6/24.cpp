#include <iostream>
#include <typeinfo>

int main()
{
	short d{4};
	short s{2};
	std::cout <<typeid (d+s).name() << ' '<< d + s << '\n';
	
	return 0; 
}