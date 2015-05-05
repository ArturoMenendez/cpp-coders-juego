#pragma once
#include "Vector3D.h"
#include "Pierna.h"

class Jugador
{
public:
	//variables
	float radio;
	Vector3D posicion;
	Vector3D ptomira;
	unsigned char r;
	unsigned char g;
	unsigned char b;
	bool botonpulsado;
	float angrot;
	bool* keyStates = new bool[256];
	Pierna p1, p2;
	Cilindro c1;
	//metodos
	Jugador(void);
	~Jugador(void);
	void Mouse(int, int, int, int);
	void Motion(int, int);
	void PassiveMotion(int, int);
	void Pinta();
	void Dibuja();
	void Rota();
	void Mueve(unsigned char);
	void Anima();
	void KeyOperations(void);
	void NoMueve(unsigned char);
};