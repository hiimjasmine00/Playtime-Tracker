#pragma once
#define backup_h

class Backup {
protected:
	static void writeFile(matjson::Value data);
	static matjson::Value getFile();

public:
	static bool fileExists();
	static void createBackup();
	static void loadBackup();
};