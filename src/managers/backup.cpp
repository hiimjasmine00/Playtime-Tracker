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

void Backup::writeFile(std::string output) {
	std::ofstream o(dataDirPath);
	o << output;
	o.close();
}

void Backup::createBackup() {
	if (data::fileExists()) {

	}
}