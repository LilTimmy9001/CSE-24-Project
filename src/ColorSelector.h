#ifndef COLOR_SELECTOR_H
#define COLOR_SELECTOR_H

#include <bobcat_ui/all.h>
#include <bobcat_ui/bobcat_ui.h>
#include <bobcat_ui/button.h>
#include <bobcat_ui/input.h>
#include "Color.h"
#include "Enums.h"

class ColorSelector : public bobcat::Group {
    bobcat::Button* colorDisplay;
    bobcat::IntInput* R;
    bobcat::IntInput* G;
    bobcat::IntInput* B;
    
    int rVal=255;
    int gVal=0;
    int bVal=0;

    COLOR color;
    void visualizeSelectedColor();
    void onChange(bobcat::Widget* sender);

    int clampVal(int num);

public:
    ColorSelector(int x, int y, int w, int h);

    Color getColor() const;

    friend struct AppTest;
};

#endif