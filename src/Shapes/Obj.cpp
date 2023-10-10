#include "Obj.h"

Obj::Obj(float x, float y, float z) : x(x), y(y), z(z) {
	this->mMat = glm::translate(glm::mat4(1.0f), glm::vec3(x, y, z));
};
Obj::~Obj() {};


glm::mat4 Obj::Trans(float x, float y, float z) {
	// changes world space position of the object
	glm::mat4 mMat = glm::translate(glm::mat4(1.0f), glm::vec3(x, y, z));
	return mMat;
}
glm::mat4 Obj::Rot(float currentTime, float x, float y, float z) {
	// coords passed in here are for rotation, not related to the position of the model
	glm::mat4 mrMat = glm::rotate(glm::mat4(1.0f), currentTime, glm::vec3(x, y, z));
	return mrMat;
}
glm::mat4 Obj::Scale(float x, float y, float z) {
	glm::mat4 msMat = glm::scale(glm::mat4(1.0f), glm::vec3(x, y, z));
	return msMat;
}
