#include "ColorSelector.h"
#include "Color.h"
#include <FL/Enumerations.H>
#include <bobcat_ui/bobcat_ui.h>
#include <bobcat_ui/button.h>
#include <bobcat_ui/input.h>
#include <iostream>
using namespace bobcat;
using namespace std;



void ColorSelector::visualizeSelectedColor() {
    colorDisplay->color(fl_rgb_color(rVal, gVal, bVal));
}

void ColorSelector::onChange(bobcat::Widget* sender) {
    if (!R->empty()) {
        rVal = clampVal(R->value());
    }
    if (!G->empty()) {
        gVal = clampVal(G->value());
    }
    if (!B->empty()) {
        bVal = clampVal(B->value());
    }

    visualizeSelectedColor();
    redraw();
}

int ColorSelector::clampVal(int num){
    if (num>255){
        num=255;
    }
    if (num<0){
        num=0;
    }
    return num;
}

Color ColorSelector::getColor() const {
    return Color(rVal/255.0, gVal/255.0, bVal/255.0);
}

ColorSelector::ColorSelector(int x, int y, int w, int h) : Group(x, y, w, h) {
    
    R=new IntInput(x, y, 50, 50, "Red");
    G=new IntInput(x+50, y, 50, 50, "Green");
    B=new IntInput(x+100, y, 50, 50, "Blue");

    colorDisplay = new Button(x+150, y, w-150, 50, "");

    color = RED;

    rVal= 255;
    gVal= 0;
    bVal= 0;

    R->textcolor(FL_WHITE);
    G->textcolor(FL_WHITE);
    B->textcolor(FL_WHITE);
    R->textsize(18);
    G->textsize(18);
    B->textsize(18);


    R->value(rVal);
    G->value(gVal);
    B->value(bVal);


    R->color(fl_rgb_color(200, 0, 0));
    G->color(fl_rgb_color(0, 170, 0));
    B->color(fl_rgb_color(0, 0, 200));

    visualizeSelectedColor();

    ON_CHANGE(R, ColorSelector::onChange);
    ON_CHANGE(G, ColorSelector::onChange);
    ON_CHANGE(B, ColorSelector::onChange);
}