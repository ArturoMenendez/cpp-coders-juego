#include "Mundo.h"



void Mundo::Dibuja(){
	j1.Dibuja();
}


void Mundo::Pinta(){
	j1.Pinta();
}


void Mundo::Rota(){
	j1.Rota();
}


void Mundo::Mueve(unsigned char key){
	j1.Mueve(key);
}


void Mundo::Anima(){
	j1.Anima();
}

void Mundo::Mouse(int button, int state, int x, int y){
	j1.Mouse(button, state, x, y);
}


void Mundo::Motion(int x, int y){
	j1.Motion(x, y);
}


void Mundo::PassiveMotion(int x, int y){
	j1.PassiveMotion(x, y);
}


Mundo::Mundo(void)
{
}


Mundo::~Mundo(void)
{
}

void Mundo::KeyOperations(void){
	j1.KeyOperations();
}

void Mundo::NoMueve(unsigned char key){
	j1.NoMueve(key);
}
