#pragma once
#include "Helpers.h"
#include "Vectors.h"

class Matrix3 {
public:

	Matrix3();
	Matrix3(float m00, float m01 , float m02, float m10, float m11, float m12, float m20, float m21, float m22);
	
public:
	
	union {
		struct { float m00, m01, m02, m10, m11, m12, m20, m21, m22 };
		float m[9];
		float mm[3][3];
		Vector3 axis[3];
	};

};

class Matrix4 {
public:

	Matrix4();
	Matrix4(float m00, float m01, float m02, float m03, float m10, float m11, float m12, float m13, float m20, float m21, float m22, float m23, float m30, float m31, float m32, float m33);

public:

	union {
		struct { float m00, m01, m02, m03, m10, m11, m12, m13, m20, m21, m22, m23, m30, m31, m32, m33 };
		float m[16];
		float mm[4][4];
		Vector4 axis[4];
	};

	

};
