#include "Shape.h"
#include "Triangle.h"
#include "Point.h"
#include <GL/freeglut.h>
#include <cmath>
#include <iostream>
#include <ostream>
#include <vector>
#include <GL/gl.h>

Triangle::Triangle() {
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

Triangle::Triangle(float x, float y) : Shape() {
    this->x = x;
    this->y = y;
}

void Triangle::resize(int s){
    if ((width+(s*0.1))+(height+(s*0.1)>0))
    {
        width = width+(s*0.1);
        height=height+(s*0.1);
        size = (width+height);
    }
}

Triangle::Triangle(float x, float y, float r, float g, float b) : Shape(x, y) {
    this->r = r;
    this->g = g;
    this->b = b;
}

Triangle::Triangle(float x, float y, float r, float g, float b, float size) : Shape(x, y, r, g, b) {
    this->size = (width+height)/1.5;
}

void Triangle::setScale(float w, float h)
{
    width=w;
    height=h;
    size = (width+height);
}

void Triangle::draw() {
    glColor3f(r, g, b);
    
    glBegin(GL_POLYGON);
        glVertex2f(x - width/2, y - height/2);
        glVertex2f(x, y + height/2);
        glVertex2f(x + width/2, y - height/2);
    glEnd();
}

bool Triangle::checkSelected(float X, float Y){
    if (X > x - width/2 && X < x + width/2){
        if (Y > y - height/2 && Y < y + height/2){
            return true;
        }
    }
    return false;
}

