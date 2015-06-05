#pragma once

class Texto
{
public:
	static int x;
	static int y;
	static int z;
	Texto();
	~Texto();
	static void setPos(float x, float y, float z);
	static void text(char *string, float tamanio, unsigned char r, unsigned char g, unsigned char b);
	static void numero(int numero, int num_digitos, float tamanio, unsigned char r, unsigned char g, unsigned char b);
};

