#include <iostream>
//#include "dummyclass.h"
//#include <fmt/format.h>
//#include <sqlite3.h>
//#include <nlohmann/json.hpp>
#include "gui.h"
///using json = nlohmann::json;

#include <QApplication>
#include "include/RectangleDrawer.h"
#include <opencv2/highgui.hpp>

#include <stdio.h>
#include <unistd.h>
#include <string>

int main(int argc, char** argv)
{
    /*
    char buff[FILENAME_MAX];
    getcwd(buff, FILENAME_MAX);
    std::string current_working_dir(buff);
    std::cout << current_working_dir << std::endl;
     */

    try
    {
        cv::Mat image = RectangleDrawer::drawRectangle("/home/22ru/dataset-labelling-tool/sample1.jpg", 0, 0, 100, 100);
        cv::namedWindow("Display Window", cv::WINDOW_AUTOSIZE);
        cv::imshow("Display Window", image);
        cv::waitKey(0);
    }
    catch (const FileNotFoundError& e)
    {
        std::cout << e.what() << std::endl;
    }

    QApplication a(argc, argv);
    gui w;
    w.show();
    return a.exec();

    /*
    std::cout << "Hello, World!" << std::endl;
    dummyclass a;
    std::string s = fmt::format("I'd rather be {1} than {0}.\n", "right", "happy");
    std::cout<<s;
    sqlite3 *db;
    sqlite3_open("database.db", &db);

    // create an empty structure (null)
    json j;
    j["pi"];
    j["pi"][0] = 2;
    j["pi"][1] = 4;

    std::cout<<j["pi"][1];*/
    return 0;
}

