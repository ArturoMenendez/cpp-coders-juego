#include "ListaObjetos.h"
#include "Mejoras.h"
#include "Codigo.h"


ListaObjetos::ListaObjetos()
{
	n_objetos = 0;
	for (int i = 0; i < MAX_OBJETOS; i++) lista[i] = 0;
}

ListaObjetos::~ListaObjetos()
{
}

void ListaObjetos::agregarObjetos(Vector3D posicion, int tipo){
	Objeto* nuevo_objeto = 0;
	if (n_objetos < MAX_OBJETOS) {
		switch (tipo){
		case CODIGO:
			nuevo_objeto = new Codigo(posicion);
			break;
		case PUNTOS:
			nuevo_objeto = new Mpuntos(posicion);
			break;
		case DANIO:
			nuevo_objeto = new Mdanio(posicion);
			break;
		case VELOCIDAD:
			nuevo_objeto = new Mvelocidad(posicion);
			break;
		case INVULNERABLE:
			nuevo_objeto = new Minvencible(posicion);
			break;
		}
		lista[n_objetos++] = nuevo_objeto;
	}
}

void ListaObjetos::dibujarObjetos(){
	for (int i = 0; i < n_objetos; i++)	lista[i]->Dibuja();
}

void ListaObjetos::actualizarObjetos(){
	for (int i = 0; i < n_objetos; i++){
		if (lista[i]->getDestruir()){
			delete lista[i];
			n_objetos--;
			for (int j = i; j < n_objetos; j++){
				lista[j] = lista[j + 1];
			}
			break;
		}
	}
}

void ListaObjetos::borraObjetos(){
	for (int i = 0; i < n_objetos; i++)
		delete lista[i];
	n_objetos = 0;
}
