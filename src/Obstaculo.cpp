#include "Obstaculo.h"
#include "glut.h"
#include "stdio.h"
#include "bitmap.h"

Obstaculo::Obstaculo(Vector3D posicion, Vector3D tamanio, int tipo, bool destruccion) : destruir(false), movimiento(0), brillo(1)
{
	this->posicion = posicion;
	this->tamanio = tamanio;
	id = tipo;
	limites.posicion = posicion;
	limites.posicion.z = 0;
	if (tipo == 2) {
		limites.radio = tamanio.x;
		limites.tipo = CIRCULO;
	}
	else if (tipo == 1) {
		limites.ancho = tamanio.x;
		limites.alto = tamanio.y;
		limites.tipo = RECTANGULO;
	}
	else if (tipo == 3) {
		limites.ancho = tamanio.x;
		limites.alto = tamanio.y;
		limites.tipo = AGUJERO;
	}
	else if (tipo == 8){
		limites.ancho = tamanio.x;
		limites.alto = tamanio.y;
		limites.tipo = PUERTAENTRADA;
	}
	else if (tipo == 9) {
		limites.ancho = tamanio.x;
		limites.alto = tamanio.y;
		limites.tipo = PUERTASALIDA;
	}
	se_destruye = destruccion;
}


Obstaculo::~Obstaculo()
{
}

void Obstaculo::Dibuja(){
	switch (id){
	case(1) : {
		glPushMatrix();
		glColor3ub(120, 150, 80);
		glTranslatef(posicion.x, posicion.y, posicion.z);
		glTranslatef(0, 0, tamanio.z / 2);
		glScalef(tamanio.x, tamanio.y, tamanio.z);
		glutSolidCube(1);
		glPopMatrix();
		break;
	}
	case(2) : {
		static bitmap bidon("bidon.bmp");
		static bitmap bidon_tapa("bidon_tapa.bmp");
		glPushMatrix();
		limites.Dibuja();
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

		glPopMatrix();
		break;

	}
	case(3) : {
		static bitmap lava("lava.bmp");
		static bitmap borde("borde.bmp");

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(brillo, brillo, brillo);
		lava.usarTextura();
		glBegin(GL_QUADS);
		glTexCoord2f(movimiento, movimiento);
		glVertex3f(posicion.x - tamanio.x / 2.0F, posicion.y - tamanio.y / 2.0F, 0.001);
		glTexCoord2f(movimiento, 1 + movimiento);
		glVertex3f(posicion.x - tamanio.x / 2.0F, posicion.y + tamanio.y / 2.0F, 0.001);
		glTexCoord2f(1 + movimiento, 1 + movimiento);
		glVertex3f(posicion.x + tamanio.x / 2.0F, posicion.y + tamanio.y / 2.0F, 0.001);
		glTexCoord2f(1 + movimiento, movimiento);
		glVertex3f(posicion.x + tamanio.x / 2.0F, posicion.y - tamanio.y / 2.0F, 0.001);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		glColor3ub(255, 255, 255);
		borde.usarTextura();
		glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
		glVertex3f(posicion.x - tamanio.x / 2.0F, posicion.y - tamanio.y / 2.0F, 0.002);
		glTexCoord2f(0, 1);
		glVertex3f(posicion.x - tamanio.x / 2.0F, posicion.y + tamanio.y / 2.0F, 0.002);
		glTexCoord2f(1, 1);
		glVertex3f(posicion.x + tamanio.x / 2.0F, posicion.y + tamanio.y / 2.0F, 0.002);
		glTexCoord2f(1, 0);
		glVertex3f(posicion.x + tamanio.x / 2.0F, posicion.y - tamanio.y / 2.0F, 0.002);
		glEnd();
		glDisable(GL_BLEND);
		glDisable(GL_TEXTURE_2D);
		glEnable(GL_LIGHTING);
		glPopMatrix();
		break;
	}

	case(8) :

	case(9) : {
		glPushMatrix();
		glColor3ub(180, 180, 220);
		glTranslatef(posicion.x, posicion.y, posicion.z);
		glTranslatef(0, 0, tamanio.z / 2);
		glScalef(tamanio.x, tamanio.y, tamanio.z);
		glutSolidCube(1);
		glPopMatrix();
		break;
	}
			limites.Dibuja();
	}
}

void Obstaculo::movTextura(){
	static bool flag = true;

	movimiento += 0.002;
	if (movimiento >= 1.0F) movimiento = 0.0F;

	if (flag) brillo -= 0.002;
	else brillo += 0.002;
	if (brillo <= 0.3) flag = false;
	if (brillo >= 1.0) flag = true;
}