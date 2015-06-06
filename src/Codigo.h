#pragma once
#include "Objeto.h"
class Codigo :
	public Objeto
{
public:
	Codigo(Vector3D pos);
	~Codigo();
	void Dibuja();
};

