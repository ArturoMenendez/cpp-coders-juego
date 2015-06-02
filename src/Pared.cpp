#include "Pared.h"
#include "glut.h"


Pared::Pared(float x1, float y1, float x2, float y2)
{
	Vector3D l1(x1, y1), l2(x2, y2);
	limite1 = l1;
	limite2 = l2;
}

Pared::~Pared()
{
}

Vector3D Pared::getLimite1(){
	return limite1;
}

Vector3D Pared::getLimite2(){
	return limite2;
}

void Pared::Dibuja(){
	//codigo para textura
	glColor3ub(255, 0, 0);
	glBegin(GL_QUADS);	//PARED SUPERIOR
	glNormal3f(0, 0, 0);//normales para iluminacion
	glVertex3f(limite1.x, limite1.y, 0.0);
	glNormal3f(0, 0, 10);
	glVertex3f(limite1.x, limite1.y, 10.0);
	glVertex3f(limite2.x, limite2.y, 10.0);
	glNormal3f(0, 0, 0);
	glVertex3f(limite2.x, limite2.y, 0.0);
	glEnd();
}
