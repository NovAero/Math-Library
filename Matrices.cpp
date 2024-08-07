#include "Matrices.h"

Matrix3::Matrix3()
{
	*this = MakeIdentityM3();
}

Matrix3::Matrix3(float m00, float m01, float m02, float m10, float m11, float m12, float m20, float m21, float m22)
{
	//X axis
	this->m00 = m00;
	this->m01 = m01;
	this->m02 = m02;

	//Y axis
	this->m10 = m10;
	this->m11 = m11;
	this->m12 = m12;

	//Z axis
	this->m20 = m20;
	this->m21 = m21;
	this->m22 = m22;

}

Vector3 Matrix3::GetRow(int index) const
{
	Vector3 vec;
	switch (index)
	{
	case 0:
		vec = Vector3(m00, m01, m02);
		break;
	case 1:
		vec = Vector3(m10, m11, m12);
		break;
	case 2:
		vec = Vector3(m20, m21, m22);
		break;
	}
	return vec;
}

float& Matrix3::operator[](int dim)
{
	return m[dim];
}

const float& Matrix3::operator[](int dim) const
{
	return m[dim];
}

std::string Matrix3::ToString() const
{
	//make header
	std::string str = ("|   x    |    y   |    z   |\n|--------|--------|--------| \n");


	for (int i = 0; i < 3; i++)
	{
		Vector3 row = GetRow(i);
		for (int j = 0; j < 3; j++)
		{
			str += "|" + std::to_string(row[j]);
		}
		str += "|\n";
	}
	return str;
}
