#include "Helpers.h"
#include "Vectors.h"
#include "Matrices.h"
#include <iostream>

using namespace std;

int main() {


	Matrix4 m1;

	m1 = MakeIdentityM4();

	cout << m1.ToString();
}