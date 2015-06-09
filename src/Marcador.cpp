#include "Marcador.h"
#include "glut.h"
#include "bitmap.h"
#include "Texto.h"

#define MAX_SALUD 10


Marcador::Marcador() : salud(MAX_SALUD), nivel(1), vidas(4), puntuacion(0), tiempo(300), llaves(0), total_llaves(8)
{
}


Marcador::~Marcador()
{
}

void Marcador::actualizarMarcador(int salud, float t, int puntos, int nivel, int vidas, int llaves, int mejoras){
	if (salud < 0) salud = 0;
	this->salud = salud;
	this->puntuacion = puntos;
	this->vidas = vidas;
	this->nivel = nivel;
	this->llaves = llaves;

	if (mejoras==1){
		this->objetos[0] = true;
		this->objetos[1] = false;
		this->objetos[2] = false;
	}
	else if (mejoras==2){
		this->objetos[0] = false;
		this->objetos[1] = true;
		this->objetos[2] = false;
	}
	else if (mejoras == 3){
		this->objetos[0] = false;
		this->objetos[1] = false;
		this->objetos[2] = true;
	}
	else if (mejoras == 4){
		this->objetos[0] = true;
		this->objetos[1] = true;
		this->objetos[2] = false;
	}
	else if (mejoras == 5){
		this->objetos[0] = true;
		this->objetos[1] = false;
		this->objetos[2] = true;
	}
	else if (mejoras == 6){
		this->objetos[0] = false;
		this->objetos[1] = true;
		this->objetos[2] = true;
	}
	else if (mejoras == 7){
		this->objetos[0] = true;
		this->objetos[1] = true;
		this->objetos[2] = true;
	}
	else {
		this->objetos[0] = false;
		this->objetos[1] = false;
		this->objetos[2] = false;
	}

	

	tiempo -= t;
}

void Marcador::dibujar(){
	static bitmap fondo("marcador.bmp");
	static bitmap bateria("salud.bmp");
	static bitmap puntos("puntos.bmp");
	static bitmap jugador("jug.bmp");
	static bitmap codigo("cpp.bmp");
	static bitmap reloj("reloj.bmp");

	
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glColor3ub(150, 150, 150);
	fondo.usarTextura();
	glBegin(GL_QUADS);
		glTexCoord2f(0.0,0.0);
		glVertex3f(-20.0, 12.5, 10.0);
		glTexCoord2f(0.0, 1.0);
		glVertex3f(-20.0, 17.5, 10.0);
		glTexCoord2f(1.0, 1.0);
		glVertex3f(20.0, 17.5, 10.0);
		glTexCoord2f(1.0, 0.0);
		glVertex3f(20.0, 12.5, 10.0);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//Barra de vida
	glColor3ub(255, 255, 255);
	bateria.usarTextura();
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-19.5, 15, 10.015);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-19.5, 17, 10.01);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(-17.5, 17, 10.01);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(-17.5, 15, 10.01);
	glEnd();
	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
	glColor3ub(0, 220, 0);
	glBegin(GL_QUADS);
	glVertex3f(-17.0, 15.25, 10.01);
	glVertex3f(-17.0, 16.75, 10.01);
	glVertex3f(-17.0 + (12.0f * salud / MAX_SALUD), 16.75, 10.01);
	glVertex3f(-17.0 + (12.0f * salud / MAX_SALUD), 15.25, 10.01);
	glEnd();
	glColor3ub(0, 255, 0);
	glBegin(GL_LINES);
	glVertex3f(-17.0, 15.25, 10.02);
	glVertex3f(-17.0, 16.75, 10.02);
	glEnd();
	glBegin(GL_LINES);
	glVertex3f(-17.0, 16.75, 10.02);
	glVertex3f(-5.0, 16.75, 10.02);
	glEnd();
	glBegin(GL_LINES);
	glVertex3f(-5.0, 16.75, 10.02);
	glVertex3f(-5.0, 15.25, 10.02);
	glEnd();
	glBegin(GL_LINES);
	glVertex3f(-5.0, 15.25, 10.02);
	glVertex3f(-17.0, 15.25, 10.02);
	glEnd();

	//Nivel
	Texto::setPos(-3.75, 15.25, 10.01);
	Texto::text("NIVEL ", 1, 255, 255, 0);
	Texto::numero(nivel, 2, 1, 255, 255, 0);
	

	//Puntuacion
	glColor3ub(255, 255, 255);
	puntos.usarTextura();
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(5.0, 15, 10.01);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(5.0, 17, 10.01);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(7.0, 17, 10.01);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(7.0, 15, 10.01);
	glEnd();
	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
	Texto::setPos(8.5, 15.25, 10.01);
	Texto::numero(puntuacion, 6, 1, 255, 255, 0);


	//Vidas
	glColor3ub(255, 255, 255);
	jugador.usarTextura();
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-19.5, 12.75, 10.01);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-19.5, 14.75, 10.01);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(-17.5, 14.75, 10.01);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(-17.5, 12.75, 10.01);
	glEnd();
	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
	Texto::setPos(-17.5, 13.0, 10.01);
	Texto::text("x", 1, 255, 255, 0);
	Texto::numero(vidas, 2, 1, 255, 255, 0);

	

	//LLaves (trozos de codigo)
	glColor3ub(255, 255, 255);
	codigo.usarTextura();
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-12.5, 12.75, 10.01);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-12.5, 14.75, 10.01);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(-10.5, 14.75, 10.01);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(-10.5, 12.75, 10.01);
	glEnd();
	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
	Texto::setPos(-10.5, 13.0, 10.01);
	Texto::numero(llaves, 1, 1, 255, 255, 0);
	Texto::text("/", 1, 255, 255, 0);
	Texto::numero(total_llaves, 1, 1, 255, 255, 0);


	//Objetos/mejoras
	glColor3ub(150, 150, 150);
	for (int i = 0; i < 4; i++){
		glBegin(GL_QUADS);
		glVertex3f(-4.5 + (i*3.25), 12.75, 10.01);
		glVertex3f(-4.5 + (i*3.25), 14.75, 10.01);
		glVertex3f(-2.5 + (i*3.25), 14.75, 10.01);
		glVertex3f(-2.5 + (i*3.25), 12.75, 10.01);
		glEnd();
	}
	if (objetos[0]){
		Texto::setPos(0, 13.75f, 11);
		Texto::text("D", 1, 255, 255, 0);
	}
	if (objetos[1]){
		Texto::setPos(3, 13.75f, 11);
		Texto::text("V", 1, 255, 255, 0);
	}
	if (objetos[2]){
		Texto::setPos(6, 13.75f, 11);
		Texto::text("I", 1, 255, 255, 0);
	}

	//Tiempo
	glColor3ub(255, 255, 255);
	reloj.usarTextura();
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(12.5, 12.75, 10.015);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(12.5, 14.75, 10.01);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(14.5, 14.75, 10.01);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(14.5, 12.75, 10.01);
	glEnd();
	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
	Texto::setPos(15.0, 13.0, 10.01);
	Texto::numero((int)tiempo, 3, 1, 255, 255, 0);

	glEnable(GL_LIGHTING);
	glPopMatrix();
}