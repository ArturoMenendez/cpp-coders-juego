#pragma once
#include "Vector3D.h"

#define RECTANGULO 0
#define CIRCULO 1
#define LINEA 2
#define AGUJERO 3
#define PUERTAENTRADA 8
#define PUERTASALIDA 9

class CrashBox
{
public:
	int tipo;
	float radio;
	float ancho;
	float alto;
	float largo;
	Vector3D direccion;
	Vector3D posicion;

public:
	CrashBox(Vector3D posicion, float radio);
	CrashBox(Vector3D posicion, float ancho, float alto);
	CrashBox(Vector3D posicion, Vector3D direccion, float largo);
	CrashBox();
	~CrashBox();
	void Dibuja();

};