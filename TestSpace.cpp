#include "Helpers.h"
#include "Vectors.h"
#include "Matrices.h"
#include <iostream>

using namespace std;
using namespace constants;

int main() {

	Matrix4 m1(1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16);
	
	cout << m1.ToString();

	Vector4 result = m1 * Vector4(2, 2, 2, 1);
	cout << result.x << endl << result.y << endl << result.z << endl << result.w;
}