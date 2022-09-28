//Pantalla inicial de cajero automatico

#include <iostream>

int resp, op=1, num_cue1=45508780,, nip1=1234;
float saldo;
string nom1="Carlos", 

void deposito()
{
	float can_dep;
	std::cout<<"Ingrese la cantidad a depositar: "<<'\n';
	std::cin>>can_dep;
	std::cout<<"La cantidad a depositar es de "<< can_dep <<'\n';
	
	saldo=saldo+can_dep;
	std::cout<<"El saldo disponible es de "<<saldo<<'\n';
}

void retiro()
{
	float can_ret;
	std::cout<<"Ingrese la cantidad a retirar: "<<'\n';
	std::cin>>can_ret;
	std::cout<<"La cantidad a retirar es de "<< can_ret <<'\n';
	
	if (saldo>=can_ret) 
	{
		saldo=saldo-can_ret;
	}
	else
	{
		std::cout<<"No cuenta con suficiente saldo"<<'\n';
	}
	
	std::cout<<"Su saldo actual es de "<< saldo <<'\n';
}

void saldo_men()
{
	std::cout<<"Su saldo actual es de "<< saldo <<'\n';
}

void cambio()
{
	int nip, nip_new;
	std::cout<<"Ingrese el NIP por defecto: "<<'\n';
	std::cin>>nip;
	std::cout<<"Ingrese el nuevo NIP: "<<'\n';
	std::cin>>nip_new;
	
	
	
}

int main()
{
	int opc_men, user, nip;
	
	do
	{
		std::cout<<"Hola, Bienvenido A UAS ATM. EL NIP por defecto es '1234' "<<'\n';
		std::cout<<"---------------------------------------------------------------------------------------"<<'\n';
		std::cout<<"Deposito (1)"<<'\n';
		std::cout<<"Retiro (2)"<<'\n';
		std::cout<<"Consulta de saldo (3)"<<'\n';
		std::cout<<"Cambio de nip (4)"<<'\n';
		std::cout<<"Transferencia (5)"<<'\n';
		std::cout<<"Impresion ultimos 5 movimientos (6)"<<'\n';
		std::cin>>opc_men;


		switch (opc_men)
		{
			case 1: 
				system("cls");
				deposito();	
			break;
			
			case 2:
				system("cls");
				retiro();
			break;
			
			case 3:
				system("cls");
				saldo_men();
			break;
			
			case 4:
				system("cls");
				cambio();
			break;
			
			case 5:
				std::cout<<"Transferencia";
			break;
			
			case 6:
				std::cout<<"Impresion ultimos 5 movimientos";
			break;
		
			default:
				std::cout<<"Por favor seleccione una opcion valida"<<'\n';	
		}
		std::cout<<"Desea hacer alguna otra operacion? 1-Si -- 2-No"<<'\n';
		std::cin>>resp;
		system("cls");
		
	} while (op==resp);
	return 0;	
}

