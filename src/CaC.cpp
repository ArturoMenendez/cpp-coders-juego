#include "CaC.h"


CaC::CaC() : Enemigo()
{
}

CaC::CaC(Vector3D pos, int id) : Enemigo(pos, id), z(0)
{
}

CaC::~CaC()
{
}

void CaC::Dibuja()
{
	glPushMatrix();
	lin.Dibuja();
	limites.Dibuja();

	if (z <= 0) flag = false;
	if (z >= 0.7) flag = true;
	
	if (flag)
		z-=0.02;
	else
		z+=0.02;

	glTranslatef(posicion.x, posicion.y, 1+z);
	glRotatef(angrot, 0, 0, 1);
	glPushMatrix();
	GLUquadricObj *obj = gluNewQuadric();
	gluCylinder(obj,0.5,0.7,1.8,20,20);
	glTranslatef(0, 0, 1.8);
	gluDisk(obj,0,0.7,20,20);
	glutSolidSphere(0.35,20,20);
	
	glPopMatrix();
	glTranslatef(0.7, 0, 1);
	glColor3ub(200,200,200);
	gluDisk(obj,0,0.5,20,20);
	gluDeleteQuadric(obj);
	glPopMatrix();

	
}
