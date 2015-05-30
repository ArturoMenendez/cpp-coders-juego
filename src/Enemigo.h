#pragma once
#include "Vector3D.h"
#include "Pierna.h"
#include "CrashBox.h"


class Enemigo
{
public:
	//variables
	Vector3D posicion;
	Vector3D pos_anterior;
	Vector3D ptomira;
	Vector3D direccion;
	CrashBox limites;
	CrashBox lin;
	float angrot;
	Pierna p1, p2;
	Cilindro c1;
	int id;
	bool destruir;
	int t;
	int recorrido;
	bool teveo;
	//metodos

	Enemigo(void);
	Enemigo(Vector3D,int);
	~Enemigo(void);
	
	virtual void Dibuja();
	void Rota();
	void Anima();
	void MueveAleat();
	void Update();
	CrashBox getCrashBox();
};