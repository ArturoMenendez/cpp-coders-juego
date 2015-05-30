#include "stdlib.h"
#include "glut.h"
#include "stdio.h"
#include "bitmap.h"
#include "Enemigo.h"
#include "math.h"

Enemigo::Enemigo(void) :t(40), teveo(false)
{
	posicion.x = posicion.y = 0;
	posicion.z = 1;
	p1.mov.z = 1;
	p1.ang = p1.mov.y;
	recorrido = 300;
	angrot = 0;
	lin.posicion = posicion;
	lin.largo = 15;
	lin.direccion = posicion;
	pos_anterior = posicion;
}

Enemigo::Enemigo(Vector3D pos, int id) : t(40), teveo(false), limites(pos, 1.1F)
{
	this->posicion.x = pos.x;
	this->posicion.y = pos.y;
	this->posicion.z = pos.z;
	this->id = id;
	p1.mov.z = 1;
	p1.ang = p1.mov.y;
	recorrido = 300;
	angrot = 0;
	lin.posicion = posicion;
	lin.largo = 15;
	lin.direccion = posicion;
	pos_anterior = posicion;
}

Enemigo::~Enemigo(void)
{
}


void Enemigo::Dibuja(){

	glEnable(GL_LIGHTING);

	lin.Dibuja();

	glColor3ub(255,255,255);
	
	glTranslatef(posicion.x, posicion.y, 0);
	glRotatef(angrot,0,0,1);


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

	glColor3ub(150, 50, 0);//cuerpo
	glTranslatef(0, 0, 0.5);
	GLUquadricObj *enem = gluNewQuadric();
	gluCylinder(enem, 0.6, 0.6, 2.2, 20, 20);
	glTranslatef(0,0,2.2);
	gluDisk(enem,0,0.6,20,20);
	glutSolidSphere(0.3,20,20);
	glTranslatef(0, 0, -2.2);

	glColor3ub(0, 150, 50);//cañon
	glTranslatef(0,0,1.7);
	glRotatef(90, 0, 1, 0);
	gluCylinder(enem, 0.2, 0.3, 1, 20, 20);
	glRotatef(-90, 0, 1, 0);
	glTranslatef(0, 0, -1.7);

	glTranslatef(0, 0, -0.5);



	glRotatef(-angrot, 0, 0, 1);
	glTranslatef(-posicion.x, -posicion.y, 0);

	/*GLUquadric* obj = gluNewQuadric();
	static bitmap cuerpo("cuerpo.bmp");
	static bitmap cabeza("cabeza.bmp");

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

	glTranslatef(-posicion.x, -posicion.y, 0);*/

	//glEnable(GL_LIGHTING);

	limites.Dibuja();
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

void Enemigo::MueveAleat(){
	if (teveo == false){
		posicion.x += direccion.x / 40;
		posicion.y += direccion.y / 40;
		limites.posicion = posicion;
		limites.posicion.z = 0;
		lin.posicion = posicion;
	}
	else{
		Vector3D d = Vector3D::creavector(lin.posicion, lin.direccion);
		d = Vector3D::unitario(d);
		posicion.x += d.x / 10;
		posicion.y += d.y / 10;
		limites.posicion = posicion;
		limites.posicion.z = 0;
		lin.posicion = posicion;
	}
}

void Enemigo::Update(){
	t += 1;
	if (t % 40 == 0){
		direccion.x = (rand() / (float)RAND_MAX) * 2;
		direccion.y = (rand() / (float)RAND_MAX) * 2;
		direccion.x -= (rand() / (float)RAND_MAX) * 2;
		direccion.y -= (rand() / (float)RAND_MAX) * 2;
		direccion = Vector3D::unitario(direccion);
	}
}

CrashBox Enemigo::getCrashBox(){
	return limites;
}