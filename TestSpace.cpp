#include "Helpers.h"
#include "Vectors.h"
#include "Matrices.h"
#include <iostream>

using namespace std;
using namespace constants;
using namespace Mx3Tmpls;
using namespace Mx4Tmpls;


int main() {

	Matrix4 m1 = MakeIdentityM4();

	cout << m1.ToString();

	cout << (m1 * Mx4Tmpls::MakeRotateX4(PI / 2)).ToString();
}