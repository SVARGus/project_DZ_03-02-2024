#pragma once
#include "BaseCache.h"
#include <iostream>
#include <unordered_map> 

using std::string;
using std::unordered_map;

class MemoryCache : public BaseCache
{
private:
	unordered_map<string, string> cache;
public:
    bool has(const string& key) override {
        return cache.find(key) != cache.end();
    }
    string read(const string& key) override {
        return cache[key];
    }
    void write(const string& key, const string& value) override {
        cache[key] = value;
    }
    void erase(const string& key) override {
        cache.erase(key);
    }
};

