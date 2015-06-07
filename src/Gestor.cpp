#include "Gestor.h"


Gestor::Gestor()
{
	estado = INICIO;
}


Gestor::~Gestor()
{
}

void Gestor::Dibuja(){
	if (estado == INICIO){
		glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
		nivel.SetNivel(0);
		if (nivel.GetPasaNivel(0) == false){
			nivel.SetPasaNivel(0);
		}
		nivel.Borrar();
		/*OpenGL::Print("HOLA MUNDO", 200, 200, 255, 0, 0);
		OpenGL::Print("CPP CODERS: RAIDERS OF THE LOST CLASS", 150, 300, 255, 255, 0);
		OpenGL::Print("PULSA E PARA EMPEZAR O S PARA SALIR", 175, 400, 0, 0, 255);*/
		glEnable(GL_LIGHTING);
	
		glBegin(GL_POLYGON);	
		glColor3ub(200, 200, 200);
		glVertex2f(-7.5, 13);
		glVertex2f(7.5, 13);
		glColor3ub(100, 100, 100);
		glVertex2f(7.5, 10);
		glVertex2f(-7.5, 10);
		glEnd();

		OpenGL::Print("JUGAR", 420, 160, 255, 0, 0);

		glBegin(GL_POLYGON);
		glColor3ub(200, 200, 200);
		glVertex2f(-7.5, 8);
		glVertex2f(7.5, 8);
		glColor3ub(100, 100, 100);
		glVertex2f(7.5, 5);
		glVertex2f(-7.5, 5);
		glEnd();
		glPopMatrix();

		OpenGL::Print("SALIR", 420, 250, 255, 0, 0);

	}
	else if (estado == JUEGO){
		glutSetCursor(GLUT_CURSOR_NONE);
		nivel.LeeNivel();
		nivel.Dibuja();
	}
	else if (estado == PAUSA){
		nivel.Dibuja();
		OpenGL::Print("PULSA C PARA CONTINUAR O S PARA SALIR", 175, 400, 0, 0, 255);

	}
}

void Gestor::Update(){
	if (estado == JUEGO){
		nivel.actualizaListas();
		//nivel.nuevoDisparo();
		nivel.updateEnemigos();
		nivel.interacciones();
		nivel.rotaJugador();
	}
}

void Gestor::JugadorDispara(){
	if (estado == JUEGO){
		nivel.nuevoDisparo();
	}
}


void Gestor::OnKeyboardDown(unsigned char key){
	if (estado == INICIO){
		if (key == 'e' || key == 'E')
			estado = JUEGO;
		else if (key == 's' || key == 'S')
			exit(0);
	}
	else if (estado == JUEGO){
		nivel.OnKeyboardDown(key,0,0);
		if (key == 'p' || key == 'P')
			estado = PAUSA;
	}
	else if (estado == PAUSA){
		if (key == 'c' || key == 'C')
			estado = JUEGO;
		if (key == 's' || key == 'S')
			estado = INICIO;
	}
}

void Gestor::OnKeyboardUp(unsigned char key){
if (estado == JUEGO){
		nivel.OnKeyboardUp(key, 0, 0);
	}
}

void Gestor::KeyOperations(){
	if (estado == JUEGO){
		nivel.KeyOperations();
	}
}

void Gestor::OnMouseDown(int button, int state, int x, int y){
	if (estado == INICIO){
		if (x > 310 && x < 590 && y>140 && y < 196)
			estado = JUEGO;
		if (x > 310 && x < 590 && y>234 && y < 290)
			exit(0);
	}
	if (estado == JUEGO)
	nivel.OnMouseDown(button, state, x, y);
}

void Gestor::OnMotion(int x, int y){
	if (estado == JUEGO)
	nivel.OnMotion(x, y);
}

void Gestor::OnPassiveMotion(int x, int y){
	if (estado == JUEGO)
	nivel.OnPassiveMotion(x, y);
}