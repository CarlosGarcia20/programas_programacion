#include <iostream>
#include <conio.h>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <iomanip>

using namespace std;

//En este apartado se declaran variables globales para el buen funcionamiento del programa
//Descripcion: Numero de cuenta, nip, saldo de la cuenta
float cuentas[5][4];
int id=2;
//En esta matriz se guardan los movimientos de cada cuenta
string mov[5][5];
int m[5];
int mov_dep, mov_ret, mov_con, mov_tran, mov_cam;
int resp, op=1, opc_men, user, nip,	nip_nue, num_cue, num_cuetrans, var=1, acum, opor, siempre=1, temp_temp;
string respu, temp_nip;
bool verifica=false;
float can_dep, can_ret, can_tran, saldo, saldo_cuenta, saldo_ret, saldo_tran, saldo_cuetran;
ofstream archivo;

//Aqui se validan los nips para poder decidir si se entra al programa o no
int inicio_cuentas()
{
	cout<<"Bienvenido al cajero automatico"<<endl;
	do
	{
		cout<<"-------------------------------------------------------"<<endl;
		cout<<"Escriba su numero de cuenta: "<<endl;
		cin>>num_cue;
		while (num_cue>id || num_cue<0)												//Aqui se valida si la cuenta ha ingresar esta registrada en la matriz, si no marcara error y se le pedira al usuario ingresarla de nuevo
		{
			cout<<"Ingrese un numero de cuenta correcto"<<endl;
			cin>>num_cue;
		}
		int temp = cuentas[num_cue][1];												//Variable temporal que guarda el valor del nip
		do
		{
			var=0;																	//Se le da el valor de 0 para que pueda salirse del ciclo principal
			cout<<"Ingrese su NIP: "<<endl;
			cin>>nip;
			while (nip!=temp)														//Evalua si el nip introducido es igual al que se encuentra registrado
			{
				cout<<"NIP incorrecto"<<endl;
				cin>>nip;	
			}
			if (nip==temp)															//Evaluacion valida y procede a acceder al sistema
			{
				verifica = true;
				system("cls");
			}
		} while (verifica==false);													//Ciclo que sirve para que permita seguir introduciendo el nip hasta 3 intentos
	}while(var==1);	
}

//Esta funcion permite al usuario ingresar dinero a la cuenta
void deposito()
{
		archivo.open("Depositos.txt", ios::app);								//Se crea el archivo de texto para guardar los movimientos del deposito 
	do
	{
		cout<<"Ingrese la cantidad a depositar: "<<endl;
		cin>>can_dep;
		if (can_dep<0 || can_dep==0)											//Se valida si la cantidad a retirar es negativa o es 0. Marcara error
		{
			cout<<"Error. No se puede depositar esa cantidad"<<endl;
				archivo<<"El numero de cuenta es "<<num_cue<<endl;
				archivo<<"La cantidad a depositar es de "<<can_dep<<endl;
				archivo<<"Error. No es posible depositar esa cantidad"<<endl;
		}
		else																	//Si la validacion anterior resulta ser falsa se proseguira con el programa
		{
			cout<<"La cantidad a depositar es de "<<can_dep<<endl;
				archivo<<"El numero de cuenta es "<<num_cue<<endl;
				archivo<<"La cantidad a depositar es de "<<can_dep<<endl;		//Se guarda el dato a depositar en el archivo de texto
			saldo_cuenta = cuentas[num_cue][2];
			saldo=saldo_cuenta+can_dep;
			cout<<"El saldo nuevo es de "<<saldo<<endl;
				archivo<<"El saldo nuevo es de "<<saldo<<endl;					//Se guarda el nuevo saldo disponible en el archivo de texto
			cuentas[num_cue][2]=saldo;
			m[num_cue]=m[num_cue]+1;
			mov[num_cue][m[num_cue]].append("Deposito: ");						//Este apartado es para poder registrar los movimientos
			string temp=to_string(can_dep);
			mov[num_cue][m[num_cue]].append(temp);
			mov[num_cue][m[num_cue]].append("\n");
		}
	}while (can_dep<0 || can_dep==0);
		archivo<<"----------------------------------------------------------------"<<endl;
		archivo.close();												//Se cierra el archivo de texto
}

