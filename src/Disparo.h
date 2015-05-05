#pragma once
#include "Vector3D.h"
#include "Jugador.h"
#include "CrashBox.h"

class Disparo
{
	CrashBox limites;
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
	float x;	//pasar a vector 3D
	float y;
	float z;
	float vx;	//pasar a vector 3D
	float vy;
	float radio;
	int daño;
	int vida;

public:
	Disparo(Jugador personaje);
	Disparo();
	~Disparo();
	void dibujar();
	bool updateDisparo(const int t);

};

