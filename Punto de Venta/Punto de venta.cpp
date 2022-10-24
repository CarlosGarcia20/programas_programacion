#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

int opc, op, op1, op2, op3 , num, id_per;
int opc1=1, opc2=1, opc3=1, opc4=1, opc5=1, resp, resp1, resp2, resp3;
float acum;
bool verifica=false;
string id_nombre, id_credito, id_nompro, id_stockac, id_stockmin, id_precio;
int id_credito1, id_cliventa, can_stock;
string can_stock1, respu;

//Orden: id, descripcion, precio del producto, cantidad de producto, stock minimo
string productos[20][5];
int id_producto=2;
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
		for (int a=0;a<5;a++)  //Para mostrar los datos de los clientes, asi como su credito disponible
		{
			cout<<"ID del cliente: "<<clientes[a][0]<<"\t\t Nombre: "<<clientes[a][1]<<"\t\t Credito: "<<clientes[a][2]<<'\n';  //Agregar un valor a la matriz para saber el credito dispoible del cliente      
		}
		cout<<"\n";
		cout<<"Ingrese el ID del cliente: "<<'\n';
		cin>>id_cliventa;
		system("cls");
		do
		{
			for (int l=0;l<20;l++)  	//Mostrar los datos de los productos disponibles en stock
			{
				cout<<"ID del producto: "<<productos[l][0]<<"\t Descripcion: "<<productos[l][1]<<"\t Precio: "<<productos[l][2]<<"\t Cantidad disponible: "<<productos[l][3]<<'\n';        
			}
			cout<<"Seleccione el producto a vender: "<<'\n';
			cin>>op;
			int f;
			f=stof(productos[op][2]); 	//Transforma una variable string a float
			cout<<"Cantidad de productos a comprar: "<<'\n';
			cin>>op1;
			while (op1<=0)		//Valida si la cantidad a comprar no es menor 0
			{
				cout<<"Ingrese una cantidad correcta"<<'\n';
				if (op1>f)
				{
					cout<<"Ingrese una cantidad menor"<<'\n';
				}
				cout<<"Cantidad de productos a comprar: "<<'\n';
				cin>>op1;
			}
			int cant;
			cant=op1*f;
			acum=acum+cant;
			cout<<"El precio final es de: "<<acum<<'\n';
			can_stock = stoi(productos[op][3]);   		//Transforma datos de tipo string a int
			can_stock=can_stock-op1;   					//Resta la cantidad comprada en los productos
			can_stock1 = to_string(can_stock);  		//Transforma datos de tipo entero a cadena
			productos[op][3]=can_stock1;
			
			cout<<"Desea hacer otra compra? (s/n)"<<'\n';
			cin>>respu;
			system("cls");
		} while (respu=="s");
	}
	
	int productos_buscar()
	{
		cout<<"Ingrese el id del producto a buscar: "<<'\n';
		cin>>num;
		int q;
		//Transforma una variable string a float
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
		string id_productos1 = "";
		id_producto++;
		cout<<"El ID asignado al nuevo producto es "<<id_producto<<'\n';
		
		id_productos1 = to_string(id_producto);  //Transforma variables de datos int a dato string 
		productos[id_producto][0]=id_productos1;    //En estos tipos de codigo se agrega la variable a la fila y columna que corresponde 
		cout<<"Añada la descripcion del producto: "<<'\n';
		cin>>id_nompro;
		productos[id_producto][1]=id_nompro;
		cout<<"Cual es el precio del producto: "<<'\n';
		cin>>id_precio;
		productos[id_producto][2]=id_precio;
		cout<<"Cual es el stock actual: "<<'\n';
		cin>>id_stockac;
		productos[id_producto][3]=id_stockac;
		cout<<"Cual es el stock minimo del producto "<<id_nompro<<"?"<<'\n';
		cin>>id_stockmin;
		productos[id_producto][4]=id_stockmin;
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
		
		case 3:
			productos_agregar();
		break;
	}
}

	int clientes_agregar()
	{
		string id_cliente1 = "";
		id_cliente++;
		cout<<"El ID asignado al nuevo cliente es "<<id_cliente<<'\n';
		id_cliente1 = to_string(id_cliente);  		//Transforma datos de tipo entero a cadena
		clientes[id_cliente][0]=id_cliente1;
		cout<<"Asigne el nombre del cliente: "<<'\n';
		cin>>id_nombre;
		clientes[id_cliente][1]=id_nombre;
		cout<<"Cuanto credito desea darle a "<<id_nombre<<" ?"<<'\n';
		cin>>id_credito;
		id_credito1 = stoi(id_credito);   		//Transforma datos de tipo string a int
		while (id_credito1<0)
		{
			cout<<"El credito no puede ser menor a 0"<<'\n';
			cout<<"Cuanto credito desea darle a "<<id_nombre<<" ?"<<'\n';
			cin>>id_credito;
			id_credito1 = stoi(id_credito);   //Transforma datos de tipo string a int
		}
		id_credito = to_string(id_credito1);  //Transforma datos de tipo entero a cadena 
		clientes[id_cliente][2]=id_credito;
	}
	
	int clientes_buscar()
	{
		cout<<"Ingrese el ID de la persona a buscar: "<<'\n';
		cin>>id_per;
		int e;
		e=stof(clientes[id_per][0]);  //Transforma datos de tipo cadena a float
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
		else
		{
			cout<<"Ingrese un ID valido"<<'\n';
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
		int abono, res;
		int acum1;
		cout<<"Ingrese el ID del cliente: "<<'\n';
		cin>>id_per;
		int e;
		e=stof(clientes[id_per][0]);   //Transforma datos de tipo cadena a float
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
			cout<<"El adeudo del cliente "<<clientes[id_per][1]<<" es de "<<clientes[id_per][3]<<'\n';
			cout<<"Cuanto quiere abonar el cliente? "<<'\n';
			cin>>abono;
			int s;
			s=stof(clientes[id_per][3]);  //Transforma datos de tipo cadena a float
			res=s-abono;
			cout<<"El abono a realizar es de: "<<abono<<'\n';
			cout<<"Su nuevo saldo es de: "<<res<<'\n';
		}	
		string adeudo_nue = to_string(res);  //Tranforma datos de tipo entero a cadena
		clientes[id_per][3]=adeudo_nue;
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
	cout<<"-- P U N T O  D E  V E N T A  L A  E S Q U I N A --"<<'\n';
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
		cout<<"Seleccione una opcion: ";cin>>opc;
		switch (opc)
		{
			case 1:
				do
				{
					venta();
					cout<<"Desea seguir vendiendo? 1-Si -- 2-No"<<'\n';
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
				system("pause");
		}
		resp1=1;
		system("cls");
	}while (opc1==resp1);
	
} 
