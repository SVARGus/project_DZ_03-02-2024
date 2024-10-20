#pragma once
#include <iostream>
#include <fstream>
#include <mutex>
#include <chrono>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::forward;
using std::mutex;


class Logger
{
public:
	enum LogPriority {
		TracePriority, DebugPriority, InfoPriority, WarnPriority, ErrorPriority, CriticalPriority
	};
private:
	static LogPriority priority;
	static mutex logMutex;
	Logger(LogPriority newPriority) { priority = newPriority; }
	Logger(const Logger&) = delete;
	Logger& operator= (const Logger&) = delete;
	template<typename... Args>
	static void log (const string& messagePriorityStr, LogPriority messagePriority, const string& message, Args... args);
	static string filepath;
	static ofstream myLogFile;
public:
	static void enableFileOutput();
	static void enableFileOutput(const string& newFilepath);
	static void closeFileOutput();

	static Logger& getInstance();
	static void setPriority(LogPriority newPriority);

	template<typename T>
	static void printArg(T&& arg);

	template<typename T, typename... Args>
	static void printArg(T&& arg, Args&&... args);

	template<typename T>
	static void printArgToFile(T&& arg);

	template<typename T, typename... Args>
	static void printArgToFile(T&& arg, Args&&... args);

	template<typename... Args>
	static void trace(const string& message, Args... args); // (const char* message, Args... args)

	template<typename... Args>
	static void debug(const string& message, Args... args); // (const char* message, Args... args)

	template<typename... Args>
	static void info(const string& message, Args... args); // (const char* message, Args... args)

	template<typename... Args>
	static void warn(const string& message, Args... args); // (const char* message, Args... args)

	template<typename... Args>
	static void error(const string& message, Args... args); // (const char* message, Args... args)

	template<typename... Args>
	static void critical(const string& message, Args... args); // (const char* message, Args... args)}
};

template<typename T>
void Logger::printArg(T&& arg) {
	cout << arg;
}
template<typename T, typename... Args>
void Logger::printArg(T&& arg, Args&&... args) {
	cout << arg << " ";
	printArg(forward<Args>(args)...);
}

template<typename T>
void Logger::printArgToFile(T&& arg) {
	myLogFile << arg;
}
template<typename T, typename... Args>
void Logger::printArgToFile(T&& arg, Args&&... args) {
	myLogFile << arg << " ";
	printArgToFile(forward<Args>(args)...);
}

template<typename... Args>
void Logger::log(const string& messagePriorityStr, LogPriority messagePriority, const string& message, Args... args) {
	if (priority <= messagePriority)
	{
		std::scoped_lock lock(logMutex);

		auto now = std::chrono::system_clock::now();
		std::time_t now_c = std::chrono::system_clock::to_time_t(now);
		tm local_time{};
		localtime_s(&local_time, &now_c);

		cout << std::put_time(&local_time, "%Y-%m-%d %H:%M:%S") << " ";
		cout << messagePriorityStr << message << " ";
		printArg(forward<Args>(args)...);
		cout << endl;
		if (myLogFile.is_open())
		{
			myLogFile << std::put_time(&local_time, "%Y-%m-%d %H:%M:%S") << " ";
			myLogFile << messagePriorityStr << " " << message << " ";
			printArgToFile(forward<Args>(args)...);
			myLogFile << endl;
		}
	}
}
template<typename... Args>
void Logger::trace(const string& message, Args... args) // (const char* message, Args... args)
{
	log("[Trace]\t", TracePriority, message, args...);
}

template<typename... Args>
void Logger::debug(const string& message, Args... args) // (const char* message, Args... args)
{
	log("[Debug]\t", DebugPriority, message, args...);
}

template<typename... Args>
void Logger::info(const string& message, Args... args) // (const char* message, Args... args)
{
	log("[Info]\t", InfoPriority, message, args...);
}

template<typename... Args>
void Logger::warn(const string& message, Args... args) // (const char* message, Args... args)
{
	log("[Warn]\t", WarnPriority, message, args...);
}

template<typename... Args>
void Logger::error(const string& message, Args... args) // (const char* message, Args... args)
{
	log("[Error]\t", ErrorPriority, message, args...);
}

template<typename... Args>
void Logger::critical(const string& message, Args... args) // (const char* message, Args... args)
{
	log("[Critical]\t", CriticalPriority, message, args...);
}

//LogPriority Logger::priority = InfoPriority;