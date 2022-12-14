#include <iostream>

int main()
{
    int array[5]{9 , 7, 5, 3, 1};

    std::cout << *array << '\n';

    int *ptr{ array };
    std::cout << *ptr << '\n';
    
    return 0;
}