#ifndef SHAPE_H
#define SHAPE_H
#include <vector>

#include "Point.h"

class Shape {
    protected:
        float x;
        float y;
        float r;
        float g;
        float b;
        float size;
        std::vector<Point*> points;

public:
    Shape();
    Shape(float x, float y);
    Shape(float x, float y, float r, float g, float b);
    Shape(float x, float y, float r, float g, float b, float size);

    void setSize(float newSize);
    virtual void draw();

    void move(float x, float y);

    virtual void setScale(float w, float h);
    virtual void resize(int s);
    virtual bool checkSelected(float x, float y);

    void changeColor(float r, float g, float b);
    

    float getX() const;
    float getY() const;
    float getR() const;
    float getG() const;
    float getB() const;
    virtual float getSize();
    std::vector<Point*> getPoints() const;
    void addPoint(float x, float y, float r, float g, float b, float size);
};

#endif