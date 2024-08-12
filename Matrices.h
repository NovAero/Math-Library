#pragma once
#include "Helpers.h"
#include "Vectors.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//                                   Matrix 3x3                                         //
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

	class Matrix3 {
	public:

		Matrix3();
		Matrix3(float m00, float m10, float m20, float m01, float m11, float m21, float m02, float m12, float m22);
		Matrix3(float numbers[]);

	public:
	
		union {
			struct { // float mROW_COLUMN
				float m00, m10, m20, //X axis
					  m01, m11, m21, //Y axis
					  m02, m12, m22; //Z axis
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
	
		operator float* () const;

		bool operator==(const Matrix3& rhs) const;
		bool operator!=(const Matrix3& rhs) const;
		bool IsEqual(const Matrix3& rhs, const float precision = constants::FLOAT_PRECISION) const;

		Matrix3 operator*(Matrix3 rhs) const;
		Vector3 operator*(Vector3 rhs) const;

		float& operator[](int dim);
		const float& operator[](int dim) const;

		std::string ToString() const;

	};

namespace Mx3Tmpls {

	static const Matrix3 MakeIdentityM3()
	{
		Matrix3 identity;
		//xAxis
		identity.m00 = 1;
		identity.m10 = 0;
		identity.m20 = 0;

		//yAxis
		identity.m01 = 0;
		identity.m11 = 1;
		identity.m21 = 0;

		//zAxis
		identity.m02 = 0;
		identity.m12 = 0;
		identity.m22 = 1;

		return identity;
	}

	static Matrix3 MakeRotateX3(float r)
	{
		return Matrix3(1, 0, 0,     //xAxis
			0, cosf(r), -sinf(r), //yAxis
			0, sinf(r), cosf(r)); //zAxis
	}
	//Param: r is radians
	static Matrix3 MakeRotateY3(float r)
	{
		return Matrix3(cosf(r), 0, sinf(r),  //xAxis
			0, 1, 0,     //yAxis
			-sinf(r), 0, cosf(r)); //zAxis
	}
	//Param: r is radians
	static Matrix3 MakeRotateZ3(float r)
	{
		return Matrix3(cosf(r), -sinf(r), 0, //xAxis
			sinf(r), cosf(r), 0, //yAxis
			0, 0, 1);//zAxis
	}

	static Matrix3 MakeEuler3(float pitch, float yaw, float roll)
	{
		Matrix3 x = MakeRotateX3(pitch);
		Matrix3 y = MakeRotateY3(yaw);
		Matrix3 z = MakeRotateZ3(roll);

		return (z * y * x);
	}

	static Matrix3 MakeScale3(float xScale, float yScale, float zScale)
	{
		return Matrix3(xScale, 0, 0,
			0, yScale, 0,
			0, 0, zScale);
	}
	static Matrix3 MakeScale3(Vector3 scale)
	{
		return MakeScale3(scale.x, scale.y, scale.z);
	}

	static Matrix3 MakeTranslation(float dirX, float dirY, float dirZ) {

		return Matrix3(1, 0, 0,
			           0, 1, 0,
			       dirX, dirY, dirZ);
	}

	static Matrix3 MakeTranslation(Vector3 dir) {
		return MakeTranslation(dir.x, dir.y, dir.z);
	}

}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//                                   Matrix 4x4                                         //
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

class Matrix4 {
public:

	Matrix4();
	Matrix4(float m00, float m10, float m20, float m30, float m01, float m11, float m21, float m31, float m02, float m12, float m22, float m32, float m03, float m13, float m23, float m33);
	Matrix4(float numbers[]);

public:

	Vector4 GetRow(int index) const;

	void SetScaled(float x, float y, float z);
	void SetRotateX(float radians);
	void Translate(float x, float y, float z);

	operator float* () const;

	bool operator==(const Matrix4& rhs) const;
	bool operator!=(const Matrix4& rhs) const;
	bool IsEqual(const Matrix4& rhs, const float precision = constants::FLOAT_PRECISION) const;

	Vector4 operator*(const Vector4& v) const;
	Matrix4 operator*(const Matrix4& other) const;

	float& operator[](int dim);
	const float& operator[](int dim) const;
	
	std::string ToString() const;

public:

	union {
		struct { //ROW,COLUMN
			float m00, m10, m20, m30,//X axis
				  m01, m11, m21, m31,//Y axis
				  m02, m12, m22, m32,//Z axis
				  m03, m13, m23, m33;//Translation
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


namespace Mx4Tmpls {

	static const Matrix4 MakeIdentityM4()
{
	Matrix4 identity;
	//xAxis
	identity.m00 = 1;
	identity.m10 = 0;
	identity.m20 = 0;
	identity.m30 = 0;

	//yAxis
	identity.m01 = 0;
	identity.m11 = 1;
	identity.m21 = 0;
	identity.m31 = 0;

	//zAxis
	identity.m02 = 0;
	identity.m12 = 0;
	identity.m22 = 1;
	identity.m32 = 0;

	//Local Position
	identity.m03 = 0;
	identity.m13 = 0;
	identity.m23 = 0;
	identity.m33 = 1;

	return identity;
}
	
	static Matrix4 MakeRotateX4(float r)
	{
		return Matrix4(1, 0, 0, 0,     //xAxis
			0, cosf(r), -sinf(r), 0, //yAxis
			0, sinf(r), cosf(r), 0, // zAxis
			0, 0, 0, 1);
	}
	//Param: r is radians
	static Matrix4 MakeRotateY4(float r)
	{
		return Matrix4(cosf(r), 0, sinf(r), 0,  //xAxis
			0, 1, 0, 0,  //yAxis
			-sinf(r), 0, cosf(r), 0,	//zAxis
			0, 0, 0, 1);
	}
	//Param: r is radians
	static Matrix4 MakeRotateZ4(float r)
	{
		return Matrix4(cosf(r), -sinf(r), 0, 0, //xAxis
			sinf(r), cosf(r), 0, 0, //yAxis
			0, 0, 1, 0, //zAxis
			0, 0, 0, 1);
	}

	static Matrix4 MakeEuler4(float pitch, float yaw, float roll)
	{
		Matrix4 x = MakeRotateX4(pitch);
		Matrix4 y = MakeRotateY4(yaw);
		Matrix4 z = MakeRotateZ4(roll);

		return (z * y * x);
	}

	static Matrix4 MakeScale4(float xScale, float yScale, float zScale)
	{
		return Matrix4(xScale, 0, 0, 0,
			0, yScale, 0, 0,
			0, 0, zScale, 0,
			0, 0, 0, 1);
	}
	static Matrix4 MakeScale4(Vector4 scale)
	{
		return MakeScale4(scale.x, scale.y, scale.z);
	}

	static Matrix4 MakeTranslation(float dirX, float dirY, float dirZ) {

		return Matrix4( 1, 0 , 0 , 0,
						0, 1 , 0 , 0,
						0, 0 , 1 , 0,
					dirX, dirY , dirZ , 1);
	}

	static Matrix4 MakeTranslation(Vector3 dir) {
		return MakeTranslation(dir.x, dir.y, dir.z);
	}

}