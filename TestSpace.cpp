#include "Helpers.h"
#include "Vectors.h"
#include <iostream>

using namespace std;

int main() {

	Vector3 vector(3,5,7);
	Vector3 vec2(1, 1, 2);

	Vector3 vec3 = vec2;

	cout << vec3.x;

}