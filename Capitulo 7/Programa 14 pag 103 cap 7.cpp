#include <iostream>
struct Employee
{
	short id;
	int age;
	double wage;
};

void printinformation(Employee employee)
{
	std :: cout << "ID:     " << employee.id << '\n';
	std :: cout << "AGE:     " << employee.age << '\n';
	std :: cout << "WAGE:     " << employee.wage << '\n';
}

int main ()
{
	Employee joe { 14, 32, 24.15 };
	Employee maria{15, 28, 18.27 };
	
	printinformation(joe);
	
	std :: cout << '\n';
	
	printinformation(maria);
	
	return 0;
}