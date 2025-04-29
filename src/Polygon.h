#ifndef Polygon_H
#define Polygon_H
#include <vector>

#include "Point.h"
#include "Shape.h"

class Polygon : public Shape {
    float sides;
    float length;

public:
    bool wasErase;
    Polygon();
    Polygon(float x, float y);
    Polygon(float x, float y, float r, float g, float b);
    Polygon(float x, float y, float r, float g, float b, float size);
    void draw() override;
    void setScale(float w, float h) override;
    bool checkSelected(float x, float y) override;
    float getSize() override;
};

#endif