#include <map>
#include <string>
#include <utility>

#include <QFileSystemModel>
#include <QImage>

#include "LinkedList.h"

class ImageModel
{
private:
    QFileSystemModel fileSystemModel;
    std::map<std::string, std::string> loadedImages;

public:
    void browseFolder();
    LinkedList<std::string> searchLoaded(const std::string&);
    std::pair<int, int> getResolution(const std::string&);
    long getFileSize(const std::string&);
    LinkedList<std::string> getAll();
    QImage getImage(const std::string&);
};
