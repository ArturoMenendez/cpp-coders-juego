#pragma once
#include "Enemigo.h"
class ADistancia : public Enemigo
{
public:
	
	ADistancia();
	ADistancia(Vector3D);
	~ADistancia();
	void Dibuja();
};

