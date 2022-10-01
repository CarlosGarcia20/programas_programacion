#include <iostream>

//En este apartado se declaran variables globales para el buen funcionamiento del programa
int num_cue, cuenta1=415287, cuenta2=668254, cuenta3=787945;
int resp, op=1, opc_men, user, nip, nip_nuevo, nip1=1234, nip2=1212, nip3=8789;
float can_dep, can_ret, can_tran, saldo, saldo_cue1=2250, saldo_cue2=5000, saldo_cue3=800;

//Aqui se validan los nips para poder decidir si se entra al programa o n
int nips()
{
	if (nip==nip1 || nip==nip2 || nip==nip3) 
	{
		std::cout<<"NIP correcto."<<'\n';
	}
	else 
	{
		std::cout<<"NIP incorrecto."<<'\n';
		exit(0);
	}
}

//Esta funcion permite al usuario ingresar dinero a la cuenta
void deposito()
{
	switch (nip)
	{
		case 1234:
			std::cout<<"Ingrese la cantidad a depositar: "<<'\n';
			std::cin>>can_dep;
			std::cout<<"La cantidad a depositar es de "<< can_dep <<'\n';
			
			saldo_cue1=saldo_cue1+can_dep;
			std::cout<<"El saldo disponible es de "<<saldo_cue1<<'\n';
		break;
		
		case 1212:
			std::cout<<"Ingrese la cantidad a depositar: "<<'\n';
			std::cin>>can_dep;
			std::cout<<"La cantidad a depositar es de "<< can_dep <<'\n';
			
			saldo_cue2=saldo_cue2+can_dep;
			std::cout<<"El saldo disponible es de "<<saldo_cue2<<'\n';
		break;
		
		case 8789:
			std::cout<<"Ingrese la cantidad a depositar: "<<'\n';
			std::cin>>can_dep;
			std::cout<<"La cantidad a depositar es de "<< can_dep <<'\n';
			
			saldo_cue3=saldo_cue3+can_dep;
			std::cout<<"El saldo disponible es de "<<saldo_cue3<<'\n';
		break;
	}
	
}

//Esta funcion permite al usuario retirar dinero de la cuenta, pero tambien te limita si el dinero a retirar es mayor a lo que se tiene disponible
void retiro()
{
	switch (nip)
	{
		case 1234:
			std::cout<<"Ingrese la cantidad a retirar: "<<'\n';
			std::cin>>can_ret;
			std::cout<<"La cantidad a retirar es de "<< can_ret <<'\n';
			
			if (saldo_cue1>=can_ret) 
			{
				saldo_cue1=saldo_cue1-can_ret;
			}
			else
			{
				std::cout<<"No cuenta con suficiente saldo"<<'\n';
			}
			
			std::cout<<"Su saldo actual es de "<<saldo_cue1<<'\n';
		break;
			
		case 1212:
			std::cout<<"Ingrese la cantidad a retirar: "<<'\n';
			std::cin>>can_ret;
			std::cout<<"La cantidad a retirar es de "<< can_ret <<'\n';
			
			if (saldo_cue2>=can_ret) 
			{
				saldo_cue2=saldo_cue2-can_ret;
			}
			else
			{
				std::cout<<"No cuenta con suficiente saldo"<<'\n';
			}
			
			std::cout<<"Su saldo actual es de "<<saldo_cue2<<'\n';
		break;
		
		case 8789:
			std::cout<<"Ingrese la cantidad a retirar: "<<'\n';
			std::cin>>can_ret;
			std::cout<<"La cantidad a retirar es de "<< can_ret <<'\n';
			
			if (saldo_cue3>=can_ret) 
			{
				saldo_cue3=saldo_cue3-can_ret;
			}
			else
			{
				std::cout<<"No cuenta con suficiente saldo"<<'\n';
			}
			
			std::cout<<"Su saldo actual es de "<<saldo_cue3<<'\n';
		break;
	}
}

//Esta funcion permite consultar el saldo disponible de la cuenta 
void saldo_men()
{
	switch (nip)
	{
		case 1234: 
			std::cout<<"Su saldo actual es de "<< saldo_cue1 <<'\n';
		break;
		
		case 1212:
			std::cout<<"Su saldo actual es de "<<saldo_cue2<<'\n';
		break;
		
		case 8789:
			std::cout<<"Su saldo actual es de "<<saldo_cue3<<'\n';
		break;
	}
}

//Esta funcion permite cambiar el nip por defecto que se tiene al iniciar el programa
void cambio()
{
	switch (nip)
	{
		case 1234:
			std::cout<<"Ingrese su NIP: "<<'\n';
			std::cin>>nip;
			do
			{
				std::cout<<"El NIP es incorrecto. Introduzcalo de nuevo: "<<'\n';
				std::cin>>nip;
			} while (nip!=nip1);
			
			system("cls");
			std::cout<<"Ingrese el nuevo NIP: "<<'\n';
			std::cin>>nip_nuevo;
			nip1=nip_nuevo;
		break;
			
		case 1212:
			std::cout<<"Ingrese su NIP: "<<'\n';
			std::cin>>nip;
			do
			{
				std::cout<<"El NIP es incorrecto. Introduzcalo de nuevo: "<<'\n';
				std::cin>>nip;
			} while (nip!=nip2);
			
			system("cls");
			std::cout<<"Ingrese el nuevo NIP: "<<'\n';
			std::cin>>nip_nuevo;
			nip2=nip_nuevo;
		break;	
		
		case 8789:
			std::cout<<"Ingrese su NIP: "<<'\n';
			std::cin>>nip;
			do
			{
				std::cout<<"El NIP es incorrecto. Introduzcalo de nuevo: "<<'\n';
				std::cin>>nip;
			} while (nip!=nip3);
			
			system("cls");
			std::cout<<"Ingrese el nuevo NIP: "<<'\n';
			std::cin>>nip_nuevo;
			nip3=nip_nuevo;
		break;		
	}
}

