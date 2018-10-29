#include "Matrix4f.h"

Matrix4f::Matrix4f()
{
	matrix = new float*[m_xy_cnt];
	for (unsigned int i = 0; i < m_xy_cnt; i++) {
		matrix[i] = new float[m_xy_cnt];
	}
	initMatrix();
}

Matrix4f::Matrix4f(float n)
{
	for (unsigned int i = 0; i < m_xy_cnt; i++) {
		for (unsigned int j = 0; j < m_xy_cnt; j++)
		{
			matrix[i][j] = n;
		}
	}
}

Matrix4f::Matrix4f(Matrix4f * n)
{
	this->matrix[0][0] = n->matrix[0][0];
	this->matrix[0][1] = n->matrix[0][1];
	this->matrix[0][2] = n->matrix[0][2];
	this->matrix[0][3] = n->matrix[0][3];
						 
	this->matrix[1][0] = n->matrix[1][0];
	this->matrix[1][1] = n->matrix[1][1];
	this->matrix[1][2] = n->matrix[1][2];
	this->matrix[1][3] = n->matrix[1][3];
						 
	this->matrix[2][0] = n->matrix[2][0];
	this->matrix[2][1] = n->matrix[2][1];
	this->matrix[2][2] = n->matrix[2][2];
	this->matrix[2][3] = n->matrix[2][3];
						 
	this->matrix[3][0] = n->matrix[3][0];
	this->matrix[3][1] = n->matrix[3][1];
	this->matrix[3][2] = n->matrix[3][2];
	this->matrix[3][3] = n->matrix[3][3];
}

Matrix4f::Matrix4f(float a0, float a1, float a2, float a3, float b0, float b1, float b2, float b3, float c0, float c1, float c2, float c3, float d0, float d1, float d2, float d3)
{
}

void Matrix4f::initMatrix()
{
	for (unsigned int i = 0; i < m_xy_cnt; i++) {
		for (unsigned int j = 0; j < m_xy_cnt; j++)
		{
			matrix[i][j] = 0;
		}
	}

	this->loadIdentity();
}

void Matrix4f::loadIdentity()
{
	for (unsigned int i = 0; i < m_xy_cnt; i++) {
		for (unsigned int j = 0; j < m_xy_cnt; j++)
		{
			if (i == j)
			{
				matrix[i][j] = 1;
			}
			else
			{
				matrix[i][j] = 0;
			}
		}
	}
}

void Matrix4f::scale(float x, float y, float z)
{
	Matrix4f* other = new Matrix4f();
	other->loadIdentity();

	other->matrix[0][0] = x;
	other->matrix[1][1] = y;
	other->matrix[2][2] = z;

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
	other->loadIdentity();

	other->matrix[0][3] = x;
	other->matrix[1][3] = y;
	other->matrix[2][3] = z;

	*this = (*other) * (*this);

	delete other;
}

void Matrix4f::rotate(float x, float y, float z, float angle)
{
	Matrix4f* other = new Matrix4f();

	float c = cos(angle);
	float s = sin(angle);

	other->matrix[0][0] = x * x * (1 - c) + c;
	other->matrix[0][1] = x * y * (1 - c) - z * s;
	other->matrix[0][2] = x * z * (1 - c) + y * s;
	other->matrix[0][3] = 0;

	other->matrix[1][0] = x * y * (1 - c) + z * s;
	other->matrix[1][1] = y * y * (1 - c) + c;
	other->matrix[1][2] = y * z * (1 - c) - x * s;
	other->matrix[1][3] = 0;

	other->matrix[2][0] = x * z * (1 - c) - z * s;
	other->matrix[2][1] = y * z * (1 - c) + x * s;
	other->matrix[2][2] = z * z * (1 - c) + c;
	other->matrix[2][3] = 0;

	other->matrix[3][0] = 0;
	other->matrix[3][1] = 0; 
	other->matrix[3][2] = 0;
	other->matrix[3][3] = 1;

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
	this->loadIdentity();

	this->matrix[0][0] = 2 / (right - left);
	this->matrix[0][1] = 0;
	this->matrix[0][2] = 0;
	this->matrix[0][3] = - ((right + left) / (right - left));
						 
	this->matrix[1][0] = 0;
	this->matrix[1][1] = 2 / (top - bottom);
	this->matrix[1][2] = 0;
	this->matrix[1][3] = -((top + bottom)/(top - bottom));
						 
	this->matrix[2][0] = 0;
	this->matrix[2][1] = 0;
	this->matrix[2][2] = -2 / (far - near);
	this->matrix[2][3] = - ((far + near)/(far - near));
						 
	this->matrix[3][0] = 0;
	this->matrix[3][1] = 0;
	this->matrix[3][2] = 0;
	this->matrix[3][3] = 0;
}

