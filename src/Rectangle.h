#ifndef Rectangle_H
#define Rectangle_H
#include <vector>

#include "Point.h"
#include "Shape.h"

class Rectangle : public Shape {
    float width;
    float height;

public:
    bool wasErase;
    Rectangle();
    Rectangle(float x, float y);
    Rectangle(float x, float y, float r, float g, float b);
    Rectangle(float x, float y, float r, float g, float b, float size);
    void draw() override;
    void setScale(float w, float h) override;
    bool checkSelected(float x, float y) override;
    void resize(int s) override;
};

#endif