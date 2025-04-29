#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <bobcat_ui/all.h>
#include <bobcat_ui/image.h>
#include <bobcat_ui/int_input.h>
#include "Enums.h"

class Toolbar : public bobcat::Group {
    bobcat::Image* pencilButton;
    bobcat::Image* eraserButton;
    bobcat::Image* circleButton;
    bobcat::Image* triangleButton;
    bobcat::Image* rectangleButton;
    bobcat::Image* polygonButton;
    bobcat::Image* clearButton;
    bobcat::Image* selectButton;
    bobcat::Image* undoButton;

    bobcat::IntInput* sizeVal;
    bobcat::IntInput* widthVal;
    bobcat::IntInput* heightVal;

    bobcat::Image* plusButton;
    bobcat::Image* minusButton;
    bobcat::Image* bringToFront;
    bobcat::Image* sendToBack;
    bobcat::Button* changeColor;

    int size;
    int width;
    int height;

    TOOL tool;
    ACTION action;
    void deselectAllTools();
    void visualizeSelectedTool();
    void onClick(bobcat::Widget* sender);
    void onThingChange(bobcat::Widget* sender);

public:
    Toolbar(int x, int y, int w, int h);

    int getSize() const;
    int getWidth() const;
    int getHeight() const;
    TOOL getTool() const;
    ACTION getAction() const;

    friend struct AppTest;
};

#endif