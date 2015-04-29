#include "Esfera.h"
#include "glut.h"

Esfera::Esfera()
{
	radio = 0.2;
	posicion.x = posicion.y = posicion.z = 0;
	g = r = 150;
	b = 0;
}


Esfera::~Esfera()
{
}

void Esfera::Dibuja(){
	glTranslatef(posicion.x, posicion.y, posicion.z);
	glutSolidSphere(radio,20,20);
	glTranslatef(-posicion.x, -posicion.y, -posicion.z);
}
