#pragma once
#include "Vector3D.h"
#include "CrashBox.h"
#include "glut.h"
enum Tipo		//codigo 0, puntos 1, daño 2, velocidad 3, invulnerable 4, ¿disparos 5?
{
	CODIGO, PUNTOS, DANIO, VELOCIDAD, INVLUNERABLE, DISPAROS
};

class Objeto
{
protected:
	Vector3D posicion;
	CrashBox limites;
	int aux;
	int tipo;
	void Anima();
public:
	Objeto();
	Objeto(Vector3D pos);
	~Objeto();
	virtual void Dibuja()=0;
	CrashBox getCrashBox();
};

