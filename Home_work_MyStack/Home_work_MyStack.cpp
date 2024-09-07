﻿/*
Домашнее задание по стекам и очередям
*/
/*
Тема: динамические структуры данных — стек Задание.
Есть строка символов, признаком конца, которой является ;. (на своем примере концем строки взял не ;, а сам конец строки '\n', но при необходимости можно заменить на ';' или другой символ)
В строке могут быть фигурные, круглые, квдратные скобки. (от себя еще добавил угловые скобки <>)
Скобки могут быть открывающими и закрывающими.
Необходимо проверить корректность расстановки скобок.
При этом необходимо, чтобы выполнились следующие правила:
1. Каждая открывающая скобка должна иметь справа такую же закрывающую. Обратное также должно быть верно.
2. Открывающие и закрывающие пары скобок разных типов должны быть правильно расположены по от-ношению друг к другу.
■ Пример правильной строки: ({x-y-z}*[x+2y]-(z+4x));
■ Примернеправильнойстроки:([x-y-z}*[x+2y)-{z+4x)].
Если все правила соблюдены выведите информационное сообщение о корректности строки, иначе покажите строку до места возникновения первой ошибки.
*/


#include <iostream>
#include "MyStack.h"
#include "MyQueue.h"
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main_stack() // выполненное задание со стэком - проверено
{
    setlocale(LC_ALL, "ru");
    
    char bracket[2][4]{ '(','[','{','<',
                        ')',']','}','>' };
    MyStack stackBracket{};
    string mathEquation{};
    int Menu{};
    int exitIndex{-1}; // для возможности выхода из вложенных циклов сразу сразу после нахождения ошибки и сохранения индекса где обнаружена ошибка
    do
    {
        cout << "Меню проверки на корректность открытия и закрытия скобок в арифметическом выражении" << endl;
        cout << "1) Проверить" << endl;
        cout << "0) Выход" << endl;
        cin >> Menu;
        if (Menu)
        {
            stackBracket.Clear();
            cout << "Введите матиматическое выражение с открытием и закрытием скобок: ";
            cin >> mathEquation;
            for (int s = 0; s < mathEquation.size(); s++)
            {
                for (int i = 0; i < 4; i++) // перебор массива открытых скобок разных типов
                {
                    if (mathEquation[s] == bracket[0][i]) // сравнение с открывающими скобками и если находит, то кладем в стэк
                    {
                        stackBracket.Push(mathEquation[s]);
                        break;
                    }
                    else if (mathEquation[s] == bracket[1][i]) // сравнение с закрывающими скобками и если находим то вытаскиваем из стэка открывающую скобку и делаем сравнение на соотвествие типу
                    {
                        if (bracket[0][i] != stackBracket.Pop()) // если несовпадает тип скобки, то завершаем сравнение и выводим индекс строки где была обнаружено не соотвествие правилу открытия и закрытия скобок
                            exitIndex = s;
                        break;
                    }
                }
                if (exitIndex >= 0)
                {
                    break;
                }
            }
            if (exitIndex < 0 && stackBracket.IsEmpty())
            {
                cout << "Математическое уравнение: " << mathEquation << " Составлено верно!" << endl;
            }
            else if (exitIndex >=0)
            {
                cout << "Математическое уравнение: \"" << mathEquation << "\" имеет ошибку в символе под номером - " << exitIndex + 1 << endl;
                cout << "Выводим уравнение до места возникновения ошибки: " << mathEquation.substr(0, exitIndex+1) << endl;
            }
            else
            {
                cout << "Уравнение не имеет следующие закрывающие скобки: ";
                while (!stackBracket.IsEmpty())
                {
                    char bra = stackBracket.Pop();
                    for (int i = 0; i < 4; i++)
                    {
                        if (bra == bracket[0][i])
                        {
                            cout << bracket[1][i] << " ";
                            break;
                        }
                    }
                }
                cout << endl;
            }
        }
        stackBracket.Clear(); // очистка стэка на случай если он дальше будет использоваться, но перед этим забудут его освободить
    } while (Menu != 0);
    

    return 0;
}

/*
Тема: динамические структуры данных — очередь, очередь с приоритетами
Задание 1.
Создать имитационную модель "остановка маршрутных такси". 
Необходимо вводить следующую информацию:
среднее время между появлениями пассажиров на остановке в разное время суток, 
среднее время между появлениями маршруток на остановке в разное время суток,
тип остановки (конечная или нет). 
Необходимо определить: среднее время пребывание человека на остановке,
достаточный интервал времени между приходами маршруток, чтобы на остановке находилось не более N людей одновременно. 
Количество свободных мест в маршрутке является случайной величиной.
*/

