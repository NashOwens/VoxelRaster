#pragma once
#include "Obj.h"
class Shape : public Obj
{
public:
    Shape(int numVerts, std::vector<float> shapePositions, float x, float y, float z) : Obj(x, y, z) {
        this->numVerts = numVerts;
        this->shapePositions = shapePositions;
    };
    ~Shape() {};

    std::vector<float> getPositions();

    inline int getNumVerts() { return numVerts; }
private:
    int numVerts;
    std::vector<float> shapePositions;
};

