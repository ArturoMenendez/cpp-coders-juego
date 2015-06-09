#pragma once
#include "Vector3D.h"
#include "CrashBox.h"
#include "glut.h"
enum Tipo		//codigo 0, puntos 1, daño 2, velocidad 3, invulnerable 4, ¿disparos 5?
{
	CODIGO, PUNTOS, DANIO, VELOCIDAD, INVULNERABLE, DISPAROS
};

class Objeto
{
protected:
	Vector3D posicion;
	CrashBox limites;
	int aux;
	int tipo;
	int valor;
	bool destruir;
	void Anima();
public:
	Objeto();
	Objeto(Vector3D pos, int id, int val);
	~Objeto();
	virtual void Dibuja()=0;
	CrashBox getCrashBox();
	bool getDestruir();
	int getTipo();
	int getValor();
	void setDestruir(bool est);
};

