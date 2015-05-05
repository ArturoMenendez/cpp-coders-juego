#include "CrashBox.h"
#include "glut.h"


CrashBox::CrashBox(Vector3D posicion, float radio)
{
	this->posicion = posicion;
	this->posicion.z = 0;
	this->radio = radio;
	tipo = CIRCULO;
}

CrashBox::CrashBox(Vector3D posicion, float ancho, float alto){
	this->posicion = posicion;
	this->posicion.z = 0;
	this->ancho = ancho;
	this->alto = alto;
	tipo = RECTANGULO;
}

CrashBox::CrashBox()
{
}

CrashBox::~CrashBox()
{
}

void CrashBox::Dibuja(){
	glColor3ub(255, 0, 0);
	glTranslatef(0, 0,  0.1);
	GLUquadric* obj = gluNewQuadric();
	gluDisk(obj, radio, radio+0.05, 20, 20);
	glTranslatef(0, 0, -0.1);
}

//NUEVO
bool CrashBox::interaccion(CrashBox obj1, CrashBox obj2){

	if (obj1.tipo == obj2.tipo == CIRCULO){
		float distancia = Vector3D::modulo(obj1.posicion - obj2.posicion);
		if (distancia <= (obj1.radio + obj2.radio)) return true;
		else return false;
	}
}
