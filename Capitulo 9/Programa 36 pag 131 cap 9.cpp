#include <iostream>

int main()
{
    int array[5]{9 , 7, 5, 3, 1};

    std::cout << "Element 0 has address: " << &array[0] << '\n';

    std::cout << "La matriz decae para almacenar una dirección de memoria: " << array << '\n';
    
    return 0;
}