#pragma once
#include "Obstaculo.h"
#include "Vector3D.h"
#define MAX_OBSTACULOS 50

class ListaObstaculos
{
public:
	int n_obstaculos;
	Obstaculo *lista[MAX_OBSTACULOS];

public:
	ListaObstaculos();
	~ListaObstaculos();
	void agregarObstaculo(Vector3D posicion, Vector3D tamanio, int tipo, bool destruccion);
	void dibujarObstaculos();
	void actualizarObstaculos();
	void animarObstaculos();
	void borraObstaculos();
	friend class Interaccion;
};

