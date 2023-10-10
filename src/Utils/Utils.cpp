#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <string>
#include "Utils.h"

using namespace std;

// Reading shader source files into memory

string Utils::readShaderSource(string filePath, int lineLength) {
	string content;
	ifstream fileStream(filePath, ios::in);
	string line = "";
	while(getline(fileStream, line)) {
		content.append(line + "\n");
	}
	fileStream.close();
	return content;
}

// Basic error checks for shaders during compile

void Utils::printShaderLog(GLuint shader) {
	int len = 0;
	int chWrittn = 0;
	char* log;
	glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &len);
	if (len > 0) {
		log = (char*)malloc(len);
		glGetShaderInfoLog(shader, len, &chWrittn, log);
		cout << "Shader Info Log: " << log << endl; free(log);
	}
}
void Utils::printProgramLog(int prog) {
	int len = 0;
	int chWrittn = 0;
	char* log; glGetProgramiv(prog, GL_INFO_LOG_LENGTH, &len);
	if (len > 0) {
		log = (char*)malloc(len);
		glGetProgramInfoLog(prog, len, &chWrittn, log);
		cout << "Program Info Log: " << log << endl; free(log);
	}
}
bool Utils::checkOpenGLError() {
	bool foundError = false;
	int glErr = glGetError();
	while (glErr != GL_NO_ERROR) {
		cout << "glError: " << glErr << endl;
		foundError = true; glErr = glGetError();
	}
	return foundError;
}

GLuint Utils::createShaderProgram(string vertShader, string fragShader) {
	// Initialise error catch variables while compiling shaders

	GLint vertCompiled;
	GLint fragCompiled;
	GLint linked;

	// Reads in shader source code from glsl files

	string vertShaderStr = readShaderSource(vertShader, 73);
	string fragShaderStr = readShaderSource(fragShader, 13);

	const char* vertShaderSrc = vertShaderStr.c_str();
	const char* fragShaderSrc = fragShaderStr.c_str();

	// shader object initialisation

	GLuint vShader = glCreateShader(GL_VERTEX_SHADER);
	GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER);

	// Populate shader objects with shader code

	glShaderSource(vShader, 1, &vertShaderSrc, NULL);
	glShaderSource(fShader, 1, &fragShaderSrc, NULL);

	// comple shaders and check for errors

	glCompileShader(vShader);
	checkOpenGLError();
	glGetShaderiv(vShader, GL_COMPILE_STATUS, &vertCompiled);
	if (vertCompiled != 1) {
		cout << "vertex compilation failed. " << endl;
		printShaderLog(vShader);
	}
	glCompileShader(fShader);
	glGetShaderiv(fShader, GL_COMPILE_STATUS, &fragCompiled);
	if (fragCompiled != 1) {
	cout << "fragment compilation failed. " << endl;
		printShaderLog(fShader);
	}

	// initialise link shader object

	GLuint vfProgram = glCreateProgram();

	// populate shaders to link shader object

	glAttachShader(vfProgram, vShader);
	glAttachShader(vfProgram, fShader);
	glLinkProgram(vfProgram);

	// catch linking shader errors

	checkOpenGLError();
	glGetProgramiv(vfProgram, GL_LINK_STATUS, &linked);
	if (linked != 1) {
		cout << "Linking failed." << endl;
		printProgramLog(vfProgram);
	}
	return vfProgram;
}

// Initialises Vertex Arrays and buffers for supplying buffer data (shaders)

GLuint* Utils::setupGlBuffers(int numOfShapes) {
	GLuint vao[numVAOs];
	GLuint* vbo = new GLuint[numOfShapes];

	glGenVertexArrays(numVAOs, vao);
	glBindVertexArray(vao[0]);
	glGenBuffers(numVBOs, vbo);

	return vbo;
}

GLuint* Utils::populateGlBuffers(std::vector<Shape*> shapes) {
	GLuint* vbo = Utils::setupGlBuffers(shapes.size());

	for (int i=0; i<shapes.size();i++) {
		glBindBuffer(GL_ARRAY_BUFFER, vbo[i]);
		glBufferData(GL_ARRAY_BUFFER, shapes[i]->getNumVerts()*6, shapes[i]->getPositions().data(), GL_STATIC_DRAW);
	}
	return vbo;
}
void Utils::GlClearReset() {
	glClear(GL_DEPTH_BUFFER_BIT);
	glClear(GL_COLOR_BUFFER_BIT);

//	Used for enabling and disabling face culling and prevent artifacts
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LEQUAL);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CW);
}
