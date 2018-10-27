#pragma once
#include "Vector3f.h"
#include <sstream>

class Triangle
{
public:
	Triangle();
	Triangle(const Vector3f& a, const Vector3f& b, const Vector3f& c /*, const material*/);
	Vector3f A, B, C;
	/*const Material* pMtrl;*/
	Vector3f calcNormal(const Vector3f& pointOnTriangle) const;
	~Triangle();

	//zu testzwecke
	std::string toString();
};

