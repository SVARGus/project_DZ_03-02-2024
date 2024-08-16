/*
Домашнее задание про водоемы
*/

/*
Тема: Константная функция-член, explicit конструктор.
Задание.
Разработать класс Reservoir(водоем). Класс должен обязательно иметь поле «название». 
Класс должен содержать: конструктор по умолчанию, конструктор с параметрами,
при необходимости реализовать деструктор и конструктор копирования.

Добавить методы для:
1. Определения приблизительного объема (ширина*длина*максимальная глубина);
2. Определения площади водной поверхности;
3. Метод для проверки относятся ли водоемы к одному типу (море-море; бассейн-пруд);
4. Для сравнения площади водной поверхности водоемов одного типа;
5. Для копирования объектов;
6. Остальные методы на усмотрение разработчика (методы set и get).

Написать интерфейс для работы с классом. 
Реализовать динамический массив объектов класса с возможностью добавления, удаления объектов из массива.
Реализовать возможность записи информации об объектах массива в текстовый файл, бинарный файл.
Используйте explicit конструктор и константные функциичлены (например, для отображения данных о водоёме и т.д.).

*/

#include <iostream>
#include"Reservoir.h"

using std::cout;
using std::cin;
using std::string;

void addArrey(Reservoir*& reservoir, int& sizeReservoir, int typeReservoir = 0);
std::string printTypeReservoir(const int typeReservoir);
void menuInterection(Reservoir*& reservoir, int& sizeReservoir, const int typeReservoir);
void delItemArray(Reservoir*& reservoir, int& sizeReservoir, int typeReservoir);
void joinAreaReservoir(Reservoir*& reservoir, const Reservoir* addReservoir, int& sizeReservoir, const int sizeAddReservoir);

void addArrey(Reservoir*& reservoir, int& sizeReservoir, int typeReservoir) // Функция добавления данных в базу
{
    int num{};
    string name{};
    ++sizeReservoir;
    Reservoir* newReservoir = new Reservoir[sizeReservoir];
    if (reservoir != nullptr)
    {
        for (int i = 0; i < sizeReservoir - 1; ++i)
        {
            newReservoir[i] = reservoir[i];
        }
    }
    cout << "Укажите название " << printTypeReservoir(typeReservoir) << ": ";
    cin >> name;
    newReservoir[sizeReservoir - 1].setNameReservoir(name);
    cout << "Укажите длину " << printTypeReservoir(typeReservoir) << " в километрах: ";
    cin >> num;
    newReservoir[sizeReservoir - 1].setLength(num);
    cout << "Укажите ширину " << printTypeReservoir(typeReservoir) << " в километрах: ";
    cin >> num;
    newReservoir[sizeReservoir - 1].setWidth(num);
    cout << "Укажите максимальную глубину " << printTypeReservoir(typeReservoir) << " в метрах: ";
    cin >> num;
    newReservoir[sizeReservoir - 1].setMaxDepth(num);
    if (typeReservoir != 0)
        newReservoir[sizeReservoir - 1].setTypeReservoit(typeReservoir);
    else
    {
        cout << "1) автоматически определить тип водоема\n";
        cout << "2) самостоятельно указать тип водоема\n";
        cout << "Выберите вариант: ";
        cin >> num;
        switch (num)
        {
        case 1:
            newReservoir[sizeReservoir - 1].definitTypeReservoir();
            break;
        case 2:
            cout << "Укажите тип водоема\n";
            cout << "1) Лужи \n";
            cout << "2) Пруды \n";
            cout << "3) Озера \n";
            cout << "4) Моря \n";
            cout << "5) Океаны \n";
            cin >> num;
            newReservoir[sizeReservoir - 1].setTypeReservoit(num);
        }
    }
    delete[] reservoir;
    reservoir = newReservoir;
}

void delItemArray(Reservoir*& reservoir, int& sizeReservoir, int typeReservoir)
{
    if (reservoir == nullptr)
    {
        cout << "База пуста и удалять нечего!!!" << endl;
        return;
    }
    int num{};
    cout << "Какие данные удалить? укажите индекс от 0 и до " << sizeReservoir - 1 << endl;
    cin >> num;
    while (num < 0 || num >= sizeReservoir)
    {
        cout << "Вы неверно указали индекс, повторите ввод: ";
        cin >> num;
    }
    Reservoir* newReservoir = new Reservoir[sizeReservoir-1];
    for (int i = 0, j = 0; j < sizeReservoir; ++i, ++j)
    {
        if (i != num)
        {
            newReservoir[i] = reservoir[j];
        }
        else
        {
            newReservoir[i] = reservoir[++j];
        }
    }
    delete[] reservoir;
    --sizeReservoir;
    reservoir = newReservoir;
}

std::string printTypeReservoir(const int typeReservoir)
{
    switch (typeReservoir)
    {
    case 0:
        return "Водоема";
        break;
    case 1:
        return "Лужи";
        break;
    case 2:
        return "Пруда";
        break;
    case 3:
        return "Озера";
        break;
    case 4:
        return "Моря";
        break;
    case 5:
        return "Океана";
    }
}

