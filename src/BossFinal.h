#pragma once
#include "Enemigo.h"
class BossFinal :
	public Enemigo
{
	int time1;
	int time2;
public:
	BossFinal(Vector3D posicion, int id);
	~BossFinal();
	void Dibuja();
	//void GiraAnima();
	void MueveAleat();
	void  Update();
	void Rota();
	bool atacar(int t);
	void Anima();
};

