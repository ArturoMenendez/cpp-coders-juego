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

		nivel.SetNivel(0);
		if (nivel.GetPasaNivel(0) == false){
			nivel.SetPasaNivel(0);
		}
		nivel.Borrar();
		nivel.LeeNivel();

		glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
		Texto::setPos(-18, 15, 0);
		Texto::text("CPP CODERS: RAIDERS OF THE LOST CLASS", 1, 255, 20, 20);
		glEnable(GL_LIGHTING);
		OpenGL::Print("    ", 500, 160, 255, 0, 0);
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

		nivel.Dibuja();
	}
	else if (estado == PAUSA){
		glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
		nivel.Dibuja();
		glPushMatrix();
		glTranslatef(0, 0, 15);

		glEnable(GL_LIGHTING);
		OpenGL::Print("    ", 500, 160, 255, 0, 0);
		glBegin(GL_POLYGON);
		glColor3ub(200, 200, 200);
		glVertex2f(-5, 3);
		glVertex2f(5, 3);
		glColor3ub(100, 100, 100);
		glVertex2f(5, 1);
		glVertex2f(-5, 1);
		glEnd();

		OpenGL::Print("CONTINUAR", 395, 340, 255, 0, 0);

		glBegin(GL_POLYGON);
		glColor3ub(200, 200, 200);
		glVertex2f(-5, -1);
		glVertex2f(5, -1);
		glColor3ub(100, 100, 100);
		glVertex2f(5, -3);
		glVertex2f(-5, -3);
		glEnd();
		glPopMatrix();

		OpenGL::Print("SALIR", 420, 445, 255, 0, 0);
		glPopMatrix();
		//OpenGL::Print("H", 580, 373, 0, 0, 255);

	}

	else if (estado == GAMEOVER){
		glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
		nivel.Dibuja();
		glPushMatrix();
		glTranslatef(0, 0, 15);

		glEnable(GL_LIGHTING);
		OpenGL::Print("    ", 500, 160, 255, 0, 0);
		glBegin(GL_POLYGON);
		glColor3ub(200, 200, 200);
		glVertex2f(-5, 3);
		glVertex2f(5, 3);
		glColor3ub(100, 100, 100);
		glVertex2f(5, 1);
		glVertex2f(-5, 1);
		glEnd();

		OpenGL::Print("CONTINUAR", 395, 340, 255, 0, 0);

		glBegin(GL_POLYGON);
		glColor3ub(200, 200, 200);
		glVertex2f(-5, -1);
		glVertex2f(5, -1);
		glColor3ub(100, 100, 100);
		glVertex2f(5, -3);
		glVertex2f(-5, -3);
		glEnd();
		glPopMatrix();

		OpenGL::Print("SALIR", 420, 445, 255, 0, 0);
		glPopMatrix();

	}
}

void Gestor::Update(){
	if (estado == JUEGO){
		nivel.actualizaListas();
		nivel.updateEnemigos();
		nivel.interacciones();
		nivel.rotaJugador();
	}
	else if (estado == GAMEOVER) nivel.actualizaListas();
	else if (estado == PAUSA) nivel.actualizaListas();
}

void Gestor::Condiciones(){
	if (estado == JUEGO){
		if (nivel.GetNumeroEnemigos() == 0 && nivel.GetTocapuerta()){
			nivel.SetNivel(nivel.GetNivel() + 1);
			nivel.SetPasaNivel(nivel.GetNivel());
			nivel.Borrar();
			nivel.LeeNivel();
		}
		if (nivel.GetVida() <= 0){
			estado = GAMEOVER;
		}
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
		nivel.OnKeyboardDown(key, 0, 0);
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
		if (x > 310 && x < 590 && y>140 && y < 196){
			estado = JUEGO;
			state = GLUT_UP;

		}
		if (x > 310 && x < 590 && y>234 && y < 290){
			exit(0);
		}
	}
	if (estado == JUEGO){
		nivel.OnMouseDown(button, state, x, y);
		if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN)){
			nivel.nuevoDisparo();
		}
	}
	if (estado == PAUSA){
		if (x > 320 && x < 580 && y>320 && y < 373){
			estado = JUEGO;
			state = GLUT_UP;

		}
		if (x > 320 && x < 580 && y>425 && y < 478){
			estado = INICIO;
			state = GLUT_UP;
		}
	}
	if (estado == GAMEOVER){
		if (x > 320 && x < 580 && y>320 && y < 373){
			nivel.SetPasaNivel(nivel.GetNivel());
			nivel.Borrar();
			nivel.LeeNivel();
			estado = JUEGO;
			state = GLUT_UP;

		}
		if (x > 320 && x < 580 && y>425 && y < 478){
			estado = INICIO;
			state = GLUT_UP;
		}
	}
}

void Gestor::OnMotion(int x, int y){
	if (estado == INICIO){
		if (x > 310 && x < 590 && y>140 && y < 196){
			glEnable(GL_LIGHTING);
			OpenGL::Print("    ", 500, 160, 255, 0, 0);
			glBegin(GL_POLYGON);
			glColor3ub(100, 100, 100);
			glVertex2f(-7.5, 13);
			glVertex2f(7.5, 13);
			glColor3ub(200, 200, 200);
			glVertex2f(7.5, 10);
			glVertex2f(-7.5, 10);
			glEnd();

			OpenGL::Print("JUGAR", 420, 160, 255, 0, 0);
		}

		if (x > 310 && x < 590 && y>234 && y < 290){

			glBegin(GL_POLYGON);
			glColor3ub(100, 100, 100);
			glVertex2f(-7.5, 8);
			glVertex2f(7.5, 8);
			glColor3ub(200, 200, 200);
			glVertex2f(7.5, 5);
			glVertex2f(-7.5, 5);
			glEnd();
			glPopMatrix();

			OpenGL::Print("SALIR", 420, 250, 255, 0, 0);
		}
	}
	if (estado == JUEGO)
		nivel.OnMotion(x, y);
}

void Gestor::OnPassiveMotion(int x, int y){
	if (estado == INICIO){
		if (x > 310 && x < 590 && y>140 && y < 196){
			glEnable(GL_LIGHTING);
			OpenGL::Print("    ", 500, 160, 255, 0, 0);
			glBegin(GL_POLYGON);
			glColor3ub(100, 100, 100);
			glVertex2f(-7.5, 13);
			glVertex2f(7.5, 13);
			glColor3ub(200, 200, 200);
			glVertex2f(7.5, 10);
			glVertex2f(-7.5, 10);
			glEnd();

			OpenGL::Print("JUGAR", 420, 160, 255, 0, 0);
		}

		if (x > 310 && x < 590 && y>234 && y < 290){

			glBegin(GL_POLYGON);
			glColor3ub(100, 100, 100);
			glVertex2f(-7.5, 8);
			glVertex2f(7.5, 8);
			glColor3ub(200, 200, 200);
			glVertex2f(7.5, 5);
			glVertex2f(-7.5, 5);
			glEnd();
			glPopMatrix();

			OpenGL::Print("SALIR", 420, 250, 255, 0, 0);
		}
	}

	if (estado == JUEGO){
		nivel.OnPassiveMotion(x, y);
	}
}