//Esta funcion permite al usuario retirar dinero de la cuenta, pero tambien te limita si el dinero a retirar es mayor a lo que se tiene disponible
void retiro()
{
		archivo.open("Retiros.txt", ios::app);
	do
	{
		cout<<"Ingrese la cantidad a retirar: "<<endl;
		cin>>can_ret;
		if (can_ret<0 || can_ret==0)																	//Se valida si la cantidad a retirar son numeros negativos o si es igual a 0, si es asi marcara error
		{
			cout<<"Error. No se pueden retirar esa cantidad"<<endl;
				archivo<<"La cantidad a retirar "<<can_ret<<" no es posible retirarla"<<endl;
		}
		else																							//Si la validacion anterior es falsa se procedera a mostrarle al usuario cuanto es la cantidad que retirara
		{
			cout<<"La cantidad a retirar es de "<< can_ret<<endl;
				archivo<<"El numero de cuenta es "<<num_cue<<endl;										//Aqui se guardan los datos de la cuenta que esta retirando asi como la cantidad que se va a retirar
				archivo<<"La cantidad a retirar es de "<< can_ret<<endl;
			saldo_cuenta = cuentas[num_cue][2];
			if (saldo_cuenta>can_ret || saldo_cuenta==can_ret) 											//Aqui se valida si lo que se va a retirar es valido a lo disponible en la cuenta
			{
				saldo_ret=saldo_cuenta-can_ret;
				cuentas[num_cue][2]=saldo_ret;
				cout<<"Su saldo actual es de "<<saldo_ret<<endl;
					archivo<<"Su saldo actual es de "<<saldo_ret<<endl;									//Aqui se guardan en los archivos el saldo que quedo despues del retiro
				m[num_cue]=m[num_cue]+1;
				mov[num_cue][m[num_cue]].append("Retiro: ");											//Este apartado es para poder registrar los movimientos
				string temp=to_string(can_ret);
				mov[num_cue][m[num_cue]].append(temp);
				mov[num_cue][m[num_cue]].append("\n");
			}
			else																						//Aqui se valida si la cantidad a retirar es menor a la que hay en la cuenta marcara un error
			{
				cout<<"No cuenta con suficiente saldo "<<endl;
					archivo<<"No cuenta con suficiente saldo "<<endl;									//En donde dice archivos se guardan los errores y el saldo actual en los archivos
				cout<<"Su saldo actual es de "<<saldo_cuenta<<endl;
					archivo<<"Su saldo actual es de "<<saldo_cuenta<<endl;
			}
		}
	}while (can_ret<0 || can_ret==0);
		archivo<<"----------------------------------------------------------------"<<endl;
		archivo.close();
	}

//Esta funcion permite consultar el saldo disponible de la cuenta 
void saldo_men()
{
		archivo.open("Consulta_de_saldos.txt", ios::app);
	cout<<"Su saldo actual es de "<<cuentas[num_cue][2]<<endl;
		archivo<<"El saldo de la cuenta "<<num_cue<<" es "<<cuentas[num_cue][2]<<endl;		//En el apartado que dice archivos se guardan los datos de las consultas
		archivo.close();
		m[num_cue]=m[num_cue]+1;
		mov[num_cue][m[num_cue]].append("El saldo a consultar fue de: ");					//Este apartado es para poder registrar los movimientos
		string temp=to_string(cuentas[num_cue][2]);
		mov[num_cue][m[num_cue]].append(temp);
		mov[num_cue][m[num_cue]].append("\n");
		archivo<<"----------------------------------------------------------------"<<endl;
		archivo.close();
}

