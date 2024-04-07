/*
Домашнее задание СДБ 311. Домашнее задание от 16.03.2024
				Структуры
*/

/*
Задание 1:
Создайте структуру, описывающую комплексное число. Реализуйте арифметические операции с комплексными числами: сумму, разность, умножение, деление.

Задание 2:
Реализовать структуру «Автомобиль» (длина, клиренс (высота посадки), объем двигателя, мощность двигателя, диаметр колес, цвет, тип коробки передач). 
Создайте функции для задания значений, отображения значений, поиска значений.

Задание 3:
Разработайтепрограмму «Библиотека». Создайтеструктуру «Книга» ( название,автор, издательство, жанр). 
Создайте массив из 10 книг. Реализуйте для него следующие возможности:
Редактировать книгу Печать всех книг Поиск книг по автору Поиск книги по названию Сортировка массива 
по наз ванию книг Сортировка массива по автору Сортировка массива по издательству 

Задание 4:
Реализовать структуру «Машина» (цвет, модель, номер). Номер машины может представлять из себя или пятизначный номер или слово до 8 символов.
Рекомендации: номер реали зовать как объединение.
Создать экземпляр структуры «Машина» и реализовать для него следующие функции:
Заполнение машины Печать машины Домашнее задание № 8 Создать массив из 10 экземпляров структуры «Машина» и реализовать для него следующие функции:
Редактировать машину Печать всех машин Поиск машины по номеру
*/

#include <iostream>
#include <Windows.h>

//Complex_Number Arithmetic(Complex_Number Z1, Complex_Number Z2, char Arit); // Изначально прототип обьявил до обьявления типа данных по структуре

/*
Шпаргалка по Заданию 1 
Комлпексное число z = a + bi
где a (с) это вещественные числа
b (d) мнимые числа

Сложение (a + bi) + (c + di) = (a + c) + (b + d)i
вычитание (a + bi) - (c + di) = (a - c) + (b - d)i
умножение (a + bi) * (c + di) = (ac – bd) + (ad + bc)i
деление (a + bi) / (c + di) = ((ac + bd)/(cc + dd)) + ((bc - ad)/(cc + dd))i
*/

//		СПИСОК СТРУКТУР		//

struct Complex_Number // Структура комплексного числа (Задание 1)
{
	int RealNum; // Вещественные числа
	int ImaginaryNum; // Мнимые числа
};

struct Car_Characteristic // Задание 2. Структура Автомобиль
{
	char Brand[15]; // Брэнд машины
	char Color[15]; // Цвет
	double LenghtM; // Длина машины
	int CleranceMM; // Клиренс машины
	double EngineVolumeL; // Обьем двигателя
	int WheelDiameterMM; // Диаметр колеса
	char Transmission[5]; // Коробка передачи AT, ASG, CVT, DCT
};

//		ПРОТОТИПЫ ФУНКЦИЙ		//

Complex_Number Arithmetic(Complex_Number Z1, Complex_Number Z2, char Arit); // 1


//		РЕАЛИЗАЦИЯ ФУНКЦИЙ		//

Complex_Number Arithmetic(Complex_Number Z1, Complex_Number Z2, char Arit) // Арифмитическая функция с комплексными числами (Задание 1)
{
	Complex_Number Result;
	if (Arit == '+')
	{
		Result.RealNum = Z1.RealNum + Z2.RealNum;
		Result.ImaginaryNum = Z1.ImaginaryNum + Z2.ImaginaryNum;
	}
	else if (Arit == '-')
	{
		Result.RealNum = Z1.RealNum - Z2.RealNum;
		Result.ImaginaryNum = Z1.ImaginaryNum - Z2.ImaginaryNum;
	}
	else if (Arit == '*')
	{
		Result.RealNum = Z1.RealNum * Z2.RealNum - Z1.ImaginaryNum * Z2.ImaginaryNum;
		Result.ImaginaryNum = Z1.RealNum * Z2.ImaginaryNum + Z1.ImaginaryNum * Z2.RealNum;
	}
	else if (Arit == '/')
	{
		Result.RealNum = (Z1.RealNum * Z2.RealNum + Z1.ImaginaryNum * Z2.ImaginaryNum) / (Z2.RealNum * Z2.RealNum + Z2.ImaginaryNum * Z2.ImaginaryNum);
		Result.ImaginaryNum = (Z1.ImaginaryNum * Z2.RealNum + Z1.RealNum * Z2.ImaginaryNum) / (Z2.RealNum * Z2.RealNum + Z2.ImaginaryNum * Z2.ImaginaryNum);
	}
	return Result;
}

