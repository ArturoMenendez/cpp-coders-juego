#pragma once
#include "Vector3D.h"
#include "glut.h"

class Cilindro
{
public:
	//variables
	float altura;
	float base;
	float tapa;
	unsigned char r, g, b;
	float ang;
	Vector3D posicion;
	Vector3D ejez;
	Vector3D mov; //x=ang menor, y=ang mayor, z=velocidad
	//metodos
	Cilindro(void);
	~Cilindro(void);
	void Dibuja();
	void Anima();
};
