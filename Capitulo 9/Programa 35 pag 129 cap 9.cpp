#include <iostream>
#include <cstddef> // std::nullptr_t

void doSomething(std::nullptr_t ptr)   
{
    std::cout << " dentro de doSomething()\n";
}


int main()
{
    doSomething(nullptr);
    
    return 0;
}