#include "BossCaC.h"
#define MAX_X	20.0f
#define MAX_Y	12.5f

BossCaC::BossCaC() :Enemigo()
{
}

BossCaC::BossCaC(Vector3D posicion, int id) : Enemigo(posicion, id), enreposo(true), preangrot(0), prevobjetivo(0, 0, 0), asdf(0)
{
	mov_teveo = 1.5;
	vida = 2;
	t0= 80;
	t = 79;
	limites.radio = 3;
	f_explo = 2;
}

BossCaC::~BossCaC()
{
}

void BossCaC::Dibuja(){
	if (vida > 0){
		static bitmap asdf("bola.bmp");
		glPushMatrix();
		lin.Dibuja();
		limites.Dibuja();

		glEnable(GL_LIGHTING);
		glColor3ub(255, 255, 255);

		glTranslatef(posicion.x, posicion.y, 0);
		glRotatef(angrot, 0, 0, 1);
		glPushMatrix();
		glTranslatef(0, 3, 3);
		glRotatef(90, 1, 0, 0);

		GiraAnima();
		asdf.usarTextura();
		GLUquadricObj *rueda = gluNewQuadric();
		gluQuadricOrientation(rueda, GLU_OUTSIDE);
		gluQuadricTexture(rueda, GL_TRUE);
		glColor3ub(255, 255, 255);
		gluCylinder(rueda, 2.5, 3, 0.5, 20, 20);
		glTranslatef(0, 0, 0.5);
		//glColor3ub(100, 100, 100);
		gluCylinder(rueda, 0.3, 0.3, 5, 20, 20);
		//glColor3ub(10, 10, 10);
		gluCylinder(rueda, 3, 2.5, 0.5, 20, 20);



		glTranslatef(0, 0, 4.5);
		gluCylinder(rueda, 2.5, 3, 0.5, 20, 20);
		glTranslatef(0, 0, 0.5);
		gluCylinder(rueda, 3, 2.5, 0.5, 20, 20);
		glPopMatrix();
		glDisable(GL_TEXTURE_2D);
		glColor3ub(100, 100, 100);
		glPushMatrix();
		glTranslatef(-3, 0, 3);
		glRotatef(90, 0, 1, 0);
		GLUquadricObj *cuerpo = gluNewQuadric();
		gluCylinder(cuerpo, 2, 2, 5, 20, 20);
		glTranslatef(0, 0, 5);
		gluCylinder(cuerpo, 0.5, 0.5, 0.5, 20, 20);
		glTranslatef(0, 0, 0.5);
		GiraAnima();
		glutSolidCone(1.8, 4, 20, 20);
		glPopMatrix();
		glPopMatrix();
	}
	if (vida <= 0){
		Explota();
	}

}

void BossCaC::Anima(){


}

void BossCaC::Update(){

	if (t%t0 == 0){
		//objetivo = lin.direccion;
		enreposo = true;
		//d = Vector3D::creavector(lin.posicion, objetivo);
		//d = Vector3D::unitario(d);
	}
	t++;
}
void BossCaC::MueveAleat(){
	if (enreposo == false){
		
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

void BossCaC::Rota(){
	/*Vector3D dirx(1, 0, 0);
	if (enreposo){
	Vector3D v1 = Vector3D::creavector(limites.posicion, objetivo);
	if (lin.direccion.y >= limites.posicion.y){
	angrot = Vector3D::angvect(dirx, v1);
	//aux = preangrot + aux;

	}
	if (lin.direccion.y < limites.posicion.y){
	angrot = -Vector3D::angvect(dirx, v1);
	//aux = preangrot + aux;

	}
	for (i; i < 100; i++){
	preangrot += (aux / 100);
	angrot = preangrot;
	}

	if (i == 99){
	preangrot = angrot;
	enreposo = false;
	i = 0;
	}
	i++;
	}*/
	if (enreposo == true){
		Vector3D dirx(1, 0, 0);
		Vector3D v1 = Vector3D::creavector(limites.posicion, lin.direccion);
		if (lin.direccion.y >= limites.posicion.y)
			angrot = Vector3D::angvect(dirx, v1);


		if (lin.direccion.y < limites.posicion.y){
			float aux = Vector3D::angvect(dirx, v1);
			angrot = -aux;
		}
		asdf++;
		if (asdf == 40){
			enreposo = false;
			objetivo = lin.direccion;
			d = Vector3D::creavector(lin.posicion, objetivo);
			d = Vector3D::unitario(d);
			asdf = 0;
		}
	}

}