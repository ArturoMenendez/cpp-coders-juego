#pragma once
#include "Vector3D.h"


class Obstaculo
{
public:
	//variables
	bool seDestruye;
	int id;				//MURO=1, BIDON=2, AGUJERO=3
	enum asdf{muro,pared};
	Vector3D posicion;	//posicion del centro del bidon, de las paredes y de los agujeros
	Vector3D tamaño;

	//metodos
	void Dibuja();
	Obstaculo();
	~Obstaculo();
};
