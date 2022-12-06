#include <iostream>
#include <conio.h>
#include <string>
#include <string.h>

using namespace std;

//En este apartado se declaran variables globales para el buen funcionamiento del programa
//Descripcion: Numero de cuenta, nip, saldo de la cuenta
int cuentas[5][4];
int resp, op=1, opc_men, user, nip, num_cue, var, acum;
bool verifica = false;
string respu;
float can_dep, can_ret, can_tran, saldo, saldo_cuenta;

//Aqui se validan los nips para poder decidir si se entra al programa o no
int incio_cuentas()
{
	cout<<"Hola, bienvenido al cajero automatico"<<endl;
	do
	{
		cout<<"-------------------------------------------------------"<<endl;
		cout<<"Escriba su numero de cuenta: "<<endl;
		cin>>num_cue;
		for (int i=0;i<4;i++)
		{
			if (num_cue==cuentas[i][0])
			{
				verifica = true;
				var = num_cue;
			}
		}
		if (verifica == false)
		{
			cout<<"Numero de cuenta incorreta"<<endl;
		}
		else
		{
			while (acum!=1)
			{
				verifica = false;
				cout<<"Ingrese su NIP: "<<endl;
				cin>>nip;
				for (int i=0;i<4;i++)
				{
					if (nip==cuentas[i][1])
					{
						verifica = true;
					}
				}
				if (verifica == false)
				{
					cout<<"NIP incorrecto"<<endl;
				}
				else
				{
					cout<<"Bienvenido"<<endl;
					acum=acum+1;
				}	
			}
		}
	} while (verifica==false);
}

//Esta funcion permite al usuario ingresar dinero a la cuenta
void deposito()
{
	do
	{
		cout<<"Ingrese la cantidad a depositar: "<<endl;
		cin>>can_dep;
		cout<<"La cantidad a depositar es de "<<can_dep<<endl;
		saldo_cuenta = cuentas[var][2];
		saldo=saldo_cuenta+can_dep;
		cout<<"El saldo nuevo es de "<<saldo<<endl;
		cuentas[var][2]=saldo;
		
		cout<<"Desea hacer otro deposito"<<endl;
		cin>>respu;
	} while (respu=="s");	
}

//Esta funcion permite al usuario retirar dinero de la cuenta, pero tambien te limita si el dinero a retirar es mayor a lo que se tiene disponible
void retiro()
{
	cout<<"Ingrese la cantidad a retirar: "<<endl;
	cin>>can_ret;
	cout<<"La cantidad a retirar es de "<< can_ret <<endl;
	
	if (saldo>=can_ret) 
	{
		saldo=saldo-can_ret;
	}
	else
	{
		cout<<"No cuenta con suficiente saldo"<<endl;
	}
	cout<<"Su saldo actual es de "<<saldo<<endl;
}

//Esta funcion permite consultar el saldo disponible de la cuenta 
void saldo_men()
{
	cout<<"Su saldo actual es de "<<saldo<<endl;
}

//Esta funcion permite cambiar el nip por defecto que se tiene al iniciar el programa
void cambio()
{
	
}

//Esta funcion permite mandar dinero de una cuenta a otra 
void transferencias()
{
 
}


void menu_prin()
{
	incio_cuentas();
	cout<<"---------------------------------------------------------------------------------------"<<endl;
	cout<<"[1] Deposito"<<endl;
	cout<<"[2] Retiro"<<endl;
	cout<<"[3] Consulta de saldo"<<endl;
	cout<<"[4] Cambio de nip"<<endl;
	cout<<"[5] Transferencia"<<endl;
	cout<<"[6] Salir"<<endl;
	cout<<"Que desea hacer?"<<endl;
	cin>>opc_men;
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
	}
}

//Aqui inicia el programa principal, se utilizaron funciones y varios elementos del lenguaje para poder hacer posible su realizacion
int main()
{	
	//Llenado de la matriz
	cuentas[0][0]=41231;cuentas[0][1]=1234;cuentas[0][2]=2250;
	cuentas[1][0]=41232;cuentas[1][1]=1212;cuentas[1][2]=5000;
	cuentas[2][0]=41233;cuentas[2][1]=8789;cuentas[2][2]=800;
	
	menu_prin();

	return 0;	
}
