#include "Helpers.h"
#include "Vectors.h"
#include "Matrices.h"
#include <iostream>

using namespace std;
using namespace constants;

int main() {

	Matrix3 m1(1,0,0,0,-1,0,0,0,0);

	cout << m1.xAxis.x << endl << m1.xAxis.y << endl<< m1.xAxis.z<<endl;
	
	cout << m1.ToString();

	m1 = m1 * MakeRotateZ(-PI/2);

	cout << m1.ToString();
}