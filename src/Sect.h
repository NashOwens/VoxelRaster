#pragma once
#include "Shapes/Cube.h"
#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Sect
{
public:
	Sect();
	~Sect();

	void drawContents(glm::mat4 vMat, float currentTime, GLuint mvLoc, GLuint projLoc, GLuint* vbo);
	void setSpace(Cube* cube);

private:
	Cube* space[10][100][10];
};

