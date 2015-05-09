#pragma once
#include "stdio.h"
#include "ListaObstaculos.h"
#include "string.h"


#define NUM_NIVELES 10


class Nivel
{
	FILE *pfile[NUM_NIVELES];
	//FILE *pfile;
	bool pasanivel[NUM_NIVELES];
	char buffer[20];
	float param[8];
	ListaObstaculos lobs;
	int act;
public:
	void LeeNivel();
	void Carga();
	void Dibuja();
	Nivel();
	~Nivel();
};

