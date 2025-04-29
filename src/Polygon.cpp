#include "Shape.h"
#include "Polygon.h"
#include "Point.h"
#include <GL/freeglut.h>
#include <cmath>
#include <iostream>
#include <ostream>
#include <vector>
#include <GL/gl.h>

Polygon::Polygon() {
    x = 0.0;
    y = 0.0;
    r = 0.0;
    g = 0.0;
    b = 0.0;
    size = 0.1;
    sides = 5;
    length = 0.1;
    wasErase=false;
}

Polygon::Polygon(float x, float y) : Shape() {
    this->x = x;
    this->y = y;
}

Polygon::Polygon(float x, float y, float r, float g, float b) : Shape(x, y) {
    this->r = r;
    this->g = g;
    this->b = b;
}

Polygon::Polygon(float x, float y, float r, float g, float b, float size) : Shape(x, y, r, g, b) {
    this->size = size;
}

void Polygon::setScale(float w, float h)
{
    sides=w;
    length=h;
}

void Polygon::draw() {
    glColor3f(r, g, b);
    
    float slength=length*size;

    glBegin(GL_POLYGON);
        float inc = 2 * M_PI / sides;
        for (float theta = 0; theta <= 2 * M_PI; theta += inc) {
            glVertex2f(x + slength * cos(theta), y + slength * sin(theta));
        }
    glEnd();
}

bool Polygon::checkSelected(float x, float y){
    float rs = sqrt(pow(this->x-x, 2) + pow(this->y-y, 2));
    if (rs<=(size/10.0)){
        return true;
    }
    return false;
}

float Polygon::getSize(){
    return size*0.3;
}

