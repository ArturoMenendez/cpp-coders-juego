#pragma once
#include "Vector3D.h"
#include "Pierna.h"

class Enemigo
{
public:
	//variables
	Vector3D posicion;
	Vector3D ptomira;
	Vector3D direccion;
	float angrot;
	Pierna p1, p2;
	Cilindro c1;
	int id;
	bool destruir;
	int t;
	int recorrido;
	//metodos
	Enemigo(void);
	Enemigo(Vector3D,int);
	~Enemigo(void);
	virtual void Dibuja();
	void Rota();
	void Anima();
	void Mueve();
	void Update();
};
