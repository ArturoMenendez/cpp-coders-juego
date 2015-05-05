#pragma once
#include "Esfera.h"
#include "Cilindro.h"
#include "Vector3D.h"

class Pierna
{
public:
	//variables
	Esfera e1, e2;
	Cilindro c1;
	Vector3D posicion;
	Vector3D mov;
	float ang;
	//metodos
	void Dibuja();
	void Anima();
	Pierna();
	~Pierna();
};
