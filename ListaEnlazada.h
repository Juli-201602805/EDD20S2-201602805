#pragma once
#include "NodoLista.h"
#include <iostream>
#include <string>
using namespace std;
class ListaEnlazada
{
public:
	NodoLista* Primero;
	NodoLista* Ultimo;

	
	ListaEnlazada()
	{
		Primero = nullptr;
		Ultimo = nullptr;
	}

	void Insertar(int carnet, string nombre);
	void Buscar();
	void Eliminar();
	void MostrarLista();
	void Menu();


	
};

