#include "Rectangle.h"
#include "Shape.h"
#include "Scribble.h"
#include "Point.h"
#include <GL/freeglut.h>
#include <iostream>
#include <math.h>
#include <ostream>
#include <vector>
#include <GL/gl.h>

Scribble::Scribble() {
    x = 0.0;
    y = 0.0;
    r = 0.0;
    g = 0.0;
    b = 0.0;
    size = 7;
    wasErase=false;
}

Scribble::Scribble(float x, float y) : Shape() {
    this->x = x;
    this->y = y;
}

Scribble::Scribble(float x, float y, float r, float g, float b) : Shape(x, y) {
    this->r = r;
    this->g = g;
    this->b = b;
}

Scribble::Scribble(float x, float y, float r, float g, float b, float size) : Shape(x, y, r, g, b) {
    this->size = size;
}

Scribble::Scribble(float x, float y, float r, float g, float b, float size, bool wasErase) : Shape(x, y, r, g, b) {
    this->size = size;
    wasErase=wasErase;
}

void Scribble::draw() {
    if (points.size()>1){

        glLineWidth(size);
        glColor3f(r, g, b);
        glBegin(GL_LINES);
        for(long unsigned int i = 0; i<points.size()-1;i++){
            points[i]->setColor(r,g,b);
            glVertex2f(points[i]->getX(), points[i]->getY());
            glVertex2f(points[i+1]->getX(), points[i+1]->getY());
            //points[i]->drawLine(points[i-1]);
        }
        glEnd();
        points[points.size()-1]->setColor(r,g,b);
        points[points.size()-1]->draw();
    } else {
        points[0]->setColor(r,g,b);
        points[0]->draw();
    }
}

void Scribble::resize(int s){
    if (size + s>0){
        float ssz = size+s;
        for(long unsigned int i = 0; i<points.size();i++){
            points[i]->multPos((ssz/size), (ssz/size));
        }
        size = ssz;
    }
}



bool Scribble::checkSelected(float x, float y){
    for(long unsigned int i = 0; i<points.size();i++){
        float rs = sqrt(pow(points[i]->getX()-x, 2) + pow(points[i]->getY()-y, 2));
        if (rs<=(size/110.0)){
            return true;
        }
    }
    return false;
}


