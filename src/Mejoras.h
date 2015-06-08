#pragma once
#include "Objeto.h"
class Mejora :
	public Objeto
{
protected:
	int vida;
public:
	Mejora(Vector3D pos, int id, int val);
	~Mejora();
};

class Mpuntos :
	public Mejora
{
public:
	Mpuntos(Vector3D pos);
	~Mpuntos();
	void Dibuja();
};

class Mdanio :
	public Mejora
{
public:
	Mdanio(Vector3D pos);
	~Mdanio();
	void Dibuja();
};

class Mvelocidad :
	public Mejora
{
public:
	Mvelocidad(Vector3D pos);
	~Mvelocidad();
	void Dibuja();
};

class Minvencible :
	public Mejora
{

public:
	Minvencible(Vector3D pos);
	~Minvencible();
	void Dibuja();
};
