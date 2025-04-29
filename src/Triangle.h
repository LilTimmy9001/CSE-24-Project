#ifndef Triangle_H
#define Triangle_H
#include <vector>

#include "Point.h"
#include "Shape.h"

class Triangle : public Shape {
    float width;
    float height;

public:
    bool wasErase;
    Triangle();
    Triangle(float x, float y);
    Triangle(float x, float y, float r, float g, float b);
    Triangle(float x, float y, float r, float g, float b, float size);
    void draw() override;
    void setScale(float w, float h) override;
    bool checkSelected(float x, float y) override;
    void resize(int s) override;
};

#endif