#pragma once
#include "stdio.h"
#include "ListaObstaculos.h"
#include "ListaEnemigos.h"
#include "ListaDisparos.h"
#include "Jugador.h"
#include "Pared.h"

#define NUM_NIVELES 10


class Nivel
{
	FILE *pfile[NUM_NIVELES];
	//FILE *pfile;
	bool pasanivel[NUM_NIVELES];
	char buffer[20];
	float param[8];
	Jugador j;
	ListaObstaculos lobs;
	ListaDisparos ldis;
	ListaEnemigos lenem;
	int act;
	Pared caja[4];
public:
	void LeeNivel();
	void Carga();
	void Dibuja();

	void actualizaListas();
	void nuevoDisparo();
	void updateEnemigos();
	void interacciones();

	void rotaJugador();
	void KeyOperations();
	void OnKeyboardDown(unsigned char, int, int);
	void OnKeyboardUp(unsigned char, int, int);
	void OnMouseDown(int button, int state, int x, int y);
	void OnMotion(int x, int y);
	void OnPassiveMotion(int x, int y);
	Nivel();
	~Nivel();

};

