#include "Objeto.h"

Objeto::Objeto() 
{
}

Objeto::Objeto(Vector3D pos, int id, int val) : posicion(pos), limites(pos, 0.5f), aux(0), tipo(id), valor(val), destruir(false)
{
}

Objeto::~Objeto()
{
}

void Objeto::Anima(){
	glRotatef(aux, 0, 0, 1);
	if (aux<180) glTranslatef(0, 0, 0.01f*aux);
	else glTranslatef(0, 0, 0.01f*(360-aux));
	aux += 2;
	if (aux >= 360) aux = 0;
}

CrashBox Objeto::getCrashBox(){
	return limites;
}

bool Objeto::getDestruir(){
	return destruir;
}

int Objeto::getTipo(){
	return tipo;
}

int Objeto::getValor(){
	return valor;
}

void Objeto::setDestruir(bool est){
	destruir = est;
}