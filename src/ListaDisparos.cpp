#include "ListaDisparos.h"


ListaDisparos::ListaDisparos(){
	tam_lista = 0;
	for (int i = 0; i < MAX_DISPAROS; i++) lista[i] = 0;
}


ListaDisparos::~ListaDisparos()
{
}

void ListaDisparos::agregarDisparos(Jugador tirador){
	Disparo* nuevo_disparo = new Disparo(tirador);	
	if (tam_lista < MAX_DISPAROS) lista[tam_lista++] = nuevo_disparo;
	
}

void ListaDisparos::actualizarDisparos(const int t){
	for (int i = 0; i < tam_lista; i++){
		if (!(lista[i]->updateDisparo(t))){
			delete lista[i];
			tam_lista--;
			for (int j = i; j < tam_lista; j++){
				lista[j] = lista[j + 1];
				lista[j]->updateDisparo(t);
			}
			break;
		}
	}
}

void ListaDisparos::dibujarDisparos(){
	for (int i = 0; i < tam_lista; i++) lista[i]->dibujar();
}