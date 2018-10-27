#pragma once
class Matrix4f
{
public:
	float* m;

	Matrix4f();
	Matrix4f(float* n);
	Matrix4f(Matrix4f* n);
	Matrix4f(
		float a0, float a1, float a2, float a3,
		float b0, float b1, float b2, float b3,
		float c0, float c1, float c2, float c3,
		float d0, float d1, float d2, float d3);
	void loadIdentity();
	void scale(float x, float y, float z);
	void scale(float u); /*uniform scale all axis the same*/
	void translate(float x, float y, float z);
	void rotate();
	//void multiply();
	void setFrustum(float left, float right, float bottom, float top, float near, float far);
	//void setFrustum(float fovY, float aspectRatio, float front, float back);
	//void setOrthoFrust(float left, float right, float back, float top, float near, float far;)
	void setOrtho();

	Matrix4f operator=(Matrix4f n) const;
	Matrix4f operator+(Matrix4f n) const;
	Matrix4f operator-(Matrix4f n) const;   
	Matrix4f operator*(Matrix4f n) const;  // = multiplay 
	~Matrix4f();

};

