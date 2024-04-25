#include <iostream>

int main_4()
{
    setlocale(LC_ALL, "ru");

    std::cout << "Задание #4\nВвести целое число n и вывести 2 в степени 𝑛 , используя битовые операции." << std::endl;
    int Result{2};
    int n{};
    std::cout << "Укажите степень для возведения: ";
    std::cin >> n;
    Result = Result << (n-1);
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
        if ((I&1) == 1)
            ++Num1;
        I = I >> 1;
    }
    std::cout << "В числе " << Num << " всего " << Num1 << " едениц." << std::endl;

    return 0;
}

int main()
{
    setlocale(LC_ALL, "ru");

    std::cout << "Задание #6\nДома у Ксюши было 2 одинаковых набора кубиков из английских букв, но во время очередной уборки один из кубиков затерялся.\nПомогите Ксюше определить, какой из кубиков отсутствует в одном из наборов." << std::endl;


    return 0;
}