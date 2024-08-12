#include "Helpers.h"
#include "Vectors.h"
#include "Matrices.h"
#include <iostream>
#include "Colour.h"

using namespace std;
using namespace constants;
using namespace Mx3Tmpls;
using namespace Mx4Tmpls;


int main() {

	Matrix4 m1(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	Matrix4 m2(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	Matrix4 m3(16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1);

	Vector4 a(2, 4, 6, 8);
	Vector4 b(3, 5, 7, 9);

	cout << a.Cross(b).ToString();

}