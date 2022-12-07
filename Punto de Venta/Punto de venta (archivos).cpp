#include <iostream>
#include <conio.h>
#include <string>
#include <stdlib.h>
#include <fstream>

using namespace std;

ofstream archivo;

int opc, op, op1, op2, op3 , num, id_per;
int opc1=1, opc2=1, opc3=1, opc4=1, opc5=1, opc6=1, resp, resp1, resp2, resp3, resp4;
float acum, precio;
bool verifica=false;
string id_nombre, id_credito, id_nompro, id_stockac, id_stockmin, id_precio;
int id_credito1, id_cliventa, can_stock, stock_min, cant, credito, credito_acum, produ_com, precio_total;
string can_stock1, respu, pago;

//Orden: id, descripcion, precio del producto, cantidad de producto, stock minimo
string productos[20][5];
int id_producto=2;
//Orden: id, nombre, credito, adeudo
string clientes[5][4];
int id_cliente=2;
//Orden: cliente ID, cuantos productos, total de la venta
string ventas[50][3];
int identi=-1;
string id_ven, pro_ven, total;
//Total de toda la venta																	
string ventast[5][4];

//Sirve para que no se pueda llenar de mas la matriz de clientes
bool llena_clie()
{
	return id_cliente == 5-1;
}

bool llena_prod()
{
	return id_producto == 20-1;
}


