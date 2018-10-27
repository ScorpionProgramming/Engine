#include "Matrix4f.h"



Matrix4f::Matrix4f()
{
	m = new float[16];
	
	loadIdentity();
}

Matrix4f::Matrix4f(float* n)
{
	m = new float[16];
	m[0] =  n[0];
	m[1] =  n[1];
	m[2] =  n[2];
	m[3] =  n[3];
		    	   
	m[4] =  n[4];
	m[5] =  n[5];
	m[6] =  n[6];
	m[7] =  n[7];
		    	   
	m[8] =  n[8];
	m[9] =  n[9];
	m[10] = n[10];
	m[11] = n[11];
				 
	m[12] = n[12];
	m[13] = n[13];
	m[14] = n[14];
	m[15] = n[15];
}

Matrix4f::Matrix4f(Matrix4f * n)
{
	m = new float[16];
	m[0] =  n->m[0];
	m[1] =  n->m[1];
	m[2] =  n->m[2];
	m[3] =  n->m[3];

	m[4] =  n->m[4];
	m[5] =  n->m[5];
	m[6] =  n->m[6];
	m[7] =  n->m[7];

	m[8] =  n->m[8];
	m[9] =  n->m[9];
	m[10] = n->m[10];
	m[11] = n->m[11];

	m[12] = n->m[12];
	m[13] = n->m[13];
	m[14] = n->m[14];
	m[15] = n->m[15];
}

Matrix4f::Matrix4f(float a0, float a1, float a2, float a3, float b0, float b1, float b2, float b3, float c0, float c1, float c2, float c3, float d0, float d1, float d2, float d3)
{
	m = new float[16];
	m[0]  = a0;
	m[1]  = a1;
	m[2]  = a2;
	m[3]  = a3;

	m[4]  = b0;
	m[5]  = b1;
	m[6]  = b2;
	m[7]  = b3;

	m[8]  = c0;
	m[9]  = c1;
	m[10] = c2;
	m[11] = c3;

	m[12] = d0;
	m[13] = d1;
	m[14] = d2;
	m[15] = d3;
}

void Matrix4f::loadIdentity()
{
	m[0]  = 1;
	m[1]  = 0;
	m[2]  = 0;
	m[3]  = 0;
		  
	m[4]  = 0;
	m[5]  = 1;
	m[6]  = 0;
	m[7]  = 0;
		  
	m[8]  = 0;
	m[9]  = 0;
	m[10] = 1;
	m[11] = 0;

	m[12] = 0;
	m[13] = 0;
	m[14] = 0;
	m[15] = 1;
}

void Matrix4f::scale(float x, float y, float z)
{
	//this = this * roationmatrix
	//http://www.songho.ca/opengl/gl_matrix.html
}

void Matrix4f::scale(float u)
{
	//this = this * scalematrix
	//http://www.songho.ca/opengl/gl_matrix.html
}

void Matrix4f::translate(float x, float y, float z)
{
	// this = this * translatematrix
	//http://www.songho.ca/opengl/gl_matrix.html
}

void Matrix4f::rotate()
{
	//http://www.songho.ca/opengl/gl_matrix.html
}

void Matrix4f::setFrustum(float left, float right, float bottom, float top, float, float)
{
}

void Matrix4f::setOrtho()
{

}


Matrix4f::~Matrix4f()
{
}
