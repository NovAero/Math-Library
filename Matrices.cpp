#include "Matrices.h"


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//                                   Matrix 3x3                                         //
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

Matrix3::Matrix3() : Matrix3{ 0 }
{

}

Matrix3::Matrix3(float m00, float m10, float m20, float m01, float m11, float m21, float m02, float m12, float m22)
{
	//X axis
	this->m00 = m00;
	this->m10 = m10;
	this->m20 = m20;

	//Y axis
	this->m01 = m01;
	this->m11 = m11;
	this->m21 = m21;

	//Z axis
	this->m02 = m02;
	this->m12 = m12;
	this->m22 = m22;

}

Matrix3::Matrix3(float numbers[])
{
	for (int i = 0; i < 9; ++i) {
		m[i] = numbers[i];
	}

}

Matrix3 Matrix3::Transposed() const
{
	return Matrix3(m00, m01, m02,
				   m10, m11, m12,
				   m20, m21, m22);
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
		vec = Vector3(m10, m11, m21);
		break;
	case 2:
		vec = Vector3(m20, m21, m22);
		break;
	}
	return vec;
}

Matrix3::operator float* () const
{
	return const_cast<float*>(m);
}

bool Matrix3::operator==(const Matrix3& rhs) const
{
	return IsEqual(rhs);
}

bool Matrix3::operator!=(const Matrix3& rhs) const
{
	return !(*this == rhs);
}

bool Matrix3::IsEqual(const Matrix3& rhs, const float precision) const
{
	return (xAxis.IsEqual(rhs.xAxis, precision) &&
		    yAxis.IsEqual(rhs.yAxis, precision) &&
		    zAxis.IsEqual(rhs.zAxis, precision));
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
		Vector3(m00, m01, m02).Dot(rhs),
		Vector3(m10, m11, m12).Dot(rhs),
		Vector3(m20, m21, m22).Dot(rhs)
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

Matrix4::Matrix4(float m00, float m10, float m20, float m30, float m01, float m11, float m21, float m31, float m02, float m12, float m22, float m32, float m03, float m13, float m23, float m33)
{
	//X axis
	this->m00 = m00;
	this->m10 = m10;
	this->m20 = m20;
	this->m30 = m30;

	//Y axis
	this->m01 = m01;
	this->m11 = m11;
	this->m21 = m21;
	this->m31 = m31;

	//Z axis
	this->m02 = m02;
	this->m12 = m12;
	this->m22 = m22;
	this->m32 = m32;

	//local pos
	this->m03 = m03;
	this->m13 = m13;
	this->m23 = m23;
	this->m33 = m33;
}

Matrix4::Matrix4(float numbers[])
{
	for (int i = 0; i < 16; ++i) {
		m[i] = numbers[i];
	}

}

Vector4 Matrix4::GetRow(int index) const
{
	Vector4 vec;
	switch (index)
	{
	case 0:
		vec = Vector4(m00, m01, m02, m03);
		break;		
	case 1:			
		vec = Vector4(m10, m11, m12, m13);
		break;		
	case 2:			
		vec = Vector4(m20, m21, m22, m23);
		break;
	case 3:
		vec = Vector4(m30, m31, m32, m33);
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

Matrix4::operator float* () const
{
	return const_cast<float*>(m);
}

bool Matrix4::operator==(const Matrix4& rhs) const
{
	return IsEqual(rhs);
}

bool Matrix4::operator!=(const Matrix4& rhs) const
{
	return !(*this == rhs);
}

bool Matrix4::IsEqual(const Matrix4& rhs, const float precision) const
{
	return (xAxis.IsEqual(rhs.xAxis, precision) &&
			yAxis.IsEqual(rhs.yAxis, precision) &&
			zAxis.IsEqual(rhs.zAxis, precision) &&
			translation.IsEqual(rhs.translation, precision));
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
			for (int i = 0; i < 4; ++i) {
				v += mm[i][r] * other.mm[c][i];
			}
			result.mm[c][r] = v;
		}
	}
	return result;
}

float& Matrix4::operator[](int dim)
{
	return m[dim];
}

const float& Matrix4::operator[](int dim) const
{
	return m[dim];
}

std::string Matrix4::ToString() const
{
	//make header
	std::string str = ("|   x    |    y   |    z   |    T   |\n|--------|--------|--------|--------| \n");


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
