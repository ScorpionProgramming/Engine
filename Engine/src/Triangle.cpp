#include "Triangle.h"


Triangle::Triangle()
{
	this->A = Vector3f(-1.0f ,-1.0f ,0.0f);
	this->B = Vector3f(1.0f, -1.0f,0.0f);
	this->C = Vector3f(0.0f, 1.0f, 0.0f);
}

Triangle::Triangle(const Vector3f & a, const Vector3f & b, const Vector3f & c)
{
	this->A = a;
	this->B = b;
	this->C = c;
}

Vector3f Triangle::calcNormal(const Vector3f & pointOnTriangle) const
{
	return Vector3f();
}

Triangle::~Triangle()
{
}

std::string Triangle::toString()
{
	std::stringstream ss; 
	ss 
		<< "A: " << A.x << " " << A.y << " " << A.z << "\n"
		<< "B: " << B.x << " " << B.y << " " << B.z << "\n"
		<< "C: " << C.x << " " << C.y << " " << C.z << "\n";
	return ss.str();
}