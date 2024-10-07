#pragma once
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

enum LogPriority {
	TracePriority, DebugPriority, InfoPriority, WarnPriority, ErrorPriority, CriticalPriority
};

class Logger
{
	static LogPriority priority;

public:
	static void setPriority(LogPriority newPriority) { priority = newPriority; }
	template<typename... Args>
	static void trace(const char* message, Args... args) {
		if (priority <= TracePriority)
		{

		}
	}

};

LogPriority Logger::priority = InfoPriority;