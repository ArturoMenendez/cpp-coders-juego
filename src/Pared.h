#pragma once
#include "bitmap.h"
#include "Vector3D.h"

class Pared
{
	Vector3D limite1;
	Vector3D limite2;
	
public:
	Pared(float x1 = 0.0F, float y1 = 0.0F, float x2 = 0.0F, float y2 = 0.0F);
	~Pared();
	Vector3D getLimite1();
	Vector3D getLimite2();
	void Dibuja();
};

