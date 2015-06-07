#pragma once
#include "Enemigo.h"
class BossCaC :
	public Enemigo
{
public:
	//variables
	Vector3D d;
	bool enreposo;
	int cont;
	float aux;
	//metodos
	BossCaC();
	BossCaC(Vector3D, int);
	~BossCaC();
	void Dibuja();
	void Anima();
	void MueveAleat();
	void Update();
	void Rota();
	bool atacar(int);
};

