#pragma once
#include "Disparo.h"
#include "Jugador.h"
#define MAX_DISPAROS 100

class ListaDisparos
{
public:
	int tam_lista;
	Disparo *lista[MAX_DISPAROS];
public:
	ListaDisparos();
	~ListaDisparos();
	void agregarDisparos(Jugador tirador);
	void actualizarDisparos(const int t);
	void dibujarDisparos();
};

