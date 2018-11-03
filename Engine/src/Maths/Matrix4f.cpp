#include "Matrix4f.h"

Matrix4f::Matrix4f()
{
	matrix = new float[4*4];
}

Matrix4f::Matrix4f(float n)
{
	for (unsigned int i = 0; i < 4*4; i++) {
		matrix[i] = n;
	}
}

Matrix4f::Matrix4f(Matrix4f* n)
{
	for (unsigned int i = 0; i < 4 * 4; i++) {
		matrix[i] = n->matrix[i];
	}
}

Matrix4f::Matrix4f(float a0, float a1, float a2, float a3, float b0, float b1, float b2, float b3, float c0, float c1, float c2, float c3, float d0, float d1, float d2, float d3)
{
	matrix[0]  = a0;
	matrix[1]  = a1;
	matrix[2]  = a2;
	matrix[3]  = a3;
			   
	matrix[4]  = b0; 
	matrix[5]  = b1;
	matrix[6]  = b2;
	matrix[7]  = b3;
			   
	matrix[8]  = c0;
	matrix[9]  = c1;
	matrix[10] = c2;
	matrix[11] = c3;

	matrix[12] = d0;
	matrix[13] = d1;
	matrix[14] = d2;
	matrix[15] = d3;

}

void Matrix4f::loadIdentity()
{
	matrix[0]  = 1;
	matrix[1]  = 0;
	matrix[2]  = 0;
	matrix[3]  = 0;
			  	
	matrix[4]  = 0;
	matrix[5]  = 1;
	matrix[6]  = 0;
	matrix[7]  = 0;
			  	
	matrix[8]  = 0;
	matrix[9]  = 0;
	matrix[10] = 1;
	matrix[11] = 0;
				
	matrix[12] = 0;
	matrix[13] = 0;
	matrix[14] = 0;
	matrix[15] = 1;
}

void Matrix4f::scale(float x, float y, float z)
{
	Matrix4f* other = new Matrix4f();
	//other->loadIdentity();

	other->matrix[0]  = x;
	other->matrix[5]  = y; 
	other->matrix[10] = z;
	other->matrix[15] = 1;

	*this = (*other) * (*this); 

	delete other;
}

void Matrix4f::scale(float u)
{
	this->scale(u, u, u);
}

void Matrix4f::translate(float x, float y, float z)
{
	Matrix4f* other = new Matrix4f();
	
	//other->loadIdentity();
	other->matrix[0]  = 1;
	other->matrix[5]  = 1;
	other->matrix[10] = 1;

	other->matrix[3]  = x;
	other->matrix[7]  = y;
	other->matrix[11] = z;
	other->matrix[15] = 1;

	*this = (*other) * (*this);

	delete other;
}

void Matrix4f::rotate(float x, float y, float z, float angle)
{
	Matrix4f* other = new Matrix4f();

	float c = cos(angle);
	float s = sin(angle);

	other->matrix[0]  = x * x * (1 - c) + c;
	other->matrix[1]  = x * y * (1 - c) - z * s;
	other->matrix[2]  = x * z * (1 - c) + y * s;
	//other->matrix[3]  = 0;
					  
	other->matrix[4]  = x * y * (1 - c) + z * s;
	other->matrix[5]  = y * y * (1 - c) + c;
	other->matrix[6]  = y * z * (1 - c) - x * s;
	//other->matrix[7]  = 0;
					  
	other->matrix[8]  = x * z * (1 - c) - z * s;
	other->matrix[9]  = y * z * (1 - c) + x * s;
	other->matrix[10] = z * z * (1 - c) + c;
	//other->matrix[11] = 0;

	//other->matrix[12] = 0;
	//other->matrix[13] = 0;
	//other->matrix[14] = 0;
	other->matrix[15] = 1;

	*this = (*other) * (*this);

	delete other;
}

void Matrix4f::rotateX(float angle)
{
	this->rotate(1, 0, 0, angle);
}

void Matrix4f::rotateY(float angle)
{
	this->rotate(0, 1, 0, angle);
}

void Matrix4f::rotateZ(float angle)
{
	this->rotate(0, 0, 1, angle);
}

void Matrix4f::setOrtho(float left, float right, float bottom, float top, float near, float far)
{
	//this->loadIdentity();

	this->matrix[0]  = 2 / (right - left);
	this->matrix[1]  = 0;
	this->matrix[2]  = 0;
	this->matrix[3]  = -((right + left) / (right - left));
					 
	this->matrix[4]  = 0;
	this->matrix[5]  = 2 / (top - bottom);
	this->matrix[6]  = 0;
	this->matrix[7]  = -((top + bottom) / (top - bottom));
					 
	this->matrix[8]  = 0;
	this->matrix[9]  = 0;
	this->matrix[10] = -2 / (far - near);
	this->matrix[11] = -((far + near) / (far - near));

	this->matrix[12] = 0;
	this->matrix[13] = 0;
	this->matrix[14] = 0;
	this->matrix[15] = 0;
}

