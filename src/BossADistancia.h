#pragma once
#include "Enemigo.h"
class BossADistancia :
	public Enemigo
{
public:
	//variables

	//metodos
	BossADistancia(Vector3D, int);
	~BossADistancia();
	void Dibuja();
	void Anima();
	bool atacar(int t);
	void MueveAleat();
	void Update();
	void Rota();
};

