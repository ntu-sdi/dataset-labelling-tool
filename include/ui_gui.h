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
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gui
{
public:
    QAction *actionOpen_folder;
    QWidget *CentralWidget;
    QFrame *MainContainer;
    QFrame *ImageBrowsingFrame;
    QHBoxLayout *horizontalLayout;
    QLabel *ImagesLabel;
    QPushButton *ImageBrowseButton;
    QLabel *ImageFolderLabel;
    QPushButton *CropSaveButton;
    QFrame *ImageSearchFrame;
    QHBoxLayout *horizontalLayout_2;
    QLabel *SearchLabel;
    QLineEdit *SearchBox;
    QListWidget *ImageList;
    QLabel *ImageInfoLabel;
    QFrame *ClassBrowsingFrame;
    QHBoxLayout *horizontalLayout_3;
    QLabel *ClassesLabel;
    QPushButton *ClassBrowseButton;
    QLabel *ClassFileLabel;
    QListWidget *ClassesList;
    QFrame *BBoxesBrowsingFrame;
    QHBoxLayout *horizontalLayout_4;
    QLabel *BBoxesLabel;
    QPushButton *BBoxBrowseButton;
    QLabel *BBoxFileName;
    QPushButton *SaveYOLOButton;
    QPushButton *RestoreButton;

    void setupUi(QMainWindow *gui)
    {
        if (gui->objectName().isEmpty())
            gui->setObjectName(QString::fromUtf8("gui"));
        gui->resize(480, 630);
        actionOpen_folder = new QAction(gui);
        actionOpen_folder->setObjectName(QString::fromUtf8("actionOpen_folder"));
        CentralWidget = new QWidget(gui);
        CentralWidget->setObjectName(QString::fromUtf8("CentralWidget"));
        MainContainer = new QFrame(CentralWidget);
        MainContainer->setObjectName(QString::fromUtf8("MainContainer"));
        MainContainer->setGeometry(QRect(10, 10, 460, 620));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainContainer->sizePolicy().hasHeightForWidth());
        MainContainer->setSizePolicy(sizePolicy);
        MainContainer->setStyleSheet(QString::fromUtf8("QFrame { border: 0; }"));
        MainContainer->setFrameShape(QFrame::StyledPanel);
        MainContainer->setFrameShadow(QFrame::Raised);
        MainContainer->setLineWidth(0);
        ImageBrowsingFrame = new QFrame(MainContainer);
        ImageBrowsingFrame->setObjectName(QString::fromUtf8("ImageBrowsingFrame"));
        ImageBrowsingFrame->setGeometry(QRect(20, 20, 261, 25));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(ImageBrowsingFrame->sizePolicy().hasHeightForWidth());
        ImageBrowsingFrame->setSizePolicy(sizePolicy1);
        ImageBrowsingFrame->setStyleSheet(QString::fromUtf8(""));
        ImageBrowsingFrame->setFrameShape(QFrame::StyledPanel);
        ImageBrowsingFrame->setFrameShadow(QFrame::Raised);
        ImageBrowsingFrame->setLineWidth(0);
        horizontalLayout = new QHBoxLayout(ImageBrowsingFrame);
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 1, 0);
        ImagesLabel = new QLabel(ImageBrowsingFrame);
        ImagesLabel->setObjectName(QString::fromUtf8("ImagesLabel"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(ImagesLabel->sizePolicy().hasHeightForWidth());
        ImagesLabel->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(ImagesLabel);

        ImageBrowseButton = new QPushButton(ImageBrowsingFrame);
        ImageBrowseButton->setObjectName(QString::fromUtf8("ImageBrowseButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(ImageBrowseButton->sizePolicy().hasHeightForWidth());
        ImageBrowseButton->setSizePolicy(sizePolicy3);

        horizontalLayout->addWidget(ImageBrowseButton);

        ImageFolderLabel = new QLabel(ImageBrowsingFrame);
        ImageFolderLabel->setObjectName(QString::fromUtf8("ImageFolderLabel"));
        sizePolicy2.setHeightForWidth(ImageFolderLabel->sizePolicy().hasHeightForWidth());
        ImageFolderLabel->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(ImageFolderLabel);

        CropSaveButton = new QPushButton(MainContainer);
        CropSaveButton->setObjectName(QString::fromUtf8("CropSaveButton"));
        CropSaveButton->setGeometry(QRect(330, 20, 111, 25));
        ImageSearchFrame = new QFrame(MainContainer);
        ImageSearchFrame->setObjectName(QString::fromUtf8("ImageSearchFrame"));
        ImageSearchFrame->setGeometry(QRect(20, 55, 220, 25));
        sizePolicy1.setHeightForWidth(ImageSearchFrame->sizePolicy().hasHeightForWidth());
        ImageSearchFrame->setSizePolicy(sizePolicy1);
        ImageSearchFrame->setFrameShape(QFrame::StyledPanel);
        ImageSearchFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(ImageSearchFrame);
        horizontalLayout_2->setSpacing(10);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        SearchLabel = new QLabel(ImageSearchFrame);
        SearchLabel->setObjectName(QString::fromUtf8("SearchLabel"));
        sizePolicy.setHeightForWidth(SearchLabel->sizePolicy().hasHeightForWidth());
        SearchLabel->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(SearchLabel);

        SearchBox = new QLineEdit(ImageSearchFrame);
        SearchBox->setObjectName(QString::fromUtf8("SearchBox"));

        horizontalLayout_2->addWidget(SearchBox);

        ImageList = new QListWidget(MainContainer);
        ImageList->setObjectName(QString::fromUtf8("ImageList"));
        ImageList->setGeometry(QRect(20, 90, 420, 200));
        sizePolicy1.setHeightForWidth(ImageList->sizePolicy().hasHeightForWidth());
        ImageList->setSizePolicy(sizePolicy1);
        ImageInfoLabel = new QLabel(MainContainer);
        ImageInfoLabel->setObjectName(QString::fromUtf8("ImageInfoLabel"));
        ImageInfoLabel->setGeometry(QRect(20, 300, 220, 15));
        ClassBrowsingFrame = new QFrame(MainContainer);
        ClassBrowsingFrame->setObjectName(QString::fromUtf8("ClassBrowsingFrame"));
        ClassBrowsingFrame->setGeometry(QRect(20, 330, 220, 25));
        sizePolicy1.setHeightForWidth(ClassBrowsingFrame->sizePolicy().hasHeightForWidth());
        ClassBrowsingFrame->setSizePolicy(sizePolicy1);
        ClassBrowsingFrame->setStyleSheet(QString::fromUtf8(""));
        ClassBrowsingFrame->setFrameShape(QFrame::StyledPanel);
        ClassBrowsingFrame->setFrameShadow(QFrame::Raised);
        ClassBrowsingFrame->setLineWidth(0);
        horizontalLayout_3 = new QHBoxLayout(ClassBrowsingFrame);
        horizontalLayout_3->setSpacing(10);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 1, 0);
        ClassesLabel = new QLabel(ClassBrowsingFrame);
        ClassesLabel->setObjectName(QString::fromUtf8("ClassesLabel"));
        sizePolicy2.setHeightForWidth(ClassesLabel->sizePolicy().hasHeightForWidth());
        ClassesLabel->setSizePolicy(sizePolicy2);

        horizontalLayout_3->addWidget(ClassesLabel);

        ClassBrowseButton = new QPushButton(ClassBrowsingFrame);
        ClassBrowseButton->setObjectName(QString::fromUtf8("ClassBrowseButton"));
        sizePolicy3.setHeightForWidth(ClassBrowseButton->sizePolicy().hasHeightForWidth());
        ClassBrowseButton->setSizePolicy(sizePolicy3);

        horizontalLayout_3->addWidget(ClassBrowseButton);

        ClassFileLabel = new QLabel(ClassBrowsingFrame);
        ClassFileLabel->setObjectName(QString::fromUtf8("ClassFileLabel"));
        sizePolicy2.setHeightForWidth(ClassFileLabel->sizePolicy().hasHeightForWidth());
        ClassFileLabel->setSizePolicy(sizePolicy2);

        horizontalLayout_3->addWidget(ClassFileLabel);

        ClassesList = new QListWidget(MainContainer);
        ClassesList->setObjectName(QString::fromUtf8("ClassesList"));
        ClassesList->setGeometry(QRect(20, 360, 420, 200));
        sizePolicy1.setHeightForWidth(ClassesList->sizePolicy().hasHeightForWidth());
        ClassesList->setSizePolicy(sizePolicy1);
        BBoxesBrowsingFrame = new QFrame(MainContainer);
        BBoxesBrowsingFrame->setObjectName(QString::fromUtf8("BBoxesBrowsingFrame"));
        BBoxesBrowsingFrame->setGeometry(QRect(20, 580, 221, 25));
        sizePolicy1.setHeightForWidth(BBoxesBrowsingFrame->sizePolicy().hasHeightForWidth());
        BBoxesBrowsingFrame->setSizePolicy(sizePolicy1);
        BBoxesBrowsingFrame->setStyleSheet(QString::fromUtf8(""));
        BBoxesBrowsingFrame->setFrameShape(QFrame::StyledPanel);
        BBoxesBrowsingFrame->setFrameShadow(QFrame::Raised);
        BBoxesBrowsingFrame->setLineWidth(0);
        horizontalLayout_4 = new QHBoxLayout(BBoxesBrowsingFrame);
        horizontalLayout_4->setSpacing(10);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 1, 0);
        BBoxesLabel = new QLabel(BBoxesBrowsingFrame);
        BBoxesLabel->setObjectName(QString::fromUtf8("BBoxesLabel"));
        sizePolicy2.setHeightForWidth(BBoxesLabel->sizePolicy().hasHeightForWidth());
        BBoxesLabel->setSizePolicy(sizePolicy2);

        horizontalLayout_4->addWidget(BBoxesLabel);

        BBoxBrowseButton = new QPushButton(BBoxesBrowsingFrame);
        BBoxBrowseButton->setObjectName(QString::fromUtf8("BBoxBrowseButton"));
        sizePolicy3.setHeightForWidth(BBoxBrowseButton->sizePolicy().hasHeightForWidth());
        BBoxBrowseButton->setSizePolicy(sizePolicy3);

        horizontalLayout_4->addWidget(BBoxBrowseButton);

        BBoxFileName = new QLabel(BBoxesBrowsingFrame);
        BBoxFileName->setObjectName(QString::fromUtf8("BBoxFileName"));
        sizePolicy2.setHeightForWidth(BBoxFileName->sizePolicy().hasHeightForWidth());
        BBoxFileName->setSizePolicy(sizePolicy2);

        horizontalLayout_4->addWidget(BBoxFileName);

        SaveYOLOButton = new QPushButton(MainContainer);
        SaveYOLOButton->setObjectName(QString::fromUtf8("SaveYOLOButton"));
        SaveYOLOButton->setGeometry(QRect(250, 580, 91, 25));
        RestoreButton = new QPushButton(MainContainer);
        RestoreButton->setObjectName(QString::fromUtf8("RestoreButton"));
        RestoreButton->setGeometry(QRect(350, 580, 91, 25));
        gui->setCentralWidget(CentralWidget);

        retranslateUi(gui);

        QMetaObject::connectSlotsByName(gui);
    } // setupUi

    void retranslateUi(QMainWindow *gui)
    {
        gui->setWindowTitle(QCoreApplication::translate("gui", "gui", nullptr));
        actionOpen_folder->setText(QCoreApplication::translate("gui", "Open folder", nullptr));
        ImagesLabel->setText(QCoreApplication::translate("gui", "Image Folder:", nullptr));
        ImageBrowseButton->setText(QCoreApplication::translate("gui", "Browse...", nullptr));
        ImageFolderLabel->setText(QCoreApplication::translate("gui", "DSC_...jpg", nullptr));
        CropSaveButton->setText(QCoreApplication::translate("gui", "Crop and Save", nullptr));
        SearchLabel->setText(QCoreApplication::translate("gui", "Search:", nullptr));
        ImageInfoLabel->setText(QCoreApplication::translate("gui", "1280x719, 258.18 KB", nullptr));
        ClassesLabel->setText(QCoreApplication::translate("gui", "Classes:", nullptr));
        ClassBrowseButton->setText(QCoreApplication::translate("gui", "Browse...", nullptr));
        ClassFileLabel->setText(QCoreApplication::translate("gui", "No fi...ted.", nullptr));
        BBoxesLabel->setText(QCoreApplication::translate("gui", "BBoxes:", nullptr));
        BBoxBrowseButton->setText(QCoreApplication::translate("gui", "Browse...", nullptr));
        BBoxFileName->setText(QCoreApplication::translate("gui", "No fi...ted.", nullptr));
        SaveYOLOButton->setText(QCoreApplication::translate("gui", "Save YOLO", nullptr));
        RestoreButton->setText(QCoreApplication::translate("gui", "Restore", nullptr));
    } // retranslateUi

};

namespace Ui {
    class gui: public Ui_gui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
