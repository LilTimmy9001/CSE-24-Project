#ifndef POINT_H
#define POINT_H

class Point {
    float x;
    float y;
    float r;
    float g;
    float b;
    int size;

public:
    Point();
    Point(float x, float y);
    Point(float x, float y, float r, float g, float b);
    Point(float x, float y, float r, float g, float b, int size);

    void setColor(float r, float g, float b);

    void draw();
    void drawLine(Point *prevPoint);

    float getX() const;
    float getY() const;
    void move(float x, float y);
    void multPos(float x, float y);

    float getR() const;
    float getG() const;
    float getB() const;
    
    float getSize() const;

    friend struct AppTest;
};

#endif