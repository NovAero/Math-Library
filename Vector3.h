#pragma once
#include "Helpers.h"

class Vector3
{

public:

private:

	union {
		struct { float x, y, z; };
		struct { float r, g, b; };
		float data[3];
	};

};

