#pragma once
#include "Vector3D.h"

class Esfera
{
public:
	//variables
	float radio;
	Vector3D posicion;
	unsigned char r;
	unsigned char g;
	unsigned char b;
	//metodos
	Esfera(void);
	void Mouse(int, int, int, int);
	~Esfera(void);
	void Dibuja();
};

