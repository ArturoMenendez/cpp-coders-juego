#include <stdlib.h>
#include "ADistancia.h"


ADistancia::ADistancia() :Enemigo()
{
}

ADistancia::ADistancia(Vector3D pos, int id) : Enemigo(pos, id)
{
}


ADistancia::~ADistancia()
{
}


void ADistancia::Dibuja()
{
	if (vida > 0){
		static bitmap ruedas("ruedas.bmp");
		static bitmap cuerpo("cuerpo_AD.bmp");
		glPushMatrix();
		lin.Dibuja();
		limites.Dibuja();

		glEnable(GL_LIGHTING);
		glColor3ub(255, 255, 255);

		glTranslatef(posicion.x, posicion.y, 0);
		glRotatef(angrot, 0, 0, 1);

		ruedas.usarTextura();
		//glColor3ub(0, 50, 150);//ruedas
		glBegin(GL_POLYGON);
		glTexCoord2f(1, 0);
		glVertex3f(0.9, 0.6, 0);
		glTexCoord2f(0, 0);
		glVertex3f(-0.9, 0.6, 0);
		glTexCoord2f(0.28, 1);
		glVertex3f(-0.5, 0.6, 0.7);
		glTexCoord2f(0.66, 1);
		glVertex3f(0.5, 0.6, 0.7);
		glEnd();
		glBegin(GL_POLYGON);
		glTexCoord2f(1, 0);
		glVertex3f(0.9, -0.6, 0);
		glTexCoord2f(0, 0);
		glVertex3f(-0.9, -0.6, 0);
		glTexCoord2f(0.28, 1);
		glVertex3f(-0.5, -0.6, 0.7);
		glTexCoord2f(0.66, 1);
		glVertex3f(0.5, -0.6, 0.7);
		glEnd();
		glDisable(GL_TEXTURE_2D);

		glPushMatrix();
		cuerpo.usarTextura();
		glColor3ub(255, 255, 255);//cuerpo
		glTranslatef(0, 0, 0.5);
		GLUquadricObj *enem = gluNewQuadric();
		gluQuadricOrientation(enem, GLU_OUTSIDE);
		gluQuadricTexture(enem, GL_TRUE);
		gluCylinder(enem, 0.6, 0.6, 2.2, 20, 20);
		glDisable(GL_TEXTURE_2D);
		glPushMatrix();
		glTranslatef(0, 0, 2.2);
		glColor3ub(110, 110, 255);
		gluDisk(enem, 0, 0.6, 20, 20);
		glutSolidSphere(0.3, 20, 20);
		glPopMatrix();

		glColor3ub(0, 150, 50);//cañon
		glPushMatrix();
		glTranslatef(0, 0, 1.7);
		glRotatef(90, 0, 1, 0);
		gluCylinder(enem, 0.2, 0.3, 1, 20, 20);
		glPopMatrix();
		glPopMatrix();
		glPopMatrix();
	}
	if (vida <= 0){
		Explota();
	}
}


void ADistancia::Anima(){}

bool ADistancia::atacar(int t){
	static int time = 1000;
	time -= t;
	if (teveo && (time < 0)) {
		time = 1000;
		return true;
	}
	else return false;

}