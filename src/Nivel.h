#pragma once
#include "stdio.h"
#include "ListaObstaculos.h"
#include "ListaEnemigos.h"
#include "ListaDisparos.h"
#include "Jugador.h"
#include "Pared.h"
#include "Marcador.h"

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
	int act;
	Pared caja[4];
	Marcador marcador;
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


	int GetNumeroEnemigos(){ return lenem.n_enemigos; }
	bool GetTocapuerta(){ return j.tocapuerta; }
	int GetVida(){ return j.vida; }
	int GetNivel(){ return act; }
	void SetNivel(int numero){ act = numero; }
	bool GetPasaNivel(int numero){ return pasanivel[numero]; }
	void SetPasaNivel(int numero){ pasanivel[numero] = true; }
	Nivel();
	~Nivel();

};
