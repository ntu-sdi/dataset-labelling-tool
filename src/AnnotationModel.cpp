#include <QFileSystemModel>
#include <QFileDialog>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QTextStream>
#include <iostream>
#include "exceptions.h"

#include "AnnotationModel.h"

/**
 * @brief Prompts user to navigate to a annotation file on the system
 *
 * if entered path is empty, or file could not be oppened, std::invalid_argument
 * exception  is thrown.
 *
 * if operation is canceled custom OperationCanceled exception is thrown
 *
 * Location of opened file is saved to a private currentFilePath attribute
 * in this class
 */
void AnnotationModel::browse()
{
    QString filePath = QFileDialog::getOpenFileName(nullptr, "Select Annotation File",
        "./", "Annotation files (*.annotation)");
    if(filePath.isNull())
        throw OperationCanceled();
    if(filePath.isEmpty())
        throw std::invalid_argument("File path cannot be empty");
    QFile file(filePath);
    if(file.open(QIODevice::ReadOnly)) {
        this->currentFilePath = filePath;
        file.close();
    }
    else {
        throw std::invalid_argument("Could not open file");
    }
}

/**
 * @brief Provides a way to enter path to annotation file as a parameter (QString)
 *
 * if entered path is empty, or file could not be oppened, std::invalid_argument
 * exception  is thrown.
 *
 * Location of opened file is saved to a private currentFilePath attribute
 * in this class
 */
void AnnotationModel::browse(const QString& filePath)
{
    if(filePath.isEmpty())
        throw std::invalid_argument("File path cannot be empty");
    QFile file(filePath);
    if(file.open(QIODevice::ReadOnly)) {
        this->currentFilePath = filePath;
        file.close();
    }
    else {
        throw std::invalid_argument("Could not open file");
    }
}
/**
 * @brief Prompts the user for a annotation file name. Creates a file using this name and path.
 *
 * if filePath is empty, or file could not be created at wanted location
 * std::invalid argument exception is thrown
 *
 * if operation is canceled custom OperationCanceled exception is thrown
 *
 * Location of opened file is saved to a private currentFilePath attribute
 * in this class
 */
void AnnotationModel::create()
{
    QString filePath = QFileDialog::getSaveFileName(nullptr, "Create New Annotation File",
        "./",
        "Annotation files (*.annotation)");
    if(filePath.isNull())
        throw OperationCanceled();
    if(filePath.isEmpty())
        throw std::invalid_argument("File path cannot be empty");
    filePath = filePath.trimmed();
    if(!filePath.contains(".annotation"))
        filePath.append(".annotation");
    QFile file(filePath);
    if(!file.open(QIODevice::ReadWrite))
        std::invalid_argument("Could not create file");
    file.close();
    this->currentFilePath = filePath;
}

/**
 * @brief Provides a way to create annotation file by providing file path as a parameter (QString)
 *
 * if filePath is empty, or file could not be created at wanted location
 * std::invalid argument exception is thrown
 *
 * Location of opened file is saved to a private currentFilePath attribute
 * in this class
 */
void AnnotationModel::create(const QString& filePath)
{
    if(filePath.isEmpty())
        throw std::invalid_argument("File path cannot be empty");
    QString path = filePath;
    if(!path.contains(".annotation"))
        path.append(".annotation");
    QFile file(path);
    if(!file.open(QIODevice::ReadWrite))
        std::invalid_argument("Could not create file");
    file.close();
    this->currentFilePath = path;
}

void AnnotationModel::add(const QString& imageFilePath, const QString& className, LinkedList<std::pair<int,int>>& coordinates) {
    QJsonObject annotationDetails;
    annotationDetails.insert("class",className);
    QJsonArray points;
    for (int i = 0; i < coordinates.length(); i++){
        int x = coordinates.at(i).first;
        int y = coordinates.at(i).second;
        QJsonObject o;
        o.insert("x",x);
        o.insert("y",y);
        points.append(o);
    }
    annotationDetails.insert("points",points);
    QJsonObject annotation;
    annotation.insert(imageFilePath,annotationDetails);
    QJsonDocument json;
    json.setObject(annotation);
    QFile jsonFile(getCurrentFilePath());
    jsonFile.open(QIODevice::WriteOnly | QIODevice::Append);
    jsonFile.write(json.toJson());
    jsonFile.close();
}

void AnnotationModel::add(const QString& jsonFilePath,const QString& imageFilePath, const QString& className, LinkedList<std::pair<int,int>>& coordinates) {
    QJsonObject annotationDetails;
    annotationDetails.insert("class",className);
    QJsonArray points;
    for (int i = 0; i < coordinates.length(); i++){
        int x = coordinates.at(i).first;
        int y = coordinates.at(i).second;
        QJsonObject o;
        o.insert("x",x);
        o.insert("y",y);
        points.append(o);
    }
    annotationDetails.insert("points",points);
    QJsonObject annotation;
    annotation.insert(imageFilePath,annotationDetails);
    QJsonDocument json;
    json.setObject(annotation);
    QFile jsonFile(jsonFilePath);
    jsonFile.open(QIODevice::WriteOnly | QIODevice::Append);
    jsonFile.write(json.toJson());
    jsonFile.close();
}

/**
 * @brief Returns path of currently active annotation file
 * @return Path to a annotation file
 */
QString AnnotationModel::getCurrentFilePath()
{
    return this->currentFilePath;
}
