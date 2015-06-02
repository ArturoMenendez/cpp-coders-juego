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
		switch (tipo){
		case (5) : {
			Enemigo* nuevo_ad = new ADistancia(posicion);
			lista[n_enemigos++] = nuevo_ad;
			break; }
		case(6) : {
			Enemigo* nuevo_cac = new CaC(posicion);
			lista[n_enemigos++] = nuevo_cac;
			break; }
		case(7) : {
			Enemigo* nuevo_k = new Kamikaze(posicion);
			lista[n_enemigos++] = nuevo_k;
			break;}
		default:
			break;
		}
	}
}

void ListaEnemigos::dibujarEnemigos(){
	for (int i = 0; i < n_enemigos; i++) lista[i]->Dibuja();
}

void ListaEnemigos::actualizarEnemigos(){
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
