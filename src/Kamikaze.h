#pragma once
#include "Enemigo.h"

class Kamikaze :
	public Enemigo
{
public:
	int rueda;
	Kamikaze();
	Kamikaze(Vector3D,int);
	~Kamikaze();
	void Dibuja();
};

