#include "Matrices.h"


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//                                   Matrix 3x3                                         //
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

Matrix3::Matrix3()
{
	m00 = m01 = m02 = m10 = m11 = m12 = m20 = m21 = m22 = 0.0f;
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

Matrix3 Matrix3::Transposed() const
{
	return Matrix3(m00, m10, m20, m01, m11, m21, m02, m12, m22);
}

Vector3 Matrix3::GetRow(int index) const
{
	Vector3 vec;
	switch (index)
	{
	case 0:
		vec = Vector3(m00, m10, m20);
		break;
	case 1:
		vec = Vector3(m01, m11, m21);
		break;
	case 2:
		vec = Vector3(m02, m12, m22);
		break;
	}
	return vec;
}

Matrix3 Matrix3::operator*(Matrix3 rhs) const
{
	// stores the return value
	Matrix3 result;
	// iterate through first matrix
	for (int i = 0; i < 3; ++i)
	{
		// current row from first matrix
		Vector3 row(mm[0][i], mm[1][i], mm[2][i]);

		// iterate through second matrix
		for (int j = 0; j < 3; ++j)
		{
			// dot each row with each column and assign to result matrix
			// result is calculated row-by-row
			result.mm[j][i] = row.Dot(rhs.axis[j]);
		}
	}

	return result;
}

Vector3 Matrix3::operator*(Vector3 rhs) const
{
	return Vector3(
		Vector3(m00, m10, m20).Dot(rhs),
		Vector3(m01, m11, m21).Dot(rhs),
		Vector3(m02, m12, m22).Dot(rhs)
	);
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

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//                                   Matrix 4x4                                         //
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//



Matrix4::Matrix4()
{
	for (int i = 0; i < 16;++i) {
		m[i] = 0.0f;
	}
}

Matrix4::Matrix4(float m00, float m01, float m02, float m03, float m10, float m11, float m12, float m13, float m20, float m21, float m22, float m23, float m30, float m31, float m32, float m33)
{
	//X axis
	this->m00 = m00;
	this->m01 = m01;
	this->m02 = m02;
	this->m03 = m03;

	//Y axis
	this->m10 = m10;
	this->m11 = m11;
	this->m12 = m12;
	this->m13 = m13;
	
	//Z axis
	this->m20 = m20;
	this->m21 = m21;
	this->m22 = m22;
	this->m23 = m23;
	
	//local pos
	this->m30 = m30;
	this->m31 = m31;
	this->m32 = m32;
	this->m33 = m33;
}

Vector4 Matrix4::GetRow(int index) const
{
	Vector4 vec;
	switch (index)
	{
	case 0:
		vec = Vector4(m00, m10, m20, m30);
		break;		
	case 1:			
		vec = Vector4(m01, m11, m21, m31);
		break;		
	case 2:			
		vec = Vector4(m02, m12, m22, m32);
		break;
	case 3:
		vec = Vector4(m03, m13, m23, m33);
		break;
	}
	return vec;
}

void Matrix4::SetScaled(float x, float y, float z) {
	// set scale of each axis
	xAxis = { x, 0, 0, 0 };
	yAxis = { 0, y, 0, 0 };
	zAxis = { 0, 0, z, 0 };
	translation = { 0, 0, 0, 1 };
}

void Matrix4::SetRotateX(float radians) {
	// leave X axis and elements unchanged
	xAxis = { 1, 0, 0, 0 };
	yAxis = { 0, cosf(radians), sinf(radians), 0 };
	zAxis = { 0, -sinf(radians), cosf(radians), 0 };
	translation = { 0, 0, 0, 1 };
}

void Matrix4::Translate(float x, float y, float z) {
	// apply vector offset
	translation += Vector4(x, y, z, 0);
}

// binary * operator
Vector4 Matrix4::operator * (const Vector4& v) const {
	Vector4 result;

	result[0] = mm[0][0] * v[0] + mm[1][0] * v[1] +
		mm[2][0] * v[2] + mm[3][0] * v[3];

	result[1] = mm[0][1] * v[0] + mm[1][1] * v[1] +
		mm[2][1] * v[2] + mm[3][1] * v[3];

	result[2] = mm[0][2] * v[0] + mm[1][2] * v[1] +
		mm[2][2] * v[2] + mm[3][2] * v[3];

	result[3] = mm[0][3] * v[0] + mm[1][3] * v[1] +
		mm[2][3] * v[2] + mm[3][3] * v[3];
	return result;
}

// binary * operator
Matrix4 Matrix4::operator*(const Matrix4& other) const {
	Matrix4 result;

	for (int r = 0; r < 4; ++r) {
		for (int c = 0; c < 4; ++c) {
			float v = 0.0f;
			for (int i = 0; 0 < 4; ++i) {
				v += mm[i][r] * other.mm[c][i];
			}
			result.mm[c][r] = v;
		}
	}
	return result;
}

std::string Matrix4::ToString()
{
	//make header
	std::string str = ("|   x    |    y   |    z   |    L   |\n|--------|--------|--------|--------| \n");


	for (int i = 0; i < 4; i++)
	{
		Vector4 row = GetRow(i);
		for (int j = 0; j < 4; j++)
		{
			str += "|" + std::to_string(row[j]);
		}
		str += "|\n";
	}
	return str;
}
