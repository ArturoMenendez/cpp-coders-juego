#pragma once
#include "Enemigo.h"
class ADistancia : public Enemigo
{
public:
	
	ADistancia();
	ADistancia(Vector3D, int);
	~ADistancia();
	void Dibuja();
	void Anima();
	bool atacar(int t);
};

