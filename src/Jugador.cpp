#include "glut.h"
#include "bitmap.h"
#include "Jugador.h"
#include "stdio.h"



Jugador::Jugador(void) :colision(false), lastKey('a')
{
	posicion.x = posicion.y = 0;
	posicion.z = 2.8;
	pos_anterior = posicion;
	p1.mov.z = 1;
	p1.ang = p1.mov.y;
	keyStates['a'] = false;
	keyStates['s'] = false;
	keyStates['d'] = false;
	keyStates['w'] = false;
}

Jugador::Jugador(Vector3D pos) :colision(false), lastKey('a')
{
	this->posicion.x = pos.x;
	this->posicion.y = pos.y;
	this->posicion.z = 2.8;
	pos_anterior = posicion;
	p1.mov.z = 1;
	p1.ang = p1.mov.y;
	keyStates['a'] = false;
	keyStates['s'] = false;
	keyStates['d'] = false;
	keyStates['w'] = false;
	limites.posicion = pos;
	limites.posicion.z = 0;
	limites.radio = 0.5;
	limites.tipo = CIRCULO;
}

Jugador::~Jugador(void)
{
}

void Jugador::Dibuja(){
	GLUquadricObj* pepe = gluNewQuadric();
	glColor3f(200, 255, 255);
	glTranslatef(ptomira.x, ptomira.y, 2.8);
	gluDisk(pepe, 0.4, 0.6, 20, 20);
	glBegin(GL_LINES);
	glVertex3f(0.4, 0, 0);
	glVertex3f(-0.4, 0, 0);
	glEnd();
	glBegin(GL_LINES);
	glVertex3f(0, 0.4, 0);
	glVertex3f(0, -0.4, 0);
	glEnd();
	glTranslatef(-ptomira.x, -ptomira.y, -2.8);
}

void Jugador::Mouse(int button, int state, int x, int y){
	switch (button){
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN){
			botonpulsado = true;
		}
		else
			botonpulsado = false;
	}
}

void Jugador::Motion(int x, int y){
	if (botonpulsado == true){
		ptomira.x = ((float)x - 400) / 16.82f;
		ptomira.y = ((float)y - 300) / -16.82f;
		ptomira.z = 2.8;
	}
}

void Jugador::PassiveMotion(int x, int y){
	ptomira.x = ((float)x - 400) / 16.82f;
	ptomira.y = ((float)y - 300) / -16.82f;
	ptomira.z = 2.8;
}

void Jugador::Pinta(){
	GLUquadric* obj = gluNewQuadric();
	static bitmap cuerpo("cuerpo.bmp");
	static bitmap cabeza("cabeza.bmp");
	glDisable(GL_LIGHTING);

	glTranslatef(posicion.x, posicion.y, 0);

	glRotatef(angrot, 0, 0, 1);

	glColor3ub(100, 100, 100);//cabeza
	glTranslatef(0, 0, 3);
	glRotatef(45, 0, 0, 1);
	cabeza.usarTextura();
	glColor3ub(255, 255, 255);
	GLUquadricObj *cab = gluNewQuadric();
	gluQuadricOrientation(cab, GLU_OUTSIDE);
	gluQuadricTexture(cab, GL_TRUE);
	gluCylinder(cab, 0.3, 0.3, 0.5, 4, 2);
	gluDeleteQuadric(cab);
	glDisable(GL_TEXTURE_2D);
	glRotatef(-45, 0, 0, 1);
	glTranslatef(0, 0, -3);

	glColor3ub(0, 100, 100);//cuerpo
	glTranslatef(0, 0, 1.4);
	cuerpo.usarTextura();
	glColor3ub(255, 255, 255);
	GLUquadricObj *cue = gluNewQuadric();
	gluQuadricOrientation(cue, GLU_OUTSIDE);
	gluQuadricTexture(cue, GL_TRUE);
	gluCylinder(cue, 0.5, 0.5, 1.6, 20, 20);
	gluDeleteQuadric(cue);
	glDisable(GL_TEXTURE_2D);
	glTranslatef(0, 0, 1.6);
	gluDisk(obj, 0, 0.50, 20, 20);
	glTranslatef(0, 0, -3);

	glColor3ub(150, 150, 150);//pierna izq
	glTranslatef(0, 0.25, 1.2);
	p1.Anima();
	glTranslatef(0, -0.25, -1.2);

	glColor3ub(150, 150, 150);//pierna der
	glTranslatef(0, -0.25, 1.2);
	p2.Anima();
	glTranslatef(0, 0.25, -1.2);

	glColor3ub(100, 255, 100);//brazo izq
	glTranslatef(0, 0.7, 2);
	c1.Anima();
	glTranslatef(0, -0.7, -2);

	glColor3ub(0, 0, 0);//brazo der
	glTranslatef(0, -0.7, 2.8);
	glRotatef(90, 0, 1, 0);
	gluDisk(obj, 0, 0.20, 20, 20);
	gluCylinder(obj, 0.2, 0.2, 1.4, 20, 20);
	glTranslatef(0, 0, 1.4);
	glColor3ub(100, 255, 100);
	gluDisk(obj, 0.1, 0.20, 20, 20);
	glTranslatef(0, 0, -1.4);
	glRotatef(-90, 0, 1, 0);
	glTranslatef(0, 0.7, -2.8);

	glRotatef(-angrot, 0, 0, 1);

	glTranslatef(-posicion.x, -posicion.y, 0);

	glEnable(GL_LIGHTING);
}

void Jugador::Rota(){
	Vector3D v1 = Vector3D::creavector(posicion, ptomira);
	Vector3D dirx;
	dirx.x = 1;
	dirx.y = 0;
	dirx.z = 0;
	if (ptomira.y >= posicion.y)
		angrot = Vector3D::angvect(dirx, v1);
	if (ptomira.y < posicion.y){
		float aux = Vector3D::angvect(dirx, v1);
		angrot = -aux;
	}
}

void Jugador::KeyOperations(void){
	if (keyStates['w']) {
		posicion.y += 0.2;
		limites.posicion.y += 0.2;
		lastKey = 'w';
	}
	if (keyStates['s']) {
		posicion.y -= 0.2;
		limites.posicion.y -= 0.2;
		lastKey = 's';
	}
	if (keyStates['d']) {
		posicion.x += 0.2;
		limites.posicion.x += 0.2;
		lastKey = 'd';
	}
	if (keyStates['a']) {
		posicion.x -= 0.2;
		limites.posicion.x -= 0.2;
		lastKey = 'a';
	}
}

void Jugador::NoMueve(unsigned char key){
	keyStates[key] = false;
}


void Jugador::Mueve(unsigned char key){
	keyStates[key] = true;
}


void Jugador::Anima(){
	if (keyStates['w'] == true || keyStates['d'] == true || keyStates['s'] == true || keyStates['a'] == true)
		c1.Anima();
	else
		c1.Dibuja();
}

CrashBox Jugador::getCrashBox(){
	return limites;
}