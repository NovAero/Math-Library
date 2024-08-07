#pragma once

#include "Helpers.h"

class Vector3
{
public:

	Vector3();
	Vector3(float x, float y, float z);
	Vector3(Vector3& copy);

	~Vector3();

public:

	Vector3& operator+(Vector3 rhs);
	Vector3& operator-(Vector3 rhs);
	Vector3& operator*(Vector3 scale);
	Vector3& operator/(Vector3 scale);




public:

	union {
		struct { float x, y, z; };
		struct { float r, g, b; };
		float data[3];
	};

};

class Vector4
{
public:



public:

	union {
		struct { float x, y, z, w; };
		struct { float r, g, b, a; };
		float data[4];
	};

};
