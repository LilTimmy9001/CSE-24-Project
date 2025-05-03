#include "Application.h"
#include "Canvas.h"
#include "Circle.h"
#include "Enums.h"
#include "Help.h"
#include "Polygon.h"
#include "Rectangle.h"
#include "Scribble.h"
#include "Shape.h"
#include "Triangle.h"
#include <FL/Enumerations.H>
#include <bobcat_ui/bobcat_ui.h>
#include <cstddef>
#include <cmath>
#include <ostream>

using namespace bobcat;
using namespace std;

bool dragging;
float mX;
float mY;
Shape* curShape;
Shape* selectedShape;

void Application::onCanvasMouseDown(bobcat::Widget* sender, float mx, float my) {
    TOOL tool = toolbar->getTool();
    Color color = colorSelector->getColor();

    if (tool == PENCIL) {
            dragging=true;
            curShape = new Scribble(mx, my, color.getR(), color.getG(), color.getB(), toolbar->getSize());
            canvas->addShape(curShape);
            curShape->addPoint(mx, my, color.getR(), color.getG(), color.getB(), toolbar->getSize());
    }

    if (tool == ERASER){
            dragging=true;
            Shape* dShape =canvas->checkSelection(mx, my);
            if (dShape!=nullptr){
                canvas->deleteS(dShape);
            }
    }

    if (tool == CIRCLE){
            dragging=true;
            mX=mx;
            mY=my;
            curShape = new Circle(mx, my, color.getR(), color.getG(), color.getB(), 0.01);
            canvas->addShape(curShape);
            curShape->setSize(toolbar->getSize()/60.0);
    }
    if (tool == RECTANGLE){
            dragging=true;
            mX=mx;
            mY=my;
            curShape = new Rectangle(mx, my, color.getR(), color.getG(), color.getB(), 1);
            curShape->setScale(toolbar->getWidth()/100.0, toolbar->getHeight()/100.0);
            curShape->setSize(toolbar->getWidth()/toolbar->getHeight());
            canvas->addShape(curShape);
    }
    if (tool == TRIANGLE){
            dragging=true;
            mX=mx;
            mY=my;
            curShape = new Triangle(mx, my, color.getR(), color.getG(), color.getB(), 1);
            curShape->setScale(toolbar->getWidth()/100.0, toolbar->getHeight()/100.0);
            curShape->setSize(toolbar->getWidth()/toolbar->getHeight());
            canvas->addShape(curShape);
    }
    if (tool == POLYGON){
            dragging=true;
            mX=mx;
            mY=my;
            curShape = new Polygon(mx, my, color.getR(), color.getG(), color.getB(), 1);
            curShape->setScale(toolbar->getWidth(), toolbar->getHeight()/100.0);
            curShape->setSize(1);
            canvas->addShape(curShape);
    }
    if (tool == SELECT){
        selectedShape=canvas->checkSelection(mx, my);
        if (selectedShape!=nullptr){
            mX = selectedShape->getX()-mx;
            mY = selectedShape->getY()-my;
            //cout<<selectedShape<<endl;
            canvas->selectionBox(selectedShape, true);
        } else {
            selectedShape=nullptr;
           canvas->selectionBox(nullptr, false);
        }
    } else{
        selectedShape=nullptr;
        canvas->selectionBox(nullptr, false);
    }
    canvas->redraw();
}


