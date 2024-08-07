#include "Helpers.h"
#include "Vectors.h"
#include <iostream>

using namespace std;

int main() {

	Vector3 vec1(3.97f, 5.02f, 0.0007f);
	Vector3 vec3(12.01f, 0.554f, 23.2f);

	Vector3 vec2 = vec3.Cross(vec1);

	cout << vec2.x << endl << vec2.y << endl << vec2.z;

}