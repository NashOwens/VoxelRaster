#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

class userInput
{
public:
	userInput() {};
	~userInput() {};

	void mouse_position_callback(GLFWwindow* window, double xPos, double yPos);
	void processInput(GLFWwindow* window);

	glm::vec3 getCameraPos() { return cameraPos;  }
	glm::vec3 getCameraUp() { return cameraUp; }
	glm::vec3 getCameraPosAndFront() { return cameraPos + cameraFront; }

// timing between frames
	float deltaTime = 0.0f;
	float lastFrame = 0.0f;
	float fov = 90.0f;
private:
	// initial camera position.
	glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 20.0f);
	glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
	float yaw = -90.0f;
	float pitch = 0.0f;
	
	// mouse state
	bool firstMouse = true;
	float lastX = 800.0f / 2.0;
	float lastY = 600.0 / 2.0;

};

