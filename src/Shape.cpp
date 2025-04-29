#include "Shape.h"
#include "Point.h"
#include <GL/freeglut.h>
#include <iostream>
#include <vector>

Shape::Shape() {
    x = 0.0;
    y = 0.0;
    r = 0.0;
    g = 0.0;
    b = 0.0;
    size = 7;
}

Shape::Shape(float x, float y) : Shape() {
    this->x = x;
    this->y = y;
}

Shape::Shape(float x, float y, float r, float g, float b) : Shape(x, y) {
    this->r = r;
    this->g = g;
    this->b = b;
}

Shape::Shape(float x, float y, float r, float g, float b, float size) : Shape(x, y, r, g, b) {
    this->size = size;
}

void Shape::draw() {
    if (points.size()>0){
        for(long unsigned int i =0; i<points.size();i++){
            points[i]->setColor(r,g,b);
            points[i]->draw();
        }
    }
}

void Shape::addPoint(float x, float y, float r, float g, float b, float size){
    points.push_back(new Point(x, y, r, g, b, size));
}

float Shape::getX() const {
    return x;
}

float Shape::getY() const {
    return y;
}

float Shape::getR() const {
    return r;
}

float Shape::getG() const {
    return g;
}

float Shape::getB() const {
    return b;
}

float Shape::getSize() {
    return size;
}

void Shape::setScale(float w, float h){

}

void Shape::move(float x, float y){
    float oX = this->x;
    float oY = this->y;
    this->x = x;
    this->y = y;
    for(long unsigned int i = 0; i<points.size();i++){
        points[i]->move(x-oX, y-oY);
    }
}

bool Shape::checkSelected(float x, float y){
    return false;
}

void Shape::changeColor(float R, float G, float B){
    r=R;
    g=G;
    b=B;
}

void Shape::resize(int s){
    if (size + (s/10.0)>0){
        size = size+(s/10.0);
    }
}

std::vector<Point*> Shape::getPoints() const {
    return points;
}

void Shape::setSize(float newSize){
    size=newSize;
}
