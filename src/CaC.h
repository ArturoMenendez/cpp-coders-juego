#pragma once
#include "Enemigo.h"

class CaC : public Enemigo
{
public:
	CaC();
	CaC(Vector3D);
	~CaC();
	void Dibuja();
};

