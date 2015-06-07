#pragma once

#include "Vector3D.h"
#include "Jugador.h"
#include "CrashBox.h"
#include "Enemigo.h"

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
	bool enemigo;
	bool dib; //simula ataque cuerpo a cuerpo, el disparo no se pinta

public:
	bool destruir;

	Disparo(Jugador personaje, int vida, int danio);
	Disparo(Enemigo &enem, int vida, int danio, bool dibujar, float desfase);
	Disparo();
	~Disparo();
	void dibujar();
	void updateDisparo(const int t);
	CrashBox getCrashBox();
	void destruye();
	int getDanio() { return danio; }
	bool getTipo() { return enemigo; }

};

