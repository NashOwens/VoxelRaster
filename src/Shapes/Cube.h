#pragma once
#include "Shape.h"

class Cube : public Shape
{
public:
    Cube(float x, float y, float z) : Shape(108, { -1.0f,  1.0f, -1.0f, -1.0f, -1.0f, -1.0f,
	1.0f, -1.0f, -1.0f, 1.0f, -1.0f, -1.0f, 1.0f,  1.0f, -1.0f,
	-1.0f,  1.0f, -1.0f, 1.0f, -1.0f, -1.0f, 1.0f, -1.0f,  1.0f,
	1.0f,  1.0f, -1.0f, 1.0f, -1.0f,  1.0f, 1.0f,  1.0f,  1.0f,
	1.0f,  1.0f, -1.0f, 1.0f, -1.0f,  1.0f, -1.0f, -1.0f,  1.0f,
	1.0f,  1.0f,  1.0f,-1.0f, -1.0f,  1.0f, -1.0f,  1.0f,  1.0f,
	1.0f,  1.0f,  1.0f,-1.0f, -1.0f,  1.0f, -1.0f, -1.0f, -1.0f,
	-1.0f,  1.0f,  1.0f,-1.0f, -1.0f, -1.0f, -1.0f,  1.0f, -1.0f,
	-1.0f,  1.0f,  1.0f,-1.0f, -1.0f,  1.0f,  1.0f, -1.0f,  1.0f,
	1.0f, -1.0f, -1.0f, 1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f,
	-1.0f, -1.0f,  1.0f,-1.0f,  1.0f, -1.0f, 1.0f,  1.0f, -1.0f,
	1.0f,  1.0f,  1.0f, 1.0f,  1.0f,  1.0f, -1.0f,  1.0f,  1.0f,
	-1.0f,  1.0f, -1.0f }, x, y ,z) {};
	~Cube() {};
};

