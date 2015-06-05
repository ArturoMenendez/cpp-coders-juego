#include "Kamikaze.h"


Kamikaze::Kamikaze() : Enemigo()
{
}

Kamikaze::Kamikaze(Vector3D pos, int id) : Enemigo(pos, id), rueda(0)
{
}

Kamikaze::~Kamikaze()
{
}

void Kamikaze::Dibuja()
{
	glEnable(GL_LIGHTING);
	static bitmap cuerpo("bola.bmp");

	limites.Dibuja();
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 1);
	glRotatef(angrot, 0, 0, 1);
	///////////////////////////
	rueda+=4.5F;
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

bool Kamikaze::atacar(int t){
	static bool ataca = false;
	if (t == 0) ataca = true;
	if (ataca) return true;
	else return false;
}
