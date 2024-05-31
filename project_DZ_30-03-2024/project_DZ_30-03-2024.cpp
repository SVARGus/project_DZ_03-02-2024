#include <iostream>

void Print(char ABC[], int SIZE);


union MyUnion
{
    int Num;
    char Sumb[sizeof(int)];
};

void Print_Num_XX(int S)
{
    if (S == 0)
        return;
    S >>= 1;
    Print_Num_XX(S);
    std::cout << (S & 1);
    /*while (S != 0)
    {
        std::cout << (S & 1);
        S >>= 1;
    }*/
}

int main() // Задание 1
{
    setlocale(LC_ALL, "ru");

    MyUnion S;
    int Menu{};
    do
    {
        std::cout << "1) Ввести целое число;\n2) Просмотреть все байты числа;\n3) Просмотреть выбранный байт числа;\n4) Вывод байтов числа в двоичном и шестнадцатеричном виде.\n0 Выход" << std::endl;
        std::cout << "Укажите пункт меню: ";
        std::cin >> Menu;
        unsigned char byte{};
        int I{};
        switch (Menu)
        {
        case 1:
            std::cin >> S.Num;
            break;
        case 2:
            std::cout << "Посмотрим все байты числа " << S.Num << ": ";
            for (int i = 0; i < sizeof(S.Num); i++)
            {
                byte = (S.Num >> (i * 8)) & 0xFF;
                std::cout << "Байт " << i << " = " << (int)byte << std::endl;
            }
            break;
        case 3:
            std::cout << "Какой байт желаете посмотреть? ";
            std::cin >> I;
            std::cout << "Выбранный вами байт " << I << " = " << (int)S.Sumb[I] << std::endl;
            break;
        case 4:
            std::cout << "Выведем число " << S.Num << " в двоичной системе: "; Print_Num_XX(S.Num); // в двоичной системе некорректно выводится, надо проверить что не так делаю
            // например число 589789 в двоичной системе выводит как 01000111111111101110, а должно быть 10001111111111011101 - теряется бит в конце и добавляется 0 в начале!
            std::cout << " и в шестнадцатиричной системе: " << std::hex << S.Num << std::dec << std::endl; // проверил - работает!
            break;
        default:
            break;
        }
    } while (Menu != 0);

    return 0;
}


int main_4()
{
    setlocale(LC_ALL, "ru");

    std::cout << "Задание #4\nВвести целое число n и вывести 2 в степени 𝑛 , используя битовые операции." << std::endl;
    int Result{ 2 };
    int n{};
    std::cout << "Укажите степень для возведения: ";
    std::cin >> n;
    Result = Result << (n - 1);
    std::cout << Result << std::endl;

    return 0;
}

int main_5()
{
    setlocale(LC_ALL, "ru");

    std::cout << "Задание #5\nНайти количество единиц в двоичном представлении целого положительного числа." << std::endl;
    int Num{};
    int I{};
    std::cout << "Введите любое целое положительно число для вычисления количества едениц в двоичной системе: ";
    std::cin >> Num;
    I = Num;
    int Num1{};
    while (I != 0)
    {
        if ((I & 1) == 1)
            ++Num1;
        I = I >> 1;
    }
    std::cout << "В числе " << Num << " всего " << Num1 << " едениц." << std::endl;

    return 0;
}

void Print(char ABC[], int SIZE)
{
    for (int i = 0; i < SIZE; i++)
        std::cout << ABC[i] << " ";
    std::cout << std::endl;
}

int main_6()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));

    std::cout << "Задание #6\nДома у Ксюши было 2 одинаковых набора кубиков из английских букв, но во время очередной уборки один из кубиков затерялся.\nПомогите Ксюше определить, какой из кубиков отсутствует в одном из наборов." << std::endl;
    const int SIZE{ 26 };
    char ABC[SIZE]{ 'a' };
    char ABCloss[SIZE - 1]{};
    int loss{};
    char Loss_abc{};
    loss = rand() % (SIZE + 1); // Рандомно определяет какой кубик потерян
    for (int i = 1; i < SIZE; i++) // Заполняем набор кубиками с английскими буквами попорядку
        ABC[i] = ABC[i - 1] + 1;
    for (int i = 0, k = 0; i < SIZE; i++, k++) // Заполняем второй набор кубиками, но один кубик рандомно потерян
    {
        if (i == loss)
            ++i;
        ABCloss[k] = ABC[i];
    }
    std::cout << "Выведем кубики из полного набора: ";
    Print(ABC, SIZE);
    std::cout << "Также выведем кубики из набора с одним потеренным кубиком: ";
    Print(ABCloss, SIZE - 1);
    for (int i = 0; i < SIZE; i++)
    {
        if (i < SIZE - 1)
            Loss_abc ^= ABCloss[i] ^ ABC[i];
        else
            Loss_abc ^= ABC[i];
    }
    std::cout << "Потерен кубик: " << Loss_abc << std::endl;

    return 0;
}