#pragma once
#include "Disparo.h"
#include "Jugador.h"
#include "Enemigo.h"
#define MAX_DISPAROS 100

class ListaDisparos
{
public:
	int tam_lista;
	Disparo *lista[MAX_DISPAROS];
public:
	ListaDisparos();
	~ListaDisparos();
	void agregarDisparos(Jugador tirador, int vida, int danio);
	void agregarDisparos(Enemigo &tirador, int vida, int danio, bool dibujar, float desfase=0.0f);
	void actualizarDisparos(const int t);
	void dibujarDisparos();
	void borraDisparos();
};