int venta()
{
		archivo.open("Ventas.txt", ios::app);			//Se crea el archivo txt para guardar las ventas
	system("cls");
	for (int a=0;a<id_cliente+1;a++)  //Para mostrar los datos de los clientes, asi como su credito disponible
	{
		cout<<"ID del cliente: "<<clientes[a][0]<<"\t\t Nombre: "<<clientes[a][1]<<"\t\t Credito: "<<clientes[a][2]<<"\t\t Adeudo: "<<clientes[a][3]<<endl;     
	}
	cout<<"Ingrese el ID del cliente: "<<endl;
	cin>>id_cliventa;
	//Aqui se guarda el Id del cliente en la matriz de ventas
	id_ven=to_string(id_cliventa);
	identi=identi+1;
	ventas[identi][0]=id_ven;
	if(id_cliventa>id_cliente)
	{
		cout<<"Ingrese un Id valido"<<endl;
		system("pause");
	}
	else
	{ 
		system("cls");
		do
		{
				archivo<<"El Id del cliente es "<<id_cliventa<<endl;
			for (int l=0;l<id_producto+1;l++)  				//Mostrar los datos de los productos disponibles en stock
			{
				cout<<"ID del producto: "<<productos[l][0]<<"\t Descripcion: "<<productos[l][1]<<"\t Precio: "<<productos[l][2]<<"\t Cantidad disponible: "<<productos[l][3]<<endl;        
			}
			cout<<"Seleccione el producto a vender: "<<endl;
			cin>>op;
			if (op>id_producto)
			{
				cout<<"Seleccione un Id valido"<<endl;
			}
			else
			{
					archivo<<"El id del producto es "<<op<<endl;
				precio=stof(productos[op][2]); 				//Transforma una variable string a float del precio de los productos
				can_stock = stoi(productos[op][3]);   		//Transforma datos de tipo string a int de los datos de stock actual
				cout<<"Cantidad de productos a comprar: "<<endl;
				cin>>op1;
				do											//Valida si la cantidad a comprar no es menor 0
				{
					if (op1<1)
					{
						cout<<"Ingrese una cantidad correcta"<<endl;
						cout<<"Cantidad de productos a comprar: "<<endl;
						cin>>op1;
					}
					else if (op1>can_stock)
					{
						cout<<"Ingrese una cantidad menor a la que hay en stock"<<endl;
						cout<<"Cantidad de productos a comprar: "<<endl;
						cin>>op1;
					}
				} while (op1<1 || op1>can_stock);
					archivo<<"La cantidad de productos a comprar fue de "<<op1<<endl;
				//Aqui se registran los productos comprados para guardarlos en la matriz de ventas
				produ_com=produ_com+op1;
				pro_ven=to_string(produ_com);
				ventas[identi][1]=pro_ven;
				produ_com=0;
				//
				cant=op1*precio;
				acum=acum+cant;
				cout<<"El precio final es de: "<<acum<<endl;
					archivo<<"El precio final es de: "<<acum<<endl;
				//Aqui se registran los datos de venta para guardarlos en la matriz de ventas
				precio_total=precio_total+acum;
				total=to_string(precio_total);
				ventas[identi][2]=total;
				precio_total=0;
				//
				stock_min = stoi(productos[op][4]);			//Transforma datos de tipo string a int de los datos de stock minimo
				can_stock = can_stock-op1;   				//Resta la cantidad comprada en los productos
				if (can_stock<stock_min)
				{
					cout<<"Ha llegado al minimo de stock, favor de llamar al proveedor"<<endl;
				}
				can_stock1 = to_string(can_stock);  		//Transforma datos de tipo entero a cadena. Usado pora guardar el stock que quedo despues de la compra en la matriz
				productos[op][3] = can_stock1;				//Guardado de datos del stock despues de la compra en la matriz
				
				cout<<"Desea pagar en efectivo o con su credito? "<<endl;
				cin>>pago;
				if (pago=="e" || pago=="efectivo")
				{
					int pago1, pago_resul=0;
					cout<<"Con cuanto pagara el/los productos? "<<endl;
					cin>>pago1;
					pago_resul=pago1-acum;
					cout<<"Su cambio es de "<<pago_resul<<" $pesos"<<endl;
						archivo<<"El pago fue en efectivo y se pago con "<<pago1<<endl;
				}
				else if (pago=="c" || pago=="credito")
				{
					int adeudo_venta;
					//Aqui se hacen las operaciones para poder agregar el adeudo nuevo a la matriz
					adeudo_venta=stoi(clientes[id_cliventa][3]);
					adeudo_venta=adeudo_venta+acum;
					cout<<"Su nuevo adeudo es de "<<adeudo_venta<<endl;
					string adeudo_nuevo;
					adeudo_nuevo = to_string(adeudo_venta);
					//Aqui se agrega el dato del adeudo a la matriz
					clientes[id_cliventa][3]=adeudo_nuevo;
					//Aqui se hacen las oepraciones para poder restarle al credito disponible lo que ha gastado de este
					int credito_venta;
					credito=stoi(clientes[id_cliventa][2]);
					credito_venta=credito-acum;
					string credito_ventas=to_string(credito_venta);
					//Aqui se agrega el nuevo credito a la matriz
					clientes[id_cliventa][2]=credito_ventas;
						archivo<<"El pago fue con el credito del cliente y su nuevo adeudo es de"<<adeudo_venta<<endl;
				}
			}
			cout<<"Desea hacer otra compra? (s/n)"<<endl;
			cin>>respu;
			system("cls");
			acum=0;
		} while (respu=="s");
	}
		archivo<<"------------------------------------------------------------------"<<endl;
		archivo.close();					//Se cierra el archivo de texto
}

int productos_buscar()
{
	cout<<"Ingrese el id del producto a buscar: "<<endl;;
	cin>>num;
	if (num>id_producto)
	{
		cout<<"Error, ingrese un Id valido"<<endl;
	}
	else
	{
		int q;
		q=stof(productos[num][0]); 			//Transforma una variable string a float
		for (int p=0;p<20;p++)
		{
			for (int o=0;o<20;o++)
			{
				if (num==q)
				{
					verifica = true;
				}
			}
		}
		if (verifica = true)
		{
			cout<<"Descripcion: "<<productos[num][1]<<"\t Precio: "<<productos[num][2]<<"\t Cantidad disponible: "<<productos[num][3]<<"\t Stock minimo: "<<productos[num][4]<<endl;;        
		}
	}
}

