#pragma once
#include "Nivel.h"
#include "OpenGL.h"
#include "glut.h"
#include "Texto.h"


class Gestor
{
public:
	//variables
	enum Estado
	{
		INICIO,
		JUEGO,
		PAUSA,
		GAMEOVER,
		FIN
	};
	Estado estado;
	bool pasar;
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