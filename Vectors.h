#pragma once
#include "Helpers.h"
#include <string>
#include <cmath>

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

	operator float*() const;

	bool IsEqual(const Vector3 rhs, float precision = constants::FLOAT_PRECISION) const;

	float Dot(const Vector3& rhs);
	float Dot(float rhsX, float rhsY, float rhsZ);

	Vector3 Cross(const Vector3& rhs);

	float Magnitude() const;
	float MagnitudeSqr() const;

	void Normalise();
	Vector3 Normalised() const;

	float Distance(const Vector3& other) const;

	std::string ToString() const;


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

	operator float* () const;

	bool operator==(const Vector4& rhs) const;
	bool operator!=(const Vector4& rhs) const;
	bool IsEqual(Vector4 rhs, float precision = constants::FLOAT_PRECISION) const;

	Vector4 operator+(const Vector4 rhs) const;
	Vector4 operator-(const Vector4 rhs) const;
	Vector4 operator*(float scale) const;
	Vector4 operator/(float scale) const;

	Vector4& operator+=(const Vector4& other);
	Vector4& operator-=(const Vector4& other);
	Vector4& operator*=(float& scalar);

	float& operator[](const int index);
	float operator[](const int index) const;
	float Magnitude() const;
	void Normalise();
	Vector4 Normalised();

	float Dot(const Vector4& other) const;
	Vector4 Cross(const Vector4& rhs) const;

	std::string ToString() const;

public:

	union {
		struct { float x, y, z, w; };
		struct { float r, g, b, a; };
		float data[4];
	};


};

Vector4 operator*(float lhs, Vector4 rhs);
float DotProduct(const Vector4& vec1, const Vector4& vec2);