Matrix4f Matrix4f::operator=(Matrix4f n) const
{
	this->matrix[0][0] = n.matrix[0][0];
	this->matrix[0][1] = n.matrix[0][1];
	this->matrix[0][2] = n.matrix[0][2];
	this->matrix[0][3] = n.matrix[0][3];

	this->matrix[1][0] = n.matrix[1][0];
	this->matrix[1][1] = n.matrix[1][1];
	this->matrix[1][2] = n.matrix[1][2];
	this->matrix[1][3] = n.matrix[1][3];

	this->matrix[2][0] = n.matrix[2][0];
	this->matrix[2][1] = n.matrix[2][1];
	this->matrix[2][2] = n.matrix[2][2];
	this->matrix[2][3] = n.matrix[2][3];

	this->matrix[3][0] = n.matrix[3][0];
	this->matrix[3][1] = n.matrix[3][1];
	this->matrix[3][2] = n.matrix[3][2];
	this->matrix[3][3] = n.matrix[3][3];

	return *this;
}

Matrix4f Matrix4f::operator+(Matrix4f n) const
{
	this->matrix[0][0] = this->matrix[0][0] + n.matrix[0][0];
	this->matrix[0][1] = this->matrix[0][1] + n.matrix[0][1];
	this->matrix[0][2] = this->matrix[0][2] + n.matrix[0][2];
	this->matrix[0][3] = this->matrix[0][3] + n.matrix[0][3];
											
	this->matrix[1][0] = this->matrix[1][0] + n.matrix[1][0];
	this->matrix[1][1] = this->matrix[1][1] + n.matrix[1][1];
	this->matrix[1][2] = this->matrix[1][2] + n.matrix[1][2];
	this->matrix[1][3] = this->matrix[1][3] + n.matrix[1][3];
											
	this->matrix[2][0] = this->matrix[2][0] + n.matrix[2][0];
	this->matrix[2][1] = this->matrix[2][1] + n.matrix[2][1];
	this->matrix[2][2] = this->matrix[2][2] + n.matrix[2][2];
	this->matrix[2][3] = this->matrix[2][3] + n.matrix[2][3];
											
	this->matrix[3][0] = this->matrix[3][0] + n.matrix[3][0];
	this->matrix[3][1] = this->matrix[3][1] + n.matrix[3][1];
	this->matrix[3][2] = this->matrix[3][2] + n.matrix[3][2];
	this->matrix[3][3] = this->matrix[3][3] + n.matrix[3][3];

	return *this;
}

Matrix4f Matrix4f::operator-(Matrix4f n) const
{
	this->matrix[0][0] = this->matrix[0][0] - n.matrix[0][0];
	this->matrix[0][1] = this->matrix[0][1] - n.matrix[0][1];
	this->matrix[0][2] = this->matrix[0][2] - n.matrix[0][2];
	this->matrix[0][3] = this->matrix[0][3] - n.matrix[0][3];
										    
	this->matrix[1][0] = this->matrix[1][0] - n.matrix[1][0];
	this->matrix[1][1] = this->matrix[1][1] - n.matrix[1][1];
	this->matrix[1][2] = this->matrix[1][2] - n.matrix[1][2];
	this->matrix[1][3] = this->matrix[1][3] - n.matrix[1][3];
										    
	this->matrix[2][0] = this->matrix[2][0] - n.matrix[2][0];
	this->matrix[2][1] = this->matrix[2][1] - n.matrix[2][1];
	this->matrix[2][2] = this->matrix[2][2] - n.matrix[2][2];
	this->matrix[2][3] = this->matrix[2][3] - n.matrix[2][3];
										    
	this->matrix[3][0] = this->matrix[3][0] - n.matrix[3][0];
	this->matrix[3][1] = this->matrix[3][1] - n.matrix[3][1];
	this->matrix[3][2] = this->matrix[3][2] - n.matrix[3][2];
	this->matrix[3][3] = this->matrix[3][3] - n.matrix[3][3];

	return *this;
}

Matrix4f Matrix4f::operator*(Matrix4f n) const
{
	Matrix4f result = Matrix4f();

	for (unsigned int i = 0; i < m_xy_cnt; i++)
	{
		for (unsigned int j = 0; j < m_xy_cnt; j++)
		{
			for (unsigned int k = 0; k < m_xy_cnt; k++)
			{
				result.matrix[i][j] += this->matrix[i][k] * n.matrix[k][j];
			}
		}
	}
	return result;
}

const float* Matrix4f::toGl()
{
	float* convert = new float[16];

	convert[0] = this->matrix[0][0];
	convert[1] = this->matrix[0][1];
	convert[2] = this->matrix[0][2];
	convert[3] = this->matrix[0][3];
	
	convert[4] = this->matrix[1][0];
	convert[5] = this->matrix[1][1];
	convert[6] = this->matrix[1][2];
	convert[7] = this->matrix[1][3];
	
	convert[8] = this->matrix[2][0];
	convert[9] = this->matrix[2][1];
	convert[10] = this->matrix[2][2];
	convert[11] = this->matrix[2][3];

	convert[12] = this->matrix[3][0];
	convert[13] = this->matrix[3][1];
	convert[15] = this->matrix[3][2];
	convert[15] = this->matrix[3][3];

	return convert;
}

std::string Matrix4f::toString()
{
	std::stringstream ss;
	
	for (unsigned int i = 0; i < m_xy_cnt; i++) {
		for (unsigned int j = 0; j < m_xy_cnt; j++)
		{
			ss << matrix[i][j] << " ";
		}
		ss << "\n";
	}
	ss << "\n";

	return ss.str();
}

Matrix4f::~Matrix4f()
{
	
}
