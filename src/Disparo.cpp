#include "Disparo.h"
#include "Vector3D.h"
#include "glut.h"
#include <math.h>
#define PI 3.1416


Disparo::Disparo(Jugador personaje) : destruir(false), radio(1), vida(1000), rojo(255), verde(255), azul(255){
	Vector3D velocidad;
	velocidad = velocidad.creavector(personaje.posicion, personaje.ptomira);
	velocidad = velocidad.unitario(velocidad);
	vx = velocidad.x / 3;
	vy = velocidad.y / 3;
	x = personaje.posicion.x; //+ 1.57*cos(2.0F*PI - ((PI / 2.0F) + (2.0F*PI*personaje.angrot) / 360.0F));
	y = personaje.posicion.y; //+ 1.57*sin(2.0F*PI - ((PI / 2.0F) + (2.0F*PI*personaje.angrot) / 360.0F));
	z = 2.8;
	limites.posicion = personaje.posicion;
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

	glTranslatef(x, y, z);
	glColor3ub(rojo, verde, azul);
	glutSolidSphere(radio, 20, 20);
	glTranslatef(0, 0, -z);
	limites.Dibuja();
	glTranslatef(-x, -y, 0);

}

void Disparo::updateDisparo(const int t){
	//actualiza la posicion
	limites.posicion.x = x = x + vx*2;
	limites.posicion.y = y = y + vy * 2;
	
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