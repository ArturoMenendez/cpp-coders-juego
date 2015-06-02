#pragma once
#include "Enemigo.h"

class CaC : public Enemigo
{
public:
	CaC();
	CaC(Vector3D,int);
	~CaC();
	void Dibuja();
};

