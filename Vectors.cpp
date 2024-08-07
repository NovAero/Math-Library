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

Vector3 Vector3::operator+=(const Vector3 rhs)
{

	for (int i = 0; i < 3; ++i) {
		data[i] = data[i] + rhs[i];
	}

	return *this;
}

Vector3 Vector3::operator-(Vector3 rhs) const
{
	Vector3 sum;

	for (int i = 0; i < 3; ++i) {
		sum[i] = sum[i] - rhs[i];
	}

	return sum;
}

Vector3 Vector3::operator-=(const Vector3 rhs)
{
	for (int i = 0; i < 3; ++i) {
		data[i] = data[i] - rhs[i];
	}

	return *this;
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

bool Vector3::operator==(const Vector3 rhs) const
{
	return IsEqual(rhs);
}
bool Vector3::operator!=(const Vector3 rhs) const
{
	return !(*this == rhs);
}
bool Vector3::IsEqual(Vector3 rhs, float precision) const
{
	float xDist = fabsf(x - rhs.x);
	float yDist = fabsf(y - rhs.y);
	float zDist = fabsf(z - rhs.z);

	return  xDist < precision &&
			yDist < precision &&
			zDist < precision;
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

float Vector3::Magnitude() const
{
	return SqrtF(MagnitudeSqr());
}

float Vector3::MagnitudeSqr() const
{
	return x * x + y * y + z * z;
}

void Vector3::Normalise()
{

	float m = Magnitude();

	if (m < constants::FLOAT_PRECISION) {
		throw std::runtime_error("Magnitude is zero");
	}

	x /= m;
	y /= m;
	z /= m;

}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//                                    Vector4                                           //
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

Vector4::Vector4() : Vector4{ 0 }
{
	w = 1;
}

Vector4::Vector4(const float x, const float y, const float z, const float w) : x{ x }, y{ y }, z{ z }, w{ w }
{
}

Vector4::Vector4(const float value) : x{ value }, y{ value }, z{ value }, w{ value }
{
}
