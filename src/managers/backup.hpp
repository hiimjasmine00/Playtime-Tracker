#pragma once
#define backup_h

class Backup {
protected:
	static bool fileExists();
	static void writeFile(std::string output);

public:
	static void createBackup();
};