#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

using namespace std;

//Declaraciones de variables
string correo_reg, contra_reg, nombre_reg, nom_tab, nom_lista;
string resp, correo, contra, espacio, tablero, tarjeta, tar_tex, nom_user;
int opc, opc_ini, opc_esp, acum, inv, var=1, x=6, y=5, a=0, z=1, m=0, n=0, q=1, w=4, listaacum=1;;
bool verifica=false, vercorreo=false;

void gotoxy(int x,int y){  
  HANDLE hcon;  
  hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
  COORD dwPos;  
  dwPos.X = x;  
  dwPos.Y= y;  
  SetConsoleCursorPosition(hcon,dwPos);  
 }  
 
 void arreglosx()
 {
 	for(int i=0;i<=119;i++)
	{
		cout<<"-";
	}	
 }
 
 void arreglosy()
 {
 	for(int i=3;i<=20;i++)
	{
		gotoxy(59,i);cout<<"*";
	}
 }
 
void arreglostab()
{
	for(int i=3;i<=21;i++)
	{
		gotoxy(30,i);cout<<"*";
		gotoxy(61,i);cout<<"*";
		gotoxy(92,i);cout<<"*";
	}
}

//Declaraciones de matrices
//Orden: correo, contraseña, nombre
string usuarios[10][3];
int id_user=1, numero=0;
string tableros[5];
string listas[5];

string espacios[5][5];
string nom_esp;

void crear_lista()
{
	gotoxy(35,12);cout<<"Ingrese el nombre de la lista: "<<endl;
	gotoxy(66,12);cin>>nom_lista;
	listas[n]=nom_lista;
	n++;
	system("cls");
}

void crear_tarjeta()
{
	do
	{
		gotoxy(50,23);cout<<"En que lista desea crear la tarjeta: "<<endl;
		gotoxy(87,23);cin>>tarjeta;
		while (verifica == false)
		{
			for (int i=0;i<5;i++) 
			{
				if (tarjeta == listas[i])
				{
					verifica = true;
				}
			}
			if (verifica == false)
			{
				gotoxy(50,25);cout<<"Ingrese un nombre de lista correcto"<<endl;
			}
			else
			{
				cout<<"Ingrese el texto de la tarjeta: "<<endl;
				cin>>tar_tex;
			}
		}
	}while (listaacum==1);
}

void menu_tablero()
{
	system("cls");
	do
	{
		gotoxy(0,0);arreglosx();
		gotoxy(0,2);arreglosx();
		gotoxy(0,22);arreglosx();
		arreglostab();
		gotoxy(50,1);cout<<"Nombre del tablero "<<tablero<<endl;
		gotoxy(2,23);cout<<"[1] Crear lista"<<endl;
		gotoxy(2,24);cout<<"[2] Crear tarjeta en lista"<<endl;
		gotoxy(2,25);cout<<"[3] Eliminar tarjeta"<<endl;
		gotoxy(2,26);cout<<"[4] Mover tarjeta"<<endl;
		gotoxy(2,27);cout<<"[5] Salir"<<endl;
		gotoxy(2,28);cout<<"Que desea hacer? "<<endl;
		gotoxy(19,28);cin>>opc;
		
		switch (opc)
		{
			case 1:
				system("cls");
				crear_lista();
				gotoxy(2,3);cout<<"Nombre de la lista: "<<endl;
				for (int i=0;i<n;i++)
				{
					gotoxy(2,5);cout<<"*"<<listas[i]<<endl;		
				}
			break;
			
			case 2:
				crear_tarjeta();
			break;
			
			default:
				gotoxy(2,25);cout<<"Seleccione una opcion valida"<<endl;
				system("cls");
		}
	} while(opc!=5);
}

void crear_tab()
{
	gotoxy(43,13);cout<<"Ingrese el nombre del tablero: "<<endl;
	gotoxy(74,13);getline(cin, nom_tab);
	getline(cin, nom_tab);
	tableros[m]=nom_tab;
	m++;
	system("cls");
}

void imprimirtab()
{
	for (int i=0;i<5;i++)
	{
		gotoxy(70,6);cout<<"*"<<tableros[i];
	}
}

void miembro()
{
	gotoxy(50,22);cout<<"Ingrese el nombre del usuario: "<<endl;
	gotoxy(81,22);getline(cin,nom_user);
	getline(cin,nom_user);
	gotoxy(50,23);cout<<"Quiere que sea administrador o invitado (1--Admin  2--Inv)? "<<endl;
	gotoxy(110,23);cin>>inv;
	do
	{
		gotoxy(50,24);cout<<"Escriba una respuesta valida"<<endl;
		gotoxy(110,23);cin>>inv;
	} while(inv<=0 || inv>=3);
	if (inv==1)
	{
		gotoxy(50,24);cout<<"El administrador "<<nom_user<<" ha sido agregado correctamente"<<endl;
		gotoxy(50,25);getch();
	}
	else if(inv==2)
	{
		gotoxy(50,24);cout<<"El invitado "<<nom_user<<" ha sido agregado correctamente"<<endl;
		gotoxy(50,25);getch();
	}
	system("cls");
}

