#pragma once
#include "Vector3D.h"
#include "Cilindro.h"
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
	Cilindro c1;
	Pierna p1, p2;
	//metodos
	Jugador(void);
	void Mouse(int, int, int, int);
	void Motion(int, int);
	void PassiveMotion(int, int);
	~Jugador(void);
	void Pinta();
	void Dibuja();
	void Rota();
	void Mueve(unsigned char);
	void Anima();
};

