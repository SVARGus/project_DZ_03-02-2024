#include "Logger.h"

Logger::LogPriority Logger::priority = Logger::InfoPriority;
mutex Logger::logMutex;

Logger& Logger::getInstance() {
	static Logger instance(InfoPriority);
	return instance;
}
void Logger::setPriority(LogPriority newPriority) { priority = newPriority; }
