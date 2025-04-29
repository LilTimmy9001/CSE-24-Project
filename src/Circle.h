#ifndef CIRCLE_H
#define CIRCLE_H
#include <vector>

#include "Point.h"
#include "Shape.h"

class Circle : public Shape {

public:
    bool wasErase;
    Circle();
    Circle(float x, float y);
    Circle(float x, float y, float r, float g, float b);
    Circle(float x, float y, float r, float g, float b, float size);
    void draw() override;
    bool checkSelected(float x, float y) override;
    float getSize() override;
    void resize(int s) override;
};

#endif