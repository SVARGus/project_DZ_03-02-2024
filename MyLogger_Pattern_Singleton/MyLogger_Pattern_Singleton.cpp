#include <iostream>
#include "Logger.h"
#include <thread>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
    setlocale(LC_ALL, "ru");
    
    Logger& logtest = Logger::getInstance();
    logtest.setPriority(Logger::TracePriority);
    logtest.enableFileOutput();
    int a = 5;
    string name{ "Pavel" };
    logtest.trace("log test", a, name);
    logtest.debug("log test", a, name);
    logtest.info("log test", a, name);
    logtest.warn("log test", a, name);
    logtest.error("log test", a, name);
    logtest.critical("log test", a, name);

    logtest.closeFileOutput();
    return 0;
}
