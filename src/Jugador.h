#pragma once
#include "Vector3D.h"
#include "Pierna.h"
#include "CrashBox.h"


class Jugador
{
public:
	//variables
	Vector3D posicion;
	Vector3D pos_anterior;
	Vector3D ptomira;
	CrashBox limites;
	bool botonpulsado;
	bool colision;
	float angrot;
	bool* keyStates = new bool[256];
	Pierna p1, p2;
	Cilindro c1;
	int salud;
	int puntos;
	int codigo;
	bool movimiento;
	bool tocapuerta;
	int contador;
	int mod_danio;
	int mod_vel; 
	int invencible;



	//metodos
	Jugador(void);
	Jugador(Vector3D);
	~Jugador(void);
	CrashBox getCrashBox();
	void act_salud(int danio);
	void invencibilidad(int t);
	void Mouse(int, int, int, int);
	void Motion(int, int);
	void PassiveMotion(int, int);
	void Pinta();
	void Dibuja();
	void Explota();
	void Rota();
	void Mueve(unsigned char);
	void Anima();
	void KeyOperations(void);
	void NoMueve(unsigned char);
	void Reinicia(Vector3D posicion);
};