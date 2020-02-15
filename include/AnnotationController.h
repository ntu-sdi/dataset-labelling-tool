#include "AnnotationModel.h"
#include "MainView.h"

class AnnotationController
{
private:
    Ui::MainView ui;
    AnnotationModel model;
    std::vector<Point> points;

public:
    void browse();
    void addPoint(Point);
    void finishShape();
    void cancelShape();
    // Do these need to take a shape object
    // as a parameter to know what shape is
    // being modified?
};
