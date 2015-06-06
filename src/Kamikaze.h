#pragma once
#include "Enemigo.h"

class Kamikaze :
	public Enemigo
{
	int rueda;
public:
	Kamikaze();
	Kamikaze(Vector3D,int);
	~Kamikaze();
	void Dibuja();
	void Anima();
	bool atacar(int t);
};

