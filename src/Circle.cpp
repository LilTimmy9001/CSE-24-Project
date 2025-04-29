#include "Shape.h"
#include "Circle.h"
#include "Point.h"
#include <GL/freeglut.h>
#include <cmath>
#include <iostream>
#include <ostream>
#include <vector>
#include <GL/gl.h>

Circle::Circle() {
    x = 0.0;
    y = 0.0;
    r = 0.0;
    g = 0.0;
    b = 0.0;
    size = 0.1;
    wasErase=false;
}

Circle::Circle(float x, float y) : Shape() {
    this->x = x;
    this->y = y;
}

Circle::Circle(float x, float y, float r, float g, float b) : Shape(x, y) {
    this->r = r;
    this->g = g;
    this->b = b;
}

void Circle::resize(int s){
    if (size + (s/30.0)>0){
        size = size+(s/30.0);
    }
}

Circle::Circle(float x, float y, float r, float g, float b, float size) : Shape(x, y, r, g, b) {
    this->size = size;
}


void Circle::draw() {
    glColor3f(r, g, b);
    
    glBegin(GL_POLYGON);
        float inc = 2 * M_PI / 60;
        for (float theta = 0; theta <= 2 * M_PI; theta += inc) {
            glVertex2f(x + size * cos(theta), y + size * sin(theta));
        }
    glEnd();
}

float Circle::getSize(){
    return size*4.0;
}

bool Circle::checkSelected(float x, float y){
    float rs = sqrt(pow(this->x-x, 2) + pow(this->y-y, 2));
    if (rs<=(size)){
        return true;
    }
    return false;
}

