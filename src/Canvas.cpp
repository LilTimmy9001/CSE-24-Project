#include "Canvas.h"
#include "Point.h"
#include <GL/freeglut.h>
#include <iterator>

Canvas::Canvas(int x, int y, int w, int h) : Canvas_(x, y, w, h) {
    sBox=false;
}

void Canvas::addShape(Shape* shape) {
    shapes.push_back(shape);
}

void Canvas::render() {
    for (long unsigned int i = 0 ; i < shapes.size(); i++) {
        shapes[i]->draw();
    }
    if (sBox==true){
        if (selectedShape->getPoints().size()==0){
            glLineWidth(2);
            glColor3f(0,0,0);
            float sc = selectedShape->getSize()*0.3f;
            glBegin(GL_LINES);
                glVertex2f(selectedShape->getX()-sc, selectedShape->getY()-sc);
                glVertex2f(selectedShape->getX()+sc, selectedShape->getY()-sc);

                glVertex2f(selectedShape->getX()+sc, selectedShape->getY()-sc);
                glVertex2f(selectedShape->getX()+sc, selectedShape->getY()+sc);

                glVertex2f(selectedShape->getX()+sc, selectedShape->getY()+sc);
                glVertex2f(selectedShape->getX()-sc, selectedShape->getY()+sc);

                glVertex2f(selectedShape->getX()-sc, selectedShape->getY()+sc);
                glVertex2f(selectedShape->getX()-sc, selectedShape->getY()-sc);
            glEnd();
        } else{
            glColor3f(0,0,0);
            float maxX=-1;
            float maxY=-1;
            float minX=1;
            float minY=1;
            float centerX=0;
            float centerY=0;
            for(long unsigned int i=0; i<selectedShape->getPoints().size(); i++){
                Point* p = selectedShape->getPoints()[i];
                centerX += p->getX();
                centerY += p->getY();
                if (p->getX()>maxX){
                    maxX=p->getX();
                }
                if (p->getX()<minX){
                    minX=p->getX();
                }
                if (p->getY()>maxY){
                    maxY=p->getY();
                }
                if (p->getY()<minY){
                    minY=p->getY();
                }
            }
            centerX=centerX/(selectedShape->getPoints().size());
            centerY=centerY/(selectedShape->getPoints().size());
            float xScale= maxX-minX;
            xScale=xScale*0.5;
            float yScale = maxY-minY;
            yScale=yScale*0.5;
            glBegin(GL_LINES);
                glVertex2f(centerX-xScale, centerY-yScale);
                glVertex2f(centerX+xScale, centerY-yScale);

                glVertex2f(centerX+xScale, centerY-yScale);
                glVertex2f(centerX+xScale, centerY+yScale);

                glVertex2f(centerX+xScale, centerY+yScale);
                glVertex2f(centerX-xScale, centerY+yScale);

                glVertex2f(centerX-xScale, centerY+yScale);
                glVertex2f(centerX-xScale, centerY-yScale);
            glEnd();

        }
    }
}

void Canvas::selectionBox(Shape* selectedShape, bool set){
    sBox=set;
    this->selectedShape=selectedShape;
}

void Canvas::empty(){
    sBox=false;
    shapes.clear();
}

Shape* Canvas::checkSelection(float x, float y){
    if (shapes.size()>0){
        for (int i=shapes.size()-1; i>=0; i--){
            if(shapes[i]->checkSelected(x, y)==true){
                return shapes[i];
            }
        }
    }
    return nullptr;
}

void Canvas::bringToFront(Shape *shape){
    if (shapes.size()>0){
        for(long unsigned int i = 0; i<shapes.size(); i++){
            if (shapes[i]==shape){
                shapes.erase(shapes.cbegin()+i);
                i = shapes.size();
            }
        }
    }
    shapes.push_back(shape);
}

void Canvas::sendToBack(Shape *shape){
    if (shapes.size()>0){
        for(long unsigned int i =0; i<shapes.size(); i++){
            if (shapes[i]==shape){
                shapes.erase(shapes.cbegin()+i);
                i = shapes.size();
            }
        }
    }
    shapes.insert(shapes.begin(),shape);
}

void Canvas::undo(){
    if (shapes.size()>0){
        shapes.pop_back();
    }
}



int Canvas::shapeNum() const{
    return shapes.size();
}