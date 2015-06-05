#include "ListaDisparos.h"


ListaDisparos::ListaDisparos(){
	tam_lista = 0;
	for (int i = 0; i < MAX_DISPAROS; i++) lista[i] = 0;
}


ListaDisparos::~ListaDisparos()
{
}

void ListaDisparos::agregarDisparos(Jugador tirador, int vida, int danio){
	Disparo* nuevo_disparo = new Disparo(tirador, vida, danio);
	if (tam_lista < MAX_DISPAROS) lista[tam_lista++] = nuevo_disparo;
	
}

void ListaDisparos::agregarDisparos(Enemigo &tirador, int vida, int danio, bool dibujar){
	Disparo* nuevo_disparo = new Disparo(tirador, vida, danio, dibujar);
	if (tam_lista < MAX_DISPAROS) lista[tam_lista++] = nuevo_disparo;
}

void ListaDisparos::actualizarDisparos(const int t){
	bool dis_destruido;
	for (int i = 0; i < tam_lista; i++){
		lista[i]->updateDisparo(t);
	}
	do{
		dis_destruido = false;
		for (int i = 0; i < tam_lista; i++){
			if (lista[i]->destruir){
				delete lista[i];
				dis_destruido = true;
				tam_lista--;
				for (int j = i; j < tam_lista; j++){
					lista[j] = lista[j + 1];
				}
				break;
			}
		}
	} while (dis_destruido);
}

void ListaDisparos::dibujarDisparos(){
	for (int i = 0; i < tam_lista; i++) lista[i]->dibujar();
}