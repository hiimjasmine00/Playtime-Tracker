#include "./backup.hpp"
#include "./data.hpp"

#include <fstream>

using namespace geode::prelude;

auto dataDir = Mod::get()->getSaveDir().string() + "/leveldata.json";
std::filesystem::path dataDirPath = std::filesystem::path(dataDir);

auto backupDir = Mod::get()->getSaveDir().string() + "/leveldata.backup";
std::filesystem::path backupDirPath = std::filesystem::path(backupDir);

bool Backup::fileExists() {
	if (std::filesystem::exists(backupDirPath)) return true;
	return false;
}

matjson::Value Backup::getFile() {
	if (Backup::fileExists()) {
		std::ifstream i(backupDir);
		auto data = matjson::parse(i).unwrap();
		i.close();
		return data;
	}
}

void Backup::writeFile(matjson::Value data) {
	std::string output = data.dump(matjson::NO_INDENTATION);
	std::ofstream o(dataDirPath);
	o << output;
	o.close();
}

void Backup::createBackup() {
		auto data = Data::getFile();
		Backup::writeFile(data);
}

void Backup::loadBackup() {
	auto data = Backup::getFile();
	std::string output = data.dump(matjson::NO_INDENTATION);
	std::ofstream o(dataDirPath);
	o << output;
	o.close();
}