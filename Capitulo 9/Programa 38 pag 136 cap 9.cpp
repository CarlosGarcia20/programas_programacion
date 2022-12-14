#include <iostream>

int main()
{
    int array[5]{9 , 7, 5, 3, 1};

    std::cout << sizeof(array) << '\n';

        int *ptr{ array };
        std::cout << sizeof(ptr) <<  '\n';
    
    return 0;
}