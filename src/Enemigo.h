#pragma once
#include "Vector3D.h"
#include "Pierna.h"
#include "CrashBox.h"
#include "bitmap.h"
#define MAX_X	20.0f
#define MAX_Y	12.5f

class Enemigo
{
public:
	//variables
	Vector3D posicion;
	Vector3D pos_anterior;
	Vector3D direccion;
	Vector3D objetivo;
	CrashBox limites;
	CrashBox lin;
	float angrot;
	int id;
	int vida;
	int t0;
	int t;
	bool teveo;
	float mov_teveo, mov_noteveo;
	float giraanima;
	float contador;
	float f_explo;
	//metodos

	Enemigo(void);
	Enemigo(Vector3D,int);
	virtual ~Enemigo(void);
	
	virtual void Dibuja() = 0;
	virtual void Rota();
	virtual void Anima() = 0;
	void GiraAnima();
	virtual void MueveAleat();
	virtual void Update();
	CrashBox getCrashBox();
	void act_Vida(int danio);
	virtual bool atacar(int t) = 0;
	virtual void Explota();
};