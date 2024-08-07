#pragma once
#include "Helpers.h"
#include <string>

class Vector3
{
public:

	Vector3();
	Vector3(const float x, const float y, const float z);
	Vector3(const float value);

public:

	float& operator[](int index);
	const float& operator[](int index) const;

	Vector3 operator+(const Vector3 rhs) const;
	Vector3 operator+=(const Vector3 rhs);
	Vector3 operator-(const Vector3 rhs) const;
	Vector3 operator-=(const Vector3 rhs);

	Vector3 operator*(float scale) const;
	Vector3 operator/(float scale) const;

	bool operator==(const Vector3 rhs) const;
	bool operator!=(const Vector3 rhs) const;

	bool IsEqual(const Vector3 rhs, float precision = constants::FLOAT_PRECISION) const;

	float Dot(const Vector3& rhs);
	float Dot(float rhsX, float rhsY, float rhsZ);

	Vector3 Cross(const Vector3& rhs);

	float Magnitude() const;
	float MagnitudeSqr() const;

	void Normalise();



public:

	union {
		struct { float x, y, z; };
		struct { float r, g, b; };
		float data[3];
	};

};

Vector3 operator*(float lhs, Vector3 rhs);
float DotProduct(const Vector3& v1, const Vector3& v2);



class Vector4
{
public:

	Vector4();
	Vector4(const float x, const float y, const float z, const float w);
	Vector4(const float value);

public:

	union {
		struct { float x, y, z, w; };
		struct { float r, g, b, a; };
		float data[4];
	};

};
