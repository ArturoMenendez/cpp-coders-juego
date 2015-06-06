#include "Mejoras.h"
#include "bitmap.h"


Mejora::Mejora(Vector3D pos) : Objeto(pos)
{
}

Mpuntos::Mpuntos(Vector3D pos) : Mejora(pos)
{
}
void Mpuntos::Dibuja(){
	static bitmap imagen("moneda.bmp");

	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, posicion.z);
	Anima();
	glColor3ub(255,255,0);
	GLUquadricObj *mon = gluNewQuadric();
	gluCylinder(mon, 0.5, 0.5, 0.2, 10, 10);
	imagen.usarTextura();
	gluQuadricOrientation(mon, GLU_OUTSIDE);
	gluQuadricTexture(mon, GL_TRUE);
	glTranslatef(0, 0, 0.1);
	gluDisk(mon, 0, 0.50, 10, 10);
	glTranslatef(0, 0, -0.2);
	gluDisk(mon, 0, 0.50, 10, 10);
	gluDeleteQuadric(mon);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

Mdanio::Mdanio(Vector3D pos) : Mejora(pos)
{
}
void Mdanio::Dibuja(){}

Mvelocidad::Mvelocidad(Vector3D pos) : Mejora(pos)
{
}
void Mvelocidad::Dibuja(){}

Minvencible::Minvencible(Vector3D pos) : Mejora(pos)
{
}
void Minvencible::Dibuja(){}