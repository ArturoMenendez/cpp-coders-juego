#include "ListaEnemigos.h"


ListaEnemigos::ListaEnemigos()
{
	n_enemigos = 0;
	for (int i = 0; i < MAX_ENEMIGOS; i++) lista[i] = 0;
}

ListaEnemigos::~ListaEnemigos()
{
}

void ListaEnemigos::agregarEnemigo(Vector3D posicion, int tipo){
	Enemigo* nuevo_enemigo = new Enemigo(posicion, tipo);
	if (n_enemigos < MAX_ENEMIGOS) lista[n_enemigos++] = nuevo_enemigo;
}

void ListaEnemigos::dibujarEnemigos(){
	for (int i = 0; i < n_enemigos; i++) lista[i]->Dibuja();
}

void ListaEnemigos::actualizarEnemigos(){
}

void ListaEnemigos::mueveEnemigos(){
	for (int i = 0; i < n_enemigos; i++) lista[i]->MueveAleat();
}

void ListaEnemigos::updateEnemigos(){
	for (int i = 0; i < n_enemigos; i++) lista[i]->Update();
}

void ListaEnemigos::rotaEnemigos(){
	for (int i = 0; i < n_enemigos; i++) lista[i]->Rota();
}
