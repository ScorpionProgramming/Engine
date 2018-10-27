#include <gl/glew.h>
#include <GLFW/glfw3.h>

#include <stdio.h>
#include <iostream>

#include "Scene.h"
#include <stdlib.h>
#include <iostream>
#include <sstream>

#define VNAME(x) #x
#define VDUMP(x) std::cout << #x << " " << x << std::endl

class Matrix
{
public:
	float** matrix;
	unsigned int m_xy_cnt;
	Matrix();
	Matrix(unsigned int xy_cnt); //row col count
	~Matrix();
	Matrix operator*(const Matrix m);
	void initMatrix();
	unsigned int getSize();
	void operator=(const Matrix m);
	std::string toString();
private:

};

Matrix::Matrix()
{
	//Init matrix 
	m_xy_cnt = 4;

	matrix = new float*[m_xy_cnt];
	for (unsigned int i = 0; i < m_xy_cnt; i++) {
		matrix[i] = new float[m_xy_cnt];
	}
	initMatrix();
}

Matrix::Matrix(unsigned int xy_cnt) {
	//Init matrix 
	m_xy_cnt = xy_cnt;

	matrix = new float*[m_xy_cnt];
	for (unsigned int i = 0; i < m_xy_cnt; i++) {
		matrix[i] = new float[m_xy_cnt];
	}
	initMatrix();
}
Matrix::~Matrix()
{
}

Matrix Matrix::operator*(const Matrix m) {
	Matrix result = Matrix(m_xy_cnt);

	for (unsigned int i = 0; i < m_xy_cnt; i++)
	{
		for (unsigned int j = 0; j < m_xy_cnt; j++)
		{
			for (unsigned int k = 0; k < m_xy_cnt; k++)
			{
				result.matrix[i][j] += this->matrix[i][k] * m.matrix[k][j];
			}
		}
	}
	return result;
}

void Matrix::initMatrix() {
	for (unsigned int i = 0; i < m_xy_cnt; i++) {
		for (unsigned int j = 0; j < m_xy_cnt; j++)
		{
			matrix[i][j] = 0;
		}
	}
}

unsigned int Matrix::getSize() {
	return this->m_xy_cnt;
}

void Matrix::operator=(const Matrix m) {
	for (unsigned int i = 0; i < m_xy_cnt; i++)
	{
		for (unsigned int j = 0; j < m_xy_cnt; j++)
		{
			this->matrix[i][j] = m.matrix[i][j];
		}
	}
}

std::string Matrix::toString() {
	std::stringstream ss;
	for (unsigned int i = 0; i < m_xy_cnt; i++)
	{
		for (unsigned int j = 0; j < m_xy_cnt; j++)
		{
			ss << this->matrix[i][j] << " ";
		}
		ss << "\n";
	}

	return ss.str();
}


int main() {
	int Testvariable = 100;
	std::cout << VNAME(Testvariable) << " " << Testvariable << std::endl;

	VDUMP(Testvariable);

	Matrix* m = new Matrix();

	/*Matrix erg = Matrix(2);
	Matrix a = Matrix(2);
	Matrix b = Matrix(2);

	a.matrix[0][0] = 1;
	a.matrix[0][1] = -3;
	a.matrix[1][0] = 0;
	a.matrix[1][1] = -2;

	b.matrix[0][0] = -1;
	b.matrix[0][1] = 4;
	b.matrix[1][0] = 7;
	b.matrix[1][1] = 1;*/

	Matrix erg = Matrix(3);
	Matrix a = Matrix(3);
	Matrix b = Matrix(3);

	a.matrix[0][0] = 5;
	a.matrix[0][1] = -3;
	a.matrix[0][2] = 11;

	a.matrix[1][0] = 5;
	a.matrix[1][1] = 6;
	a.matrix[1][2] = 22;

	a.matrix[2][0] = 8;
	a.matrix[2][1] = 19;
	a.matrix[2][2] = 0;

	b.matrix[0][0] = 12;
	b.matrix[0][1] = 3;
	b.matrix[0][2] = -4;

	b.matrix[1][0] = 5;
	b.matrix[1][1] = 16;
	b.matrix[1][2] = 9;

	b.matrix[2][0] = 8;
	b.matrix[2][1] = -3;
	b.matrix[2][2] = 4;

	std::cout << a.toString() << "\n\n" << b.toString() << std::endl;

	erg = a * b;

	std::cout << "Ergebnis: \n" << erg.toString() << std::endl;

	std::cout << m->getSize()*m->getSize() << std::endl;


	system("Pause");
	return 0;
}
