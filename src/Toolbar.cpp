#include "Toolbar.h"
#include "Enums.h"
#include <FL/Enumerations.H>
#include <bobcat_ui/bobcat_ui.h>
#include <bobcat_ui/int_input.h>
using namespace bobcat;

void Toolbar::deselectAllTools() {
    pencilButton->color(FL_BACKGROUND_COLOR);
    eraserButton->color(FL_BACKGROUND_COLOR);
    circleButton->color(FL_BACKGROUND_COLOR);
    triangleButton->color(FL_BACKGROUND_COLOR);
    rectangleButton->color(FL_BACKGROUND_COLOR);
    polygonButton->color(FL_BACKGROUND_COLOR);
    selectButton->color(FL_BACKGROUND_COLOR);
}

void Toolbar::visualizeSelectedTool() {
    if (tool == PENCIL) {
        pencilButton->color(FL_WHITE);
    }
    else if (tool == ERASER) {
        eraserButton->color(FL_WHITE);
    }
    else if (tool == CIRCLE) {
        circleButton->color(FL_WHITE);
    }
    else if (tool == TRIANGLE) {
        triangleButton->color(FL_WHITE);
    }
    else if (tool == RECTANGLE) {
        rectangleButton->color(FL_WHITE);
    }
    else if (tool == POLYGON) {
        polygonButton->color(FL_WHITE);
    } 
    else if (tool == SELECT) {
        selectButton->color(FL_WHITE);
    }
}

void Toolbar::onClick(bobcat::Widget* sender) {
    if (sender != plusButton && sender != minusButton && sender != bringToFront && sender != sendToBack && sender!=changeColor){
        deselectAllTools();
        tool = NOTOOL;
        plusButton->hide();
        minusButton->hide();
        bringToFront->hide();
        sendToBack->hide();
        changeColor->hide();
    }
    action = NONE;
    sizeVal->hide();
    widthVal->hide();
    heightVal->hide();
    widthVal->label("Width");
    heightVal->label("Height");

    
    if (sender == pencilButton) {
        tool = PENCIL;
        sizeVal->show();
    }
    else if (sender == eraserButton) {
        tool = ERASER;
        sizeVal->show();
    }
    else if (sender == circleButton) {
        tool = CIRCLE;
        sizeVal->show();
    }
    else if (sender == triangleButton) {
        tool = TRIANGLE;
        widthVal->show();
        heightVal->show();
    }
    else if (sender == rectangleButton) {
        tool = RECTANGLE;
        widthVal->show();
        heightVal->show();
    }
    else if (sender == polygonButton) {
        widthVal->show();
        heightVal->show();
        widthVal->label("Sides");
        heightVal->label("Length");
        tool = POLYGON;
    }
    if (sender == selectButton) {
        tool = SELECT;
        plusButton->show();
        minusButton->show();
        bringToFront->show();
        sendToBack->show();
        changeColor->show();
    }
    else if (sender == clearButton) {
        action = CLEAR;
    }
    else if (sender == undoButton) {
        action = UNDO;
    }
    else if (sender == plusButton) {
        action = PLUS;
    }
    else if (sender == minusButton) {
        action = MINUS;
    }
    else if (sender == bringToFront) {
        action = FRONT;
    }
    else if (sender == sendToBack) {
        action = BACK;
    }
    else if (sender == changeColor) {
        action = CCHANGE;
    }

    if (onChangeCb) {
        onChangeCb(this);
    }

    visualizeSelectedTool();
    redraw();
}

void Toolbar::onThingChange(bobcat::Widget* sender) {
    if (sender == sizeVal){
        if (!sizeVal->empty()){
            if (sizeVal->value()>0 && sizeVal->value()<1000 ){
                size = sizeVal->value();
            }
        }
    }
    if (sender == widthVal){
        if (!widthVal->empty()){
            if (widthVal->value()>0 && widthVal->value()<1000 ){
                width = widthVal->value();
            }
        }
    }
    if (sender == heightVal){
        if (!heightVal->empty()){
            if (heightVal->value()>0 && heightVal->value()<1000 ){
                height = heightVal->value();
            }
        }
    }
}

TOOL Toolbar::getTool() const {
    return tool;
}

int Toolbar::getSize() const{
    return size;
}

