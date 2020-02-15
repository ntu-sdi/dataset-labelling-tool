#include "MainView.h"
#include "ImageModel.h"

class ImageController
{
private:
    Ui::MainView ui;
    ImageModel model;

public:
    void browse();
    LinkedList<std::string> searchLoaded(const std::string&);
    LinkedList<std::string> sortLoaded();
    std::string select(const std::string&);
    void open();
};
