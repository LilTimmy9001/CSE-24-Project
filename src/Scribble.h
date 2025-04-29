#ifndef SCRIBBLE_H
#define SCRIBBLE_H
#include <vector>

#include "Point.h"
#include "Shape.h"

class Scribble : public Shape {

public:
    bool wasErase;
    Scribble();
    Scribble(float x, float y);
    Scribble(float x, float y, float r, float g, float b);
    Scribble(float x, float y, float r, float g, float b, float size);
    Scribble(float x, float y, float r, float g, float b, float size, bool wasErase);
    bool checkSelected(float x, float y) override;
    void draw() override;
    void resize(int s) override;
};

#endif