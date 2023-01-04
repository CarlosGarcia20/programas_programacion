#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

using namespace std;

//Declaraciones de variables
string correo_reg, contra_reg, nombre_reg, nom_tab;
string correo, contra, espacio;
int opc, opc_ini, opc_esp, acum, var=1, x=6, y=5, a=0, b=0;
bool verifica=false, vercorreo=false;
void gotoxy(int x,int y){  
  HANDLE hcon;  
  hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
  COORD dwPos;  
  dwPos.X = x;  
  dwPos.Y= y;  
  SetConsoleCursorPosition(hcon,dwPos);  
 }  

//Declaraciones de matrices
//Orden: correo, contraseña, nombre
string usuarios[5][3];
int id_user=1;
string tableros[5];

string espacios[5][5];
string nom_esp;

void crear_tab()
{
	cout<<"Ingrese el nombre del tablero "<<endl;
	getline(cin, nom_tab);
	getline(cin, nom_tab);
	system("cls");
}


void menu_espacio()
{
	do
	{
		gotoxy(0,0);cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
		gotoxy(50,1);cout<<"Espacio de trabajo "<<espacio<<endl;
		gotoxy(0,2);cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
		gotoxy(5,3);cout<<"Miembros del espacio de trabajo: "<<endl;
		gotoxy(5,4);cout<<"Administradores: "<<endl;
		gotoxy(5,6);cout<<correo;
		gotoxy(40,4);cout<<"Invitados: "<<endl;
		gotoxy(70,4);cout<<"Tableros: "<<endl;
		gotoxy(5,20);cout<<"[1] Crear tablero"<<endl;
		gotoxy(5,21);cout<<"[2] Entrar a un tablero"<<endl;
		gotoxy(5,22);cout<<"[3] Añadir a un miembro"<<endl;
		gotoxy(5,23);cout<<"[4] Salir"<<endl;
		gotoxy(5,24);cout<<"Que desea hacer? "<<endl;
		gotoxy(22,24);cin>>opc;
		switch(opc)
		{
			case 1: 
				system("cls");
				crear_tab();
				gotoxy(70,6);cout<<"*"<<nom_tab;
			break;
			
			case 2:
			
			break;
			
			case 3:
				
			break;
		}
	}while (opc!=4);
}


void espacio_nue()
{
	gotoxy(40,12);cout<<"Nombre del espacio de trabajo: ";
	getline(cin,nom_esp);
	getline(cin,nom_esp);
	espacios[a][b]=nom_esp;
	a++; b++;
	system("cls");
}

void espacios_menu()
{
	do
	{
		gotoxy(40,1);cout<<"-- E S P A C I O S  D E  T R A B A J O --"<<endl;
		cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
		gotoxy(6,3);cout<<"Administador: ";
		gotoxy(75,3);cout<<"Espectador: ";
		gotoxy(5,22);cout<<"[1] Agregar un espacio de trabajo"<<endl;
		gotoxy(45,22);cout<<"[2] Ingresar a un espacio de trabajo"<<endl;
		gotoxy(90,22);cout<<"[3] Salir"<<endl;
		gotoxy(5,24);cout<<"Que desea hacer? ";
		gotoxy(22,24);cin>>opc_esp;
		switch(opc_esp)
		{
			case 1:
				system("cls");
				espacio_nue();
				gotoxy(x,y);cout<<"-"<<nom_esp<<endl;
				x++; y++;
			break;
			
			case 2:
				gotoxy(5,26);cout<<"**************************************************************************************************"<<endl;
				while (verifica == false)
				{
					gotoxy(5,27);cout<<"A que espacio desea ingresar? "<<endl;
					gotoxy(35,27);cin>>espacio;
					for (int i=0;i<5;i++) 
					{
						if (espacio == espacios[i][0])
						{
							verifica = true;
						}
					}
					if (vercorreo == false)
					{
						gotoxy(5,28);cout<<"Ingrese un espacio valido"<<endl;
					}
				}
				system("cls");
				menu_espacio();
			break;
			
			default:
				gotoxy(5,28);cout<<"Seleccione una opcion valida";
			break;
		}	
	} while (opc_esp!=3);
}