Car_Characteristic Add_Date_Car(Car_Characteristic* ListCar, int* FillSize) // функция ввода данных в структуру (Обновление и добавление)
{
	int MenuF{};
	int MenuDate{};
	std::cout << "Ввести только часть данных (1) или полные данные (2): " << std::endl;
	std::cin >> MenuF;
	switch (MenuF)
	{
	case 1:
		std::cout << "Укажите какие данные хотите изменить:" << std::endl;
		std::cout << "\t1) Брэнд машины" << std::endl;
		std::cout << "\t2) Цвет" << std::endl;
		std::cout << "\t3) Длина машины" << std::endl;
		std::cout << "\t4) Клиренс машины" << std::endl;
		std::cout << "\t5) Обьем двигателя" << std::endl;
		std::cout << "\t6) Диаметр колеса" << std::endl;
		std::cout << "\t7) Коробка передачи" << std::endl;
		std::cin >> MenuDate;
		switch (MenuDate)
		{
		case 1:
			std::cin >> ListCar[*FillSize].Brand;
			break;
		case 2:
			std::cin >> ListCar[*FillSize].Color;
			break;
		case 3:
			std::cin >> ListCar[*FillSize].LenghtM;
			break;
		case 4:
			std::cin >> ListCar[*FillSize].CleranceMM;
			break;
		case 5:
			std::cin >> ListCar[*FillSize].EngineVolumeL;
			break;
		case 6:
			std::cin >> ListCar[*FillSize].WheelDiameterMM;
			break;
		case 7:
			std::cin >> ListCar[*FillSize].Transmission;
			break;
		}
		break;
	case 2:
		std::cout << "Введите Брэнд машины: ";
		std::cin >> ListCar[*FillSize].Brand;
		std::cout << "Введите Цвет машины: ";
		std::cin >> ListCar[*FillSize].Color;
		std::cout << "Введите Длину машины: ";
		std::cin >> ListCar[*FillSize].LenghtM;
		std::cout << "Введите Клиренс машины: ";
		std::cin >> ListCar[*FillSize].CleranceMM;
		std::cout << "Введите Обьем двигателя: ";
		std::cin >> ListCar[*FillSize].EngineVolumeL;
		std::cout << "Введите Диаметр колеса: ";
		std::cin >> ListCar[*FillSize].WheelDiameterMM;
		std::cout << "Введите Коробку передачи: ";
		std::cin >> ListCar[*FillSize].Transmission;
		break;
	}
	return ListCar[*FillSize];
}

void Add_Car(Car_Characteristic* ListCar, int *FillSize, int *PtrS) //Функция добавления данных в пустую ячейку (+ надо реализовать увеличение массива в случае если новые данные могут переполнить массив)
{
	if (*FillSize >= *PtrS)
	{
		// Сдесь будет функция увеличения размера массива в случае если будет перполнение массива(напишу позже)
	}
	ListCar[*FillSize] = Add_Date_Car(ListCar, FillSize);
	*FillSize += 1; // на выходе из функции увеличивается - проверено!
}

void Print_Car(Car_Characteristic* ListCar, int FillSize, int X = 0) // Функция по выводу данных на экран (позже Х = 0 вынести в прототип!!!)
{
	for (int i = X; i < FillSize; i++)
	{
		std::cout << "# " << i +1 << "\tБрэнд Машины: " << ListCar[i].Brand << std::endl;
		std::cout << "\t\tЦвет Машины: " << ListCar[i].Color << std::endl;
		std::cout << "\t\tДлина Машины: " << ListCar[i].LenghtM << std::endl;
		std::cout << "\t\tКлиренс Машины: " << ListCar[i].CleranceMM << std::endl;
		std::cout << "\t\tОбъем двигателя Машины: " << ListCar[i].EngineVolumeL << std::endl;
		std::cout << "\t\tДиаметр колеса Машины: " << ListCar[i].WheelDiameterMM << std::endl;
		std::cout << "\t\tКоробка передачи Машины: " << ListCar[i].Transmission << std::endl;
	}
}

