#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

int opc, op, op1, op2, op3 , num, id_per;
int opc1=1, opc2=1, opc3=1, opc4=1, opc5=1, resp, resp1, resp2, resp3;
float acum;
bool verifica=false;
string id_nombre, id_credito;

//Orden: id, descripcion, precio del producto, cantidad de producto, stock minimo
string productos[20][4];
//Orden: id, nombre, credito, adeudo
string clientes[5][4];
int id_cliente=2;
//Orden: cliente, cuantos productos, total de la venta
string ventas[50][3];
//Total de toda la venta
string ventast[5][4];

	int venta()
	{
		system("cls");
		cout<<"Seleccione el producto a vender: "<<'\n';
		cin>>op;
		cout<<"Cantidad de "<<productos[op][1]<<" que hay disponible: "<<productos[op][3]<<'\n';
		int f;
		f=stof(productos[op][2]);
		cout<<"Cantidad de productos a comprar: "<<'\n';
		cin>>op1;
		if (op1<0)
		{
			cout<<"Ingrese una cantidad correcta";
		}
		else if (op1>f)
		{
			cout<<"Ingrese una cantidad menor";
		}
		int cant;
		cant=op1*f;
		acum=acum+cant;
		cout<<"El precio final es de: "<<acum<<'\n';
	}
	
	int productos_buscar()
	{
		cout<<"Ingrese el id del producto a buscar: "<<'\n';
		cin>>num;
		int q;
		q=stof(productos[num][0]);
		for (int p=0;p<=20;p++)
		{
			for (int o=0;o<=4;o++)
			{
				if (num==q)
				{
					verifica = true;
				}
			}
		}
		if (verifica = true)
		{
			cout<<"Descripcion: "<<productos[num][1]<<"\t Precio: "<<productos[num][2]<<"\t Cantidad disponible: "<<productos[num][3]<<"\t Stock minimo: "<<productos[num][4]<<'\n';        
		}
	}
	
	int productos_mostrar()
	{
		for (int l=0;l<20;l++)
		{
			cout<<"ID del producto: "<<productos[l][0]<<"\t Descripcion: "<<productos[l][1]<<"\t Precio: "<<productos[l][2]<<"\t Cantidad disponible: "<<productos[l][3]<<"\t Stock minimo: "<<productos[l][4]<<'\n';        
		}
		cout<<"\n";
	}
	
	int productos_agregar()
	{
	
}

int productos1()
{
	system("cls");
	cout<<"-- PRODUCTOS --"<<'\n';
	cout<<"[1] Buscar productos"<<'\n';
	cout<<"[2] Mostrar productos en stock"<<'\n';
	cout<<"[3] Agregar productos"<<'\n';
	cin>>op2;
	switch (op2)
	{
		case 1:
			productos_buscar();
		break;
			
		case 2:
			productos_mostrar();
		break;	
	}
}

	int clientes_agregar()
	{
		string id_cliente1 = "";
		id_cliente++;
		cout<<"El ID asignado al nuevo cliente es "<<id_cliente<<'\n';
		id_cliente1 = to_string(id_cliente);
		clientes[id_cliente][0]=id_cliente1;
		cout<<"Asigne el nombre del cliente: "<<'\n';
		cin>>id_nombre;
		clientes[id_cliente][1]=id_nombre;
		cout<<"Cuanto credito desea darle a "<<id_nombre<<" ?"<<'\n';
		cin>>id_credito;
		clientes[id_cliente][2]=id_credito;
	}
	
	int clientes_buscar()
	{
		cout<<"Ingrese el id de la persona a buscar: "<<'\n';
		cin>>id_per;
		int e;
		e=stof(clientes[id_per][0]);
		for (int p=0;p<=20;p++)
		{
			for (int o=0;o<=4;o++)
			{
				if (id_per==e)
				{
					verifica = true;
				}
			}
		}
		if (verifica = true)
		{
			cout<<"Nombre del cliente: "<<clientes[id_per][1]<<"\t Credito: "<<clientes[id_per][2]<<"\t Adeudo: "<<clientes[id_per][3]<<'\n';        
		}
	}
	
	int clientes_mostrar()
	{
		for (int a=0;a<5;a++)
		{
			cout<<"ID del cliente: "<<clientes[a][0]<<"\t\t Nombre: "<<clientes[a][1]<<"\t\t Credito: "<<clientes[a][2]<<"\t Adeudo: "<<clientes[a][3]<<'\n';        
		}
		cout<<"\n";
	}
	
	int clientes_adeudo()
	{
		
	}

int clientes1()
{
		system("cls");
		cout<<"-- C L I E N T E S --"<<'\n';
		cout<<"[1] Agregar clientes"<<'\n';
		cout<<"[2] Buscar clientes"<<'\n';
		cout<<"[3] Mostar clientes"<<'\n';
		cout<<"[4] Abonar credito de clientes"<<'\n';
		cin>>op2;
		switch (op2)
		{
			case 1: 
				clientes_agregar();
			break;
			
			case 2:
				clientes_buscar();	
			break;
			
			case 3:
				clientes_mostrar();
			break;
			
			case 4:
				clientes_adeudo();
			break;
		}
}

int menu(void)
{
	cout<<"-- P U N T O  D E  V E N T A  T O R O  L O C O --"<<'\n';
	cout<<"[1] Vender"<<'\n';
	cout<<"[2] Productos"<<'\n';
	cout<<"[3] Clientes"<<'\n';
	cout<<"[4] Registros de venta "<<'\n';
}


int main()
{
	//Llenado de la matriz de clientes
	clientes[0][0]="0";clientes[0][1]="Carlos";clientes[0][2]="1000";clientes[0][3]="250";
	clientes[1][0]="1";clientes[1][1]="Pablo";clientes[1][2]="700";clientes[1][3]="50";
	clientes[2][0]="2";clientes[2][1]="Chapo";clientes[2][2]="5000";clientes[2][3]="780";
	
	//Llenado de la matriz de productos
	productos[0][0]="0";productos[0][1]="Takis";productos[0][2]="15";productos[0][3]="20";productos[0][4]="10";
	productos[1][0]="1";productos[1][1]="Arizona";productos[1][2]="18";productos[1][3]="12";productos[1][4]="6";
	productos[2][0]="2";productos[2][1]="Tortillas";productos[2][2]="20";productos[2][3]="10";productos[2][4]="5";
	
	do
	{
		menu();
		cin>>opc;
		switch (opc)
		{
			case 1:
				do
				{
					venta();
					cout<<"Desea hacer otra compra? 1-Si -- 2-No"<<'\n';
					cin>>resp;
					system("cls");
				} while (opc2==resp);
			break;
				
			case 2:
				do
				{
					productos1();
					cout<<"Desea hacer otra operacion? 1-Si -- 2-No"<<'\n';
					cin>>resp2;	
					system("cls");
				}while (opc3==resp2);
			break;			
			
			case 3:
				do
				{
					clientes1();
					cout<<"Desea hacer otra operacion? 1-Si -- 2-No"<<'\n';
					cin>>resp3;
					system("cls");
				}while (opc4==resp3);
				
			break;
			
			case 4:
				system("cls");
				cout<<"-- R E G I S T R O  D E  V E N T A S --"<<'\n';
				cout<<"[1] Ver ventas totales"<<'\n';
				cout<<"[2] Ver ventas individuales"<<'\n';
			break;
				
			default:
				cout<<"Seleccione una opcion valida "<<'\n';
		}
		resp1=1;
		system("cls");
	}while (opc1==resp1);
	
} 
