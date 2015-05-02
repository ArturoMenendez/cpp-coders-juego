#pragma once
#include "Vector3D.h"

class Disparo
{
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
	float x;
	float y;
	float z;
	float vx;
	float vy;
	float radio;
	int daño;
	int vida;

public:
	Disparo(Vector3D jugador, Vector3D mira);
	Disparo();
	~Disparo();
	void dibujar();
	bool updateDisparo(const int t);

};