void Application::onCanvasDrag(bobcat::Widget* sender, float mx, float my) {
    if (dragging==false){
        curShape = new Shape;
        mX=mx;
        mY=my;
    }
    dragging=true;
    TOOL tool = toolbar->getTool();
    Color color = colorSelector->getColor();

    if (tool == PENCIL) {
        if (curShape==nullptr){
            curShape = new Scribble(mx, my, color.getR(), color.getG(), color.getB(), toolbar->getSize());
            canvas->addShape(curShape);
        }
        curShape->addPoint(mx, my, color.getR(), color.getG(), color.getB(), toolbar->getSize());
    }

    else if (tool == ERASER) {
            dragging=true;
            Shape* dShape =canvas->checkSelection(mx, my);
            if (dShape!=nullptr){
                canvas->deleteS(dShape);
            }
    }

    if (tool == CIRCLE){
        if (curShape==nullptr){
            mX=mx;
            mY=my;
            curShape = new Circle(mx, my, color.getR(), color.getG(), color.getB(), 0.01);
            canvas->addShape(curShape);
        }
        curShape->setSize(distanceCalc(mx, my)+0.001);
        //cout << distanceCalc(mx, my) << endl;
    }

    if (tool == RECTANGLE){
        if (curShape==nullptr){
            dragging=true;
            mX=mx;
            mY=my;
            curShape = new Rectangle(mx, my, color.getR(), color.getG(), color.getB(), 1);
            canvas->addShape(curShape);
        }
        float w= sqrt(pow(mX-mx, 2))*2;
        float h= sqrt(pow(mY-my, 2))*2;
        curShape->setSize(toolbar->getWidth()/toolbar->getHeight());
        curShape->setScale(w, h);
    }
        
    if (tool == TRIANGLE){
        if (curShape==nullptr){
            dragging=true;
            mX=mx;
            mY=my;
            curShape = new Triangle(mx, my, color.getR(), color.getG(), color.getB(), 1);
            canvas->addShape(curShape);
        }
        float w= sqrt(pow(mX-mx, 2))*2;
        float h= sqrt(pow(mY-my, 2))*2;
        curShape->setSize(toolbar->getWidth()/toolbar->getHeight());
        curShape->setScale(w, h);
    }

    if (tool == POLYGON){
        if (curShape==nullptr){
            mX=mx;
            mY=my;
            curShape = new Polygon(mx, my, color.getR(), color.getG(), color.getB(), 1);
            canvas->addShape(curShape);
        }
        curShape->setScale(toolbar->getWidth(), toolbar->getHeight()/100.0);
        curShape->setSize(distanceCalc(mx, my)*3.0 + 0.1);
        //cout << distanceCalc(mx, my) << endl;
    }

    if (tool == SELECT){
        if (selectedShape==nullptr){
            selectedShape=canvas->checkSelection(mx, my);
            if (selectedShape!=nullptr){
                mX = selectedShape->getX()-mx;
                mY = selectedShape->getY()-my;
            }
        } 
        if (selectedShape!=nullptr){
            selectedShape->move(mx+mX, my+mY);
            canvas->selectionBox(selectedShape, true);
        }
    } else{
        selectedShape=nullptr;
        canvas->selectionBox(nullptr, false);
    }
    
    canvas->redraw();
    canvas->shapeNum();
}

float Application::distanceCalc(float x, float y){
    float rs = sqrt(pow(mX-x, 2) + pow(mY-y, 2));
    if (rs<0.000001){
        rs=0.000001;
    }
    return rs;
}

void Application::onCanvasRelease(bobcat::Widget* sender, float mx, float my) {
    TOOL tool = toolbar->getTool();

    if (tool == PENCIL || tool == ERASER) {
        curShape=nullptr;
    } if (tool == CIRCLE){
        curShape=nullptr;
    } if (tool == RECTANGLE){
        curShape=nullptr;
    } if (tool == TRIANGLE){
        curShape=nullptr;
    } if (tool == POLYGON){
        curShape=nullptr;
    }
    canvas->redraw();
    //cout<<canvas->shapeNum()<<endl;
}

void Application::onToolbarChange(bobcat::Widget* sender) {
    Color color = colorSelector->getColor();
    if (toolbar->getAction() == CLEAR) {
        canvas->clear();
        canvas->empty();
        selectedShape=nullptr;
        canvas->selectionBox(nullptr, false);
    }
    if (toolbar->getAction() == UNDO) {
        if (selectedShape==nullptr){
            canvas->undo();
            selectedShape=nullptr;
            canvas->selectionBox(nullptr, false);
        } else{
            canvas->deleteS(selectedShape);
            selectedShape=nullptr;
            canvas->selectionBox(nullptr, false);
        }
    }
    if (toolbar->getAction() == PLUS){
        if (selectedShape!=nullptr){
            selectedShape->resize(1);
        }
    }
    if (toolbar->getAction() == MINUS){
        if (selectedShape!=nullptr){
            selectedShape->resize(-1);
        }
    }
    if (toolbar->getAction() == FRONT){
        if (selectedShape!=nullptr){
            canvas->bringToFront(selectedShape);
        }
    }
    if (toolbar->getAction() == BACK){
        if (selectedShape!=nullptr){
            canvas->sendToBack(selectedShape);
        }
    }
    if (toolbar->getAction() == CCHANGE){
        //cout << "WEE" << endl;
        if (selectedShape!=nullptr){
            selectedShape->changeColor(color.getR(), color.getG(), color.getB());
        }
    }
    canvas->redraw();
}

Application::Application() {
    dragging = false;
    mX=0;
    mY=0;
    curShape=nullptr;
    window = new Window(100, 100, 900, 600, "Paint Application");
    canvas = new Canvas(50, 0, 550, 550);
    help = new Help(600, 0, 300, 600);
    toolbar = new Toolbar(0, 0, 50, 600);
    colorSelector = new ColorSelector(50, 550, 550, 50);

    window->add(toolbar);
    window->add(canvas);
    window->add(colorSelector);
    window->add(help);

    ON_DRAG(canvas, Application::onCanvasDrag);
    ON_MOUSE_DOWN(canvas, Application::onCanvasMouseDown);
    ON_MOUSE_UP(canvas, Application::onCanvasRelease);
    ON_CHANGE(toolbar, Application::onToolbarChange);

    window->show();
}