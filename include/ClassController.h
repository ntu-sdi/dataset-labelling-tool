#include "ClassModel.h"
#include "MainView.h"

class ClassController
{
private:
    Ui::MainView ui;
    ClassModel model;

public:
    void browse();
    void create(const std::string&);
    LinkedList<std::string> sortLoaded();
    void add(const std::string&);
    void select(const std::string&);
    /*void open(const std::string&);
     * This was in the class diagram,
     * but didn't have match anything in the
     * sequence diagram.
     */
};
