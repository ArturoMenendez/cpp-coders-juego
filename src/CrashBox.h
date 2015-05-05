#pragma once
#include "Vector3D.h"
#define RECTANGULO 0
#define CIRCULO 1

class CrashBox
{
public:
	int tipo;
	float radio;
	float ancho;
	float alto;
	Vector3D posicion;

public:
	CrashBox(Vector3D posicion, float radio);
	CrashBox(Vector3D posicion, float ancho, float alto);
	CrashBox();
	~CrashBox();
	void Dibuja();
	static bool interaccion(CrashBox obj1, CrashBox obj2);
	
};

