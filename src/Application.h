#ifndef APPLICATION_H
#define APPLICATION_H

#include "Canvas.h"
#include "Help.h"
#include "Toolbar.h"
#include "ColorSelector.h"
#include <bobcat_ui/all.h>

class Application : public bobcat::Application_ {
    bobcat::Window* window;
    Toolbar* toolbar;
    Canvas* canvas;
    Help* help;
    ColorSelector* colorSelector;

    void onCanvasMouseDown(bobcat::Widget* sender, float mx, float my);
    void onCanvasDrag(bobcat::Widget* sender, float mx, float my);
    void onCanvasRelease(bobcat::Widget* sender, float mx, float my);
    void onToolbarChange(bobcat::Widget* sender);
    

    float distanceCalc(float x, float y);

public:
    Application();

    friend struct::AppTest;
};


#endif