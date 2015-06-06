#pragma once
#include "Enemigo.h"

class CaC : public Enemigo
{
public:
	float z;
	bool flag;
	CaC();
	CaC(Vector3D,int);
	~CaC();
	void Dibuja();
	void Anima();
	bool atacar(int t);
};

