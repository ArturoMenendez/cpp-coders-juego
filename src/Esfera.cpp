#include "Esfera.h"
#include "glut.h"

Esfera::Esfera(void)
{
	radio=1;
	posicion.x=posicion.y=posicion.z=3;
	g=b=200;
	r=0;
}


Esfera::~Esfera(void)
{
}

void Esfera::Dibuja(){
	glColor3f(r,g,b);
	glTranslatef(posicion.x,posicion.y,posicion.z);
	glutSolidSphere(radio,20,20);
	glTranslatef(-posicion.x, -posicion.y, -posicion.z);
}

void Esfera::Mouse(int button, int state, int x, int y){
	switch (button){
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN){
			
			botonpulsado = true;
		}
		else
			botonpulsado = false;
	}
}

void Esfera::Motion(int x, int y){
	if (botonpulsado == true){
	posicion.x = ((float)x - 400) / 16.82f;
			posicion.y = ((float)y - 300) / -16.82f;
			posicion.z = 1;
	}
}

void Esfera::PassiveMotion(int x, int y){
	posicion.x = ((float)x - 400) / 16.82f;
	posicion.y = ((float)y - 300) / -16.82f;
	posicion.z = 1;
}
