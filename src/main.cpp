#include <iostream>
#include <gui.h>
#include <QApplication>

int main(int argc, char** argv)
{
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

