#include "Vectors.h"
#include <iostream>


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//                                    Vector3                                           //
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

Vector3::Vector3() : Vector3{0}
{
}
Vector3::Vector3(const float x, const float y, const float z) : x{ x }, y{ y }, z{ z }
{
}
Vector3::Vector3(const float value) : x{ value }, y{ value }, z(value)
{
}

float& Vector3::operator[](int index)
{
	return data[index];
}
const float& Vector3::operator[](int index) const
{
	return data[index];
}

Vector3 Vector3::operator+(Vector3 rhs) const
{
	Vector3 sum;

	for (int i = 0; i < 3; ++i) {
		sum[i] = sum[i] + rhs[i];
	}	

	return sum;
}

Vector3 Vector3::operator-(Vector3 rhs) const
{
	Vector3 sum;

	for (int i = 0; i < 3; ++i) {
		sum[i] = sum[i] - rhs[i];
	}

	return sum;
}

Vector3 Vector3::operator*(float scale) const
{
	return Vector3(x * scale, y * scale, z * scale);
}

Vector3 Vector3::operator/(float scale) const
{
	if (scale == 0) {
		throw std::runtime_error("Cannot divide by 0");
	}

	return Vector3(x / scale, y / scale, z / scale);
}



float Vector3::Dot(const Vector3& rhs)
{
	return ((x * rhs.x) + (y * rhs.y) + (z * rhs.z));
}
float Vector3::Dot(float rhsX, float rhsY, float rhsZ)
{
	return ((x * rhsX) + (y * rhsY) + (z * rhsZ));
}

Vector3 Vector3::Cross(const Vector3& rhs)
{
	float a, b, c;
	a = (y * rhs.z) - (z * rhs.y);
	b = (z * rhs.x) - (x * rhs.z);
	c = (x * rhs.y) - (y * rhs.x);

	return Vector3(a, b, c);
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//                                    Vector4                                           //
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

Vector4::Vector4() : Vector4{ 0 }
{
}

Vector4::Vector4(const float x, const float y, const float z, const float w) : x{ x }, y{ y }, z{ z }, w{ w }
{
}

Vector4::Vector4(const float value) : x{ value }, y{ value }, z{ value }, w{ value }
{
}