//Esta funcion permite mandar dinero de una cuenta a otra 
void transferencias()
{
	switch (nip)
	{
		case 1234:
			std::cout<<"Ingrese el numero de cuenta a transferir: "<<'\n';
			std::cin>>num_cue;
			if (num_cue==cuenta2 || num_cue==cuenta3)
			{
				std::cout<<"Ingrese la cantidad de dinero a transferir: "<<'\n';
				std::cin>>can_tran;
				if(can_tran>saldo_cue1)
				{
					do
					{
						std::cout<<"No tienes la cantidad de dinero suficiente para transferir. Tu saldo actual es de "<<saldo_cue1<<'\n';
						std::cout<<"Ingrese la cantidad de dinero a transferir: "<<'\n';
						std::cin>>can_tran;
					} while (can_tran>saldo_cue1);
					
				}
				saldo_cue1=saldo_cue1-can_tran;
				std::cout<<"La transferencia ha sido exitosa. Tu saldo actual es de "<<saldo_cue1<<'\n';
			}
			else
			{
				std::cout<<"Numero de cuenta incorrecta. Ingrese un numero de cuenta existente"<<'\n';
			}
		break;
		
		case 1212:
			std::cout<<"Ingrese el numero de cuenta a transferir: "<<'\n';
			std::cin>>num_cue;
			if (num_cue==cuenta1 || num_cue==cuenta3)
			{
				std::cout<<"Ingrese la cantidad de dinero a transferir: "<<'\n';
				std::cin>>can_tran;
				if(can_tran>saldo_cue2)
				{
					do
					{
						std::cout<<"No tienes la cantidad de dinero suficiente para transferir. Tu saldo actual es de "<<saldo_cue2<<'\n';
						std::cout<<"Ingrese la cantidad de dinero a transferir: "<<'\n';
						std::cin>>can_tran;
					} while (can_tran>saldo_cue2);
					
				}
				saldo_cue2=saldo_cue2-can_tran;
				std::cout<<"La transferencia ha sido exitosa. Tu saldo actual es de "<<saldo_cue2<<'\n';
			}
			else
			{
				std::cout<<"Numero de cuenta incorrecta. Ingrese un numero de cuenta existente"<<'\n';
			}
		break;
		
		
		case 8789:
			std::cout<<"Ingrese el numero de cuenta a transferir: "<<'\n';
			std::cin>>num_cue;
			if (num_cue==cuenta1 || num_cue==cuenta2)
			{
				std::cout<<"Ingrese la cantidad de dinero a transferir: "<<'\n';
				std::cin>>can_tran;
				if(can_tran>saldo_cue3)
				{
					do
					{
						std::cout<<"No tienes la cantidad de dinero suficiente para transferir. Tu saldo actual es de "<<saldo_cue3<<'\n';
						std::cout<<"Ingrese la cantidad de dinero a transferir: "<<'\n';
						std::cin>>can_tran;
					} while (can_tran>saldo_cue3);
					
				}
				saldo_cue3=saldo_cue3-can_tran;
				std::cout<<"La transferencia ha sido exitosa. Tu saldo actual es de "<<saldo_cue3<<'\n';
			}
			else
			{
				std::cout<<"Numero de cuenta incorrecta. Ingrese un numero de cuenta existente"<<'\n';
			}
		break;
	}
	
}

//Aqui inicia el programa principal, se utilizaron funciones y varios elementos del lenguaje para poder hacer posible su realizacion
int main()
{	
	std::cout<<"Hola, Bienvenido A UAS ATM. Escriba su NIP a continuacion: "<<'\n';
	std::cin>>nip;
	nips();
	do
	{
		std::cout<<"---------------------------------------------------------------------------------------"<<'\n';
		std::cout<<"Deposito\t\t [1]"<<'\n';
		std::cout<<"Retiro\t\t\t [2]"<<'\n';
		std::cout<<"Consulta de saldo\t [3]"<<'\n';
		std::cout<<"Cambio de nip\t\t [4]"<<'\n';
		std::cout<<"Transferencia\t\t [5]"<<'\n';
		std::cout<<"Salir \t\t\t [6]"<<'\n';
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
				system("cls");
				transferencias();
			break;
			
			case 6:
				std::cout<<"Saliendo...";
				exit(0);
		
			default:
				std::cout<<"Por favor seleccione una opcion valida"<<'\n';	
		}
		std::cout<<"Desea hacer alguna otra operacion? 1-Si -- 2-No"<<'\n';
		std::cin>>resp;
		system("cls");
		
	}while (op==resp);
	return 0;	
}
