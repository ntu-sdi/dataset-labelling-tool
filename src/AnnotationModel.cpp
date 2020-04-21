#include <QFileSystemModel>
#include <QFileDialog>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include "exceptions.h"
#include "AnnotationModel.h"

/**
 * @brief Returns path of currently active annotation file.
 * @return Path to a annotation file.
 */
QString AnnotationModel::getCurrentFilePath()
{
    return this->currentFilePath;
}

/**
 * @brief Prompts user to navigate to a annotation file on the system.
 *
 * If entered path is empty, or file could not be oppened, std::invalid_argument
 * exception  is thrown.
 * If operation is canceled custom OperationCanceled exception is thrown.
 * Location of opened file is saved to a private currentFilePath attribute
 * in this class.
 */
void AnnotationModel::browse()
{
    QString filePath = QFileDialog::getOpenFileName(nullptr, "Select Annotation File",
        "./", "Annotation files (*.annotation)");
    if (filePath.isNull()) {
        throw OperationCanceled();
    }
    if (filePath.isEmpty()) {
        throw std::invalid_argument("File path cannot be empty");
    }
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly)) {
        this->currentFilePath = filePath;
        file.close();
    }
    else {
        throw FileNotFoundError();
    }
}

/**
 * @brief Provides a way to enter path to annotation file as a parameter (QString).
 *
 * If entered path is empty, or file could not be oppened, std::invalid_argument
 * exception is thrown.
 * Location of opened file is saved to a private currentFilePath attribute
 * in this class.
 *
 * @param filePath QString path for a annotation file you want to create.
 */
void AnnotationModel::browse(const QString& filePath)
{
    if (filePath.isEmpty()) {
        throw std::invalid_argument("File path cannot be empty");
    }
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly)) {
        this->currentFilePath = filePath;
        file.close();
    }
    else {
        throw FileNotFoundError();
    }
}

/**
 * @brief Prompts the user for a annotation file name. Creates a file using this name and path.
 *
 * If filePath is empty, or file could not be created at wanted location
 * std::invalid argument exception is thrown.
 * If operation is canceled custom OperationCanceled exception is thrown.
 * Location of opened file is saved to a private currentFilePath attribute in this class.
 */
void AnnotationModel::create()
{
    QString filePath = QFileDialog::getSaveFileName(nullptr, "Create New Annotation File",
        "./",
        "Annotation files (*.annotation)");
    if (filePath.isNull()) {
        throw OperationCanceled();
    }
    if (filePath.isEmpty()) {
        throw std::invalid_argument("File path cannot be empty");
    }
    filePath = filePath.trimmed();
    if (!filePath.contains(".annotation")) {
        filePath.append(".annotation");
    }
    QFile file(filePath);
    if (!file.open(QIODevice::ReadWrite)) {
        std::invalid_argument("Could not create file");
    }
    file.close();
    this->currentFilePath = filePath;
}

/**
 * @brief Provides a way to create annotation file by providing file path as a parameter (QString)
 *
 * If filePath is empty, or file could not be created at wanted location
 * std::invalid argument exception is thrown.
 * Location of opened file is saved to a private currentFilePath attribute in this class.
 *
 * @param filePath QString path for a annotation file you want to create.
 */
void AnnotationModel::create(const QString& filePath)
{
    if (filePath.isEmpty()) {
        throw std::invalid_argument("File path cannot be empty");
    }
    QString path = filePath;
    if (!path.contains(".annotation")) {
        path.append(".annotation");
    }
    QFile file(path);
    if (!file.open(QIODevice::ReadWrite)) {
        std::invalid_argument("Could not create file");
    }
    file.close();
    this->currentFilePath = path;
}

/**
 * @brief Provides a way to save annotation to annotation file
 *
 * Function opens and loads all annotation details from annotation file into memory. After that
 * it creates a new annotation and adds annotation details to it, or it updates previous annotation
 * if that image was previously annotated in this annotation file.
 * Annotation file which is being edited depends on which file is currently selected,
 * obtained from getCurrentFile function.
 * If for some reason that file is not available function throws FileNotFoundError.
 *
 * @param imageFilePath QString Path to a image for which annotation is being made.
 * @param className QString Name of a class which is used for annotating when drawing a shape.
 * @param coordinates QString LinkedList of all points in a annotation shape, in format x,y (QPair<int,int>).
 */
void AnnotationModel::add(const QString& imageFilePath, const QString& className, LinkedList<QPair<int, int> >& coordinates)
{
    QFile jsonFile(getCurrentFilePath());
    if (!jsonFile.exists()) {
        throw FileNotFoundError();
    }
    jsonFile.open(QIODevice::ReadOnly); //open file in read mode
    QByteArray data = jsonFile.readAll();
    QJsonDocument json = QJsonDocument::fromJson(data); //create json document from file contents
    jsonFile.close();
    QJsonObject allAnnotations = json.object(); //get outer json object
    QJsonObject newAnnotation; //create new annotation object for storing class name and list of points
    QJsonArray points; //create array for string points
    for (size_t i = 0; i < coordinates.length(); i++) {
        int x = coordinates.at(i).first;
        int y = coordinates.at(i).second;
        QJsonObject o;
        o.insert("x", x);
        o.insert("y", y);
        points.append(o); //append object of points to array of points
    }
    newAnnotation.insert("class", className);
    newAnnotation.insert("points", points); //fill annotation with data
    QJsonArray annotationsForThisImage = allAnnotations.value(imageFilePath).toArray(); //get array with all previous annotations for this image
    annotationsForThisImage.append(newAnnotation); //append all previous annotations with new annotation
    allAnnotations.insert(imageFilePath, annotationsForThisImage); //set changes to outer json object
    json.setObject(allAnnotations); //create json document from outer object
    jsonFile.open(QIODevice::WriteOnly); //write contents to file
    jsonFile.write(json.toJson());
    jsonFile.close();
}

