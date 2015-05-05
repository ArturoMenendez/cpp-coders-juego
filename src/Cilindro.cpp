#include "Cilindro.h"


GLUquadric* objeto = gluNewQuadric();
Cilindro::Cilindro(void)
{
	base = 0.2;
	tapa = 0.2;
	altura = 1;
	posicion.x = posicion.y = posicion.z = 0;
	mov.x = -30;
	mov.y = 30;
	mov.z = -1;
	r = g = b = 200;
	ang = -30;
	ejez.x = ejez.y = 0;
	ejez.z = 1;
}


Cilindro::~Cilindro(void)
{
}


void Cilindro::Dibuja(){
	glColor3ub(r, g, b);
	glTranslatef(posicion.x, posicion.y, posicion.z);
	gluDisk(objeto, 0, base, 20, 20);
	gluCylinder(objeto, base, tapa, altura, 20, 20);
	glTranslatef(0, 0, altura);
	gluDisk(objeto, 0, tapa, 20, 20);
	glTranslatef(0, 0, -altura);
	glTranslatef(-posicion.x, -posicion.y, -posicion.z);
}

void Cilindro::Anima(){

	if (ang <= mov.x){
		mov.z = -mov.z;
	}
	if (ang >= mov.y){
		mov.z = -mov.z;
	}
	glTranslatef(0, 0, altura - tapa);
	glRotatef(ang += mov.z, 0, 1, 0);
	glTranslatef(0, 0, -altura + tapa);
	Dibuja();
	glTranslatef(0, 0, altura - tapa);
	glRotatef(-ang, 0, 1, 0);
	glTranslatef(0, 0, -altura + tapa);
}