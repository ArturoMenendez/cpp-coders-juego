#pragma once

#include "ListaDisparos.h"
#include "ListaObstaculos.h"
#include "Jugador.h"

class Interaccion
{
public:
	Interaccion();
	~Interaccion();
	static void interaccion(ListaDisparos disparo, ListaObstaculos obstaculo);
	static void interaccion(Jugador jugador, ListaObstaculos obstaculo);
};
