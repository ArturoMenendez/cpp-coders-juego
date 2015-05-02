#include "Disparo.h"
#include "Vector3D.h"
#include "glut.h"

/*disparo::disparo(float x2, float y2) :x(0),y(0),z(1),radio(1),vida(1000),rojo(255),verde(255),azul(255){
	Vector3D velocidad, p_inicial, p_final;
	p_inicial.x = p_inicial.y = 0.0;
	x2 = (x2 - 400) / 16.82f;
	y2 = (y2 - 300) / -16.82f;
	p_final.x = x2;
	p_final.y = y2;
	velocidad = velocidad.creavector(p_inicial, p_final);
	velocidad = velocidad.unitario(velocidad);
	vx = velocidad.x/3;
	vy = velocidad.y/3;

}*/
Disparo::Disparo(Vector3D jugador, Vector3D mira) : radio(1), vida(1000), rojo(255), verde(255), azul(255){
	Vector3D velocidad;
	velocidad = velocidad.creavector(jugador, mira);
	velocidad = velocidad.unitario(velocidad);
	vx = velocidad.x / 3;
	vy = velocidad.y / 3;
	x = jugador.x;
	y = jugador.y;
	z = jugador.z;
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
	glTranslatef(-x, -y, -z);
}

bool Disparo::updateDisparo(const int t){
	//actualiza la posicion
	x = x + vx*2;
	y = y + vy*2;
	//actualiza el tiempo de vida
	vida -= t;
	if (vida > 0) return true;
	else return false;
	//comprueba colisones//
}
