#pragma once
#include "BaseCache.h"
#include <iostream>

using std::string;

class NullCache : public BaseCache
{
public:
    bool has(const string& key) override { return false; }
    string read(const string& key) override { return ""; }
    void write(const string& key, const string& value) override {}
    void erase(const string& key) override {}
};

