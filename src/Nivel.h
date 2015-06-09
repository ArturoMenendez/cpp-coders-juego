#pragma once
#include "stdio.h"
#include "ListaObjetos.h"
#include "ListaObstaculos.h"
#include "ListaEnemigos.h"
#include "ListaDisparos.h"
#include "Jugador.h"
#include "Pared.h"

#define NUM_NIVELES 12


class Nivel
{
	FILE *pfile[NUM_NIVELES];
	bool pasanivel[NUM_NIVELES];
	char buffer[20];
	float param[8];
	Jugador j;
	ListaObstaculos lobs;
	ListaDisparos ldis;
	ListaEnemigos lenem;
	ListaObjetos lobj;
	int act;
	Pared caja[4];
public:
	void LeeNivel();
	void Carga();
	void Dibuja();
	void Borrar();


	void actualizaListas();
	void nuevoDisparo();
	void updateEnemigos();
	void interacciones();
	void rotaJugador();


	void KeyOperations();
	void OnKeyboardDown(unsigned char, int, int);
	void OnKeyboardUp(unsigned char, int, int);
	void OnMouseDown(int button, int state, int x, int y);
	void OnMotion(int x, int y);
	void OnPassiveMotion(int x, int y);

	int GetPuntos(){ return j.puntos; }
	int GetCodigo(){ return j.codigo; }
	int GetMejoras();
	int GetNumeroEnemigos(){ return lenem.getNumero(); }
	bool GetTocapuerta(){ return j.tocapuerta; }
	int GetSalud(){ return j.salud; }
	void SetSalud(int salud){ j.salud = salud; }
	int GetNivel(){ return act; }
	void SetNivel(int numero){ act = numero; }
	bool GetPasaNivel(int numero){ return pasanivel[numero]; }
	void SetPasaNivel(int numero){ pasanivel[numero] = true; }
	void SetModificadores(){ j.mod_danio = j.mod_vel = 1; j.invencible = 0; }
	Nivel();
	~Nivel();

};
