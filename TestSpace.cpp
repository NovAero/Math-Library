#include "Helpers.h"
#include <iostream>

using namespace std;

int main() {

	float number = 132342.0f;

	double sqrtn = SqrtF(number);

	cout << sqrtn << endl;

	cout << number << endl;
	cout << sqrtn * sqrtn;
}