#pragma once
#include "Vector3D.h"
#include "CrashBox.h"


class Obstaculo
{
public:
	//variables
	bool destruir;		
	bool se_destruye;	//especifica si el obstaculo puede ser destruido por el jugador
	int id;				//MURO=1, BIDON=2, AGUJERO=3
	Vector3D posicion;	//posicion del centro del bidon, de las paredes y de los agujeros
	Vector3D tamanio;
	CrashBox limites;

	//metodos
	void Dibuja();
	Obstaculo(Vector3D posicion, Vector3D tamanio, int tipo, bool destruccion);
	~Obstaculo();
};