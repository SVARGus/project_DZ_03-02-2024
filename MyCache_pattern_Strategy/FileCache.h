#pragma once
#include "BaseCache.h"
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <sstream>

using std::string;
using std::ofstream;
using std::ifstream;
using std::hash;
using std::to_string;
using std::getline;
using std::istringstream;

class FileCache : public BaseCache
{
    
public:
    string getFileName(const std::string& key) const {
        hash<string> hashFunc;
        return to_string(hashFunc(key)) + ".cache";
    }
    bool has(const string& key) override {
        ifstream file(getFileName(key));
        return file.good();
    }
    string read(const string& key) override {
        ifstream file(getFileName(key));
        string line{};
        string k{};
        string v{};
        while (getline(file, line))
        {
            istringstream ss(line);
            if (ss >> k >> v && k == key)
            {
                return v;
            }
        }
        return "";
    }
    void write(const string& key, const string& value) override {
        ofstream file(getFileName(key), std::ios::app);
        file << key << "\t" << value << "\n";
    }
    void erase(const string& key) override {
        std::filesystem::remove(getFileName(key));
    }
};

