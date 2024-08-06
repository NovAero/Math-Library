#include "Helpers.h"
#include <iostream>

using namespace std;

int main() {

	float number = 1373.0123f;

	float sqrtn = SqrtF(number);

	cout << sqrtn << endl;

	cout << number << endl;
	cout << sqrtn * sqrtn;
}