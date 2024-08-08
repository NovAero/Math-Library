#include "Helpers.h"
#include "Vectors.h"
#include "Matrices.h"
#include <iostream>

using namespace std;

int main() {


	Matrix3 m1;

	m1 = MakeScale(Vector3(7,4,9));

	cout << m1.ToString();

}