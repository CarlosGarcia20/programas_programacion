#include <iostream>


 void doB ()
 {
 	std :: cout<<"En doB () \n";
 }
 
 void doA ()
 {
 	std :: cout<<"Iniciando doA () \n";
 	doB ();
 	std :: cout<<"Finalizando doA () \n";
 }
 
 int main ()
 {
 	std :: cout<<"Iniciando main () \n"; 
 	doA ();
 	std :: cout<<"Finalizando main () \n";
 	
 	return 0;
	 
 }
