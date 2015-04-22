#pragma once
class Vector3D
{
public:
	float x;
	float y;
	float z;
	static float prodesc(Vector3D, Vector3D);
	static float modulo(Vector3D);
	static Vector3D prodvect (Vector3D, Vector3D);
	static Vector3D unitario (Vector3D);
	static float angvect(Vector3D,Vector3D);
	Vector3D operator+(Vector3D&);
	Vector3D operator-(Vector3D&);
	Vector3D operator*(float&); 
	float operator*(Vector3D&);
	Vector3D operator/(float&);
	Vector3D(void);
	~Vector3D(void);
};



































































