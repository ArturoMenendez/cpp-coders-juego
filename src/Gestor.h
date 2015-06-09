#pragma once
#include "Nivel.h"
#include "OpenGL.h"
#include "glut.h"
#include "Texto.h"
#include "Marcador.h"
enum Estado
	{
		INICIO,
		JUEGO,
		PAUSA,
		GAMEOVER,
		FIN
	};

class Gestor
{
public:
	//variables
	int estado;
	Marcador marcador;
	int vidas;
	int puntuacion;

	//metodos
	//constructor y destructor
	Gestor();
	virtual ~Gestor();

	//metodos que afectan a los entes fisicos
	void Dibuja();
	void Mueve();
	void Update();

	//metodos para control del juego
	void Condiciones();

	//metodos para marcador
	int GetPuntos();
	void SetTiempo(int tiempo);


	//metodos relacionados mayormente con glut 
	void OnKeyboardDown(unsigned char);
	void OnKeyboardUp(unsigned char);
	void KeyOperations();
	void OnMouseDown(int button, int state, int x, int y);
	void OnMotion(int x, int y);
	void OnPassiveMotion(int x, int y);
protected:
	Nivel nivel;

};