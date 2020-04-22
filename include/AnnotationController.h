#pragma once

#include<thread>

#include "AnnotationModel.h"
#include "ui_MainView.h"

/**
 * Sub-controller which gets delegated tasks related to annotation files.
 * Communicates directly with the AnnotationModel.
 */
class AnnotationController
{
private:
    Ui_MainView ui;
    std::vector<Point> points;
    AnnotationModel model;
public:
    AnnotationController(const Ui_MainView&, const AnnotationModel&);
    void create();
    void browse();
    void add(const QString& filePath, const QString& className, LinkedList<QPair<int, int>>);
    void save();
    LinkedList<QPair<QString, Shape>> get(const QString&);
};


