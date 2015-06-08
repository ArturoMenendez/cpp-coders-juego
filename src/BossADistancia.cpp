#include "stdlib.h"
#include "BossADistancia.h"


BossADistancia::BossADistancia(Vector3D posicion, int id) : Enemigo(posicion, id), cont(0)
{
	t0 = 100;
	t = t0;
	mov_noteveo = 40;
	f_explo = 2;
	vida = 20;
}


BossADistancia::~BossADistancia()
{
}


void BossADistancia::Dibuja(){
	if (vida > 0){
		//static bitmap asdf("bola.bmp");
		glPushMatrix();
		lin.Dibuja();
		limites.Dibuja();

		glEnable(GL_LIGHTING);
		glColor3ub(255, 255, 255);

		glTranslatef(posicion.x, posicion.y, 0);
		glRotatef(angrot, 0, 0, 1);
		glPushMatrix();

		GLUquadricObj *cuerpo = gluNewQuadric();
		gluCylinder(cuerpo, 3, 2, 5, 20, 20);
		glPushMatrix();
		glTranslatef(0,0,3);
		glRotatef(90, 0, 1, 0);
		gluCylinder(cuerpo, 0, 1, 4, 20, 20);
		glPopMatrix();
		glPopMatrix();
		glPopMatrix();
	}
	if (vida <= 0){
		Explota();
	}
}

bool BossADistancia::atacar(int t){
	static int time = 2500;
	time -= t;
	if (time%500==0&&time!=2500){
		teveo = true;
		return true;
	}
	

	if (time < 1) {
		time = 2500;
		teveo = false;
		return true;
	}
	else return false;
}

void BossADistancia::Anima(){

}

void BossADistancia::MueveAleat(){

	posicion.x += direccion.x / mov_noteveo;
	posicion.y += direccion.y / mov_noteveo;
	limites.posicion = posicion;
	limites.posicion.z = 0;
	lin.posicion = posicion;

	if (posicion.x > MAX_X - limites.radio) posicion.x = MAX_X - limites.radio;
	if (posicion.x < -MAX_X + limites.radio) posicion.x = -MAX_X + limites.radio;
	if (posicion.y > MAX_Y - limites.radio) posicion.y = MAX_Y - limites.radio;
	if (posicion.y < -MAX_Y + limites.radio) posicion.y = -MAX_Y + limites.radio;
}


void BossADistancia::Update(){
	if (t > t0){
		direccion.x = (rand() / (float)RAND_MAX);
		direccion.y = (rand() / (float)RAND_MAX);
		direccion.x -= (rand() / (float)RAND_MAX);
		direccion.y -= (rand() / (float)RAND_MAX);
		direccion = Vector3D::unitario(direccion);
		t = 0;
	}
	t++;
}

void BossADistancia::Rota(){
	Vector3D dirx(1, 0, 0);

	Vector3D v1 = Vector3D::creavector(limites.posicion, lin.direccion);
	if (lin.direccion.y >= limites.posicion.y)
		angrot = Vector3D::angvect(dirx, v1);

	if (lin.direccion.y < limites.posicion.y){
		angrot = -Vector3D::angvect(dirx, v1);
	}
}