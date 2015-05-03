#include "Obstaculo.h"
#include "glut.h"
#include "stdio.h"
#include "bitmap.h"




Obstaculo::Obstaculo()
{
	posicion.x = posicion.y = posicion.z = 0;
	tamaño.x = tamaño.y = tamaño.z = 1;
}


Obstaculo::~Obstaculo()
{
}

void Obstaculo::Dibuja(){
	glDisable(GL_LIGHTING);
	switch (id){
	case(1) :
			glTranslatef(posicion.x, posicion.y, posicion.z);
			glTranslatef(0, 0, tamaño.z / 2);
			glScalef(tamaño.x, tamaño.y, tamaño.z);
			glutSolidCube(1);
			glLoadIdentity();
			glTranslatef(0, 0, tamaño.z / 2);
			glTranslatef(-posicion.x, -posicion.y, -posicion.z);
		
			break;
	case(2) :
		static bitmap bidon("bidon.bmp");
		static bitmap bidon_tapa("bidon_tapa.bmp");

		glTranslatef(posicion.x, posicion.y, posicion.z);
		bidon.usarTextura();
		glColor3ub(255,255,255);
		GLUquadricObj* lado = gluNewQuadric();
		gluQuadricOrientation(lado, GLU_OUTSIDE);
		gluQuadricTexture(lado, GL_TRUE);
		gluCylinder(lado, tamaño.x, tamaño.y, tamaño.z, 20, 20);
		gluDeleteQuadric(lado);
		glDisable(GL_TEXTURE_2D);

		glTranslatef(0, 0, tamaño.z);
		bidon_tapa.usarTextura();
		GLUquadricObj* tapa = gluNewQuadric();
		gluQuadricOrientation(tapa, GLU_OUTSIDE);
		gluQuadricTexture(tapa, GL_TRUE);
		gluDisk(tapa,0, tamaño.y, 20, 20);
		gluDeleteQuadric(tapa);
		glDisable(GL_TEXTURE_2D);
		glTranslatef(0, 0, -tamaño.z);
		glTranslatef(-posicion.x, -posicion.y, -posicion.z);
		break;
		
	}
glEnable(GL_LIGHTING);
}
