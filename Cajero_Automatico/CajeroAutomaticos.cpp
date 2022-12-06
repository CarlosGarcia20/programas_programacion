#include <iostream>
#include <conio.h>
#include <string>
#include <string.h>

using namespace std;

//En este apartado se declaran variables globales para el buen funcionamiento del programa
//Descripcion: Numero de cuenta, nip, saldo de la cuenta
float cuentas[5][4];
int mov[5];
int mov_dep, mov_ret, mov_con, mov_tran, mov_cam;
int id=2;
int resp, op=1, opc_men, user, nip, num_cue, num_cuetrans;
int var, verifica=1, acum, opor, siempre;
string respu;
float can_dep, can_ret, can_tran, saldo, saldo_cuenta, saldo_ret, saldo_tran;
float saldo_cuetran;

//Aqui se validan los nips para poder decidir si se entra al programa o no
int inicio_cuentas()
{
	do
	{
		cout<<"Escriba su numero de cuenta: "<<endl;
		cin>>num_cue;
		if (num_cue>id || num_cue<0)
		{
			cout<<"Ingrese un numero de cuenta correcto"<<endl;
			var=1;
		}	

		else
		{
			var=0;
			do
			{
				cout<<"Ingrese su NIP: "<<endl;
				cin>>nip;
				if (nip==cuentas[num_cue][1])
				{
					verifica = 0;
				}
				if (verifica == 0)
				{
					cout<<"Bienvenido"<<endl;
				}
				else
				{
					cout<<"NIP incorrecto"<<endl;	
				}
			} while (verifica==1);
		}
	}while(var==1);	
}

//Esta funcion permite al usuario ingresar dinero a la cuenta
void deposito()
{
	cout<<"Ingrese la cantidad a depositar: "<<endl;
	cin>>can_dep;
	cout<<"La cantidad a depositar es de "<<can_dep<<endl;
	saldo_cuenta = cuentas[num_cue][2];
	saldo=saldo_cuenta+can_dep;
	cout<<"El saldo nuevo es de "<<saldo<<endl;
	cuentas[num_cue][2]=saldo;
}

//Esta funcion permite al usuario retirar dinero de la cuenta, pero tambien te limita si el dinero a retirar es mayor a lo que se tiene disponible
void retiro()
{
	cout<<"Ingrese la cantidad a retirar: "<<endl;
	cin>>can_ret;
	cout<<"La cantidad a retirar es de "<< can_ret<<endl;
	saldo_cuenta = cuentas[num_cue][2];
	if (saldo_cuenta>can_ret) 
	{
		saldo_ret=saldo_cuenta-can_ret;
		cuentas[num_cue][2]=saldo_ret;
		cout<<"Su saldo actual es de "<<saldo_ret<<endl;
		mov_ret=mov_ret+1;
	}
	else
	{
		cout<<"No cuenta con suficiente saldo "<<endl;
		cout<<"Su saldo actual es de "<<saldo_cuenta<<endl;
	}
}

//Esta funcion permite consultar el saldo disponible de la cuenta 
void saldo_men()
{
	cout<<"Su saldo actual es de "<<cuentas[num_cue][2]<<endl;
}

//Esta funcion permite cambiar el nip por defecto que se tiene al iniciar el programa
void cambio()
{
	system("cls");
	cout<<"Ingrese su NIP"<<endl;
	cin>>nip;
	if (nip==cuentas[num_cue][1])
	{
		cout<<"Ingrese el nuevo NIP: "<<endl;
		int nip_nue;
		cin>>nip_nue;
		cuentas[num_cue][1]=nip_nue;
		cout<<"Su NIP ha sido cambiado"<<endl;
		mov_cam=mov_cam+1;
	}
	else
	{
		cout<<"NIP incorrecto"<<endl;	
	}
}

//Esta funcion permite mandar dinero de una cuenta a otra 
void transferencias()
{
	cout<<"Digite la cuenta a transferir: "<<endl;
 	cin>>num_cuetrans;
	if (num_cuetrans>id || num_cuetrans<0 || num_cuetrans==num_cue)
	{
		cout<<"Ingrese un numero de cuenta correcto"<<endl;
	}
	else
	{
		cout<<"Digite la cantidad a transferir: "<<endl;
	 	cin>>can_tran;
	 	saldo_cuenta = cuentas[num_cue][2];
		if (saldo_cuenta>can_tran) 
		{
			saldo_tran=saldo_cuenta-can_tran;
			cuentas[num_cue][2]=saldo_tran;
			cout<<"Su saldo actual es de "<<saldo_tran<<endl;
			cout<<"La transferencia se ha realizado con exito"<<endl;
			saldo_cuetran=cuentas[num_cuetrans][2];
			saldo_cuetran=saldo_cuetran+can_tran;
			cuentas[num_cuetrans][2]=saldo_cuetran;
			mov_tran=mov_tran+1;
		}
		else
		{
			cout<<"No cuenta con suficiente saldo "<<endl;
			cout<<"Su saldo actual es de "<<saldo_cuenta<<endl;
		}	
	}	
}

void movimientos()
{
	cout<<"-- U L T I M O S  5  M O V I M I E N T O S --"<<endl;
	
}

int menu()
{
	do
	{
		cout<<"-------------------------------------------------------"<<endl;
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
				mov_dep=mov_dep+1;
			break;
			
			case 2:
				system("cls");
				retiro();
			break;
			
			case 3:
				system("cls");
				saldo_men();
				mov_con=mov_con+1;
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
	} while (opc_men!=6);
}

//Aqui inicia el programa principal, se utilizaron funciones y varios elementos del lenguaje para poder hacer posible su realizacion
int main()
{	
	//Llenado de la matriz
	cuentas[0][0]=0;cuentas[0][1]=1234;cuentas[0][2]=2250;
	cuentas[1][0]=1;cuentas[1][1]=1212;cuentas[1][2]=5000;
	cuentas[2][0]=2;cuentas[2][1]=8789;cuentas[2][2]=800;
	
	
	do
	{
		system("cls");
		cout<<"Bienvenido al cajero automatico"<<endl;
		cout<<"-------------------------------------------------------"<<endl;
		inicio_cuentas();
		menu();
		siempre=1;
	} while (siempre==1);
		
	return 0;	
}
