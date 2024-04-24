#include <iostream>

int main()
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