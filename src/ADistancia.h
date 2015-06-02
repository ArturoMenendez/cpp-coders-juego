#pragma once
#include "Enemigo.h"
class ADistancia : public Enemigo
{
public:
	
	ADistancia();
	ADistancia(Vector3D, int id);
	~ADistancia();
	void Dibuja();
};

