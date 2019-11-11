/********************************************************************************
** Form generated from reading UI file 'gui.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_H
#define UI_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gui
{
public:
    QWidget *centralwidget;
    QFrame *SearchFrame_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_7;
    QPushButton *pushButton_4;
    QLabel *label_8;
    QListView *listView;
    QFrame *SearchFrame_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QPushButton *pushButton_3;
    QLabel *label_6;
    QFrame *SearchFrame_5;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QLabel *label_10;
    QLabel *label_9;
    QListView *listView_2;
    QLabel *label_2;
    QFrame *SearchFrame_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QFrame *SearchFrame;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QStatusBar *statusbar;
    QMenuBar *menubar;

    void setupUi(QMainWindow *gui)
    {
        if (gui->objectName().isEmpty())
            gui->setObjectName(QString::fromUtf8("gui"));
        gui->resize(404, 627);
        centralwidget = new QWidget(gui);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        SearchFrame_4 = new QFrame(centralwidget);
        SearchFrame_4->setObjectName(QString::fromUtf8("SearchFrame_4"));
        SearchFrame_4->setGeometry(QRect(10, 520, 161, 21));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SearchFrame_4->sizePolicy().hasHeightForWidth());
        SearchFrame_4->setSizePolicy(sizePolicy);
        SearchFrame_4->setFrameShape(QFrame::StyledPanel);
        SearchFrame_4->setFrameShadow(QFrame::Raised);
        horizontalLayout_5 = new QHBoxLayout(SearchFrame_4);
        horizontalLayout_5->setSpacing(10);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(SearchFrame_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy1);

        horizontalLayout_5->addWidget(label_7);

        pushButton_4 = new QPushButton(SearchFrame_4);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        sizePolicy1.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy1);

        horizontalLayout_5->addWidget(pushButton_4);

        label_8 = new QLabel(SearchFrame_4);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        sizePolicy1.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy1);

        horizontalLayout_5->addWidget(label_8);

        listView = new QListView(centralwidget);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(10, 70, 381, 171));
        SearchFrame_3 = new QFrame(centralwidget);
        SearchFrame_3->setObjectName(QString::fromUtf8("SearchFrame_3"));
        SearchFrame_3->setGeometry(QRect(10, 290, 191, 21));
        sizePolicy.setHeightForWidth(SearchFrame_3->sizePolicy().hasHeightForWidth());
        SearchFrame_3->setSizePolicy(sizePolicy);
        SearchFrame_3->setFrameShape(QFrame::StyledPanel);
        SearchFrame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(SearchFrame_3);
        horizontalLayout_4->setSpacing(10);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(SearchFrame_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(label_5);

        pushButton_3 = new QPushButton(SearchFrame_3);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        sizePolicy1.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(pushButton_3);

        label_6 = new QLabel(SearchFrame_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(label_6);

        SearchFrame_5 = new QFrame(centralwidget);
        SearchFrame_5->setObjectName(QString::fromUtf8("SearchFrame_5"));
        SearchFrame_5->setGeometry(QRect(230, 520, 161, 21));
        sizePolicy.setHeightForWidth(SearchFrame_5->sizePolicy().hasHeightForWidth());
        SearchFrame_5->setSizePolicy(sizePolicy);
        SearchFrame_5->setFrameShape(QFrame::StyledPanel);
        SearchFrame_5->setFrameShadow(QFrame::Raised);
        horizontalLayout_6 = new QHBoxLayout(SearchFrame_5);
        horizontalLayout_6->setSpacing(5);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        pushButton_5 = new QPushButton(SearchFrame_5);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        sizePolicy1.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy1);

        horizontalLayout_6->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(SearchFrame_5);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        sizePolicy1.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy1);

        horizontalLayout_6->addWidget(pushButton_6);

        label_10 = new QLabel(SearchFrame_5);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        sizePolicy1.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy1);

        horizontalLayout_6->addWidget(label_10);

        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(770, -10, 321, 391));
        label_9->setPixmap(QPixmap(QString::fromUtf8("../../../Downloads/download.jpg")));
        label_9->setScaledContents(true);
        listView_2 = new QListView(centralwidget);
        listView_2->setObjectName(QString::fromUtf8("listView_2"));
        listView_2->setGeometry(QRect(10, 320, 381, 171));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 250, 101, 16));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        SearchFrame_2 = new QFrame(centralwidget);
        SearchFrame_2->setObjectName(QString::fromUtf8("SearchFrame_2"));
        SearchFrame_2->setGeometry(QRect(10, 10, 191, 21));
        sizePolicy.setHeightForWidth(SearchFrame_2->sizePolicy().hasHeightForWidth());
        SearchFrame_2->setSizePolicy(sizePolicy);
        SearchFrame_2->setFrameShape(QFrame::StyledPanel);
        SearchFrame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(SearchFrame_2);
        horizontalLayout_3->setSpacing(10);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(SearchFrame_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(label_4);

        SearchFrame = new QFrame(centralwidget);
        SearchFrame->setObjectName(QString::fromUtf8("SearchFrame"));
        SearchFrame->setGeometry(QRect(10, 40, 241, 31));
        SearchFrame->setFrameShape(QFrame::StyledPanel);
        SearchFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(SearchFrame);
        horizontalLayout_2->setSpacing(10);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(SearchFrame);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        lineEdit = new QLineEdit(SearchFrame);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_2->addWidget(lineEdit);

        gui->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(gui);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        gui->setStatusBar(statusbar);
        menubar = new QMenuBar(gui);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 404, 22));
        gui->setMenuBar(menubar);

        retranslateUi(gui);

        QMetaObject::connectSlotsByName(gui);
    } // setupUi

    void retranslateUi(QMainWindow *gui)
    {
        gui->setWindowTitle(QCoreApplication::translate("gui", "gui", nullptr));
        label_7->setText(QCoreApplication::translate("gui", "Bboxes:", nullptr));
        pushButton_4->setText(QCoreApplication::translate("gui", "Browse...", nullptr));
        label_8->setText(QCoreApplication::translate("gui", "N......", nullptr));
        label_5->setText(QCoreApplication::translate("gui", "Classes:", nullptr));
        pushButton_3->setText(QCoreApplication::translate("gui", "Browse...", nullptr));
        label_6->setText(QCoreApplication::translate("gui", "No fi...ted.", nullptr));
        pushButton_5->setText(QCoreApplication::translate("gui", "Save YOLO", nullptr));
        pushButton_6->setText(QCoreApplication::translate("gui", "Restore", nullptr));
        label_10->setText(QString());
        label_9->setText(QString());
        label_2->setText(QCoreApplication::translate("gui", "1280x719, 258.18 KB", nullptr));
        label_4->setText(QCoreApplication::translate("gui", "Images:", nullptr));
        label_3->setText(QCoreApplication::translate("gui", "Search:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class gui: public Ui_gui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
