#pragma once
#include "Vector3D.h"
class Esfera
{
public:
	//variables
	float radio;
	unsigned char r, g, b;
	Vector3D posicion;



	//metodos
	void Dibuja();
	Esfera();
	~Esfera();
};
