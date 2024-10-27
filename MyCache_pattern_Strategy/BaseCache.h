#pragma once
#include <iostream>

using std::string;

class BaseCache
{
public:
    virtual bool has(const string& key) = 0;
    virtual string read(const string& key) = 0;
    virtual void write(const string& key, const string& value) = 0;
    virtual void erase(const string& key) = 0;
};

