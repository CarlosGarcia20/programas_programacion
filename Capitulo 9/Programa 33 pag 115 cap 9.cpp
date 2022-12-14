#include <iostream>
//Lo veremos después. No se preocupe por ahora
// Solo lo usamos para engañar al compilador para que piense que p tiene un valor 
void foo (int *&)
{
        // p es una referencia al puntero
        // Estamos usando esto para engañar al compilador haciendole pensar que p podría modificarse,
        // Por lo que no se quejará de que p no esté inicializado
        // Esto no es algo que quieras hacer intencionalmente 
}

int main()
{
        int *p; // Crea un puntero no inicializado (que apunta a basura)
        foo (p); // Engañar al compilador para que piense que vamos a asignarle un valor valido

        
        std::cout << * p << '\n'; // Indirección a través del puntero de basura


}       return 0;