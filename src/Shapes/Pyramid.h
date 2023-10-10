#pragma once
#include "Shape.h"
class Pyramid :
    public Shape
{
public:
	Pyramid(float x, float y, float z) : Shape(54, { -1.0f, -1.0f, 1.0f, 1.0f, -1.0f, 1.0f, 0.0f, 1.0f, 0.0f,
		1.0f, -1.0f, 1.0f, 1.0f, -1.0f, -1.0f, 0.0f, 1.0f, 0.0f,  1.0f, -1.0f, -1.0f, -1.0f,
		-1.0f, -1.0f, 0.0f, 1.0f, 0.0f,  -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, 1.0f, 0.0f, 1.0f,
		0.0f,  -1.0f, -1.0f, -1.0f, 1.0f, -1.0f, 1.0f, -1.0f, -1.0f, 1.0f,  1.0f, -1.0f, 1.0f,
		-1.0f, -1.0f, -1.0f, 1.0f, -1.0f, -1.0f
		}, x, y, z) {};
	~Pyramid() {};
};

