#include "Logger.h"

string Logger::filepath = "";
ofstream Logger::myLogFile{};

Logger::LogPriority Logger::priority = Logger::InfoPriority;
mutex Logger::logMutex;

Logger& Logger::getInstance() {
	static Logger instance(InfoPriority);
	return instance;
}
void Logger::setPriority(LogPriority newPriority) { priority = newPriority; }
// ����� ��������� ������ enableFileOutput
void Logger::enableFileOutput() {
	if (myLogFile.is_open())
		myLogFile.close();
	filepath = "log.txt";
	myLogFile.open(filepath, std::ios::out | std::ios::app); // �������� � ����� �����
	if (!myLogFile.is_open())
		cout << "Logger: ������ �������� �����: " << filepath << endl;
}
void Logger::enableFileOutput(const string& newFilepath) {
	if (myLogFile.is_open())
		myLogFile.close();
	filepath = newFilepath;
	myLogFile.open(filepath, std::ios::out | std::ios::app); // �������� � ����� �����
	if (!myLogFile.is_open())
		cout << "Logger: ������ �������� �����: " << filepath << endl;
}
void Logger::closeFileOutput() {
	myLogFile.close();
	filepath.clear();
}