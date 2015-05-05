#pragma once
#include "Jugador.h"

class Mundo

{
public:
	//variables

	Jugador j1;

	//metodos

	void Dibuja();
	void Pinta();
	void Rota();
	void Mueve(unsigned char);
	void Anima();
	void Mouse(int, int, int, int);
	void Motion(int, int);
	void PassiveMotion(int, int);
	Mundo(void);
	~Mundo(void);

	void KeyOperations(void);
	void NoMueve(unsigned char);
};

