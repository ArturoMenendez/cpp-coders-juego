#pragma once
#include "Objeto.h"
#include "Vector3D.h"
#define MAX_OBJETOS 20

class ListaObjetos
{
	int n_objetos;
	Objeto *lista[MAX_OBJETOS];
public:
	ListaObjetos();
	~ListaObjetos();
	void agregarObjetos(Vector3D posicion, int tipo);
	void dibujarObjetos();
	void destruirObjetos();
	void borraObjetos();
	friend class Interaccion;
};

