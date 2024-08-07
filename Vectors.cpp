#include "Vectors.h"

Vector3::Vector3()
{

	x = 0;
	y = 0;
	z = 0;

}

Vector3::Vector3(float x, float y, float z)
{
	data[0] = x;
	data[1] = y;
	data[2] = z;
}

Vector3::Vector3(Vector3& copy)
{
	*this = copy;
}

Vector3::~Vector3()
{
}





Vector3& Vector3::operator+(Vector3 rhs)
{
	for (int i = 0; i < 3; ++i) {
		data[i] = data[i] + rhs.data[i];
	}

	return *this;
}

Vector3& Vector3::operator-(Vector3 rhs)
{
	for (int i = 0; i < 3; ++i) {
		data[i] = data[i] - rhs.data[i];
	}

	return *this;
}

Vector3& Vector3::operator*(Vector3 scale)
{
	for (int i = 0; i < 3; ++i) {
		data[i] = data[i] * scale.data[i];
	}

	return *this;
}

Vector3& Vector3::operator/(Vector3 scale)
{
	for (int i = 0; i < 3; ++i) {
		data[i] = data[i] / scale.data[i];
	}

	return *this;
}