void menuInterection(Reservoir*& reservoir, int & sizeReservoir, const int typeReservoir)
{
    int I, J{};
    int menu{};
    cout << "Меню взаимодействия с " << printTypeReservoir(typeReservoir) << endl;
    cout << "1) Добавить данные \n2) Удалить данные \n3) напечатать базу \n4) Полностью удалить базу \n5) Сравнить площадь водоемов" << endl;
    cin >> menu;
    switch (menu)
    {
    case 1:
        addArrey(reservoir, sizeReservoir, typeReservoir);
        break;
    case 2:
        delItemArray(reservoir, sizeReservoir, typeReservoir);
        break;
    case 3:
        if (reservoir == nullptr)
            break;
        for (int i = 0; i < sizeReservoir; ++i)
        {
            reservoir[i].printReservoir();
        }
        cout << "Размер -------- " << sizeReservoir << endl;
        break;
    case 4:
        delete[] reservoir;
        sizeReservoir = 0;
        break;
    case 5:
        cout << "Укажите индексы для сравнения: ";
        cin >> I;
        cin >> J;
        if (!reservoir[I].compareTypeReservoir(reservoir[J]))
        {
            cout << "Водоемы относятся к разному типу!!!" << endl;
        }
        if (reservoir[I].compareAreaReservoir(reservoir[J]))
            cout << "Водоем " << reservoir[I].getNameReservoir() << " имеет большую площадь по отношению к " << reservoir[J].getNameReservoir() << endl;
        else
            cout << "Водоем " << reservoir[I].getNameReservoir() << " имеет меньшую площадь по отношению к " << reservoir[J].getNameReservoir() << endl;
    }
}

void joinAreaReservoir(Reservoir*& reservoir, const Reservoir* addReservoir, int& sizeReservoir, const int sizeAddReservoir)
{
    Reservoir* newReservoir = new Reservoir[sizeReservoir + sizeAddReservoir];
    for (int i = 0, j = 0; i < (sizeReservoir + sizeAddReservoir); ++i)
    {
        if (i < sizeReservoir)
        {
            newReservoir[i] = reservoir[i];
        }
        else
        {
            newReservoir[i] = addReservoir[j];
            ++j;
        }
    }
    delete[] reservoir;
    reservoir = newReservoir;
    sizeReservoir += sizeAddReservoir;
}

int main()
{
    setlocale(LC_ALL, "ru");

    cout << "База водоемов мира!" << endl;
    cout << "Градация водоемов: \n";
    cout << "1) Лужи \n";
    cout << "2) Пруды \n";
    cout << "3) Озера \n";
    cout << "4) Моря \n";
    cout << "5) Океаны \n";
    // далее базовые базы некоторых водоемов, для теста
    int sizeOcean = 5;
    Reservoir* Ocean = new Reservoir[sizeOcean]{ {"Atlantic", 6110, 15000, 8742, 5},{"Indian", 8000, 9520, 7729, 5},{"Arctic", 3800, 3880, 5527, 5},{"Pacific", 14000, 12760, 10994, 5},{"Southern", 4600, 4420, 72335, 5}};
    int sizeSea = 5;
    Reservoir* Sea = new Reservoir[sizeSea]{ {"Black", 646, 653, 2210, 4},{"Azov", 126, 39, 13, 4},{"Baltic", 412, 1016, 470, 4},{"Barents", 1256, 1133, 600, 4},{"White", 259, 347, 350, 4} };
    int sizeLake{};
    Reservoir* Lake{ nullptr };
    int sizePond{};
    Reservoir* Pond{ nullptr };
    int sizePuddle{};
    Reservoir* Puddle{ nullptr };
    int sizeNewBaseReservoir{};
    Reservoir* NewBaseReservoir{ nullptr };
  
    
    int menu{};
    do
    {
        cout << "Меню взаимодействия с базой водоемов" << endl;
        cout << "0) Взаимодействие с общей базой \n"; // сделать для 0-5 пункта отдельную фунцкцию с возможностью выбора добавления или удаления данных и полной очисткой, а также печатью
        cout << "1) Взаимодействие с базой Луж\n";
        cout << "2) Взаимодействие с базой Прудов\n";
        cout << "3) Взаимодействие с базой Озер\n";
        cout << "4) Взаимодействие с базой Морей\n";
        cout << "5) Взаимодействие с базой Океанов\n";
        cout << "6) Объединение всех баз в общую\n";
        cout << "7) Выход\n";
        cout << "Выберите пункт меню: ";
        cin >> menu;
        switch (menu)
        {
        case 0:
            menuInterection(NewBaseReservoir, sizeNewBaseReservoir, menu);
            break;
        case 1:
            menuInterection(Puddle, sizePuddle, menu);
            break;
        case 2:
            menuInterection(Pond, sizePond, menu);
            break;
        case 3:
            menuInterection(Lake, sizeLake, menu);
            break;
        case 4:
            menuInterection(Sea, sizeSea, menu);
            break;
        case 5:
            menuInterection(Ocean, sizeOcean, menu);
            break;
        case 6:
            if (Puddle != nullptr)
                joinAreaReservoir(NewBaseReservoir, Puddle, sizeNewBaseReservoir, sizePuddle);
            if (Pond != nullptr)
                joinAreaReservoir(NewBaseReservoir, Pond, sizeNewBaseReservoir, sizePond);
            if (Lake != nullptr)
                joinAreaReservoir(NewBaseReservoir, Lake, sizeNewBaseReservoir, sizeLake);
            if (Sea != nullptr)
                joinAreaReservoir(NewBaseReservoir, Sea, sizeNewBaseReservoir, sizeSea);
            if (Ocean != nullptr)
                joinAreaReservoir(NewBaseReservoir, Ocean, sizeNewBaseReservoir, sizeOcean);
            break;
        default:
            break;
        }
    } while (menu != 7);


    // удаление динамических данных
    delete[] Ocean;
    delete[] Sea;
    delete[] Lake;
    delete[] Pond;
    delete[] Puddle;
    delete[] NewBaseReservoir;

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
