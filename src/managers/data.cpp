#include "./data.hpp"

#include <fstream>
#include <ctime>
#include <matjson.hpp>


using namespace geode::prelude;

auto dataDir = Mod::get()->getSaveDir().string() + "/testing.json";
std::filesystem::path dataDirPath = std::filesystem::u8path(dataDir);

void data::initializeFile() {
    matjson::Value data;

    std::string output = data.dump();
    std::ofstream o(dataDir);
    o << output;
    o.close();
    }

bool data::fileExists() {
    if (std::filesystem::exists(dataDirPath)) {
        return true;
    }
    initializeFile();
    if (std::filesystem::exists(dataDirPath)) {
        return true;
    }
    return false;
}

void data::addStart(int levelID) {
    if (fileExists()) {
        std::ifstream i(dataDir);
        auto result = matjson::parse(i);
        matjson::Value data = result.unwrap();
        data[std::to_string(levelID)] = "test";

        i.close();

        std::string output = data.dump();
        std::ofstream o(dataDir);
        o << output;
        o.close();
    }
}