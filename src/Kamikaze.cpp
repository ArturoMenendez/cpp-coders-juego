#include "Kamikaze.h"


Kamikaze::Kamikaze() : Enemigo()
{
}

Kamikaze::Kamikaze(Vector3D pos, int id) : Enemigo(pos, id), rueda(0), ataca(false)
{
	rueda = 0;
	giraanima=4.5;
	mov_teveo = 7;
}

Kamikaze::~Kamikaze()
{
}

void Kamikaze::Dibuja()
{
	if (vida > 0){
		glEnable(GL_LIGHTING);
		static bitmap cuerpo("bola.bmp");
		limites.Dibuja();
		glPushMatrix();
		glTranslatef(posicion.x, posicion.y, 1);
		glRotatef(angrot, 0, 0, 1);
		///////////////////////////

		glPushMatrix();
		glRotatef(90, 1, 0, 0);
		GiraAnima();
		cuerpo.usarTextura();
		glColor3ub(255, 255, 255);
		GLUquadricObj *cab = gluNewQuadric();
		gluQuadricOrientation(cab, GLU_OUTSIDE);
		gluQuadricTexture(cab, GL_TRUE);
		gluSphere(cab, 1, 20, 20);
		gluDeleteQuadric(cab);
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();
		glTranslatef(0, 0, 1);
		glutSolidCone(0.5, 0.5, 20, 20);
		///////////////////////////
		glPopMatrix();
	}
	else
		Explota();
}

void Kamikaze::Anima(){}

bool Kamikaze::atacar(int t){
	if (t == 0)	ataca = true;
	if (ataca && vida>0){
		return true;
	}
	return false;
}