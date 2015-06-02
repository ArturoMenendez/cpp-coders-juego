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
	Vector3D pos;
	Vector3D vel;
	float radio;
	int danio;
	int vida;

public:
	bool destruir;

	Disparo(Jugador personaje);
	Disparo();
	~Disparo();
	void dibujar();
	void updateDisparo(const int t);
	CrashBox getCrashBox();
	void destruye();
	int getDanio() { return danio; }

};

