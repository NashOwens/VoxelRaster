#pragma once
#include <glm/fwd.hpp>
#include<vector>

class testUtils
{
public:
	static double* getMat4Values(glm::mat4);
	static int getVertArrayLen(std::vector<float> verts);
	static float* convertVecFloattoFloat(std::vector<float> arr);
};