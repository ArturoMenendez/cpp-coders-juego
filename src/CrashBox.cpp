#include "CrashBox.h"
#include "glut.h"


CrashBox::CrashBox(Vector3D posicion, float radio) :ancho(0), alto(0)
{
	this->posicion = posicion;
	this->posicion.z = 0;
	this->radio = radio;
	tipo = CIRCULO;
}

CrashBox::CrashBox(Vector3D posicion, float ancho, float alto) :radio(0)
{
	this->posicion = posicion;
	this->posicion.z = 0;
	this->ancho = ancho;
	this->alto = alto;
	tipo = RECTANGULO;
}

CrashBox::CrashBox(Vector3D posicion, Vector3D direccion, float largo){
	this->posicion = posicion;
	this->posicion.z = 0;
	this->largo = largo;
	this->direccion = direccion;
}

CrashBox::CrashBox()
{
}

CrashBox::~CrashBox()
{
}

void CrashBox::Dibuja(){
	glColor3ub(255, 0, 0);
	/*glTranslatef(0, 0, 0.1);
	GLUquadric* obj = gluNewQuadric();
	gluDisk(obj, radio, radio + 0.05, 20, 20);
	glTranslatef(0, 0, -0.1);*/
	glBegin(GL_LINES);
	glVertex3f(posicion.x,posicion.y, 1);
	glVertex3f(posicion.x + direccion.x, posicion.y + direccion.y, 1);
	glEnd();
}