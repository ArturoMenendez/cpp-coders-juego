#include "Obstaculo.h"
#include "glut.h"
#include "stdio.h"
#include "bitmap.h"




Obstaculo::Obstaculo(Vector3D posicion, Vector3D tamanio, int tipo, bool destruccion) : destruir(false)
{
	this->posicion = posicion;
	this->tamanio = tamanio;
	id = tipo;
	limites.posicion = posicion;
	if (tipo == 2) {
		limites.radio = tamanio.x;
		limites.tipo = CIRCULO;
	}
	else {
		limites.ancho = tamanio.x;
		limites.alto = tamanio.y;
		limites.tipo = RECTANGULO;
	}
	se_destruye = destruccion;
}


Obstaculo::~Obstaculo()
{
}

void Obstaculo::Dibuja(){
	glDisable(GL_LIGHTING);
	switch (id){
	case(1) :
		glPushMatrix();
		glColor3ub(120, 150, 80);
		glTranslatef(posicion.x, posicion.y, posicion.z);
		glTranslatef(0, 0, tamanio.z / 2);
		glScalef(tamanio.x, tamanio.y, tamanio.z);
		glutSolidCube(1);
		glPopMatrix();
		break;
		
	case(2) :
		static bitmap bidon("bidon.bmp");
		static bitmap bidon_tapa("bidon_tapa.bmp");

		glTranslatef(posicion.x, posicion.y, posicion.z);
		bidon.usarTextura();
		glColor3ub(255, 255, 255);
		GLUquadricObj* lado = gluNewQuadric();
		gluQuadricOrientation(lado, GLU_OUTSIDE);
		gluQuadricTexture(lado, GL_TRUE);
		gluCylinder(lado, tamanio.x, tamanio.y, tamanio.z, 20, 20);
		gluDeleteQuadric(lado);
		glDisable(GL_TEXTURE_2D);


		glTranslatef(0, 0, tamanio.z);
		bidon_tapa.usarTextura();
		GLUquadricObj* tapa = gluNewQuadric();
		gluQuadricOrientation(tapa, GLU_OUTSIDE);
		gluQuadricTexture(tapa, GL_TRUE);
		gluDisk(tapa, 0, tamanio.y, 20, 20);
		gluDeleteQuadric(tapa);
		glDisable(GL_TEXTURE_2D);
		glTranslatef(0, 0, -tamanio.z);
		glTranslatef(-posicion.x, -posicion.y, -posicion.z);

	}
	glEnable(GL_LIGHTING);
}