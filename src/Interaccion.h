#pragma once

#include "ListaDisparos.h"
#include "ListaObstaculos.h"

class Interaccion
{
public:
	Interaccion();
	~Interaccion();
	static void interaccion(ListaDisparos disparo, ListaObstaculos obstaculo);
};

