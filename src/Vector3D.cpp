#include "Vector3D.h"
#include "math.h"


Vector3D Vector3D::operator+(Vector3D&v){
	Vector3D res;
	res.x=x+v.x;
	res.y=y+v.y;
	res.z=z+v.z;
	return res;
}

Vector3D Vector3D::operator/(float&f){
	Vector3D res;
	res.x=x/f;
	res.y=y/f;
	res.z=z/f;
	return res;
}

float Vector3D::operator*(Vector3D&v){
	float res;
	res=x*v.x+y*v.y+z*v.z;
	return res;
}

Vector3D Vector3D::operator*(float&f){
	Vector3D res;
	res.x=x*f;
	res.y=y*f;
	res.z=z*f;
	return res;
}

Vector3D Vector3D::operator-(Vector3D&v){
	Vector3D res;
	res.x=x-v.x;
	res.y=y-v.y;
	res.z=z-v.z;
	return res;
}

Vector3D Vector3D::prodvect(Vector3D u,Vector3D v){
	Vector3D w;
	w.x=u.y*u.z-u.z*v.y;
	w.y=u.z*v.x-u.x*v.z;
	w.z=u.x*v.y-u.y*v.x;
	return w;
}

float Vector3D::prodesc(Vector3D u,Vector3D v){
	float res=u.x*v.x+u.y*v.y+u.z*v.z;
	
	return res;
}

float Vector3D::angvect(Vector3D u, Vector3D v){
	float prod=prodesc(u,v);
	float mod1=modulo(u);
	float mod2=modulo(v);
	
	float f=prod/(mod1*mod2);
	float res= (float)acos(f)*180/3.14159;
	return res;

}

float Vector3D::modulo(Vector3D v){
	float res=sqrt(v.x*v.x+v.y*v.y+v.z*v.z);
	return res;
}

Vector3D Vector3D::unitario(Vector3D v){
	float f=modulo(v);
	Vector3D res=v/f;
	return res;
}

Vector3D Vector3D::creavector(Vector3D p, Vector3D q){
	Vector3D res;
	 res.x = q.x - p.x;
	 res.y = q.y - p.y;
	 res.z = q.z - p.z;
	 return res;
}

Vector3D::Vector3D(void)
{
	x=y=z=0;
}


Vector3D::~Vector3D(void)
{
}

