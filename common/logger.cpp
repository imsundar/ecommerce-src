#include "logger.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>

void log(const std::string& level, const std::string& service, const std::string& message) {
    std::time_t now = std::time(nullptr);
    char buf[20];
    std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
    std::string logLine = std::string(buf) + " " + level + " [" + service + "] " + message + "\n";
    std::cout << logLine;
    std::ofstream logFile("../ecommerce-logs/" + service + ".log", std::ios::app);
    if (logFile.is_open()) {
        logFile << logLine;
        logFile.close();
    }
}