#pragma once
#include "BaseCache.h"
#include <iostream>
#include <vector>

using std::string;
using std::vector;
using std::pair;

class PoorManMemoryCache : public BaseCache
{
    int maxSize{};
    vector<pair<string, string>> cache{};
public:
    explicit PoorManMemoryCache (int N) : maxSize { N } {}
    bool has(const string& key) override {
        for (const auto &entry : cache)
        {
            if (entry.first == key) { return true; }
        }
        return false;
    }
    string read(const string& key) override {
        for (const auto& entry : cache)
        {
            if (entry.first == key) { return entry.second; }
        }
        return "";
    }
    void write(const string& key, const string& value) override {
        if (cache.size() == maxSize)
        {
            cache.erase(cache.begin());
        }
        cache.emplace_back(key, value);
    }
    void erase(const string& key) override {
        for (auto it = cache.begin(); it != cache.end(); ++it)
        {
            if (it->first == key)
            {
                cache.erase(it);
                return;
            }
        }
    }
};