void Menu_Print_Car(Car_Characteristic* ListCar, int FillSize) // Меню частичного или полного вывода данных на экран
{
	int MenuPrint{};
	int I{};
	std::cout << "Меню вывода данных:\n\t1) Вывод всего списка\n\t2) Вывод конкретных данных";
	std::cin >> MenuPrint;
	std::cout << std::endl;
	switch (MenuPrint)
	{
	case 1:
		Print_Car(ListCar, FillSize);
		break;
	case 2:
		std::cout << "Укажите конкретную позицию в базе данных для вывода"; // Позже можно реализовать дополнительно поиск по отдельному элементу и его вывод если будет найден
		std::cin >> I;

		Print_Car(ListCar, I, I);
		break;
	default:
		break;
	}
}

//		ВЫПОЛНЯЕМЫЕ ЗАДАНИЯ		//

int main_1() // Задание 1. 
{
	setlocale(LC_ALL, "ru");

	Complex_Number Z1{}, Z2{}, Result{};
	char Arit{}; // *, /, +, -
	std::cout << "Введите первое вещественное число: ";
	std::cin >> Z1.RealNum;
	std::cout << "Введите первое мнимое число: ";
	std::cin >> Z1.ImaginaryNum;
	std::cout << "Введите второе вещественное число: ";
	std::cin >> Z2.RealNum;
	std::cout << "Введите второе мнимое число: ";
	std::cin >> Z2.ImaginaryNum;
	std::cout << "Укажите арифметическое дейтсвие с комплексными числами: ";
	std::cin >> Arit;
	Result = Arithmetic(Z1, Z2, Arit);
	std::cout << "Результат арифметических действий: Вещественное число = " << Result.RealNum << std::endl;
	std::cout << "Мнимое число = " << Result.ImaginaryNum << std::endl;

	return 0;
}

int main()
{
	setlocale(LC_ALL, "ru");

	int Size{ 10 };
	int* PtrS{nullptr};
	PtrS = &Size;
	Car_Characteristic Ford{ "Ford", "Blue", 3.7, 145, 1.5, 600, "AT" };
	Car_Characteristic Reno{ "Reno", "Read", 3.9, 140, 1.6, 650, "AT" };
	Car_Characteristic Mersedes{ "Mersedes", "Black", 4.5, 120, 2.5, 700, "AT" };
	Car_Characteristic Tuareg{ "Tuareg", "Green", 3.5, 120, 1.2, 500, "AT" };
	Car_Characteristic Kia{ "Kia", "Yellow", 3.7, 145, 1.5, 600, "AT" };
	Car_Characteristic* ListCar = new Car_Characteristic[Size]; // Динамический массив структуры
	ListCar[0] = Ford; ListCar[1] = Kia; ListCar[2] = Tuareg; ListCar[3] = Mersedes; ListCar[4] = Reno;
	int FillSize{ 5 };
	int Menu{};
	do
	{
		std::cout << "Меню взаимодействия по Базе данных Автомобилей: " << std::endl;
		std::cout << "\t1) Добавить новую машину." << std::endl;
		std::cout << "\t2) Вывод списка машин." << std::endl;
		std::cout << "\t3) Поиск машины по определенной характеристике." << std::endl;
		std::cout << "\t4) Редактирование информации конкретной машины." << std::endl;
		std::cout << "\t0) Выход." << std::endl;
		std::cin >> Menu;
		switch (Menu)
		{
		case 1:
			Add_Car(ListCar, &FillSize, PtrS);
			break;
		case 2:
			Menu_Print_Car(ListCar, FillSize);
			break;
		default:
			break;
		}
	} while (Menu!=0);

	return 0;
}