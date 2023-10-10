#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

class Obj
{
public:
	Obj(float x, float y, float z);
	~Obj();
	
	inline glm::mat4 getMMat() { return mMat; };
	inline float getX() { return x; };
	inline float getY() { return y; };
	inline float getZ() { return z; };

	glm::mat4 Trans(float x, float y, float z);
	glm::mat4 Rot(float currentTime, float x, float y, float z);
	glm::mat4 Scale(float x, float y, float z);

protected:
	inline void setX(float x) { this->x = x; }
	inline void setY(float y) { this->y = y; }
	inline void setZ(float z) { this->z = z; }
	inline void setMMat(glm::mat4 mMat) { this->mMat = mMat; }

private:
	glm::mat4 mMat;
	float x;
	float y;
	float z;
};

