#ifndef CANVAS_H
#define CANVAS_H

#include <bobcat_ui/all.h>
#include <vector>

#include "Point.h"
#include "Shape.h"

class Canvas : public bobcat::Canvas_ {
    std::vector<Shape*> shapes;
    Shape* selectedShape;

public:
    Canvas(int x, int y, int w, int h);

    bool sBox;

    void empty();

    void selectionBox(Shape* shape, bool set);

    void bringToFront(Shape* shape);
    void sendToBack(Shape* shape);

    void addShape(Shape* shape);
    void checkErase(int x, int y, int size);
    void render();
    Shape* checkSelection(float x, float y);
    int shapeNum() const;
    void undo();
};

#endif