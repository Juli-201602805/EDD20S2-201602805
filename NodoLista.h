#pragma once
#include <iostream>
#include <string>
using namespace std;

class NodoLista
{
public:
	NodoLista* Siguiente;

	int carnet;
	string nombre;

	NodoLista(int dato1, string dato2)
	{
		Siguiente = nullptr;
		carnet = dato1;
		nombre = dato2;
	}

	NodoLista()
	{
	}

};

