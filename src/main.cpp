#include <iostream>
#include "dummyclass.h"
#include <fmt/format.h>
#include <sqlite3.h>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

int main() {
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

    std::cout<<j["pi"][1];
    return 0;
}