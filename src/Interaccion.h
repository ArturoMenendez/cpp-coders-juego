#pragma once

#include "ListaDisparos.h"
#include "ListaObstaculos.h"
#include "Jugador.h"
#include "ListaEnemigos.h"
#include "Pared.h"

class Interaccion
{
public:
	Interaccion();
	~Interaccion();
	static void interaccion(ListaDisparos disparo, ListaObstaculos obstaculo);
	static void interaccion(ListaDisparos disparo, ListaEnemigos enemigo, Jugador &jugador);
	static void interaccion(Jugador &jugador, ListaObstaculos obstaculo);
	static void interaccion(ListaEnemigos enemigo, ListaObstaculos obstaculo);
	static void interaccion(ListaEnemigos enemigos);
	static void interaccion(Jugador jugador, ListaEnemigos enemigo);
	static void ldv(ListaObstaculos obstaculo, ListaEnemigos enemigo);

};

