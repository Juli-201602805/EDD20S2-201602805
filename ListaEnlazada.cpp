#include "pch.h"
#include "ListaEnlazada.h"
#include "NodoLista.h"
#include <iostream>
#include <string>

using namespace std;



void::ListaEnlazada::Menu()
{
	int opcion;
	int carnet;
	string nombre;


	do
	{
		cout << "\n***************************************";
		cout << "\n**              LISTA SIMPLE         **";
		cout << "\n***************************************";
		cout << "\n** 1. Insertar                       **";
		cout << "\n** 2. Buscar                         **";
		cout << "\n** 3. Eliminar                       **";
		cout << "\n** 4. Mostrar Lista                  **";
		cout << "\n** 5. Salir                          **";
		cout << "\n***************************************";
		cout << "\n\n Escoja una Opcion: ";
		cin >> opcion;

		switch (opcion)
		{
		case 1:
			cout << "\n\n Isertar Datos En La Lista \n\n";
			cout << " *Ingrese Carnet: ";
			cin >> carnet;
			cout << " *Ingrese Nombre: ";
			cin >> nombre;
		    Insertar(carnet, nombre);
			break;
		case 2:
			cout << "\n\n Buscar Datos En La Lista \n\n";
			Buscar();
			break;
		case 3:
			cout << "\n\n Eliminar Datos De La Lista \n\n";
			Eliminar();
			break;
		case 4:
			cout << "\n\n Desplegar Lista \n\n";
			MostrarLista();
			break;
		case 5:
			cout << "\n\n Programa finalizado...";
			break;
		default:
			cout << "\n\n Opcion No Valida \n\n";
		}
	} while (opcion!= 6);


	//return 0;
}

void ListaEnlazada::Insertar(int carnet, string nombre)
{
	NodoLista* nuevo;
	nuevo = new NodoLista(carnet, nombre);
	

	if(Primero == nullptr)
	{
		Primero = nuevo;
		Primero->Siguiente = nullptr;
		Ultimo = nuevo;
	}
	else
	{
		Ultimo->Siguiente = nuevo;
		nuevo->Siguiente = nullptr;
		Ultimo = nuevo;
	}

	cout << " *Datos Ingresados";
}

void ListaEnlazada::Buscar()
{
	NodoLista* actual;
	actual = new NodoLista();
	actual = Primero;
	bool nodoEncontrado = false;
	string nodoBuscar;
	int carnet;

	cout << " ** Ingrese el nombre del estudiante a buscar: **";
	cin >> nodoBuscar;

	if(Primero != nullptr)
	{
		while(actual != nullptr && nodoEncontrado != true)
		{
			if (actual->nombre == nodoBuscar)
			{
				cout << " **Nodo con el dato " << nodoBuscar << " Encontrado "<<endl;
				nodoEncontrado = true;
				cout << " Carnet: " << actual->carnet << " Nombre: " << actual->nombre << endl;

			}

			actual = actual->Siguiente;
		}
		if (!nodoEncontrado)
		{
			cout << " ** Nodo No Encontrado ** ";
		}
	}
	else
	{
		cout << " ** La Lista se encuentra Vacia ** ";
	}
}
	
void ListaEnlazada::Eliminar()
{
	NodoLista* actual;
	actual = new NodoLista();
	actual = Primero;
	NodoLista* Anterior = new NodoLista();
	Anterior = nullptr;
	bool nodoEncontrado = false;
	string nodoBuscado = "";
	cout << " Ingrese el nombre del alumno a Buscar para eliminar: ";
	cin >> nodoBuscado;

	if (Primero!= nullptr)
	{

		while (actual!= nullptr && nodoEncontrado!= true)
		{

			if (actual->nombre == nodoBuscado)
			{
				cout << " ** Nodo con el dato " << nodoBuscado << " Encontrado ** ";

				if (actual == Primero)
				{
					Primero = Primero->Siguiente;
				} else if (actual == Ultimo)
				{
					Anterior->Siguiente = nullptr;
					Ultimo = Anterior;
				}
				else
				{
					Anterior->Siguiente = actual->Siguiente;
				}

				cout << " ** Alumno ELiminado Con Exito ** ";

				nodoEncontrado = true;
			}

			Anterior = actual;
			actual = actual->Siguiente;
		}
		if (!nodoEncontrado)
		{
			cout << " ** Nodo No Encontrado ** ";
		}
	}
	else
	{
		cout << " \ n La Lista se encuentra Vacia \ n \ n ";
	}
}

void ListaEnlazada::MostrarLista()
{
	NodoLista* actual;
	actual = new NodoLista();
	actual = Primero;
	int carnet;
	string nombre;
	if (Primero != nullptr) 
	{

		while (actual != nullptr) 
		{
			cout << " Carnet: "<< actual->carnet<< " Nombre: "<< actual->nombre << endl;
			actual = actual->Siguiente;
		}

	}
	else {
		cout << " ** La Lista se Encuentra Vacia ** ";
	}
}

