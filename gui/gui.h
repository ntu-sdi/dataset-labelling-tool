#ifndef GUI_H
#define GUI_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class gui; }
QT_END_NAMESPACE

class gui : public QMainWindow
{
    Q_OBJECT

public:
    gui(QWidget *parent = nullptr);
    ~gui();

private:
    Ui::gui *ui;
};
#endif // GUI_H
