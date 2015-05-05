#include "Pierna.h"
#include "glut.h"


Pierna::Pierna()
{
	posicion.x = posicion.y = posicion.z = 0;
	mov.x = -30;
	mov.y = 20;
	mov.z = -1;
	ang = mov.x;
}


Pierna::~Pierna()
{
}

void Pierna::Dibuja(){
	glTranslatef(posicion.x, posicion.y, posicion.z);
	e1.Dibuja();
	glTranslatef(0, 0, -c1.altura);
	e2.Dibuja();
	c1.Dibuja();
	glTranslatef(0, 0, c1.altura);
	glTranslatef(-posicion.x, -posicion.y, -posicion.z);
}

void Pierna::Anima(){
	if (ang <= mov.x){
		mov.z = -mov.z;
	}
	if (ang >= mov.y){
		mov.z = -mov.z;
	}
	//glTranslatef(0, 0, c1.altura + e2.radio);
	glRotatef(ang += mov.z, 0, 1, 0);
	//glTranslatef(0, 0, -c1.altura - e2.radio);
	Dibuja();
	//glTranslatef(0, 0, c1.altura + e2.radio);
	glRotatef(-ang, 0, 1, 0);
	//glTranslatef(0, 0, -c1.altura - e2.radio);
}