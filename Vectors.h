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

class Vector4
{
public:



private:

	union {
		struct { float x, y, z, w; };
		struct { float r, g, b, a; };
		float data[4];
	};

};
