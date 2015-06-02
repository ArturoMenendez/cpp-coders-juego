#include "stdlib.h"
#include "glut.h"
#include "stdio.h"
#include "bitmap.h"
#include "Enemigo.h"
#include "math.h"

Enemigo::Enemigo(void) :t0(40), teveo(false), vida(2), posicion(0,0,0)
{
	angrot = 0;
	lin.posicion = posicion;
	lin.largo = 15;
	lin.direccion = posicion;
	pos_anterior = posicion;
	t = t0;
}

Enemigo::Enemigo(Vector3D pos, int id) : t(40), teveo(false), limites(pos, 1.1F), vida(2), posicion(0, 0, 0)
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
			float aux = Vector3D::angvect(dirx, v1);
			angrot = -aux;
		}
	}
	else{
		Vector3D v1 = Vector3D::creavector(limites.posicion, lin.direccion);
		if (lin.direccion.y >= limites.posicion.y)
			angrot = Vector3D::angvect(dirx, v1);


		if (lin.direccion.y < limites.posicion.y){
			float aux = Vector3D::angvect(dirx, v1);
			angrot = -aux;
		}
	}
}

void Enemigo::Anima(){

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
}

void Enemigo::Update(){
	if (teveo == false){
		t += 1;
		if (t % t0 == 0){
			direccion.x = (rand() / (float)RAND_MAX);
			direccion.y = (rand() / (float)RAND_MAX);
			direccion.x -= (rand() / (float)RAND_MAX);
			direccion.y -= (rand() / (float)RAND_MAX);
			direccion = Vector3D::unitario(direccion);
		}
	}
}

CrashBox Enemigo::getCrashBox(){
	return limites;
}

void Enemigo::act_Vida(int danio){
	vida -= danio;
}