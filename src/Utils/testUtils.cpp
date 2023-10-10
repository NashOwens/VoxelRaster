#include "testUtils.h"
#include <glm/gtc/type_ptr.hpp>

// Utilities for Unit tests

double* testUtils::getMat4Values(glm::mat4 mat) {
	double matArray[16] = { 0.0 };
	const float* pSource = (const float*)glm::value_ptr(mat);
	for (int i = 0; i < 16; ++i)
		matArray[i] = pSource[i];
	return matArray;
}
int testUtils::getVertArrayLen(std::vector<float> verts) {
	int count = 0;
	for (float i : verts) {
		count += 1;
	}
	return count;
}
float* testUtils::convertVecFloattoFloat(std::vector<float> arr) {
	return &arr[0];
}