int Toolbar::getWidth() const{
    return width;
}

int Toolbar::getHeight() const{
    return height;
}

ACTION Toolbar::getAction() const {
    return action;
}

Toolbar::Toolbar(int x, int y, int w, int h) : Group(x, y, w, h) {
    pencilButton = new Image(x, y, 50, 50, "./assets/pencil.png");
    eraserButton = new Image(x, y + 50, 50, 50, "./assets/eraser.png");
    circleButton = new Image(x, y + 100, 50, 50, "./assets/circle.png");
    triangleButton = new Image(x, y + 150, 50, 50, "./assets/triangle.png");
    rectangleButton = new Image(x, y + 200, 50, 50, "./assets/rectangle.png");
    polygonButton = new Image(x, y + 250, 50, 50, "./assets/polygon.png");
    clearButton = new Image(x, y + 300, 50, 50, "./assets/clear.png");
    selectButton = new Image(x, y + 350, 50, 50, "./assets/mouse.png");
    undoButton = new Image(x, y + 400, 50, 50, "./assets/undo.png");

    sizeVal = new IntInput(x, y+500, 50, 50, "Size");
    widthVal = new IntInput(x, y+470, 50, 50, "Width");
    heightVal = new IntInput(x, y+540, 50, 50, "Height");

    plusButton = new Image(x, y + 450, 25, 50, "./assets/plus.png");
    minusButton = new Image(x+25, y + 450, 25, 50, "./assets/minus.png");
    bringToFront = new Image(x, y + 500, 25, 50, "./assets/bring-to-front.png");
    sendToBack = new Image(x+25, y + 500, 25, 50, "./assets/send-to-back.png");
    changeColor = new Button(x, y + 550, 50, 50, "Change \n Color");

    tool = PENCIL;
    action = NONE;
    size=7;
    width=7;
    height=7;

    sizeVal->value(7);
    widthVal->value(7);
    heightVal->value(7);

    changeColor->hide();
    
    widthVal->hide();
    heightVal->hide();

    plusButton->hide();
    minusButton->hide();
    bringToFront->hide();
    sendToBack->hide();
    

    pencilButton->box(FL_BORDER_BOX);
    eraserButton->box(FL_BORDER_BOX);
    circleButton->box(FL_BORDER_BOX);
    triangleButton->box(FL_BORDER_BOX);
    rectangleButton->box(FL_BORDER_BOX);
    polygonButton->box(FL_BORDER_BOX);
    clearButton->box(FL_BORDER_BOX);
    selectButton->box(FL_BORDER_BOX);
    undoButton->box(FL_BORDER_BOX);
    changeColor->box(FL_BORDER_BOX);

    plusButton->box(FL_BORDER_BOX);
    minusButton->box(FL_BORDER_BOX);
    bringToFront->box(FL_BORDER_BOX);
    sendToBack->box(FL_BORDER_BOX);

    sizeVal->box(FL_BORDER_BOX);

    sizeVal->labelsize(14);
    widthVal->labelsize(14);
    heightVal->labelsize(14);

    changeColor->labelsize(12);

    visualizeSelectedTool();

    ON_CLICK(pencilButton, Toolbar::onClick);
    ON_CLICK(eraserButton, Toolbar::onClick);
    ON_CLICK(circleButton, Toolbar::onClick);
    ON_CLICK(triangleButton, Toolbar::onClick);
    ON_CLICK(rectangleButton, Toolbar::onClick);
    ON_CLICK(polygonButton, Toolbar::onClick);
    ON_CLICK(clearButton, Toolbar::onClick);
    ON_CLICK(selectButton, Toolbar::onClick);
    ON_CLICK(undoButton, Toolbar::onClick);



    ON_CHANGE(sizeVal, Toolbar::onThingChange);
    ON_CHANGE(widthVal, Toolbar::onThingChange);
    ON_CHANGE(heightVal, Toolbar::onThingChange);

    ON_CLICK(plusButton, Toolbar::onClick);
    ON_CLICK(minusButton, Toolbar::onClick);
    ON_CLICK(bringToFront, Toolbar::onClick);
    ON_CLICK(sendToBack, Toolbar::onClick);
    ON_CLICK(changeColor, Toolbar::onClick)
}