#pragma once
#include <iostream>
#include <fstream>
#include <mutex>

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
public:
	static Logger& getInstance();
	static void setPriority(LogPriority newPriority);

	template<typename T>
	static void printArg(T&& arg);

	template<typename T, typename... Args>
	static void printArg(T&& arg, Args&&... args);

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

template<typename... Args>
void Logger::trace(const string& message, Args... args) // (const char* message, Args... args)
{
	if (priority <= TracePriority)
	{
		std::scoped_lock lock(logMutex);
		cout << "[Trace]\t" << message << " ";
		printArg(forward<Args>(args)...);
		cout << endl;
	}
}

template<typename... Args>
void Logger::debug(const string& message, Args... args) // (const char* message, Args... args)
{
	if (priority <= DebugPriority)
	{
		std::scoped_lock lock(logMutex);
		cout << "[Debug]\t" << message << " ";
		printArg(forward<Args>(args)...);
		cout << endl;
	}
}

template<typename... Args>
void Logger::info(const string& message, Args... args) // (const char* message, Args... args)
{
	if (priority <= InfoPriority)
	{
		std::scoped_lock lock(logMutex);
		cout << "[Info]\t" << message << " ";
		printArg(forward<Args>(args)...);
		cout << endl;
	}
}

template<typename... Args>
void Logger::warn(const string& message, Args... args) // (const char* message, Args... args)
{
	if (priority <= WarnPriority)
	{
		std::scoped_lock lock(logMutex);
		cout << "[Warn]\t" << message << " ";
		printArg(forward<Args>(args)...);
		cout << endl;
	}
}

template<typename... Args>
void Logger::error(const string& message, Args... args) // (const char* message, Args... args)
{
	if (priority <= ErrorPriority)
	{
		std::scoped_lock lock(logMutex);
		cout << "[Error]\t" << message << " ";
		printArg(forward<Args>(args)...);
		cout << endl;
	}
}

template<typename... Args>
void Logger::critical(const string& message, Args... args) // (const char* message, Args... args)
{
	if (priority <= CriticalPriority)
	{
		std::scoped_lock lock(logMutex);
		cout << "[Critical]\t" << message << " ";
		printArg(forward<Args>(args)...);
		cout << endl;
	}
}

//LogPriority Logger::priority = InfoPriority;