#include "Disparo.h"
#include "Vector3D.h"
#include "glut.h"
#include <math.h>
#define PI 3.1416


Disparo::Disparo(Jugador personaje, int vida, int danio) : destruir(false), radio(0.3), vida(1000), rojo(255), verde(0), azul(0), danio(1), enemigo(false), dib(true){
	Vector3D velocidad;
	float f = 3;
	pos.x = personaje.posicion.x + (1.4*cos(personaje.angrot * 2 * PI / 360)) + (0.7*sin(personaje.angrot * 2 * PI / 360)); 
	pos.y = personaje.posicion.y - (0.7*cos(personaje.angrot * 2 * PI / 360)) + (1.4*sin(personaje.angrot * 2 * PI / 360)); 
	pos.z = 2.8;
	velocidad = velocidad.creavector(pos, personaje.ptomira);
	velocidad = velocidad.unitario(velocidad);
	vel = velocidad / f;
	limites.posicion = pos;
	limites.posicion.z = 0;
	limites.radio = radio;
	limites.tipo = CIRCULO;
}

Disparo::Disparo(Enemigo &enem, int life, int damage, bool dibujar) : destruir(false), radio(0.3), vida(life), rojo(0), verde(0), azul(255), danio(damage), enemigo(true), dib(dibujar){
	Vector3D velocidad;
	float f = 3;
	pos.x = enem.posicion.x;
	pos.y = enem.posicion.y;
	pos.z = 2.8;
	velocidad = velocidad.creavector(pos, enem.lin.direccion);
	velocidad = velocidad.unitario(velocidad);
	vel = velocidad / f;
	limites.posicion = pos;
	limites.posicion.z = 0;
	limites.radio = radio;
	limites.tipo = CIRCULO;
}

Disparo::Disparo()
{
}

Disparo::~Disparo(){
}

void Disparo::dibujar(){

	if (1){
		glPushMatrix();
		glTranslatef(pos.x, pos.y, pos.z);
		glColor3ub(rojo, verde, azul);
		glutSolidSphere(radio, 20, 20);
		glPopMatrix();
	}

}

void Disparo::updateDisparo(const int t){
	//actualiza la posicion
	limites.posicion.x = pos.x = pos.x + vel.x * 2;
	limites.posicion.y = pos.y = pos.y + vel.y * 2;

	//actualiza el tiempo de vida
	vida -= t;
	if (vida < 0) destruir = true;
}

CrashBox Disparo::getCrashBox(){
	return limites;
}

void Disparo::destruye(){
	destruir = true;
}