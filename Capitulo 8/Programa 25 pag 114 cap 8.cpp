#include <iostream>
#include <cstdlib>
#include <ctime> // std::time()

int main()
{	/// establecer el valor de semilla inicial con el reloj del sistema	
	std::rand(static_cast<unsigned int>(std::time(nullptr_t)));

	for (int count{ 1 }; count <= 100; ++count)
	{
		std::cout << std::rand() << '\t';

		if (count % 5 == 0)
			std::cout << '\n';
	}

	return 0;
}