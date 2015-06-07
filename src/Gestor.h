#pragma once
#include "Nivel.h"
#include "OpenGL.h"
#include "glut.h"

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
	//metodos
	Gestor();
	virtual ~Gestor();

	void Dibuja();
	void Mueve();
	void Update();
	void JugadorDispara();

	void OnKeyboardDown(unsigned char);
	void OnKeyboardUp(unsigned char);
	void KeyOperations();
	void OnMouseDown(int button, int state, int x, int y);
	void OnMotion(int x, int y);
	void OnPassiveMotion(int x, int y);
protected:
	Nivel nivel;

};

