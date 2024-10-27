#pragma once
#include "BaseCache.h"
#include <iostream>

using std::string;

class CacheApplier
{
    BaseCache* strategy = nullptr;
public:
    void set_strategy(BaseCache& newStrategy) {
        strategy = &newStrategy;
    }
    string read_from_cache(const string& key) {
        if (strategy && strategy->has(key))
        {
            return strategy->read(key);
        }
        return "Key not found in chach";
    }
    void write_from_cache(const string& key, const string& value) {
        if (strategy)
        {
            strategy->write(key, value);
        }
    }
    void delete_from_cache(const string& key) {
        if (strategy)
        {
            strategy->erase(key);
        }
    }
};

