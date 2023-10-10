#pragma once
#include <string>
#include <vector>
#include "../Shapes/Shape.h"

using namespace std;

#define numVAOs 1
#define numVBOs 2

class Utils
{
public:
	static string readShaderSource(string filePath, int fileLength);
	static void printShaderLog(GLuint shader);
	static void printProgramLog(int prog);
	static bool checkOpenGLError();
	static GLuint createShaderProgram(string vertShader, string fragShader);
	
	// For setupVertices for loading shaders into buffers
	
	static GLuint* setupGlBuffers(int numOfShapes);
	static GLuint* populateGlBuffers(std::vector<Shape*> shapes);

	// Setup function for the display render loop
	static void GlClearReset();

};