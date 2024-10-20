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

int main()
{
    std::cout << "Hello World!\n";
}