void menu_espacio()
{
	do
	{
		gotoxy(0,0);arreglosx();
		gotoxy(0,2);arreglosx();
		gotoxy(0,21);arreglosx();
		gotoxy(59,0);arreglosy();
		gotoxy(50,1);cout<<"Espacio de trabajo "<<espacio<<endl;
		gotoxy(5,3);cout<<"Miembros del espacio de trabajo: "<<endl;
		gotoxy(5,4);cout<<"Administradores: "<<endl;
		string temp = usuarios[numero][2];
		gotoxy(5,6);cout<<"*"<<temp;
		gotoxy(40,4);cout<<"Invitados: "<<endl;
		gotoxy(70,4);cout<<"Tableros: "<<endl;
		gotoxy(5,22);cout<<"[1] Crear tablero"<<endl;
		gotoxy(5,23);cout<<"[2] Entrar a un tablero"<<endl;
		gotoxy(5,24);cout<<"[3] Añadir a un miembro"<<endl;
		gotoxy(5,25);cout<<"[4] Salir"<<endl;
		gotoxy(5,26);cout<<"Que desea hacer? "<<endl;
		gotoxy(22,26);cin>>opc;
		switch(opc)
		{
			case 1: 
				system("cls");
				crear_tab();
				imprimirtab();
			break;
			
			case 2:
				while (q==1)
				{
					gotoxy(50,22);cout<<"A que tablero desea ingresar? "<<endl;
					gotoxy(80,22);cin>>tablero;
					for (int i=0;i<5;i++) 
					{
						if (tablero == tableros[i])
						{
							verifica = true;
							q=0;
						}
					}
					if (verifica == false)
					{
						gotoxy(50,23);cout<<"El tablero no existe"<<endl;
						q=0;
						gotoxy(71,23);getch();
						system("cls");
					}
					else
					{
						menu_tablero();
					}
					system("cls");
				} 	
				q=1;	
				verifica = false;
				break;
			
			case 3:
				miembro();
				gotoxy(40,6);cout<<"*"<<nom_user;
			break;
			
			default:
				gotoxy(5,30);cout<<"Seleccione una opcion valida"<<endl;
				system("cls");
		}
	}while (opc!=4);
}


void espacio_nue()
{
	gotoxy(40,12);cout<<"Nombre del espacio de trabajo: ";
	getline(cin,nom_esp);
	getline(cin,nom_esp);
	espacios[a][0]=nom_esp;
	a++;
	system("cls");
}

void espacios_menu()
{
	do
	{
		gotoxy(0,0);arreglosx();
		gotoxy(0,2);arreglosx();
		gotoxy(0,21);arreglosx();
		arreglosy();
		gotoxy(40,1);cout<<"-- E S P A C I O S  D E  T R A B A J O --"<<endl;
		gotoxy(6,3);cout<<"Administador: ";
		gotoxy(75,3);cout<<"Espectador: ";
		gotoxy(5,22);cout<<"[1] Agregar un espacio de trabajo"<<endl;
		gotoxy(45,22);cout<<"[2] Ingresar a un espacio de trabajo"<<endl;
		gotoxy(90,22);cout<<"[3] Cerrar Sesion"<<endl;
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
				gotoxy(0,26);arreglosx();
				while (z==1)
				{
					gotoxy(5,27);cout<<"A que espacio desea ingresar? "<<endl;
					gotoxy(35,27);cin>>espacio;
					for (int i=0;i<5;i++) 
					{
						if (espacio == espacios[i][0])
						{
							verifica = true;
							z=0;
						}
					}
					if (verifica == false)
					{
						gotoxy(5,28);cout<<"Ingrese un espacio valido"<<endl;
						z=0;
						gotoxy(31,28);getch();
					}
					else
					{
						system("cls");
						menu_espacio();
					}
				}
				verifica=false;
				z=1;
				system("cls");
			break;
			
			default:
				gotoxy(5,28);cout<<"Seleccione una opcion valida";
			break;
			system("cls");
		}	
	} while (opc_esp!=3);
}

void letinicio()
{
	gotoxy(35,2);cout<<"-- I N I C I O  D E  S E S I O N  --"<<endl;
	gotoxy(20,3);cout<<"-------------------------------------------------------------"<<endl;
}

void inicio()
{
	do
	{
		cout<<numero<<endl;
		letinicio();
		gotoxy(20,5);cout<<"Ingrese su correo electronico: ";
		gotoxy(51,5);cin>>correo;
		while (vercorreo == false)
		{
			for (int i=0;i<id_user+1;i++) 
			{
				if (correo == usuarios[i][0])
				{
					vercorreo = true;
					numero = i;
				}
				else
				{
					gotoxy(20,7);cout<<"Ingrese un correo electronico valido";
				}
			}
			if (vercorreo == false)
			{
				
				system("cls");
				letinicio();
				gotoxy(20,5);cout<<"Ingrese su correo electronico: ";
				gotoxy(51,5);cin>>correo;
			}
		}
		system("cls");
		string temp = usuarios[numero][1];
		do
		{
			cout<<numero<<endl;
			var=0;
			letinicio();
			gotoxy(20,5);cout<<"Ingrese su correo electronico: "; gotoxy(51,5);cout<<correo;
			gotoxy(20,6);cout<<"Ingrese su contraseña: ";
			gotoxy(43,6);cin>>contra;
			if (contra==temp)
			{
				cout<<"Bienvenido"<<endl;
			}
			else
			{
				gotoxy(20,8);cout<<"Contraseña incorrecta"<<endl;
			}
			system("cls");
		} while (contra!=temp);
	} while (var==1);
	vercorreo = false;
	numero=0;
	var=1;
}

void registrar()
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
				registrar();
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
}
