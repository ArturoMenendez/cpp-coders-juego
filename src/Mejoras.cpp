#include <stdlib.h>
#include "Mejoras.h"
#include "bitmap.h"


Mejora::Mejora(Vector3D pos, int id, int val) : Objeto(pos,id,val)
{
}
Mejora::~Mejora()
{
}

Mpuntos::Mpuntos(Vector3D pos) : Mejora(pos, PUNTOS, rand() % 1901 + 100)
{
}
Mpuntos::~Mpuntos()
{
}
void Mpuntos::Dibuja(){
	static bitmap moneda("moneda.bmp");
	static 	GLUquadricObj *mon1 = gluNewQuadric();

	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, posicion.z);
	Anima();
	glRotatef(60,1,0,0);
	glColor3ub(255,255,0);
	gluCylinder(mon1, 0.5, 0.5, 0.2, 20, 20);
	moneda.usarTextura();
	gluQuadricOrientation(mon1, GLU_OUTSIDE);
	gluQuadricTexture(mon1, GL_TRUE);
	glTranslatef(0, 0, 0.2);
	gluDisk(mon1, 0, 0.50, 20, 20);
	glTranslatef(0, 0, -0.2);
	gluDisk(mon1, 0, 0.50, 20, 20);
	gluDeleteQuadric(mon1);
	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

Mdanio::Mdanio(Vector3D pos) : Mejora(pos, DANIO, 2)
{
}
Mdanio::~Mdanio()
{
}
void Mdanio::Dibuja(){

	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, posicion.z);
	Anima();
	glPushMatrix();
	glRotatef(45, 1, 1, 1);
	glColor3ub(0, 230, 0);
	glutWireOctahedron();
	glPopMatrix();
	glRotatef(90, 1, 0, 0);
	glRotatef(aux, 0, 0, -1);
	glColor3ub(0, 255, 255);
	glScalef(0.5, 0.5, 0.5);
	glutSolidDodecahedron();
	glPopMatrix();
}

Mvelocidad::Mvelocidad(Vector3D pos) : Mejora(pos, VELOCIDAD, 2)
{
}
Mvelocidad::~Mvelocidad()
{
}
void Mvelocidad::Dibuja(){
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, posicion.z);
	Anima();
	glPushMatrix();
	glRotatef(45, 1, 1, 1);
	glColor3ub(0, 230, 0);
	glutWireOctahedron();
	glPopMatrix();
	glRotatef(90, 1, 0, 0);
	glRotatef(aux, 0, 0, -1);
	glColor3ub(255, 0, 255);
	glScalef(0.3, 0.3, 0.3);
	glutSolidIcosahedron();
	glPopMatrix();
}

Minvencible::Minvencible(Vector3D pos) : Mejora(pos, INVULNERABLE, 5)
{
}
Minvencible::~Minvencible()
{
}
void Minvencible::Dibuja(){
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, posicion.z);
	Anima();
	glPushMatrix();
	glRotatef(45, 1, 1, 1);
	glColor3ub(0, 230, 0);
	glutWireOctahedron();
	glPopMatrix();
	glRotatef(90, 1, 0, 0);
	glRotatef(aux, 0, 0, -1);
	glColor3ub(255, 255, 0);
	glutSolidTeapot(0.5);
	glPopMatrix();
}