Matrix4f Matrix4f::operator=(Matrix4f n) const
{
	for (unsigned int i = 0; i < 4 * 4; i++) {
		matrix[i] = n.matrix[i];
	}

	return *this;
}

Matrix4f Matrix4f::operator+(Matrix4f n) const
{
	Matrix4f result;
	
	for (unsigned int i = 0; i < 4 * 4; i++) {
		result.matrix[i] = matrix[i] + n.matrix[i];
	}

	return result;
}

Matrix4f Matrix4f::operator-(Matrix4f n) const
{
	Matrix4f result;

	for (unsigned int i = 0; i < 4 * 4; i++) {
		result.matrix[i] = matrix[i] - n.matrix[i];
	}

	return result;
}

Matrix4f Matrix4f::operator*(Matrix4f n) const
{
	Matrix4f result = Matrix4f();

	result.matrix[0]  = this->matrix[0] * n.matrix[0] + this->matrix[1] * n.matrix[4] + this->matrix[2] * n.matrix[8]  + this->matrix[3] * n.matrix[12];
	result.matrix[1]  = this->matrix[0] * n.matrix[1] + this->matrix[1] * n.matrix[5] + this->matrix[2] * n.matrix[9]  + this->matrix[3] * n.matrix[13];
	result.matrix[2]  = this->matrix[0] * n.matrix[2] + this->matrix[1] * n.matrix[6] + this->matrix[2] * n.matrix[10] + this->matrix[3] * n.matrix[14];
	result.matrix[3]  = this->matrix[0] * n.matrix[3] + this->matrix[1] * n.matrix[7] + this->matrix[2] * n.matrix[11] + this->matrix[3] * n.matrix[15];
	 
	result.matrix[4]  = this->matrix[4] * n.matrix[0] + this->matrix[5] * n.matrix[4] + this->matrix[6] * n.matrix[8]  + this->matrix[7] * n.matrix[12];
	result.matrix[5]  = this->matrix[4] * n.matrix[1] + this->matrix[5] * n.matrix[5] + this->matrix[6] * n.matrix[9]  + this->matrix[7] * n.matrix[13];
	result.matrix[6]  = this->matrix[4] * n.matrix[2] + this->matrix[5] * n.matrix[6] + this->matrix[6] * n.matrix[10] + this->matrix[7] * n.matrix[14];
	result.matrix[7]  = this->matrix[4] * n.matrix[3] + this->matrix[5] * n.matrix[7] + this->matrix[6] * n.matrix[11] + this->matrix[7] * n.matrix[15];
		 
	result.matrix[8]  = this->matrix[8] * n.matrix[0] + this->matrix[9] * n.matrix[4] + this->matrix[10] * n.matrix[8]  + this->matrix[11] * n.matrix[12];
	result.matrix[9]  = this->matrix[8] * n.matrix[1] + this->matrix[9] * n.matrix[5] + this->matrix[10] * n.matrix[9]  + this->matrix[11] * n.matrix[13];
	result.matrix[10] = this->matrix[8] * n.matrix[2] + this->matrix[9] * n.matrix[6] + this->matrix[10] * n.matrix[10] + this->matrix[11] * n.matrix[14];
	result.matrix[11] = this->matrix[8] * n.matrix[3] + this->matrix[9] * n.matrix[7] + this->matrix[10] * n.matrix[11] + this->matrix[11] * n.matrix[15];
		 
	result.matrix[12] = this->matrix[12] * n.matrix[0] + this->matrix[13] * n.matrix[4] + this->matrix[14] * n.matrix[8]  + this->matrix[15] * n.matrix[12];
	result.matrix[13] = this->matrix[12] * n.matrix[1] + this->matrix[13] * n.matrix[5] + this->matrix[14] * n.matrix[9]  + this->matrix[15] * n.matrix[13];
	result.matrix[14] = this->matrix[12] * n.matrix[2] + this->matrix[13] * n.matrix[6] + this->matrix[14] * n.matrix[10] + this->matrix[15] * n.matrix[14];
	result.matrix[15] = this->matrix[12] * n.matrix[3] + this->matrix[13] * n.matrix[7] + this->matrix[14] * n.matrix[11] + this->matrix[15] * n.matrix[15];
	
	return result;
}

const float* Matrix4f::toGl()
{
	return matrix;
}

/*Only for debug purpose - console output is very heavy.*/
std::string Matrix4f::toString()
{
	std::stringstream ss;
	
	for (unsigned int i = 0; i < 4*4; i++) {
		ss << matrix[i] << " ";
		
		if (i % 4 == 3)
		{
			ss << "\n";	
		}
	}
	ss << "\n";

	return ss.str();
}

Matrix4f::~Matrix4f()
{
	delete matrix;
}
