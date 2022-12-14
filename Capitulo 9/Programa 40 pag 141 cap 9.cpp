#include <iostream>

void changeArray(int *ptr)
{
    *ptr = 5;
}

int main()
{
    int array[]{ 1, 1, 2, 3, 5, 8, 13, 21 };
    std::cout "El elemento 0 tiene el valor: " << array[0] << '\n';

    changeArray(array);

    std::cout << "El elemento 0 tiene el valor: " << array[0] << '\n';
        
        return 0;
}