#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <cmath>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Utils/Utils.h"
#include <stack>
#include "Shapes/Cube.h"
#include "Shapes/Pyramid.h"
#include "userInput.h"
#include "Sect.h"

using namespace std;

GLuint renderingProgram;
GLuint* vbo;
float cameraX, cameraY, cameraZ;
float cubeLocX, cubeLocY, cubeLocZ;


float x = 0.0f; // initial location of drawn object on x axis
float s = 1.0f; // size of object in pixels
float s_inc = 0.05f; // size offset for growing and shrinking
float inc = 0.01f; // offset for moving it
double timediff = 0.0f;
float rotation = 1.0f;
float rotation_inc = 0.1f;

// allocate variables used in display so they wont need to be allocated during rendering

GLuint mvLoc, projLoc;
int width, height;
float aspect, timeFactor, tfLoc;
glm::mat4 pMat, vMat, mMat, mvMat, tMat, rMat;

userInput user;

void setupVertices(void) {  // 36 vertices, 12 triangles, makes 2x2x2 cube placed at origin 
	Cube* cube = new Cube(0.0,0.0,0.0);
	Pyramid* pyramid = new Pyramid(0.0,0.0,0.0);

	std::vector<Shape*> shapes;

	shapes.push_back(cube);
	shapes.push_back(pyramid);

	vbo = Utils::populateGlBuffers(shapes);
};

void solarSys(glm::mat4 vMat, float currentTime) {
	//  setting up for stack mv matrix
	stack<glm::mat4> mvStack;

	mvStack.push(vMat);
	// pyramid -- sun
	Pyramid sun = Pyramid(0.0, 0.0, 0.0);
	mvStack.push(mvStack.top());
	mvStack.top() *= sun.Trans(0.0, 0.0, 0.0); // sun position
	mvStack.push(mvStack.top());
	mvStack.top() *= sun.Rot((float)currentTime, 1.0, 0.0, 0.0); // sun rotation

	glUniformMatrix4fv(mvLoc, 1, GL_FALSE, glm::value_ptr(mvStack.top()));
	glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);
	glFrontFace(GL_CCW);
	glDrawArrays(GL_TRIANGLES, 0, 18);
	mvStack.pop();

	// cube -- planet
	Cube planet = Cube(0.0, 0.0, 0.0);
	mvStack.push(mvStack.top());
	mvStack.top() *= planet.Trans(sin((float)currentTime) * 4.0, 0.0, cos((float)currentTime) * 4.0); // planet position
	mvStack.push(mvStack.top());
	mvStack.top() *= planet.Rot((float)currentTime, 0.0, 1.0, 0.0); // planet rotation

	glUniformMatrix4fv(mvLoc, 1, GL_FALSE, glm::value_ptr(mvStack.top()));
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);
	glFrontFace(GL_CW);
	glDrawArrays(GL_TRIANGLES, 0, 36);
	mvStack.pop();
	// smaller cube -- moon
	Cube moon = Cube(0.0, 0.0, 0.0);
	mvStack.push(mvStack.top());
	mvStack.top() *= moon.Trans(0.0, sin((float)currentTime) * 2.0, cos((float)currentTime) * 2.0); // moon position
	mvStack.push(mvStack.top());
	mvStack.top() *= moon.Rot((float)currentTime, 0.0, 0.0, 1.0); // moon rotation
	mvStack.top() *= moon.Scale(0.25f, 0.25f, 0.25f);

	glUniformMatrix4fv(mvLoc, 1, GL_FALSE, glm::value_ptr(mvStack.top()));
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);
	glFrontFace(GL_CW);
	glDrawArrays(GL_TRIANGLES, 0, 36);

	// removes moon scale/rotation/position, planet position, sun position, and view matrices from stack
	
	for(int i=0;i<4;i++)  {
		mvStack.pop();
	}
}

void init(GLFWwindow* window) {
	renderingProgram = Utils::createShaderProgram("../src/vertShader.glsl", "../src/fragShader.glsl");
	cameraX = 0.0f; cameraY = 0.0f; cameraZ = 0.0f;
//cubeLocX = 0.0f; cubeLocY = -2.0f; cubeLocZ = 0.0f; // shift the cube down Y to show 3d perspective

// load all verts and positions into gpu memory
	setupVertices();

	glfwGetFramebufferSize(window, &width, &height);
	aspect = (float)width / (float)height;
	pMat = glm::perspective(glm::radians(user.fov), aspect, 0.1f, 100.0f);  // 1.0472 radians = 60 degrees 
}

void mouse_position_callback(GLFWwindow* window, double xPos, double yPos) {
	user.mouse_position_callback(window, xPos, yPos);
}

void window_reshape_callback(GLFWwindow* window, int newWidth, int newHeight) {
	aspect = (float)newWidth / (float)newHeight;
	glViewport(0, 0, newWidth, newHeight);
	pMat = glm::perspective(glm::radians(user.fov), aspect, 0.1f, 100.0f);  // 1.0472 radians = 60 degrees 
}
Sect* test = new Sect();
void display(GLFWwindow* window, double currentTime) { 
	Utils::GlClearReset();
	glUseProgram(renderingProgram);

// get the uniform variables for the MV and projection matrices
	mvLoc = glGetUniformLocation(renderingProgram, "mv_matrix");
	projLoc = glGetUniformLocation(renderingProgram, "proj_matrix"); 
	
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(pMat));

// build perspective matrix
	float currentFrame = glfwGetTime();
	user.deltaTime = currentFrame - user.lastFrame;
	user.lastFrame = currentFrame;

// keyboard input
	user.processInput(window);

// creates the view matrix

	vMat = glm::lookAt(user.getCameraPos(), user.getCameraPosAndFront(), user.getCameraUp());
	
	//solarSys(vMat, currentTime);
	test->drawContents(vMat, currentTime, mvLoc, projLoc, vbo);
	
}

int main(void) { 
	if (!glfwInit()) { 
		exit(EXIT_FAILURE); 
	} 
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4); 
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); 
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
	GLFWwindow* window = glfwCreateWindow(800, 600, "Chapter2 - program1", NULL, NULL); 
	glfwMakeContextCurrent(window); 
	if (glewInit() != GLEW_OK) { exit(EXIT_FAILURE); } 
	glfwSwapInterval(0);
	
	glfwSetWindowSizeCallback(window, window_reshape_callback); // window resize callback
	glfwSetCursorPosCallback(window, mouse_position_callback);

	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	init(window);
	
	while (!glfwWindowShouldClose(window)) { 
		display(window, glfwGetTime()); 
		glfwSwapBuffers(window); 
		glfwPollEvents(); 
	} 

	glfwDestroyWindow(window); 
	glfwTerminate(); 
	std::cout << "Exit code: " << EXIT_SUCCESS << " | Success!\n\n";
	exit(EXIT_SUCCESS); 
}
