#include "Point.h"
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <iostream>

Point::Point() {
    x = 0.0;
    y = 0.0;
    size = 7;
}

Point::Point(float x, float y) : Point() {
    this->x = x;
    this->y = y;
}

Point::Point(float x, float y, float r, float g, float b) : Point(x, y) {
    this->r = r;
    this->g = g;
    this->b = b;
}

Point::Point(float x, float y, float r, float g, float b, int size) : Point(x, y, r, g, b) {
    this->size = size;
}

void Point::setColor(float r, float g, float b){
    this->r=r;
    this->b=b;
    this->g=g;
}

void Point::move(float x, float y){
    this->x+=x;
    this->y+=y;
}

void Point::multPos(float X, float Y){
    x=x*X;
    y=y*Y;
}


void Point::draw() {
    glPointSize(size);
    glColor3f(r, g, b);

    glBegin(GL_POINTS);
        glVertex2f(x, y);
    glEnd();
}

void Point::drawLine(Point *prevPoint){
    glLineWidth(size);
    glColor3f(r, g, b);

    glBegin(GL_LINE);
        glVertex2f(x, y);
        glVertex2f(prevPoint->getX(), prevPoint->getY());
    glEnd();
}


float Point::getX() const {
    return x;
}

float Point::getY() const {
    return y;
}

float Point::getR() const {
    return r;
}

float Point::getG() const {
    return g;
}

float Point::getB() const {
    return b;
}

float Point::getSize() const {
    return size;
}