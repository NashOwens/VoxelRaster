#include "Sect.h"
#include "Shapes/Cube.h"
#include "glm/glm.hpp"
#include <vector>
#include <stack>


Sect::Sect() 
{
	for (int i = 0;i < 10;i++) {
		for (int j = 0;j < 100; j++) {
			for (int k = 0; k < 10; k++) {
				this->space[i][j][k] = new Cube(i, j, k);
			}
		}
	}
}
Sect::~Sect() {};

void Sect::drawContents(glm::mat4 vMat,float currentTime, GLuint mvLoc, GLuint projLoc, GLuint* vbo) {
	std::stack<glm::mat4> mvStack;
	glEnable(GL_CULL_FACE);
	mvStack.push(vMat);
	for (int i = 0;i < 10;i++) {
		for (int j = 0;j < 100; j++) {
			for (int k = 0; k < 10; k++) {
				mvStack.push(mvStack.top());
				mvStack.top() *= this->space[i][j][k]->Trans(i, j, k);
				mvStack.top() *= this->space[i][j][k]->Scale(0.5f, 0.5f, 0.5f);

				glUniformMatrix4fv(mvLoc, 1, GL_FALSE, glm::value_ptr(mvStack.top()));
				glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
				glEnableVertexAttribArray(0);
				glCullFace(GL_BACK);
				glFrontFace(GL_CW);
				glDrawArrays(GL_TRIANGLES, 0, 36);
				mvStack.pop();
			};
		}
	}
}
void Sect::setSpace(Cube* cube) {
	int x = cube->getX();
	int y = cube->getY();
	int z = cube->getZ();
	space[x][y][z] = cube;
};
