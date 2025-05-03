#include "Help.h"
#include <GL/freeglut.h>
#include <bobcat_ui/bobcat_ui.h>
#include <iterator>
#include <string>
#include "Help.h"


Help::Help(int x, int y, int w, int h) : Group(x, y, w, h) {
        std::string words = 
        "User Guide: \n \n";
        words += "Clicking will place a point using \n the settings in the bottom left. \n \n ";
        words += "Clicking and dragging when creating \n a shape will allow you to \n resize it dynamically. \n \n";
        words += "The Undo Button will delete \n the last shape that was placed. \n \n";
        words += "Pressing Undo with a selected \n shape will delete it instead. \n \n";
        helpText = new bobcat::TextBox(x, y, 300, 600, words);
}


void Help::render() {
    for (unsigned int i = 0 ; i < shapes.size(); i++) {
        shapes[i]->draw();
    }
}

