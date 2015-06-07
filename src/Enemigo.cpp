#include "stdlib.h"
#include "glut.h"
#include "bitmap.h"
#include "Enemigo.h"
#include "math.h"


Enemigo::Enemigo(void) :t0(40), teveo(false), vida(2), posicion(0, 0, 0), giraanima(5), contador(0), f_explo(7), objetivo(0, 0, 0)
{
	angrot = 0;
	lin.posicion = posicion;
	lin.largo = 15;
	lin.direccion = posicion;
	pos_anterior = posicion;
	t = t0;

}

Enemigo::Enemigo(Vector3D pos, int id) : t0(40), teveo(false), limites(pos, 1.1F), vida(2), contador(0), giraanima(0), f_explo(7), objetivo(0, 0, 0), mov_teveo(20), mov_noteveo(20)
{
	posicion = pos;
	this->id = id;
	angrot = 0;
	lin.posicion = posicion;
	lin.largo = 15;
	lin.direccion = posicion;
	pos_anterior = posicion;
	t = t0;
}

Enemigo::~Enemigo(void)
{
}

void Enemigo::Rota(){
	Vector3D dirx(1, 0, 0);
	if (teveo == false){
		Vector3D v1 = Vector3D::creavector(posicion, posicion + direccion);

		if (posicion.y + direccion.y >= posicion.y)
			angrot = Vector3D::angvect(dirx, v1);
		if (posicion.y + direccion.y < posicion.y){
			angrot = -Vector3D::angvect(dirx, v1);
		}
	}
	else{
		Vector3D v1 = Vector3D::creavector(limites.posicion, lin.direccion);
		if (lin.direccion.y >= limites.posicion.y)
			angrot = Vector3D::angvect(dirx, v1);


		if (lin.direccion.y < limites.posicion.y){
			angrot = -Vector3D::angvect(dirx, v1);
		}
	}
}

void Enemigo::MueveAleat(){
	if (teveo == false){
		posicion.x += direccion.x / mov_noteveo;
		posicion.y += direccion.y / mov_noteveo;
		limites.posicion = posicion;
		limites.posicion.z = 0;
		lin.posicion = posicion;
	}
	else{
		Vector3D d = Vector3D::creavector(lin.posicion, lin.direccion);
		d = Vector3D::unitario(d);
		posicion.x += d.x / mov_teveo;
		posicion.y += d.y / mov_teveo;
		limites.posicion = posicion;
		limites.posicion.z = 0;
		lin.posicion = posicion;
	}
	if (posicion.x > MAX_X - limites.radio) posicion.x = MAX_X - limites.radio;
	if (posicion.x < -MAX_X + limites.radio) posicion.x = -MAX_X + limites.radio;
	if (posicion.y> MAX_Y - limites.radio) posicion.y = MAX_Y - limites.radio;
	if (posicion.y < -MAX_Y + limites.radio) posicion.y = -MAX_Y + limites.radio;
}

void Enemigo::Update(){
	if (teveo == false){
		
		if (t > t0){
			direccion.x = (rand() / (float)RAND_MAX);
			direccion.y = (rand() / (float)RAND_MAX);
			direccion.x -= (rand() / (float)RAND_MAX);
			direccion.y -= (rand() / (float)RAND_MAX);
			direccion = Vector3D::unitario(direccion);
			t = 0;
		}
		t ++;
	}
}

CrashBox Enemigo::getCrashBox(){
	return limites;
}

void Enemigo::act_Vida(int danio){
	vida -= danio;
}

void Enemigo::GiraAnima(){
	glRotatef(giraanima,0,0,-1);
	giraanima += 4.5;
}

void Enemigo::Explota(){
	glDisable(GL_LIGHTING);
		glPushMatrix();
		glTranslatef(posicion.x, posicion.y, 5);
		glScalef(contador / f_explo, contador / f_explo, contador / f_explo);
		glColor3ub(200, 10, 10);
		glutSolidOctahedron();
		glColor3ub(30, 30, 30);
		glutSolidSphere(0.7, 20, 20);
		glRotatef(50, 0.2, 0.4, 0.7);
		glColor3ub(255, 150, 30);
		glutSolidOctahedron();
		glPopMatrix();
		contador++;
		glEnable(GL_LIGHTING);
}