//Esta funcion permite cambiar el nip por defecto que se tiene al iniciar el programa
void cambio()
{
		archivo.open("Cambio_de_nip.txt", ios::app);
	system("cls");
	cout<<"Ingrese su NIP"<<endl;
	cin>>nip;
	if (nip==cuentas[num_cue][1])
	{
		cout<<"Ingrese el nuevo NIP: "<<endl;
		cin>>nip_nue;
		temp_nip=to_string(nip_nue);					//Esta es una variable temporal string que guarda los datos del NIP
		temp_temp=temp_nip.length();					//Aqui se guarda la longitud de la variable string anterior
		int comparador=4;								//Esta variable sirve para comparar la longitud del NIP
		while(temp_temp!=comparador)					//Aqui se compara la longitud del NIP para validar que sea de 4 digitos
		{
			cout<<"El NIP debe de ser de 4 digitos"<<endl;
			cout<<"Ingrese el nuevo NIP: "<<endl;
			cin>>nip_nue;
			temp_nip=to_string(nip_nue);
			temp_temp=temp_nip.length();
		}
		int temp = nip_nue;								//Esta variable temporal guarda el valor del NIP nuevo para luego compararlo otra vez con el mismo NIP nuevo
		nip_nue=0;
		cout<<"Ingreselo nuevamente: "<<endl;
		cin>>nip_nue;
		int temp1 = nip_nue;							//Esta es otra variable temporal que guarda el valor del NIP nuevo para luego compararlo otra vez con el mismo NIP nuevo
		if (temp!=temp1)								//Aqui se comparan las dos variables para ver si el cambio de NIP sera exitoso o no
		{
			cout<<"Error. El NIP es diferente"<<endl;
		}
		else											//Si la comparacion fue verdadera se ejecutara el guardado de NIP en la matriz de datos
		{
			cuentas[num_cue][1]=nip_nue;
			cout<<"Su NIP ha sido cambiado"<<endl;
				archivo<<"El NIP de la cuenta "<<num_cue<<" ha sido cambiado"<<endl;
			m[num_cue]=m[num_cue]+1;
			mov[num_cue][m[num_cue]].append("El cambio de NIP fue exitoso");						//Este apartado es para poder registrar los movimientos
			mov[num_cue][m[num_cue]].append("\n");
		}
	}
	else
	{
		cout<<"NIP incorrecto"<<endl;	
	}
		archivo<<"----------------------------------------------------------------"<<endl;
		archivo.close();
}

