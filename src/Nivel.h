#pragma once
#include "stdio.h"
#include "ListaObstaculos.h"
#include "ListaEnemigos.h"
#include "Jugador.h"

#define NUM_NIVELES 10


class Nivel
{
	FILE *pfile[NUM_NIVELES];
	//FILE *pfile;
	bool pasanivel[NUM_NIVELES];
	char buffer[20];
	float param[8];
	ListaObstaculos lobs;
	Jugador j;
	ListaEnemigos lenem;
	int act;
public:
	void LeeNivel();
	void Carga();
	void Dibuja();
	ListaObstaculos getLisObs();
	void actualizaLisObs();
	ListaEnemigos getLisEnem();
	void actualizaLisEnem();
	void mueveLisEnem();
	void updateLisEnem();
	void rotaLisEnem();
	Jugador getJugador();
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

