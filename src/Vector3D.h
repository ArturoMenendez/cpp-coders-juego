#pragma once
class Vector3D
{
public:
	float x;
	float y;
	float z;
	static float prodesc(Vector3D, Vector3D);//devuelve el producto escalar de dos vectores
	static float modulo(Vector3D);//devuelve el modulo del vector
	static Vector3D prodvect(Vector3D, Vector3D);//devuelve el producto vectorial de dos vectores
	static Vector3D unitario(Vector3D);//devuelve un vector unitario 
	static float angvect(Vector3D, Vector3D);//devuelve el angulo entre dos vectores en grados
	static Vector3D creavector(Vector3D, Vector3D);//crea un vector a partir de dos puntos
	Vector3D operator+(Vector3D&);
	Vector3D operator-(Vector3D&);
	Vector3D operator*(float&);
	float operator*(Vector3D&);
	Vector3D operator/(float&);
	Vector3D();
	Vector3D(float x, float y, float z);
	~Vector3D(void);
};