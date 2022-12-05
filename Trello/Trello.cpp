#include <iostream>

using namespace std;

//Declaraciones de variables
string correo_reg, contra_reg, nombre_reg, ape_reg;
string correo, contra;
int opc, opc_ini, opc_esp, acum;
bool verifica=false;

//Declaraciones de matrices
//Orden: correo, contraseña, nombre, apellidos
string usuarios[5][5];
int id_user=1;
string tableros[5];

string espacios[5][4];
string tipo_espa[8]={"Marketing", "Ingenieria y TI", "Educacion", "CRM de ventas", "Recursos humanos", "Operaciones", "Empresa pequeña"};
string nom_esp, sel_esp;

void tableros_menu()
{
	
}

void espacio_nue()
{
	cout<<"Nombre del espacio de trabajo: "<<endl;
	cin>>nom_esp;
	cout<<"Tipo de espacio de trabajo"<<endl;
	for (int i=0;i<7;i++)
	{
		cout<<"["<<i+1<<"] "<<tipo_espa[i]<<endl;
	}
	cout<<"[8] Otro"<<endl;
	cin>>sel_esp;
}

void espacio_ver()
{
	
}

void espacios_menu()
{
	cout<<"-- E S P A C I O S  D E  T R A B A J O --"<<endl;
	cout<<"-----------------------------------------"<<endl;
	cout<<"[1] Agregar un espacio de trabajo"<<endl;
	cout<<"[2] Ver los espacios de trabajo"<<endl;
	cout<<"[3] Salir"<<endl;
	cout<<"Que desea hacer?"<<endl;
	cin>>opc_esp;
	switch(opc_esp)
	{
		case 1:
			espacio_nue();
		break;
		
		case 2:
			espacio_ver();
		break;
	}
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


void registros()
{
		system("cls");
		id_user++;
		cout<<"-- R E G I S T R A R S E --"<<endl;
		cout<<"---------------------------"<<endl;
		cout<<"Ingrese su correo electronico: "<<endl;
		cin>>correo_reg;
		usuarios[id_user][0]=correo_reg;
		cout<<"Introduzca una contraseña: "<<endl;
		cin>>contra_reg;
		usuarios[id_user][1]=contra_reg;
		cout<<"Cual es su nombre? "<<endl;
		cin>>nombre_reg;
		usuarios[id_user][2]=nombre_reg;
		cout<<"Cual es su apellido? "<<endl;
		cin>>ape_reg;
		usuarios[id_user][3]=ape_reg;
		
		cout<<"Bienvenido "<<usuarios[id_user][2]<<" "<<usuarios[id_user][3] <<" ,su correo "<<usuarios[id_user][0]<<" ha sido registrado con exito"<<endl;
}

void inicio()
{
	system("cls");
	cout<<"-- I N I C I O  D E  S E S I O N  --"<<endl;
	do
	{
		cout<<"------------------------------------"<<endl;
		cout<<"Ingrese su correo electronico: "<<endl;
		cin>>correo;
		for (int i=0;i<id_user+1;i++) 
		{
			if (correo == usuarios[i][0])
			{
				verifica = true;
			}
		}
		if (verifica == false)
		{
			cout<<"Correo electronico incorrecto"<<endl;
		}
		else
		{
			while (acum!=1)
			{
				verifica = false;
				cout<<"Ingrese su contraseña: "<<endl;
				cin>>contra;
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
					acum=acum+1;
				}
			} 	 
		}
		if( acum==3)
		{
			cout<<"Error. Ha ingresado muchas veces una contraseña incorrecta"<<endl;
		}
	} while (verifica==false);
}

void menu()
{
	cout<<"[1] Registrarse"<<endl;
	cout<<"[2] Iniciar sesion"<<endl;
}

int main()
{
	//Llenado de las matrices
	usuarios[0][0]="cargarcia085@gmail.com";usuarios[0][1]="1234";usuarios[0][2]="Carlos";usuarios[0][3]="Garcia";
	usuarios[1][0]="tomaterancio@hotmail.com";usuarios[1][1]="Tomatito45";usuarios[1][2]="Angel";usuarios[1][3]="Alvarez";
	

	do
	{
		system("cls");
		cout<<"-- B I E N V E N I D O  A  T R E L L O --"<<endl;
		cout<<"-----------------------------------------"<<endl;
		menu();
		cout<<"Que desea hacer? "<<endl;
		cin>>opc;
		switch(opc)
		{
			case 1:
				registros();
			break;
			
			case 2:
				menu_inicio();
			break;
			
			default:
				cout<<"seleccione una opcion valida"<<endl;
			break;
		}
	} while (opc!=100);
	return 0;
}
