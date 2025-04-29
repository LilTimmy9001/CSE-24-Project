#ifndef HELP_H
#define HELP_H

#include <bobcat_ui/all.h>
#include <bobcat_ui/textbox.h>
#include <vector>

#include "Point.h"
#include "Shape.h"

class Help : public bobcat::Group {
    std::vector<Shape*> shapes;

public:
    bobcat::TextBox* helpText;
    Help(int x, int y, int w, int h);
    void render();

    friend struct AppTest;

};

#endif