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
	if (n_enemigos < MAX_ENEMIGOS) {
		Enemigo* nuevo;
		switch (tipo){
		case (5) : {
			nuevo = new ADistancia(posicion, 5);
			lista[n_enemigos++] = nuevo;
			break; }
		case(6) : {
			nuevo = new CaC(posicion, 6);
			lista[n_enemigos++] = nuevo;
			break; }
		case(7) : {
			nuevo = new Kamikaze(posicion, 7);
			lista[n_enemigos++] = nuevo;
			break; }
		default:
			break;
		}
	}
}

void ListaEnemigos::dibujarEnemigos(){
	for (int i = 0; i < n_enemigos; i++) lista[i]->Dibuja();
}

void ListaEnemigos::detruirEnemigo(){
	for (int i = 0; i < n_enemigos; i++) {
		if (lista[i]->vida <= 0){
			delete lista[i];
			n_enemigos--;
			for (int j = i; j < n_enemigos; j++)	lista[j] = lista[j + 1];
		}
	}
}

void ListaEnemigos::mueveEnemigos(){
	for (int i = 0; i < n_enemigos; i++) lista[i]->MueveAleat();
}

void ListaEnemigos::updateEnemigos(Vector3D jugador){
	for (int i = 0; i < n_enemigos; i++) {
		lista[i]->Update();
		lista[i]->lin.direccion = jugador;
	}
}

void ListaEnemigos::rotaEnemigos(){
	for (int i = 0; i < n_enemigos; i++) lista[i]->Rota();
}
