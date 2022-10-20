#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

//Orden: id, descripcion, precio de venta, cantidad de producto, stock minimo
string productos[20][4];
//Orden: id, nombre, credito, adeudo
string clientes[5][4];
//Orden: cliente, cuantos productos, total de la venta
string ventas[50][4];
//Total de toda la venta
string ventast[5][4];

int opc, opc1=1, resp, op, op1, i;
float acum;

int menu(void)
{
	cout<<"-- P U N T O  D E  V E N T A  C A R L O S  G A R C I A --"<<'\n';
	cout<<"[1] Vender"<<'\n';
	cout<<"[2] Productos"<<'\n';
	cout<<"[3] Clientes"<<'\n';
	cout<<"[4] Registros de venta "<<'\n';
	cout<<"[5] Ventas totales"<<'\n';
	cout<<"[6] Productos en stock"<<'\n';
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
	
	menu();
	cin>>opc;
	switch (opc)
	{
		case 1:
			{
				do
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
					cout<<"Desea hacer otra compra? 1-Si -- 2-No"<<'\n';
					cin>>resp;
				} while (opc1==resp);
				
				break;
			}
			
		case 2:
			{
				system("cls");
				cout<<"-- PRODUCTOS --"<<'\n';
				cout<<"[1] Buscar productos"<<'\n';
				cout<<"[2] Mostrar productos"<<'\n';
				cout<<"[3] Agregar productos"<<'\n';
				break;			
			}	
		
		case 3:
			{
				system("cls");
				cout<<"-- C L I E N T E S --"<<'\n';
				cout<<"[1] Agregar clientes"<<'\n';
				cout<<"[3] Buscar clientes"<<'\n';
				cout<<"[1] Mostar clientes"<<'\n';
				cout<<"[1] Abonar clientes"<<'\n';
				break;
			}
		
		case 4:
			{
				system("cls");
				cout<<"-- R E G I S T R O  D E  V E N T A S --"<<'\n';
				cout<<"[1] Ver ventas totales"<<'\n';
				break;
			}
		
		
		
		
		
	}
	
	
	
	
	
	
	
	
	
	
} 
