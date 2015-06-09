#include <stdlib.h>
#include "BossFinal.h"


BossFinal::BossFinal(Vector3D posicion, int id) : Enemigo(posicion, id), time1(3000), time2(1500)
{
	t0 = 100;
	t = t0;
	mov_noteveo = 40;
	f_explo = 2;
	limites.radio = 4;
	posicion.z = 6;
}


BossFinal::~BossFinal()
{
}

void BossFinal::Dibuja(){
	if (vida > 0){
		glPushMatrix();
		glTranslatef(posicion.x, posicion.y, posicion.z + 4);
		glPushMatrix();
		glRotatef(angrot, 0, 0, 1);
		glColor3ub(100, 100, 100);
		glutSolidSphere(3, 20, 20);
		glTranslatef(0, 0, 2);
		glRotatef(90,0,1,0);
		GLUquadric *cil = gluNewQuadric();
		gluCylinder(cil, 0.8, 0.8, 4, 20, 20);
		glPopMatrix();
		glPushMatrix();
		glColor3ub(0, 255, 0);
		glScalef(2, 2, 0.5);
		glutWireSphere(2.5, 40, 40);
		glScalef(1, 1, 1);
		glPopMatrix();
		glPushMatrix();
		GiraAnima();
		glColor3ub(0, 255, 155);
		for (int i = 0; i < 360; i += 45){
			glRotatef(45, 0, 0, 1);
			glTranslatef(4.5, 0, -0.7);
			glutSolidSphere(0.75, 20, 20);
			glTranslatef(-4.5, 0, 0.7);
		}
		glPopMatrix();
		glPushMatrix();
		glRotatef(giraanima, 0, 0, 1);
		glColor3ub(155, 255, 0);
		for (int i = 0; i < 360; i += 45){
			glRotatef(45, 0, 0, 1);
			glTranslatef(4.5, 0, 0.7);
			glutSolidSphere(0.75, 20, 20);
			glTranslatef(-4.5, 0, -0.7);
		}
		glPopMatrix();
		glPopMatrix();
	limites.Dibuja();
	}
	else Explota();
}

void BossFinal::MueveAleat(){

	posicion.x += direccion.x / mov_noteveo;
	posicion.y += direccion.y / mov_noteveo;
	limites.posicion = posicion;
	limites.posicion.z = 0;
	lin.posicion = posicion;

	if (posicion.x > MAX_X - limites.radio) posicion.x = MAX_X - limites.radio;
	if (posicion.x < -MAX_X + limites.radio) posicion.x = -MAX_X + limites.radio;
	if (posicion.y > MAX_Y - limites.radio) posicion.y = MAX_Y - limites.radio;
	if (posicion.y < -MAX_Y + limites.radio) posicion.y = -MAX_Y + limites.radio;
}


void BossFinal::Update(){
	if (t > t0){
		direccion.x = (rand() / (float)RAND_MAX);
		direccion.y = (rand() / (float)RAND_MAX);
		direccion.x -= (rand() / (float)RAND_MAX);
		direccion.y -= (rand() / (float)RAND_MAX);
		direccion = Vector3D::unitario(direccion);
		t = 0;
	}
	t++;
}

void BossFinal::Rota(){
	Vector3D dirx(1, 0, 0);

	Vector3D v1 = Vector3D::creavector(limites.posicion, lin.direccion);
	if (lin.direccion.y >= limites.posicion.y)
		angrot = Vector3D::angvect(dirx, v1);

	if (lin.direccion.y < limites.posicion.y){
		angrot = -Vector3D::angvect(dirx, v1);
	}
}

bool BossFinal::atacar(int t){

	time1 -= t;
	time2 -= t;
	if (time1<0){
		time1 = 1500;
		return true;
	}
	if (time2<0){
		time2 = 700;
		teveo = true;
	}
	else teveo = false;
	return false;
}

void BossFinal::Anima(){

}