//Esta funcion permite mandar dinero de una cuenta a otra 
void transferencias()
{
		archivo.open("Transferencias.txt", ios::app);
	do
	{
		cout<<"Digite la cuenta a transferir: "<<endl;
	 	cin>>num_cuetrans;
		if (num_cuetrans>id || num_cuetrans<0 || num_cuetrans==num_cue)									//Aqui se valida si el No. Cuenta a transferir es existente o no
		{
			cout<<"Ingrese un numero de cuenta correcto"<<endl;
				archivo<<"Numero de cuenta a transferir "<<num_cuetrans<<endl;
				archivo<<"Error. Ingrese un numero de cuenta correcto"<<endl;
				archivo<<"----------------------------------------------------------------"<<endl;
		}
		else																							//Si el numero de cuenta es existente se le pregunta al usuario la cantidad a transferir
		{
			cout<<"Digite la cantidad a transferir: "<<endl;
		 	cin>>can_tran;
	 		if (can_tran<0 || can_tran==0)																//Aqui se valida que la cantidad a transferir no sean numeros negativos o que sea 0
	 		{
	 			cout<<"Error. No es posible transferir esa cantidad"<<endl;
		 			archivo<<"Numero de cuenta a transferir "<<num_cuetrans<<endl;
	 				archivo<<"La cantidad a transferir es de "<<can_tran<<endl;
	 				archivo<<"No es posible transferir esa cantidad"<<endl;
	 				archivo<<"----------------------------------------------------------------"<<endl;
			}
			else																						//Si la validacion anterior es falsa, entonces el programa sigue avanzando para decir que la transferencia fue exitosa
			{
					archivo<<"Digite la cantidad a transferir: "<<endl;									//Aqui se guardan los datos de la transferencia en los archivos
			 		archivo<<can_tran<<endl;
			 	saldo_cuenta = cuentas[num_cue][2];
				if (saldo_cuenta>can_tran || saldo_cuenta==can_tran) 
				{
					saldo_tran=saldo_cuenta-can_tran;
					cuentas[num_cue][2]=saldo_tran;
					cout<<"Su saldo actual es de "<<saldo_tran<<endl;
					cout<<"La transferencia se ha realizado con exito"<<endl;
						archivo<<"Numero de cuenta a transferir "<<num_cuetrans<<endl;					//En este apartado que dice archivos se guardan todos los datos de la transferncia en los archivos 
		 				archivo<<"La cantidad a transferir es de "<<can_tran<<endl;
						archivo<<"El saldo actual de la cuenta "<<num_cue<<" es de "<<saldo_tran<<endl;
						archivo<<"La transferencia se ha realizado con exito"<<endl;
					saldo_cuetran=cuentas[num_cuetrans][2];
					saldo_cuetran=saldo_cuetran+can_tran;
					cuentas[num_cuetrans][2]=saldo_cuetran;
					m[num_cue]=m[num_cue]+1;
					mov[num_cue][m[num_cue]].append("La transferencia fue de: ");						//Este apartado es para poder registrar los movimientos
					string temp=to_string(can_tran);
					mov[num_cue][m[num_cue]].append(temp);
					mov[num_cue][m[num_cue]].append("\n");
				}
				else																						//Aqui se valida si la cantidad a transferir es mayor a la existente marcara error
				{
					cout<<"No cuenta con suficiente saldo "<<endl;
					cout<<"Su saldo actual es de "<<saldo_cuenta<<endl;
						archivo<<"No cuenta con suficiente saldo "<<endl;
						archivo<<"El saldo actual de la cuenta "<<num_cue<<" es de "<<saldo_cuenta<<endl;	//Los errores tambien se guardan en los archivos
				}		
			}
		}
	}while (can_tran<0 || can_tran==0);
		archivo<<"----------------------------------------------------------------"<<endl;
		archivo.close();
}

void movimientos()
{
		archivo.open("Movimientos.txt", ios::app);
	cout<<"-- U L T I M O S  5  M O V I M I E N T O S --"<<endl;	
	for (int i=1;i<=m[num_cue];i++)																//Este ciclo se utiliza para poder mostrar los movimientos que se ha realizado en la cuenta 
	{
		cout<<"Movimiento "<<i<<endl;
		cout<<"\n"<<mov[num_cue][i]<<endl;
			archivo<<"Movimiento "<<i<<" de la cuenta "<<num_cue<<endl;
			archivo<<"\n"<<mov[num_cue][i]<<endl;
	}
		archivo<<"------------------------------------"<<endl;
		archivo.close();
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
		cout<<"[6] Ultimos movimientos"<<endl;
		cout<<"[7] Salir"<<endl;
		cout<<"Que desea hacer?"<<endl;
		cin>>opc_men;
		system("cls");
		switch (opc_men)
		{
			case 1: 
				deposito();	
			break;
			
			case 2:
				retiro();
			break;
			
			case 3:
				saldo_men();
			break;
			
			case 4:
				cambio();
			break;
			
			case 5:
				transferencias();
			break;
			
			case 6:
				movimientos();
			break;
		}
	} while (opc_men!=7);
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
		inicio_cuentas();
		menu();
	} while (siempre==1);
		
	return 0;	
}