int productos_mostrar()
{
		archivo.open("Productos en stock.txt", ios::app);
	for (int l=0;l<id_producto+1;l++)
	{
		cout<<"ID del producto: "<<productos[l][0]<<"\t Descripcion: "<<productos[l][1]<<"\t Precio: "<<productos[l][2]<<"\t Cantidad disponible: "<<productos[l][3]<<"\t Stock minimo: "<<productos[l][4]<<endl;
			archivo<<"ID del producto: "<<productos[l][0]<<"\t Descripcion: "<<productos[l][1]<<"\t Precio: "<<productos[l][2]<<"\t Cantidad disponible: "<<productos[l][3]<<"\t Stock minimo: "<<productos[l][4]<<endl;;       
	}
	cout<<"\n";
		archivo<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
		archivo.close();
}

int productos_agregar()
{
		archivo.open("Agregar productos.txt", ios::app);
	if (llena_prod())
	{
		cout<<"Ya se ha llenado el inventario"<<endl;
	}
	else
	{
		string id_productos1 = "";
		id_producto++;
		cout<<"El ID asignado al nuevo producto es "<<id_producto<<endl;
			archivo<<"El ID asignado al nuevo producto es "<<id_producto<<endl;
		id_productos1 = to_string(id_producto);  //Transforma variables de datos int a dato string 
		productos[id_producto][0]=id_productos1;    //En estos tipos de codigo se agrega la variable a la fila y columna que corresponde 
		cout<<"Añada la descripcion del producto: "<<endl;
		getline(cin, id_nompro);
		getline(cin, id_nompro);
			archivo<<"El nombre del producto es "<<id_nompro<<endl;
		productos[id_producto][1]=id_nompro;
		cout<<"Cual es el precio del producto: "<<endl;
		cin>>id_precio;
			archivo<<"El precio del producto es "<<id_precio<<endl;
		productos[id_producto][2]=id_precio;
		cout<<"Cual es el stock actual: "<<endl;
		cin>>id_stockac;
			archivo<<"El stock actual del producto es "<<id_stockac<<endl;
		productos[id_producto][3]=id_stockac;
		cout<<"Cual es el stock minimo del producto "<<id_nompro<<"?"<<endl;
		cin>>id_stockmin;
			archivo<<"El stock minimo del producto es de "<<id_stockac<<endl;
		productos[id_producto][4]=id_stockmin;
			archivo<<"--------------------------------------------------------------------"<<endl;
	}
		archivo.close();
}
	
int productos1()
{
	system("cls");
	cout<<"-- PRODUCTOS --"<<endl;
	cout<<"[1] Buscar productos"<<endl;
	cout<<"[2] Mostrar productos en stock"<<endl;
	cout<<"[3] Agregar productos"<<endl;
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
		archivo.open("Agregar clientes.txt", ios::app);
	if (llena_clie())
	{
		cout<<"Ya se ha llenado la agenda de clientes"<<endl;
	}
	else
	{
		string id_cliente1 = "";
		id_cliente++;
		cout<<"El ID asignado al nuevo cliente es "<<id_cliente<<endl;
			archivo<<"El ID asignado al nuevo cliente es "<<id_cliente<<endl;
		id_cliente1 = to_string(id_cliente);  		//Transforma datos de tipo entero a cadena. Se le da el valor que tiene el Id nuevo pero en formato de cadena
		clientes[id_cliente][0]=id_cliente1;		//Se agrega el Id a la matriz
		cout<<"Asigne el nombre del cliente: "<<endl;
		cin>>id_nombre;
			archivo<<"El nombre del cliente es: "<<id_nombre<<endl;
		clientes[id_cliente][1]=id_nombre;
		cout<<"Cuanto credito desea darle a "<<id_nombre<<" ?"<<endl;
		cin>>id_credito;
		id_credito1 = stoi(id_credito);   		//Transforma datos de tipo string a int. Se transforma para poder evaluar si es mayor a 0
		while (id_credito1<0)
		{
			cout<<"El credito no puede ser menor a 0 pesos"<<endl;
			cout<<"Cuanto credito desea darle a "<<id_nombre<<" ?"<<endl;
			cin>>id_credito;
			id_credito1 = stoi(id_credito);   //Transforma datos de tipo string a int. Se transforma para poder guardar el valor en la matriz
		}
			archivo<<"El credito dado al cliente es de "<<id_credito<<" Pesos"<<endl;
		id_credito = to_string(id_credito1);  
		clientes[id_cliente][2]=id_credito;		//Se guarda el valor en la matriz
		clientes[id_cliente][3]="0";
	}
		archivo<<"------------------------------------------------------"<<endl;
		archivo.close();
}