//struct Passenger
//{
//    static int count;
//    int idPas{count}; // присваивает порядковый номер 
//    int time{};
//};
//int Passenger::count = 1;
int main_queue()
{
    setlocale(LC_ALL,"ru");
    srand(time(NULL));

    cout << "Программа для определения достаточности интервала времени между приходами маршруток на остановку за пассажирами и избежания переполнения остановки пассажирами" << endl;
    
    int arrivalTimeBusStop{}; // Время прихода пассажира на остановку
    vector<int> averageQueueTime{}; // массив содеоржит среднее время прибывания пассажира на остановке
    int maxN{ 20 }; // Максимальное количество на остановке
    MyQueue<int> bussStop{ maxN }; // очередь на остановку
    int timePass{}; // среднее время на интервал появления пассижиров на остановке от 1 минуты до 5 (или другое которое установит пользователь)
    int timeBuss{}; // средниее время появления маршрутки на остановке 5-10 минут
    int sizeBuss{ 6 };// маршрутка максиму на 6 мест
    bool tipeBussStop{}; // тип остановки 0 - конечная, 1 - обычная
    int measuringTime{ 120 }; // Время замера трафика на остановке для анализа (при желании можно заменить на другой интервал)
    int countExitPass{}; // счетчик пассажиров которые не влезли на остановку и пошли пешком
    int menu{};
    do // для начала выберу вариант конечной остановки, дальше будет приезжать автобус с рандомным количством свободных мест от 1 до 6
    {
        cout << "Меню программы: \n1) Ввод занчений для расчета результатов (в том числе повторный)\n2) Выход из программы" << endl;
        cin >> menu;
        if (menu == 1)
        {
            cout << "Введите среднее время прибытия пассажира на остановку в выбранный период времени: ";
            cin >> timePass;
            cout << "Введите среднее время интервала движения маршрутного такси: ";
            cin >> timeBuss;
            cout << "Выбирите тип остановки 0) конечная 1) обычная: ";
            cin >> tipeBussStop;
            for (int i = 1; i <= measuringTime; i++)
            {
                if (i% timePass == 0)
                {
                    if (bussStop.IsFull())
                    {
                        cout << "Остановка переполнена, пассажир вынужден идти пешком, уменьшите интервал между приходом маршрутного такси!!!" << endl;
                        ++countExitPass;
                    }
                    else
                        bussStop.Add(i);
                }
                if (i % timeBuss == 0) // возможно стоит предусмотреть случай когда на остановку прибывает автобус и новый пассажир и остановка фактически полная в этот момент, но пассажир сможет встать в очередь так как идет посадка
                {
                    if (!tipeBussStop)
                        sizeBuss = 6;
                    else
                        sizeBuss = rand() % 6 + 1;
                    for (int j = 0; j < sizeBuss && !bussStop.IsEmpty(); j++)
                        averageQueueTime.push_back(i - bussStop.Extract()); // записываем в вектор сколько ждал пассижир на остановке для дальнейшего вычисления среднего времени ожидания
                }
            }
            double sum{};
            for (int num : averageQueueTime)
            {
                sum += num;
            }
            double averageWaitTimePass = sum / averageQueueTime.size();
            cout << "Среднее время прибывание пассажира на остановке = " << averageWaitTimePass << " минут." << endl;
            cout << "Интервал движения маршрутного такси = " << timeBuss << ". Среднее время прихода пассажиров на остановку = " << timePass << endl;
            cout << "Всего перевезено пассажиров = " << averageQueueTime.size() << endl;
            if (countExitPass > 0)
            {
                cout << countExitPass << " пассажиров вынуждены пойти пешком из-за переполненной остановки, вам стоит сократить интервал движения маршрутного такси!!!" << endl;
            }
        }
    } while (menu);
    
    


    return 0;
}

/*
Тема: динамические структуры данных — очередь, очередь с приоритетами
Задание 2.
Разработать приложение, имитирующее очередь печати принтера. 
Должны быть клиенты, посылающие запросы на принтер, у каждого из которых есть свой приоритет.
Каждый новый клиент попадает в очередь в зависимости от своего приоритета. 
Необходимо сохранять статистику печати (пользователь, время) в отдельной очереди.
Предусмотреть вывод статистики на экран.
*/
struct MyStruct
{
    enum PRIORITY{GENDIR, BUHG, SECRETAR, MANAG, GOSTI}; // вынести за структуру?
    int prioryEmploy{};
    int ID_Employ{};
    int timeEntry{};
    int timeExit{};
};
int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));

    /*
    создать класс или структуру с данными пользователя : 
    Приоритет через enum, 
    айди пользователя(например это может быть имя пользователя на компьютере), 
    время когда встал в очередь на печать, 
    время когда был напечатан(вышел с очереди).
    Класс с данными пользователями будет уникальным с пустыми полями в времени вхождения и выхода с очереди (данные поля сама очередь будет записывать перед вхождением и после выхода)
    в рамках задачи нужно сделать отдельную очередь статистики печати (пользователь, время)
    При выходе из очереди записывать эти данные в обычную очередь (она у меня уже шаблонизирована)
    Может стоит полностью переделать свою очередь с приоритетом? (надо подумать)
    */


    return 0;
}