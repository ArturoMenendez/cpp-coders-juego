#pragma once
#include "Vector3D.h"
#include "Pierna.h"
#include "CrashBox.h"
#include "bitmap.h"

class Enemigo
{
public:
	//variables
	Vector3D posicion;
	Vector3D pos_anterior;
	Vector3D direccion;
	CrashBox limites;
	CrashBox lin;
	float angrot;
	int id;
	int vida;
	int t0;
	int t;
	bool teveo;
	float mov_teveo = 20, mov_noteveo = 20;
	//metodos

	Enemigo(void);
	Enemigo(Vector3D,int);
	virtual ~Enemigo(void);
	
	virtual void Dibuja() = 0;
	void Rota();
	void Anima();
	void MueveAleat();
	void Update();
	CrashBox getCrashBox();
	void act_Vida(int danio);
	virtual bool atacar(int t) = 0;
};