#pragma once
#include "Vector3D.h"
#include "CrashBox.h"


class Obstaculo
{
public:
	//variables
	bool seDestruye;
	int id;				//MURO=1, BIDON=2, AGUJERO=3
	enum asdf{ muro, pared };
	Vector3D posicion;	//posicion del centro del bidon, de las paredes y de los agujeros
	Vector3D tamanio;
	CrashBox limites;

	//metodos
	void Dibuja();
	Obstaculo(Vector3D posicion, Vector3D tamanio, int tipo);
	~Obstaculo();
};