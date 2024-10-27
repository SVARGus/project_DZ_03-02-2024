/*
https://oop.afti.ru/tasks/kesh-strategiya
на 6 выполнить диаграмму классов
на 8 написать в виде кода реалицию классов с определение методов
(методы не реализуем)
на 10+ релаизовать полностью код для данного задания
Задание
1. Реализовать класс кэш. Примерный интерфейс:

class BaseCache {
public:
    virtual bool has(const std::string &key) = 0;
    virtual std::string read(const std::string &key) = 0;
    virtual void write(const std::string &key, const std::string &value) = 0;
    virtual void delete(const std::string &key) = 0;
};
2. Реализовать четыре типа поведения (стратегий)

MemoryCache - данные хранятся в unordered_map (или map, если не с++11)

FileCache - данные хранятся в файлах на диске. По ключу генерируется хэш
(можно использовать ранее реализованные студентом хэш-функции),
который является именем файла. В файлах хранятся tab separated
пары ключ-значения (ключи нужны для резолвинга коллизий)

Пример файла:

vasja   +79454585688
petja   +79499585688

NullCache - кэш ничего не хранит, а запись происходит дико быстро
(составить только описание класса без реализации)

PoorManMemoryCache - кэш хранит последние N записанных ключей

3. Реализовать класс, который будет использовать одну из стратегий

class CacheApplier {
public:
    void set_strategy(BaseCache& strategy);

    std::string read_from_cache(const std::string &key);
    void write_from_cache(const std::string &key, const std::string &value)
    void delete_from_cache(const std::string &key); // Удалить из cache
};
и применить его в программе.
*/

#include <iostream>
#include "CacheApplier.h"
#include "MemoryCache.h"
#include "FileCache.h"
#include "PoorManMemoryCache.h"
#include "NullCache.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
    setlocale(LC_ALL, "ru");

    CacheApplier cacheManager;

    MemoryCache memoryCache;
    FileCache fileCache;
    PoorManMemoryCache poorManMemoryCache(4);
    NullCache nullCache;

    cout << "Выберите стратегию записи кэша" << endl;
    cout << "1) memoryCache \n2 fileCache \n3) poorManMemoryCache \n4) nullCache \n";
    int cach{};
    cin >> cach;
    switch (cach)
    {
    case 1:
        cacheManager.set_strategy(memoryCache);
        break;
    case 2:
        cacheManager.set_strategy(fileCache);
        break;
    case 3:
        cacheManager.set_strategy(poorManMemoryCache);
        break;
    case 4:
        cacheManager.set_strategy(nullCache);
        break;
    }
    cacheManager.write_from_cache("key1", "value1");
    cacheManager.write_from_cache("key2", "value2");
    cacheManager.write_from_cache("key3", "value3");
    cacheManager.write_from_cache("key4", "value4");
    cacheManager.write_from_cache("key5", "value5");
    cacheManager.write_from_cache("key6", "value6");
    cacheManager.write_from_cache("key7", "value7");
    cacheManager.write_from_cache("key8", "value8");

    std::cout << "PoorManMemoryCache key1: " << cacheManager.read_from_cache("key1") << std::endl;
    std::cout << "PoorManMemoryCache key3: " << cacheManager.read_from_cache("key3") << std::endl;
    std::cout << "PoorManMemoryCache key7: " << cacheManager.read_from_cache("key7") << std::endl;
    std::cout << "PoorManMemoryCache key9: " << cacheManager.read_from_cache("key9") << std::endl;


    return 0;
}