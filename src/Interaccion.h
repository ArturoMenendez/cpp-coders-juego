#pragma once

#include "ListaDisparos.h"
#include "ListaObstaculos.h"
#include "Jugador.h"
#include "ListaEnemigos.h"

class Interaccion
{
public:
	Interaccion();
	~Interaccion();
	static void interaccion(ListaDisparos disparo, ListaObstaculos obstaculo);
	static void interaccion(Jugador &jugador, ListaObstaculos obstaculo);
	static void interaccion(ListaEnemigos enemigo, ListaObstaculos obstaculo);
	static void ldv(ListaObstaculos obstaculo, ListaEnemigos enemigo);

};
