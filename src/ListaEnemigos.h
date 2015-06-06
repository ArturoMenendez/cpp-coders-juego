#pragma once
#include "Enemigo.h"
#include "CaC.h"
#include "ADistancia.h"
#include "Kamikaze.h"
#include "BossCaC.h"
#include "Vector3D.h"
#include "ListaDisparos.h"
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
	void destruirEnemigo();
	void mueveEnemigos();
	void updateEnemigos(Vector3D jugador);
	void rotaEnemigos();
	void updateEnemigos(Vector3D jugador, ListaDisparos &ldis);
};

