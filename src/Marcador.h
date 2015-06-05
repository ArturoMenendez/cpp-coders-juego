#pragma once

class Marcador
{
	int nivel;
	int salud=10;
	int vidas;
	int puntuacion;
	float tiempo;
	int llaves;
	int total_llaves;
	bool objetos[3];
public:
	Marcador();
	~Marcador();
	void actualizarMarcador(int salud, float t);
	void dibujar();
};