void menu_inicio()
{
	system("cls");
	cout<<"[1] Tableros"<<endl;
	cout<<"[2] Espacios de trabajo"<<endl;
	cout<<"Que desea hacer?"<<endl;
	cin>>opc_ini;
	switch (opc_ini)
	{
		case 1:
			
		break;
		
		case 2:
			espacios_menu();
		break;
	}
}

void inicio()
{
	
	do
	{
		while (vercorreo == false)
		{
			gotoxy(35,2);cout<<"-- I N I C I O  D E  S E S I O N  --"<<endl;
			gotoxy(20,3);cout<<"-------------------------------------------------------------"<<endl;
			gotoxy(20,5);cout<<"Ingrese su correo electronico: ";cin>>correo;
			for (int i=0;i<id_user+1;i++) 
			{
				if (correo == usuarios[i][0])
				{
					vercorreo = true;
				}
			}
			if (vercorreo == false)
			{
				system("cls");
				gotoxy(20,6);cout<<"Ingrese un correo electronico valido"<<endl;
			}
		}
		do
		{
			system("cls");
			var=0;
			gotoxy(35,2);cout<<"-- I N I C I O  D E  S E S I O N  --"<<endl;
			gotoxy(20,3);cout<<"-------------------------------------------------------------"<<endl;
			gotoxy(20,5);cout<<"Ingrese su contraseña: ";cin>>contra;
			for (int i=0;i<id_user+1;i++) 
			{
				if (contra == usuarios[i][1])
				{
					verifica = true;
				}
			}
			if(verifica == false)
			{
				cout<<"Contraseña incorrecta"<<endl;
			}
			else
			{
				cout<<"Inicio de sesion correcto. Bienvenido"<<endl;
			}
		} while (verifica == false);
	} while (var==1);
}

void registros()
{
	system("cls");
	id_user++;
	gotoxy(40,2);cout<<"-- R E G I S T R A R S E --"<<endl;
	gotoxy(20,3);cout<<"-------------------------------------------------------------"<<endl;
	gotoxy(20,5);cout<<"Ingrese su nombre y apellidos: ";getline(cin,nombre_reg);
	getline(cin,nombre_reg);
	usuarios[id_user][2]=nombre_reg;
	gotoxy(20,6);cout<<"Ingrese su correo electronico: ";cin>>correo_reg;
	usuarios[id_user][0]=correo_reg;
	gotoxy(20,7);cout<<"Ingrese una contraseña: ";cin>>contra_reg;
	usuarios[id_user][1]=contra_reg;
	gotoxy(20,10);cout<<"Presione una tecla para continuar..."<<endl;
	getch();
}

int main()
{
	//Llenado de las matrices
	usuarios[0][0]="cargarcia085@gmail.com";usuarios[0][1]="1234";usuarios[0][2]="Carlos Garcia";
	usuarios[1][0]="tomaterancio@hotmail.com";usuarios[1][1]="Tomatito45";usuarios[1][2]="Angel Alvarez";
	
	do
	{
		system("cls");
		gotoxy(30,8);cout<<"-- B I E N V E N I D O  A  T R E L L O --"<<endl;
		gotoxy(30,9);cout<<"-----------------------------------------"<<endl;
		gotoxy(40,10);cout<<"[1] Iniciar sesion"<<endl;
		gotoxy(40,11);cout<<"[2] Registrarse"<<endl;
		gotoxy(40,12);cout<<"[3] Salir"<<endl;
		gotoxy(40,13);cout<<"Que desea hacer? ";cin>>opc;
		system("cls");
		switch(opc)
		{
			case 1:
				espacios_menu();
			break;
			
			case 2:
				registros();
			break;
			
			case 3:
				cout<<"Saliendo..."<<endl;
				system("EXIT");
			break; 
			
			default:
				cout<<"seleccione una opcion valida"<<endl;
			break;
		}
	} while (opc!=3);
	return 0;
}
