#pragma once
#include "Helpers.h"
#include "Vectors.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//                                   Matrix 3x3                                         //
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

class Matrix3 {
public:

	Matrix3();
	Matrix3(float m00, float m01 , float m02, float m10, float m11, float m12, float m20, float m21, float m22);
	
public:
	
	union {
		struct { 
			float m00, m10, m20,
				  m01, m11, m21,
				  m02, m12, m22;
		};
		struct {

			Vector3 xAxis;
			Vector3 yAxis;
			Vector3 zAxis;

		};
		float m[9];
		float mm[3][3];
		Vector3 axis[3];
	};

public:
		
	Matrix3 Transposed() const;
	Vector3 GetRow(int index) const;
	
	Matrix3 operator*(Matrix3 rhs) const;
	Vector3 operator*(Vector3 rhs) const;

	float& operator[](int dim);
	const float& operator[](int dim) const;

	std::string ToString() const;

};

static const Matrix3 MakeIdentityM3()
{
	Matrix3 identity;
	//xAxis
	identity.m00 = 1;
	identity.m01 = 0;
	identity.m02 = 0;

	//yAxis
	identity.m10 = 0;
	identity.m11 = 1;
	identity.m12 = 0;

	//zAxis
	identity.m20 = 0;
	identity.m21 = 0;
	identity.m22 = 1;

	return identity;
}

static Matrix3 MakeRotateX(float r)
{
	return Matrix3(1,    0,       0,     //xAxis
				   0, cosf(r), -sinf(r), //yAxis
				   0, sinf(r), cosf(r)); //zAxis
}
//Param: r is radians
static Matrix3 MakeRotateY(float r)
{
	return Matrix3(cosf(r), 0, sinf(r),  //xAxis
		              0,    1,    0,     //yAxis
		          -sinf(r), 0, cosf(r)); //zAxis
}
//Param: r is radians
static Matrix3 MakeRotateZ(float r)
{
	return Matrix3(cosf(r), -sinf(r), 0, //xAxis
		           sinf(r),  cosf(r), 0, //yAxis
		              0,       0,     1);//zAxis
}

static Matrix3 MakeEuler(float pitch, float yaw, float roll)
{
	Matrix3 x = MakeRotateX(pitch);
	Matrix3 y = MakeRotateY(yaw);
	Matrix3 z = MakeRotateZ(roll);

	return (z * y * x);
}

static Matrix3 MakeScale(float xScale, float yScale, float zScale)
{
	return Matrix3(xScale, 0, 0,
		0, yScale, 0,
		0, 0, zScale);
}
static Matrix3 MakeScale(Vector3 scale)
{
	return MakeScale(scale.x, scale.y, scale.z);
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//                                   Matrix 4x4                                         //
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

class Matrix4 {
public:

	Matrix4();
	Matrix4(float m00, float m01, float m02, float m03, //X axis
			float m10, float m11, float m12, float m13, //Y axis
			float m20, float m21, float m22, float m23, //Z axis
			float m30, float m31, float m32, float m33);//Translation

public:

	Vector4 GetRow(int index) const;

	void SetScaled(float x, float y, float z);
	void SetRotateX(float radians);
	void Translate(float x, float y, float z);
	Vector4 operator*(const Vector4& v) const;
	Matrix4 operator*(const Matrix4& other) const;

	std::string ToString();

public:

	union {
		struct { //X    Y    Z    T
			float m00, m10, m20, m30,
				  m01, m11, m21, m31,
				  m02, m12, m22, m32,
				  m03, m13, m23, m33;
			};
		
		struct {
			Vector4 xAxis;
			Vector4 yAxis;
			Vector4 zAxis;
			Vector4 translation;
		};

		float m[16];
		float mm[4][4];
		Vector4 axis[4];
	};

};

static const Matrix4 MakeIdentityM4()
{
	Matrix4 identity;
	//xAxis
	identity.m00 = 1;
	identity.m01 = 0;
	identity.m02 = 0;
	identity.m03 = 0;

	//yAxis
	identity.m10 = 0;
	identity.m11 = 1;
	identity.m12 = 0;
	identity.m13 = 0;

	//zAxis
	identity.m20 = 0;
	identity.m21 = 0;
	identity.m22 = 1;
	identity.m23 = 0;

	//Local Position
	identity.m30 = 0;
	identity.m31 = 0;
	identity.m32 = 0;
	identity.m33 = 1;

	return identity;
}