#include "Disparo.h"
#include "Vector3D.h"
#include "glut.h"
#include <math.h>
#define PI 3.1416


Disparo::Disparo(Jugador personaje) : destruir(false), radio(0.3), vida(1000), rojo(255), verde(0), azul(0){
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

Disparo::Disparo()
{
}

Disparo::~Disparo(){
}

void Disparo::dibujar(){

	glTranslatef(pos.x, pos.y, pos.z);
	glColor3ub(rojo, verde, azul);
	glutSolidSphere(radio, 20, 20);
	glTranslatef(0, 0, -pos.z);
	//limites.Dibuja();
	glTranslatef(-pos.x, -pos.y, 0);

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