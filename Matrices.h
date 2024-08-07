#pragma once
#include "Helpers.h"
#include "Vectors.h"


class Matrix3 {
public:

	Matrix3();
	Matrix3(float m00, float m01 , float m02, float m10, float m11, float m12, float m20, float m21, float m22);
	
public:
	
	union {
		struct { float m00, m01, m02, m10, m11, m12, m20, m21, m22; };
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

static Matrix3 MakeIdentityM3()
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


class Matrix4 {
public:

	Matrix4();
	Matrix4(float m00, float m01, float m02, float m03, float m10, float m11, float m12, float m13, float m20, float m21, float m22, float m23, float m30, float m31, float m32, float m33);

public:

	union {
		struct { float m00, m01, m02, m03, m10, m11, m12, m13, m20, m21, m22, m23, m30, m31, m32, m33; };
		float m[16];
		float mm[4][4];
		Vector4 axis[4];
	};

	

};

static Matrix4 MakeIdentityM4()
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