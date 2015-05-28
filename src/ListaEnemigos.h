#pragma once
#include "Enemigo.h"
#include "Vector3D.h"
#define MAX_ENEMIGOS 20

class ListaEnemigos
{
public:
	int n_enemigos;
	Enemigo *lista[MAX_ENEMIGOS];
public:
	ListaEnemigos();
	~ListaEnemigos();
	void agregarEnemigo(Vector3D posicion, int tipo);
	void dibujarEnemigos();
	void actualizarEnemigos();
	void mueveEnemigos();
	void updateEnemigos(Vector3D jugador);
	void rotaEnemigos();
};

