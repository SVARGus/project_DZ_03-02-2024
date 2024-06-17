/*
Тема: Конструкторы, деструкторы 

Задание.

Создайте приложение "Телефонная книга". Необходимо хранить данные об абоненте (ФИО, домашний телефон, рабочий телефон, мобильный телефон, дополнительная информация о контакте) 
внутри соответствующего клас-са. Наполните класс переменными-членами, функция-ми-членами, конструкторами,inline-функциями-членами, используйте инициализаторы, реализуйте деструктор.
Обязательно необходимо выделять динамически память под ФИО. Предоставьте пользователю возможность до-бавлять новых абонентов, удалять абонентов, искать або-нентов по ФИО, 
показывать всех абонентов, сохранять информацию в файл и загружать из файла.
*/

#include <iostream>
#include "PagePhoneBook.h"

int PagePhoneBook::Size = 0;

int main()
{
    setlocale(LC_ALL, "ru");

    char Name[15]{}; // Имя
    char Phone[15]{}; // Отчество
    
    unsigned short BirthDay; // День рождения
    unsigned short BirthMounth; // Месяц рождения
    unsigned short BirthYear; // Год рождения
    

    PagePhoneBook* first{ nullptr }; // возможно лишнее
    int Menu{};
    bool Add{};
    int i{};
    PagePhoneBook* PhoneBook{ nullptr };

    // в будущем реализовать автозагрузку базы телефонной книжки совместно с созданием массива PhoneBook

    do
    {
        std::cout << "Меню записной телефонной книжки\n";
        std::cout << "1) Добавить новый контакт\n";
        std::cout << "2) Изменить определенный контакт\n";
        std::cout << "3) Удалить определенный контакт\n";
        std::cout << "4) Вывести на печать всю телефонную книгу или определенный контакт\n";
        std::cout << "5) Отсортировать телефонную книгу по Имени\n";
        //std::cout << "6)\n";
        std::cout << "0) Выход\n";
        std::cin >> Menu;
        switch (Menu)
        {
        case 1:
            std::cout << "укажите Имя: ";
            std::cin >> Name;
            std::cout << "укажите Сотовый телефон: ";
            std::cin >> Phone;
            first = new PagePhoneBook{ Name, Phone };
            std::cout << "Добавить дополнительные данные? 1 - Да 0 - НЕТ ";
            std::cin >> Add;
            if (Add)
                first->setAddInPage();
            std::cout << "Маркер static Size: " << PagePhoneBook::getSize() << std::endl; // Временно для проверки
            
            PhoneBook = PhoneBook->setPageAppEnd(PhoneBook, first); // некорректно работает
            first = nullptr;
            break;
        case 2:
            std::cout << "изменить контакт под # ";
            std::cin >> i;
            std::cout << "Маркер static Size: " << PagePhoneBook::getSize() << std::endl; // Временно для проверки
            if (i < PagePhoneBook::getSize())
                PhoneBook[i].setAddInPage();
            else
                std::cout << "Данный контакт отсутствует в записной книжке!" << std::endl;
            break;
        case 3:
            std::cout << "Удалить контакт под номером # ";
            std::cin >> i;
            if (i < PagePhoneBook::getSize())
                PhoneBook = PhoneBook->setPageDell_i(PhoneBook, i); // добавить метод удаления контакта со сдвигом
            else
                std::cout << "Данный контакт отсутствует в записной книжке!" << std::endl;
            break;
        case 4:
            std::cout << "Вывести все конткты 1) Да 0) Нет ";
            std::cin >> Add;
            if (Add)
            {
                for (int j = 0; j < PagePhoneBook::getSize(); j++)
                {
                    std::cout << "Контакт #" << j << std::endl;
                    PhoneBook[j].printPageBook();
                }
            }
            else
            {
                std::cout << "Какой контакт вывести на печать? ";
                std::cin >> i;
                if (i < PagePhoneBook::getSize())
                    PhoneBook[i].printPageBook();
                else
                    std::cout << "Данный контакт отсутствует в записной книжке!" << std::endl;
            }
            break;
        case 5:
            PhoneBook->sortNameBook(PhoneBook);
            break;
       /* case 6:
            break;*/
        }
    } while (Menu!=0);
    /*int size{};*/
    if (first != nullptr)
        delete first;
    if (PhoneBook != nullptr)
        delete[] PhoneBook;

    return 0;
}