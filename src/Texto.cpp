#include "Texto.h"
#include "bitmap.h"
#include <string.h>
#define ANCHO 32
#define ALTO 53
#define N_X_FILA 17
#define F_ESCALA (53.0f/32.0f)
#define TAM_TEXT 600

int Texto::x = 0;
int Texto::y = 0;
int Texto::z = 0;

void Texto::setPos(float px, float py, float pz){
	x = px;
	y = py;
	z = pz;
}

void Texto::text(char *string, float tamanio, unsigned char r, unsigned char g, unsigned char b){
	static bitmap fuente("elronet.bmp");
	float puntero[] = { 0, 0 };
	int caracter ,i;

	glPushMatrix();
	glDisable(GL_LIGHTING);
	glColor3ub(r, g, b);
	fuente.usarTextura();
	for (i = 0; i < strlen(string); i++){
		caracter = (int)string[i];
		caracter -= 32;
		puntero[0] = ((caracter % N_X_FILA)*ANCHO) / (float)TAM_TEXT;
		puntero[1] = 1.0f - (((caracter / N_X_FILA)+1)*ALTO) / (float)TAM_TEXT;
		glBegin(GL_QUADS);
			glTexCoord2f(puntero[0], puntero[1]);
			glVertex3f(x + i*tamanio, y, z);
			glTexCoord2f(puntero[0], puntero[1] + (ALTO / (float)TAM_TEXT));
			glVertex3f(x + i*tamanio, y + tamanio*F_ESCALA, z);
			glTexCoord2f(puntero[0] + (ANCHO / (float)TAM_TEXT), puntero[1] + (ALTO / (float)TAM_TEXT));
			glVertex3f(x + (i+1)*tamanio, y + tamanio*F_ESCALA, z);
			glTexCoord2f(puntero[0] + (ANCHO / (float)TAM_TEXT), puntero[1]);
			glVertex3f(x + (i+1)*tamanio, y, z);
		glEnd();
	}
	x = x + i*tamanio;
	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

}
void Texto::numero(int numero, int num_digitos, float tamanio, unsigned char r, unsigned char g, unsigned char b){
	char *string;
	int digitos[6] = { 0, 0, 0, 0, 0, 0 };
	int denominador = 1000000;
	if (numero > 999999) numero = 999999;
	if (numero < 0) numero = 0;
	if (num_digitos < 0) num_digitos = 0;
	if (num_digitos > 6) num_digitos = 6;
	for (int j = 0; j < 6; j++){
		denominador /= 10;
		digitos[j] = numero/denominador;
		numero %= denominador;
	}
	string = new char[num_digitos+1];
	for (int i = (6-num_digitos), k = 0; i < 6; i++, k++){
		string[k] = digitos[i] + 48;
	}
	string[num_digitos] = '\0';
	text(string, tamanio, r, g, b);
	delete[] string;
}