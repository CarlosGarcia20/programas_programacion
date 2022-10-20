#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

//Orden: id, descripcion, precio del producto, cantidad de producto, stock minimo
string productos[20][4];
//Orden: id, nombre, credito, adeudo
string clientes[5][4];
//Orden: cliente, cuantos productos, total de la venta
string ventas[50][3];
//Total de toda la venta
string ventast[5][4];

int opc, opc1=1, opc2, opc3=1, opc4=1, resp, resp1, resp2, op, op1, num;
float acum;
bool verifica=false;

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
}

int menu(void)
{
	cout<<"-- P U N T O  D E  V E N T A  T O R O  L O C O --"<<'\n';
	cout<<"[1] Vender"<<'\n';
	cout<<"[2] Productos"<<'\n';
	cout<<"[3] Clientes"<<'\n';
	cout<<"[4] Registros de venta "<<'\n';
	cout<<"[6] Productos en stock"<<'\n';
}

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

int productos1()
{
	system("cls");
	cout<<"-- PRODUCTOS --"<<'\n';
	cout<<"[1] Buscar productos"<<'\n';
	cout<<"[2] Mostrar productos"<<'\n';
	cout<<"[3] Agregar productos"<<'\n';
	cin>>opc2;
	switch (opc2)
	{
		case 1:
			productos_buscar();
		break;
			
		case 2:
			productos_mostrar();
		break;	
	}
}

int main()
{
	//Llenado de la matriz de clientes
	clientes[0][0]="0";clientes[0][1]="Carlos";clientes[0][2]="1000";clientes[0][3]="250";
	clientes[1][0]="1";clientes[1][1]="Pablito";clientes[1][2]="700";clientes[1][3]="50";
	clientes[2][0]="2";clientes[2][1]="Jarochos";clientes[2][2]="5000";clientes[2][3]="780";
	
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
				} while (opc1==resp);
			break;
				
			case 2:
				do
				{
					productos1();
					cout<<"Desea hacer otra operacion? 1-Si -- 2-No"<<'\n';
					cin>>resp2;	
				}while (opc4==resp2);
			break;			
			
			case 3:
				system("cls");
				cout<<"-- C L I E N T E S --"<<'\n';
				cout<<"[1] Agregar clientes"<<'\n';
				cout<<"[3] Buscar clientes"<<'\n';
				cout<<"[1] Mostar clientes"<<'\n';
				cout<<"[1] Abonar clientes"<<'\n';
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
		cout<<"Desea regresar al menu principal? 1-Si -- 2-No"<<'\n';
		cin>>resp1;
		system("cls");
	}while (opc3==resp1);
	
} 
