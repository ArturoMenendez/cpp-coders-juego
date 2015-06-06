#pragma once
#include "Vector3D.h"
#include "CrashBox.h"
#include "glut.h"


class Objeto
{
public:
	//variables
	Vector3D posicion;
	CrashBox limites;
	int giraanima;
	//metodos
	Objeto(Vector3D);
	~Objeto();
	void Dibuja();
	void Anima();
	CrashBox getCrashBox();
};

