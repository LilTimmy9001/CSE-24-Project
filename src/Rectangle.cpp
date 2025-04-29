#include "Shape.h"
#include "Rectangle.h"
#include "Point.h"
#include <GL/freeglut.h>
#include <cmath>
#include <iostream>
#include <ostream>
#include <vector>
#include <GL/gl.h>

Rectangle::Rectangle() {
    x = 0.0;
    y = 0.0;
    r = 0.0;
    g = 0.0;
    b = 0.0;
    size = 0.1;
    width=1;
    height=1;
    wasErase=false;
}

Rectangle::Rectangle(float x, float y) : Shape() {
    this->x = x;
    this->y = y;
}

Rectangle::Rectangle(float x, float y, float r, float g, float b) : Shape(x, y) {
    this->r = r;
    this->g = g;
    this->b = b;
}

Rectangle::Rectangle(float x, float y, float r, float g, float b, float size) : Shape(x, y, r, g, b) {
    this->size = (width+height)/1.5;
}

void Rectangle::setScale(float w, float h)
{
    width=w;
    height=h;
    size = (width+height);
}

void Rectangle::resize(int s){
    if ((width+(s*0.1))+(height+(s*0.1)>0))
    {
        width = width+(s*0.1);
        height=height+(s*0.1);
        size = (width+height);
    }
}

void Rectangle::draw() {
    glColor3f(r, g, b);
    
    glBegin(GL_POLYGON);
        glVertex2f(x - width/2, y + height/2);
        glVertex2f(x + width/2, y + height/2);
        glVertex2f(x + width/2, y - height/2);
        glVertex2f(x - width/2, y - height/2);
    glEnd();
}

bool Rectangle::checkSelected(float X, float Y){
    if (X > x - width/2 && X < x + width/2){
        if (Y > y - height/2 && Y < y + height/2){
            return true;
        }
    }
    return false;
}
