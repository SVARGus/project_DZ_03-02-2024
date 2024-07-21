#include "HomeApartmentPerson.h"

// Методы Персоны

Person::Person(std::string fio, int age) : fio{ fio }, age {age} {}

//std::string Person::getFIO () const
//{
//	return fio;
//}
//int Person::getAge() const
//{
//	return age;
//}
void Person::print() const
{
	std::cout << "ФИО " << fio << ", возраст - " << age << std::endl;
}
std::istream& operator>> (std::istream& input, Person& person)
{
	std::getline(std::cin, person.fio);
	input >> person.age;
	std::cin.ignore();
	return input;
}
Person& Person::operator= (const Person& person)
{
	this->fio = person.fio;
	this->age = person.age;
	return *this;
}


// Методы Квартиры

Apartment::Apartment(int room) : appartNumber{count}, room {room}
{
	switch (room)
	{
	case 1:
		sizePerson = 3;
		person = new Person[sizePerson];
		break;
	case 2:
		sizePerson = 4;
		person = new Person[sizePerson];
		break;
	case 3:
		sizePerson = 6;
		person = new Person[sizePerson];
		break;
	default: // надо продумать блок на случай если пользователь укажет более 3 комнат в квартире!
		break;
	}
	++count;
}
void Apartment::print() const
{
	std::cout << "Номер квартиры: " << appartNumber << ". Количество комнат: " << room << std::endl;
	for (int i = 0; i < sizePerson; i++)
	{
		// прописать условие вывода только прописанные персоны
		person[i].print();
	}
}

void Apartment::freeRegistrPerson(Person* person) // Переделал и Работает // ОК
{
	// поиск определенной квартиры надо реализовать в классе дома и уже вызывать данный метод для правки
	if (person->age != 0 || person->fio != "")
	{
		for (int i = 0; i < this->sizePerson; i++)
		{
			if (this->person[i].age == 0)
			{
				this->person[i] = *person; // корректно ли работает? (проверить при возможности)
				person->~Person(); //
				return;
			}
		}
		std::cout << "В данную кваритру невозможно прописать " << person->fio << ", выберите другую квартиру" << std::endl;
	}
	else
		std::cout << " Для проверки - персона уже прописалась ранее" << std::endl; // позже обрать или переделать для информативности
}
void Apartment::discharPersonInHome(Person& freeperson)
{
	if (freeperson.age != 0 && freeperson.fio != "")
	{
		this->print();
		int i{};
		std::cout << "Какую персону выписать? укажите порядковый номер из списка выше (если выписывать некого - выбирете любой вариант от 1 до " << sizePerson << "): " << std::endl;
		std::cin >> i;
		while (i < 1 || i > sizePerson)
		{
			std::cout << "Не верно указан порядковый номер, повторите ввод: ";
			std::cin >> i;
		}
		if (freeperson.age == 0 || freeperson.fio == "")
		{
			std::cout << "Выписывать некого" << std::endl;
			return;
		}
		freeperson = person[i-1];
		person[i].~Person();
	}
	else
	{
		std::cout << "Ошибка!!! У вас уже бланк заполнен другой персоной, выберети чистый бланк персоны для выписки" << std::endl;
	}
}
void Apartment::discharPersonInHome()
{
	this->print();
	int i{};
	std::cout << "Какую персону выписать? укажите порядковый номер из списка выше (если выписывать некого - выбирете любой вариант от 1 до " << sizePerson << "): " << std::endl;
	std::cin >> i;
	if (i < 1 || i > sizePerson)
		return;
	if (person[i].age != 0 || person[i].fio != "")
	{
		std::cout << "Персона " << person[i].age << " выписана из квартиры" << std::endl;
		person[i].~Person();
	}
}


// Методы Дома

Apartment& Home::operator[](int appartNumber)
{
	--appartNumber;
	return apartment[appartNumber / numbeOfApartmenOnFloor][appartNumber % numbeOfApartmenOnFloor];
	// надо добавить исключение если квартира не найдена или номер квартиры передан не верно (пока вынес проверки квартиры за метод, так как нумерация в доме идет по порядку и количпство квартир на этаже одинаковое)
}

Home::Home(std::string street, int numberHous, int floor, int numbeOfApartmenOnFloor, int* numRoomApartFloor) : street{ street }, numberHous { numberHous }, floor{ floor }, numbeOfApartmenOnFloor{ numbeOfApartmenOnFloor }
{
	Apartment::count = 1; // обнуляем количество квартир в доме и при создании каждой квартиры записываем как номер квартиры c начальной нумерацией с 1
	apartment = new Apartment*[this->floor];
	for (int i = 0; i < this->floor; ++i)
	{
		apartment[i] = new Apartment[this->numbeOfApartmenOnFloor];
		for (int j = 0; j < numbeOfApartmenOnFloor; ++j)
		{
			apartment[i][j] = Apartment(numRoomApartFloor[j]);
		}
	}
	this->apartmentInHous = floor * numbeOfApartmenOnFloor;
}

void Home::print() const
{
	std::cout << street << ", " << numberHous << std::endl;
	std::cout << "Количество этажей: " << floor << std::endl;
	for (int i = 0; i < floor; i++)
	{
		for (int j = 0; j < numbeOfApartmenOnFloor; j++)
		{
			apartment[i][j].print();
			std::cout << std::endl;
		}
	}
}

//void Home::freeRegistrPersonInHome(Person& person, const int floor, const int numbeOfApartmenOnFloor) // до объявления пеегрузки оператора [] для указания конкретной квартиры в место этажа и квартиры на этаже
//{
//	if (floor < 1 || floor > this->floor)
//	{
//		std::cout << "Вы выбрали не верный этаж, в доме всего этажей: " << this->floor << std::endl;
//		return;
//	}
//	if (numbeOfApartmenOnFloor < 1 || numbeOfApartmenOnFloor > this->numbeOfApartmenOnFloor)
//	{
//		std::cout << "Вы выбрали не верную квартиру на этаже, на этаже всего квартир: " << this->numbeOfApartmenOnFloor << std::endl;
//		return;
//	}
//	this->apartment[floor-1][numbeOfApartmenOnFloor-1].freeRegistrPerson(person);
//}
void Home::freeRegistrPersonInHome(Person* person, const int appartNumber) // рефакторинг предыдущего метода с использованием перегрузки [] по номеру квартиры в доме
{
	(*this)[appartNumber].freeRegistrPerson(person);
}

//void Home::discharPersonInHome(Person& freeperson, const int floor, const int numbeOfApartmenOnFloor) // до объявления пеегрузки оператора [] для указания конкретной квартиры в место этажа и квартиры на этаже
//{
//	if (floor < 1 || floor > this->floor)
//	{
//		std::cout << "Вы выбрали не верный этаж, в доме всего этажей: " << this->floor << std::endl;
//		return;
//	}
//	if (numbeOfApartmenOnFloor < 1 || numbeOfApartmenOnFloor > this->numbeOfApartmenOnFloor)
//	{
//		std::cout << "Вы выбрали не верную квартиру на этаже, на этаже всего квартир: " << this->numbeOfApartmenOnFloor << std::endl;
//		return;
//	}
//	this->apartment[floor - 1][numbeOfApartmenOnFloor - 1].discharPersonInHome(freeperson);
//}
void Home::discharPersonInHome(Person& freeperson, const int appartNumber) // рефакторинг предыдущего метода с использованием перегрузки [] по номеру квартиры в доме
{
	(*this)[appartNumber].discharPersonInHome(freeperson);
}

void Home::discharPersonInHome(const int appartNumber)
{
	(*this)[appartNumber].discharPersonInHome();
}