int clientes_buscar()
{
	cout<<"Ingrese el ID de la persona a buscar: "<<endl;
	cin>>id_per;
	if (id_per>id_cliente)
	{
		cout<<"Error, ingrese un Id valido"<<endl;
	}
	else
	{
		int e;
		e=stof(clientes[id_per][0]);  //Transforma datos de tipo cadena a floata
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
			cout<<"Nombre del cliente: "<<clientes[id_per][1]<<"\t Credito: "<<clientes[id_per][2]<<"\t Adeudo: "<<clientes[id_per][3]<<endl;        
		}
	}	
}

int clientes_mostrar()
{
		archivo.open("Registro de clientes.txt", ios::app);
	for (int a=0;a<id_cliente+1;a++)
	{
		cout<<"ID del cliente: "<<clientes[a][0]<<"\t\t Nombre: "<<clientes[a][1]<<"\t\t Credito: "<<clientes[a][2]<<"\t Adeudo: "<<clientes[a][3]<<endl; 
			archivo<<"ID del cliente: "<<clientes[a][0]<<"\t\t Nombre: "<<clientes[a][1]<<"\t\t Credito: "<<clientes[a][2]<<"\t Adeudo: "<<clientes[a][3]<<endl;       
	}
	cout<<"\n";
		archivo<<"-----------------------------------------------------------------------------------------------------"<<endl;
		archivo.close();
}

int clientes_adeudo()
{
		archivo.open("Abono de clientes.txt", ios::app);
	int res=0, abono=0;
	cout<<"Ingrese el ID del cliente: "<<endl;
	cin>>id_per;
	if (id_per>id_cliente)
	{
		cout<<"Error, ingrese un Id valido"<<endl;
	}
	else
	{
		int e;
		e=stoi(clientes[id_per][0]);   //Transforma datos de tipo cadena a int. La variable e toma el valor que hay en la matriz, y lo que hay en la matriz es el Id de algun cliente
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
				archivo<<"El Id del cliente es "<<id_per<<endl;
			int adeudo;
			adeudo=stof(clientes[id_per][3]);  		//Transforma datos de tipo cadena a float, para poder guardar el adeudo del cliente en una variable
			credito=stof(clientes[id_per][2]);		//Transforma datos de tipo cadena a float, para poder guardar el credito de la persona en una variable
			if(adeudo>0)
			{
				cout<<"El adeudo del cliente "<<clientes[id_per][1]<<" es de "<<clientes[id_per][3]<<endl;
					archivo<<"El adeudo del cliente es de "<<clientes[id_per][3]<<endl;
				cout<<"Cuanto quiere abonar el cliente? "<<endl;
				cin>>abono;
					archivo<<"El abono del cliente fue de "<<abono<<endl;
				res=adeudo-abono;
				cout<<"El abono a realizar es de: "<<abono<<endl;
				if (res<=0)
				{
					cout<<"¡Felicidades!, ha saldado su adeudo en  L A  T I E N D I T A  D E  L A  E S Q U I N A"<<endl;
						archivo<<"¡Felicidades!, el cliente ha saldado su cuenta"<<endl;
					if(abono>adeudo)
					{
						abono=abono-adeudo;
						cout<<"El abono fue mayor a la deuda total, su cambio es de "<<abono<<endl;
						res=0;
						credito_acum = credito + adeudo;
					}
				}
				else
				{
					cout<<"Su nuevo saldo es de: "<<res<<endl;
					credito_acum = credito + abono;
						archivo<<"El nuevo saldo del cliente es de "<<res<<endl;
				}
			}	
			else
			{
				cout<<"El cliente no tiene adeudos. ¡Felicidades!"<<endl;
					archivo<<"El cliente no tiene adeudos"<<endl;
			}
		}
	}
	string credito_nue = to_string(credito_acum);		//Transforma datos de tipo entero a cadena, para poder aumentar el credito del cliente y guardarlo en la matriz
	clientes[id_per][2]= credito_nue;
	string adeudo_nue = to_string(res);  			//Tranforma datos de tipo entero a cadena, para guardar el adeudo nuevo en la matriz 
	clientes[id_per][3]=adeudo_nue;
		archivo<<"--------------------------------------------------"<<endl;
		archivo.close();
}