/**
 * @brief Provides a way to save annotation to annotation file
 *
 * Function opens and loads all annotation details from annotation file into memory. After that
 * it creates a new annotation and adds annotation details to it, or it updates previous annotation
 * if the image was previously annotated in this annotation file.
 * Annotation file which is being edited is passed as 1st parameter to this function.
 * If for some reason that file is not available function throws FileNotFoundError.
 *
 * @param jsonFilePath QString Path to a annotation file in which annotation is going to be stored to.
 * @param imageFilePath QString Path to a image for which annotation is being made.
 * @param className QString Name of a class which is used for annotating when drawing a shape.
 * @param coordinates LinkedList of all points in a annotation shape, in format x,y (QPair<int,int>).
 */
void AnnotationModel::add(const QString& jsonFilePath, const QString& imageFilePath, const QString& className, LinkedList<QPair<int, int> >& coordinates)
{
    QFile jsonFile(jsonFilePath); //set file
    if (!jsonFile.exists()) {
        throw FileNotFoundError();
    }
    jsonFile.open(QIODevice::ReadOnly); //open file in read mode
    QByteArray data = jsonFile.readAll();
    QJsonDocument json = QJsonDocument::fromJson(data); //create json document from file contents
    jsonFile.close();
    QJsonObject allAnnotations = json.object(); //get outer json object
    QJsonObject newAnnotation; //create new annotation object for storing class name and list of points
    QJsonArray points; //create array for string points
    for (size_t i = 0; i < coordinates.length(); i++) {
        int x = coordinates.at(i).first;
        int y = coordinates.at(i).second;
        QJsonObject o;
        o.insert("x", x);
        o.insert("y", y);
        points.append(o); //append object of points to array of points
    }
    newAnnotation.insert("class", className);
    newAnnotation.insert("points", points); //fill annotation with data
    QJsonArray annotationsForThisImage = allAnnotations.value(imageFilePath).toArray(); //get array with all previous annotations for this image
    annotationsForThisImage.append(newAnnotation); //append all previous annotations with new annotation
    allAnnotations.insert(imageFilePath, annotationsForThisImage); //set changes to outer json object
    json.setObject(allAnnotations); //create json document from outer object
    jsonFile.open(QIODevice::WriteOnly); //write contents to file
    jsonFile.write(json.toJson());
    jsonFile.close();
}

/**
 * @brief Provides a way to obtain annotations for a given image from currently loaded annotation file
 *
 * Function searches for all annotations which are made for image name provided in a parameter.
 * If provided image is not annotated in currenlly loaded annotation file,
 * custom ImageNotAnnotatedYet exception is thrown.
 *
 * @param imageName QString name of the image user wants to obtain.
 * @return QMap of annotations, key being class name and value being LinkedList of QPair.
 */
LinkedList<QPair<QString, Shape>> AnnotationModel::get(const QString& imageName)
{
    QFile jsonFile(getCurrentFilePath());
    jsonFile.open(QIODevice::ReadOnly);
    QJsonDocument doc(QJsonDocument::fromJson(jsonFile.readAll()));
    jsonFile.close();
    QJsonObject json = doc.object();
    if (json.value(imageName).toArray().isEmpty()) {
        throw ImageNotAnnotatedYet();
    }
    LinkedList<QPair<QString, Shape>> returnVar;
    for(QJsonValue i : json.value(imageName).toArray()) {
        QString className;
        Shape coordinates;
        className = i["class"].toString();
        QJsonArray f = i["points"].toArray();
        for (auto j : f) {
            QJsonObject o = j.toObject();
            Point currentPoint(o["x"].toInt(), o["y"].toInt());
            coordinates.push(currentPoint);
        }
        returnVar.push(QPair<QString, Shape> (className, coordinates));
    }
    return returnVar;
}

/**
 * @brief Provides a way to obtain annotations for a given image from a specified annotation file
 *
 * Function searches for all annotations which are made for image name provided in a parameter.
 * If provided image is not annotated in currenlly loaded annotation file,
 * custom ImageNotAnnotatedYet exception is thrown.
 *
 * @param imageName QString name of the image user wants to obtain.
 * @param filePath QString path to annotation file where annotation for the image should be looked for.
 * @return QMap of annotations, key being class name and value being LinkedList of QPair.
 */
QMap<QString, LinkedList<QPair<int, int> > > AnnotationModel::get(const QString& imageName, const QString& filePath)
{
    QFile jsonFile(filePath);
    jsonFile.open(QIODevice::ReadOnly);
    QJsonDocument doc(QJsonDocument::fromJson(jsonFile.readAll()));
    jsonFile.close();
    QJsonObject json = doc.object();
    if (json.value(imageName).toArray().isEmpty()) {
        throw ImageNotAnnotatedYet();
    }
    QMap<QString, LinkedList<QPair<int, int> > > returnVar;
    for (QJsonValue i : json.value(imageName).toArray()) {
        QString className;
        LinkedList<QPair<int, int> > coordinates;
        className = i["class"].toString();
        QJsonArray f = i["points"].toArray();
        for (auto j : f) {
            QJsonObject o = j.toObject();
            QPair<int, int> currentPoint(o["x"].toInt(), o["y"].toInt());
            coordinates.push(currentPoint);
        }
        returnVar[className] = coordinates;
    }
    return returnVar;
}
