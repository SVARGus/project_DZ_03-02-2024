/*
Домашнее задание СДБ 311. Домашнее задание от 16.03.2024
				Многомерные динамические массивы
*/

#include <iostream>
#include <cstring>
#include <windows.h> 
//#include <cstdio>
//#include <fstream> //!!!!!

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

Car_Characteristic Add_Date_Car(Car_Characteristic* ListCar, int* FillSize) // функция ввода данных в структуру (Обновление и добавление)
{
	int MenuF{};
	int MenuDate{};
	std::cout << "Ввести (Изменить) только часть данных (1) или полные данные (2): " << std::endl;
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

void Expan_Car_Array(Car_Characteristic* ListCar, int* PtrS) // Функция увеличения размера массива на 10. Нужно проверить!!!
{
	int NewSize = *PtrS + 10;
	Car_Characteristic* NewListCar = new Car_Characteristic[NewSize];
	for (int i = 0; i < *PtrS; i++)
	{
		NewListCar[i] = ListCar[i];
	}
	delete[]ListCar;
	ListCar = NewListCar;
	*PtrS = NewSize;
}

void Add_Car(Car_Characteristic* ListCar, int* FillSize, int* PtrS) //Функция добавления данных в пустую ячейку (+ надо реализовать увеличение массива в случае если новые данные могут переполнить массив)
{
	if (*FillSize >= *PtrS)
	{
		Expan_Car_Array(ListCar, PtrS); // Сдесь будет функция увеличения размера массива в случае если будет перполнение массива(напишу позже)
	}
	ListCar[*FillSize] = Add_Date_Car(ListCar, FillSize);
	*FillSize += 1; // на выходе из функции увеличивается - проверено!
}

void Print_Car(Car_Characteristic* ListCar, int FillSize, int X = 0) // Функция по выводу данных на экран (позже Х = 0 вынести в прототип!!!)
{
	for (int i = X; i < FillSize; i++)
	{
		std::cout << "# " << i + 1 << "\tБрэнд Машины: " << ListCar[i].Brand << std::endl;
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


/*
Надо задать глобальный ENUM {BRAND, COLOR,...} и уже его передавать в функцию м в функции сделать switch по энаму (попробовать еще локальный енам)
*/
template<class D>
void Search_Car(Car_Characteristic* ListCar, int FillSize, D* Name) // Функция поиска Не уверен что правильно, надо поискать как правильно передать. НЕ ГОТОВА!!!
{
	return;
}

/*
Функция поиска в массиве данных Машин. Будет выводит полный список найденных данных.
Но если X != 0, то пользователь может выбрать кокретный элемент для взаимеодействия с другими функциями (будет выводить i для ListCar[i])
*/


//		ВЫПОЛНЯЕМЫЕ ЗАДАНИЯ		//

int main()
{
	setlocale(LC_ALL, "ru");

	int Size{ 10 };
	int* PtrS{ nullptr };
	PtrS = &Size;
	//Car_Characteristic Ford{ "Ford", "Blue", 3.7, 145, 1.5, 600, "AT" };
	//Car_Characteristic Reno{ "Reno", "Read", 3.9, 140, 1.6, 650, "AT" };
	//Car_Characteristic Mersedes{ "Mersedes", "Black", 4.5, 120, 2.5, 700, "AT" };
	//Car_Characteristic Tuareg{ "Tuareg", "Green", 3.5, 120, 1.2, 500, "AT" };
	//Car_Characteristic Kia{ "Kia", "Yellow", 3.7, 145, 1.5, 600, "AT" };
	//Car_Characteristic* ListCar = new Car_Characteristic[Size]; // Динамический массив структуры
	//ListCar[0] = Ford; ListCar[1] = Kia; ListCar[2] = Tuareg; ListCar[3] = Mersedes; ListCar[4] = Reno;
	//// Начало временного кода
	//Car_Characteristic Ford2{ "Ford2", "Blue", 3.7, 145, 1.5, 600, "AT" };
	//Car_Characteristic Reno2{ "Reno2", "Read", 3.9, 140, 1.6, 650, "AT" };
	//Car_Characteristic Mersedes2{ "Mersedes2", "Black", 4.5, 120, 2.5, 700, "AT" };
	//Car_Characteristic Tuareg2{ "Tuareg2", "Green", 3.5, 120, 1.2, 500, "AT" };
	//Car_Characteristic Kia2{ "Kia2", "Yellow", 3.7, 145, 1.5, 600, "AT" };
	//ListCar[5] = Ford2; ListCar[6] = Kia2; ListCar[7] = Tuareg2; ListCar[8] = Mersedes2; ListCar[9] = Reno2;
	//// конец временного кода




	//FILE* myFile;
	////myFile = fopen("mydate.txt", "w");
	//if ((fopen_s(&myFile, "mydate.txt", "w")) != NULL)
	//{
	//	std::cout << "Файл не создан" << std::endl;
	//}
	//else
	//{
	//	fprintf(myFile, "%d ", Size);
	//	fprintf(myFile, "\n");
	//	for (int i = 0; i < Size; i++)
	//	{
	//		fprintf(myFile, "%s ", ListCar[i].Brand);
	//		fprintf(myFile, "%s ", ListCar[i].Color);
	//		fprintf(myFile, "%f ", ListCar[i].LenghtM);
	//		fprintf(myFile, "%d ", ListCar[i].CleranceMM);
	//		fprintf(myFile, "%f ", ListCar[i].EngineVolumeL);
	//		fprintf(myFile, "%d ", ListCar[i].WheelDiameterMM);
	//		fprintf(myFile, "%s ", ListCar[i].Transmission);
	//		fprintf(myFile, "\n");
	//	}
	//	if (fclose(myFile) == EOF)
	//	{
	//		std::cout << "NOT Clossed" << std::endl;
	//	}
	//	else
	//	{
	//		std::cout << " Clossed" << std::endl;
	//	}
	//	//fclose(myFile);
	//}
	//// Запись работает, Изучить как правильно записывать формат данных


	Car_Characteristic* ListCar{ nullptr };
	FILE* readFile;
	if (fopen_s(&readFile, "mydate.txt", "r") != NULL)
	{
		std::cout << "ERROR" << std::endl;
	}
	else
	{
		fscanf_s(readFile, "%d ", &Size);
		fscanf_s(readFile, "\n");
		ListCar = new Car_Characteristic[Size];
		for (int i = 0; i < Size; i++)
		{
			//fscanf_s(readFile, "%s %s %f %d %f %d %s", ListCar[i].Brand, ListCar[i].Color, ListCar[i].LenghtM, ListCar[i].CleranceMM, ListCar[i].EngineVolumeL, ListCar[i].WheelDiameterMM, ListCar[i].Transmission);

			fscanf_s(readFile, "%s ", ListCar[i].Brand, sizeof(ListCar[i].Brand));
			fscanf_s(readFile, "%s ", ListCar[i].Color, sizeof(ListCar[i].Color));
			fscanf_s(readFile, "%lf ", &ListCar[i].LenghtM); // Долго мучался как правильно считать данные типа double и этот вариант верный
			fscanf_s(readFile, "%d ", &ListCar[i].CleranceMM);
			fscanf_s(readFile, "%lf ", &ListCar[i].EngineVolumeL); // Долго мучался как правильно считать данные типа double и этот вариант тоже верный
			fscanf_s(readFile, "%d ", &ListCar[i].WheelDiameterMM);
			fscanf_s(readFile, "%s ", ListCar[i].Transmission, sizeof(ListCar[i].Transmission));
		}
		fclose(readFile);
	}

	// Считывание из файла работает, но намучался разбираясь в тонкостях. Но требуется изучить как правильно как правильно определять размер строки если он в структуре изначально не константный



	int FillSize{ 5 }; // для временного кода заменить на 10, чтобы проверить увеличение массива при добавлении новой строки
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
	} while (Menu != 0);

	return 0;
}