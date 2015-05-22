#include "stdlib.h"
#include "glut.h"
#include "stdio.h"
#include "bitmap.h"
#include "Enemigo.h"
#include "math.h"

Enemigo::Enemigo(void) :t(40)
{
	posicion.x = posicion.y = 0;
	posicion.z = 1;
	p1.mov.z = 1;
	p1.ang = p1.mov.y;
	recorrido = 300;
	angrot = 0;
}

Enemigo::Enemigo(Vector3D pos,int id): t(40){
	this->posicion.x = pos.x;
	this->posicion.y = pos.y;
	this->posicion.z = pos.z;
	this->id = id;
	p1.mov.z = 1;
	p1.ang = p1.mov.y;
	recorrido = 300;
	angrot = 0;
}

Enemigo::~Enemigo(void)
{
}

void Enemigo::Dibuja(){
	glDisable(GL_LIGHTING);

	glColor3ub(255,255,255);
	
	glTranslatef(posicion.x, posicion.y, 0);
	glRotatef(angrot,0,0,1);
	glutSolidTeapot(2);
	glRotatef(-angrot, 0, 0, 1);
	glTranslatef(-posicion.x, -posicion.y, 0);

	glEnable(GL_LIGHTING);
}

void Enemigo::Rota(){
	Vector3D v1 = Vector3D::creavector(posicion, posicion + direccion);
	Vector3D dirx(1, 0, 0);
	if (posicion.y + direccion.y >= posicion.y)
		angrot = Vector3D::angvect(dirx, v1);
	if (posicion.y + direccion.y < posicion.y){
		float aux = Vector3D::angvect(dirx, v1);
		angrot = -aux;
	}
}

void Enemigo::Anima(){
}

void Enemigo::Mueve(){
	posicion.x += direccion.x / 40;
	posicion.y += direccion.y / 40;
}

void Enemigo::Update(){
	t += 1;
	if (t % 40 == 0){
		direccion.x = (rand() / (float)RAND_MAX) * 2;
		direccion.y = (rand() / (float)RAND_MAX) * 2;
		direccion.x -= (rand() / (float)RAND_MAX) * 2;
		direccion.y -= (rand() / (float)RAND_MAX) * 2;
	}
}
