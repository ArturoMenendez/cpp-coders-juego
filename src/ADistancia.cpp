#include "ADistancia.h"


ADistancia::ADistancia(Vector3D posicion)
{
	this->posicion = posicion;
	mov_teveo = 100;
	t0 = 30;
}


ADistancia::~ADistancia()
{
}


void ADistancia::Dibuja()
{
	glPushMatrix();
	lin.Dibuja();
	limites.Dibuja();

	glEnable(GL_LIGHTING);
	glColor3ub(255, 255, 255);

	glTranslatef(posicion.x, posicion.y, 0);
	glRotatef(angrot, 0, 0, 1);


	glColor3ub(0, 50, 150);//ruedas
	glBegin(GL_POLYGON);
	glVertex3f(0.9, 0.6, 0);
	glVertex3f(-0.9, 0.6, 0);
	glVertex3f(-0.5, 0.6, 0.7);
	glVertex3f(0.5, 0.6, 0.7);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(0.9, -0.6, 0);
	glVertex3f(-0.9, -0.6, 0);
	glVertex3f(-0.5, -0.6, 0.7);
	glVertex3f(0.5, -0.6, 0.7);
	glEnd();

	glPushMatrix();
	glColor3ub(150, 50, 0);//cuerpo
	glTranslatef(0, 0, 0.5);
	GLUquadricObj *enem = gluNewQuadric();
	gluCylinder(enem, 0.6, 0.6, 2.2, 20, 20);
	glPushMatrix();
	glTranslatef(0, 0, 2.2);
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

/*glPushMatrix();
	lin.Dibuja();
	limites.Dibuja();

	glEnable(GL_LIGHTING);
	glColor3ub(255, 255, 255);

	glTranslatef(posicion.x, posicion.y, 0);
	glRotatef(angrot, 0, 0, 1);


	glColor3ub(0, 50, 150);//ruedas
	glBegin(GL_POLYGON);
	glVertex3f(0.9, 0.6, 0);
	glVertex3f(-0.9, 0.6, 0);
	glVertex3f(-0.5, 0.6, 0.7);
	glVertex3f(0.5, 0.6, 0.7);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(0.9, -0.6, 0);
	glVertex3f(-0.9, -0.6, 0);
	glVertex3f(-0.5, -0.6, 0.7);
	glVertex3f(0.5, -0.6, 0.7);
	glEnd();

	glPushMatrix();
	glColor3ub(150, 50, 0);//cuerpo
	glTranslatef(0, 0, 0.5);
	GLUquadricObj *enem = gluNewQuadric();
	gluCylinder(enem, 0.6, 0.6, 2.2, 20, 20);
	glPushMatrix();
	glTranslatef(0, 0, 2.2);
	gluDisk(enem, 0, 0.6, 20, 20);
	glutSolidSphere(0.3, 20, 20);
	glTranslatef(0, 0, -2.2);

	glColor3ub(0, 150, 50);//cañon
	glTranslatef(0, 0, 1.7);
	glRotatef(90, 0, 1, 0);
	gluCylinder(enem, 0.2, 0.3, 1, 20, 20);
	glRotatef(-90, 0, 1, 0);
	glTranslatef(0, 0, -1.7);

	glTranslatef(0, 0, -0.5);



	glRotatef(-angrot, 0, 0, 1);
	glTranslatef(-posicion.x, -posicion.y, 0);*/