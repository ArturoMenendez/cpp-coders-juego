#include "Kamikaze.h"


Kamikaze::Kamikaze()
{
}


Kamikaze::Kamikaze(Vector3D posicion)
{
	this->posicion = posicion;
	mov_teveo = 10;
	rueda = 0;
}

Kamikaze::~Kamikaze()
{
}

void Kamikaze::Dibuja()
{
	glEnable(GL_LIGHTING);
	static bitmap cuerpo("bola.bmp");
	//lin.Dibuja();
	//limites.Dibuja();
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 1);
	glRotatef(angrot, 0, 0, 1);
	///////////////////////////
	rueda+=4;
	glPushMatrix();
	glRotatef(rueda,0,1,0);
	cuerpo.usarTextura();
	glColor3ub(255, 255, 255);
	GLUquadricObj *cab = gluNewQuadric();
	gluQuadricOrientation(cab, GLU_OUTSIDE);
	gluQuadricTexture(cab, GL_TRUE);
	gluSphere(cab, 1, 20, 20);
	gluDeleteQuadric(cab);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glTranslatef(0,0,1);
	glutSolidCone(0.5,0.5,20,20);
	///////////////////////////
	glPopMatrix();
	glDisable(GL_LIGHTING);
}