int clientes1()
{
	system("cls");
	cout<<"-- C L I E N T E S --"<<endl;
	cout<<"[1] Agregar clientes"<<endl;
	cout<<"[2] Buscar clientes"<<endl;
	cout<<"[3] Mostar clientes"<<endl;
	cout<<"[4] Abonar credito de clientes"<<endl;
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

int venta_total()
{
		archivo.open("Registro de ventas totales.txt", ios::app);
	cout<<"-- V E N T A S  T O T A L E S --"<<endl;
	cout<<"------------------------------------------"<<endl;
	for (int i=0;i<=3;i++)
	{
		cout<<"ID del cliente: "<<ventas[i][0]<<"\t\t Productos totales: "<<ventas[i][1]<<"\t\t Precio final: "<<ventas[i][2]<<endl;
			archivo<<"ID del cliente: "<<ventas[i][0]<<"\t\t Productos totales: "<<ventas[i][1]<<"\t\t Precio final: "<<ventas[i][2]<<endl;
	}
		archivo<<"--------------------------------------------------------------------------------"<<endl;
		archivo.close();
}

int ven_menu()
{
	system("cls");
	cout<<"-- R E G I S T R O  D E  V E N T A S --"<<endl;
	opc=1;
	switch(opc)
	{
		case 1:
			venta_total();
		break;
		
		default:
			cout<<"Seleccione una opcion valida"<<endl;
		break;

	}
}

int menu(void)
{
	cout<<"[1] Vender"<<endl;
	cout<<"[2] Productos"<<endl;
	cout<<"[3] Clientes"<<endl;
	cout<<"[4] Registros de venta "<<endl;
}


int main()
{
	//Llenado de la matriz de clientes
	clientes[0][0]="0";clientes[0][1]="Carlos";clientes[0][2]="750";clientes[0][3]="250";
	clientes[1][0]="1";clientes[1][1]="Pablo";clientes[1][2]="650";clientes[1][3]="50";
	clientes[2][0]="2";clientes[2][1]="Chapo";clientes[2][2]="420";clientes[2][3]="780";
	
	//Llenado de la matriz de productos
	productos[0][0]="0";productos[0][1]="Takis";productos[0][2]="15";productos[0][3]="20";productos[0][4]="10";
	productos[1][0]="1";productos[1][1]="Arizona";productos[1][2]="18";productos[1][3]="12";productos[1][4]="6";
	productos[2][0]="2";productos[2][1]="Tortillas";productos[2][2]="20";productos[2][3]="10";productos[2][4]="5";

	do
	{
		cout<<"-- P U N T O  D E  V E N T A  L A  E S Q U I N A --"<<endl;

		menu();
		cout<<"Seleccione una opcion: ";cin>>opc;
		switch (opc)
		{
			case 1:
					venta();
					system("cls");
			break;
				
			case 2:
				do
				{
					productos1();
					cout<<"Desea hacer otra operacion? 1-Si -- 2-No"<<endl;
					cin>>resp2;	
					system("cls");
				}while (opc3==resp2);
			break;			
			
			case 3:
				do
				{
					clientes1();
					cout<<"Desea hacer otra operacion? 1-Si -- 2-No"<<endl;
					cin>>resp3;
					system("cls");
				}while (opc4==resp3);
				
			break;
			
			case 4:
				do
				{
					ven_menu();
					cout<<"Desea hacer otra operacion? 1-Si -- 2-No"<<endl;
					cin>>resp4;
					system("cls");
				} while(opc6==resp4);
				
			break;
				
			default:
				cout<<"Seleccione una opcion valida "<<endl;
				system("pause");
		}
		resp1=1;
		system("cls");
	}while (opc1==resp1);
	
} 
