#pragma once
#include "Enemigo.h"
class BossCaC :
	public Enemigo
{
public:
	//variables
	Vector3D objetivo;
	Vector3D prevobjetivo;
	Vector3D d;
	float preangrot;
	bool enreposo;
	int asdf, tiempo, tiempo0;
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
	bool atacar(int){ return true; }
};

