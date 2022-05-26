#include <iostream>
#include "SetArray.h"
#define MaxSize 35
using namespace std;

/*
Конструктор без параметрів
*/
Set::Set()
{

	cout << "\n\nВикликався конструктор за замовчуванням-" << this << "!\n\n";
 
	if (!(_data = new char[MaxSize]))
	{

		cout << "Не вдалося виділити пам'ять задля розміщення множини!" << endl;
 
		exit(0);
	}
	_currentSize = 0;
	_maxSize = MaxSize;
}

/*
Конструктор з параметрами
Вхід:
data-вказівник на константний рядок, передача за посиланням
size-змінна, яка зберігає значення розміру множини, передача за значенням
*/
Set::Set(char* data, int size)
{

	cout << "\n\nВикликався конструктор з параметрами-" << this << "!\n\n";
 
	if (strlen(data) > MaxSize)
	{

		cout << "Ємність переданої множини більша за максимальну доступну!" << endl;
 
		exit(0);
	}

	if (size <0 || size > strlen(data) || size > MaxSize)
	{

		cout << "Задане некоректне значення розміру множини!" << endl;

		exit(0);
	}

	if (!(_data = new char[MaxSize]))
	{
 
		cout << "Не вдалося виділити пам'ять задля розміщення множини!" << endl;
 
		exit(0);
	}
	_currentSize = size;
	if (_checkDuplicates(data))
	{
		_deleteDuplicates(data);
	}
	for (int i = 0; i < _currentSize; i++)
	{
		_data[i] = data[i];
	}
	_maxSize = MaxSize;
}

/*
Спрощений конструктор з параметрами
Вхід:
data-вказівник на константний рядок, передача за посиланням
*/
Set::Set(char* data)
{

	cout << "\n\nВикликався спрощений конструктор з одним параметром-" << this << "!\n\n";
 
	if (strlen(data) > MaxSize)
	{

		cout << "Ємність переданої множини більша за максимальну доступну!" << endl;

		exit(0);
	}
	if (!(_data = new char[MaxSize]))
	{

		cout << "Не вдалося виділити пам'ять задля розміщення множини!" << endl;

		exit(0);
	}

	_currentSize = strlen(data);
	if (_checkDuplicates(data))
	{
		_deleteDuplicates(data);
	}
	for (int i = 0; i < _currentSize; i++)
	{
		_data[i] = data[i];
	}
	_maxSize = MaxSize;
}

/*
Конструктор копіювання
Вхід:
other-змінна типу класу, передача за посиланням
*/
Set::Set(const Set& other)
{

	cout << "\n\nВикликався конструктор копіювання-" << this << "!\n\n";
 
	_currentSize = other._currentSize;
	_maxSize = other._maxSize;

	if (!(_data = new char[MaxSize]))
	{

		cout << "Не вдалося виділити пам'ять задля розміщення множини!" << endl;

		exit(0);
	}

	for (int i = 0; i < _currentSize; i++)
	{
		_data[i] = other._data[i];
	}
}

/*
Деструктор
*/
Set::~Set()
{

	cout << "\n\nВикликався деструктор-" << this << "!\n\n" << endl;
 
	delete[] _data;
}

/*
Метод Print для виводу в консоль множини
Вихід:
1-при успішному виконанні методу
0-у випадку, якщо множина для друку не була створена
*/
int Set::Print()
{
	if (_data != NULL)
	{
		cout << "{";
		for (int i = 0; i < _currentSize; i++)
		{
			if (i == _currentSize - 1)
			{
				cout << _data[i];
			}
			else
			{
				cout << _data[i] << ", ";
			}
		}
		cout << "}"<<std::endl;
		
		return 1;
	}
	else
	{

		cout << "Рядок для друку не був створений!" << endl;

		return 0;
	}
}

void Set::DeleteLastElement()
{
	
	char* temp = new char[_currentSize];
	memcpy(temp, _data, _currentSize);
	delete _data;
	_currentSize--;
	_data = new char[_currentSize];
	for (int i = 0; i < _currentSize; i++)
	{
		_data[i] = temp[i];
	}
	delete temp;

	
} 

/*
Метод GetData для отримання значення поля _data об'єкту класу
Вихід:
Вказівник на рядок з записаною множиною в ньому або вказівник на nullpointer
*/
char* Set::GetData()
{
	if (_currentSize != 0)
	{
		char* temp = new char[_currentSize];
		for (int i = 0; i < _currentSize; i++)
		{
			temp[i] = _data[i];
		}
		return temp;
	}
	else
	{
		return NULL;
	}
}

/*
Метод GetCurrentSize для отримання значення поля _currentSize об'єкту класу
Вихід:
Поточна ємність множини, яка записана в полі _currentSize об'єкту класу
*/
int Set::GetCurrentSize()
{
	return _currentSize;
}

/*
Метод GetMaxSize для отримання значення поля _maxSize об'єкту класу
Вихід:
Максимальна ємність множини, яка записана в полі _maxSize об'єкту класу
*/
int Set::GetMaxSize()
{
	return _maxSize;
}

/*
Метод SetData для запису множини з рядка data до масиву _data
Вхід:
data-вказівник на константний рядок, передача за посиланням
size-кількість елементів переданої множини, передача за значенням
Вихід:
0-якщо не був переданий рядок
1-при успішному виконанні методу
*/
int Set::SetData(char* data, int size)
{
	if (strlen(data) > MaxSize)
	{

		cout << "Ємність переданої множини більша за максимальну доступну!" << endl;

		exit(0);
	}
	if (size <0 || size > strlen(data) || size > MaxSize)
	{

		cout << "Задане некоректне значення розміру множини!" << endl;

		exit(0);
	}

	if (data == NULL)
	{

		printf("Ви не передали рядок з елементами для задання поля класу!\n");

		return 0;
	}
	else
	{
		if (_data != NULL)
		{
			delete[] _data;
		}

		if (!(_data = new char[MaxSize]))
		{

			cout << "Не вдалося виділити пам'ять задля розміщення множини!" << endl;
			exit(0);
		}
	}
	_currentSize = size;
	if (_checkDuplicates(data))
	{
		_deleteDuplicates(data);
	}
	for (int i = 0; i < _currentSize; i++)
	{
		_data[i] = data[i];
	}
	return 1;
}

/*
Спрощений метод SetData для запису множини з рядка data до масиву _data
Вхід:
data-вказівник на константний рядок, передача за посиланням
Вихід:
0-якщо не був переданий рядок
1-при успішному виконанні методу
*/
int Set::SetData(char* data)
{
	int size;
	if (strlen(data) > _maxSize)
	{

		cout << "Ємність переданої множини більша за максимальну доступну!" << endl;


		exit(0);
	}
	if (data == NULL)
	{
		printf("Ви не передали рядок з елементами для задання поля класу!\n");

		return 0;
	}
	else
	{
		if (_data != NULL)
		{
			delete[] _data;
		}

		if (!(_data = new char[_maxSize]))
		{

			cout << "Не вдалося виділити пам'ять задля розміщення множини!" << endl;

			exit(0);
		}
	}
	_currentSize = size = strlen(data);
	if (_checkDuplicates(data))
	{
		_deleteDuplicates(data);
	}
	for (int i = 0; i < _currentSize; i++)
	{
		_data[i] = data[i];
	}
	return 1;
}

/*
Метод SetCurrentSize для запису поточного розміру множини у поле _currentSize
Вхід:
currentSize-змінна, яка зберігає значення поточного розміру множини, передача за значенням
*/
void Set::SetCurrentSize(int currentSize)
{
	if (currentSize < 0)
	{
		cout << "Передане Вами значення для поточного розміру рядка не є коректним!\n";

		exit(0);
	}

	if (currentSize > _currentSize && currentSize <= MaxSize)
	{
		for (int i = _currentSize; i < currentSize; i++)
		{
			_data[i] = ' ';
		}
	}

	if (currentSize > MaxSize)
	{
		char* tempData;
		if (!(tempData = new char[_currentSize]))
		{

			cout << "Не вдалося виділити пам'ять задля тимчасового розміщення множини!" << endl;

			exit(0);
		}

		for (int i = 0; i < _currentSize; i++)
		{
			tempData[i] = _data[i];
		}
		_maxSize = currentSize;
		delete[] _data;

		if (!(_data = new char[_maxSize]))
		{

			cout << "Не вдалося виділити пам'ять задля розміщення множини!" << endl;

			exit(0);
		}

		for (int i = 0; i < _currentSize; i++)
		{
			_data[i] = tempData[i];
		}
		delete[] tempData;
		for (int i = _currentSize; i < _maxSize; i++)
		{
			_data[i] = ' ';
		}
	}

	_currentSize = currentSize;
}



/*
Перевантаження оператора перевірки множин на рівність
Вхід:
other-змінна типу класу, передача за посиланням
Вихід:
-2-якщо одна з множин не існує
1-якщо множини рівні
0-якщо множини не рівні
*/
int Set::operator!=(const Set& other)
{
	if (!_dataCheck(other))
	{
		return -2;
	}

	if (!_dataCheck(*this))
	{
		return -2;
	}
	if (this->_currentSize != other._currentSize)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/*
Перевантаження оператора присвоювання задля утворення копії вже існуючого об'єкту класу
Вхід:
other-змінна типу класу, передача за посиланням
Вихід:
Змінна типу класу
*/
Set Set::operator=(const Set& other)
{
	if (this == &other)
	{

		cout << "Викликане самоприсвоювання!" << endl;
		return *this;
	}

	if (_data != NULL)
	{
		delete[] _data;
	}

	if (!(_data = new char[other._currentSize]))
	{

		cout << "Не вдалося виділити пам'ять задля розміщення множини!" << endl;

		exit(0);
	}

	_currentSize = other._currentSize;
	_maxSize = other._maxSize;
	for (int i = 0; i < _currentSize; i++)
	{
		_data[i] = other._data[i];
	}
	return *this;
}

/*
Функція для видалення елементів, які повторюються у масиві data
Вхід:
data-покажчик на рядок у пам'яті
*/
void Set::_deleteDuplicates(char* data)
{
	for (int i = 0; i < _currentSize; i++)
	{
		for (int j = i + 1; j < _currentSize; j++)
		{
			if (data[i] == data[j])
			{
				for (int k = j; k < _currentSize; k++)
				{
					data[k] = data[k + 1];
				}
				j--;
				_currentSize--;
			}
		}
	}
}

/*
Функція для видалення елементів які повторюються, у масиві data
Вхід:
data-покажчик на рядок у пам'яті
Вихід:
1-якщо елементи повторюються в масиві
0-якщо елементи не повторюються в масиві
*/
bool Set::_checkDuplicates(char* data)
{
	for (int i = 0; i < _currentSize; i++)
	{
		for (int j = i + 1; j < _currentSize; j++)
		{
			if (data[i] == data[j])
			{
				return 1;
			}
		}
	}
	return 0;
}

/*
Функція для перевірки того, чи поле переданого об'єкту класу вказує на ділянку пам'яті з множиною
Вхід:
other-змінна типу класу, передача за посиланням
Вихід:
0-якщо поле переданого об'єкту класу не вказує на ділянку пам'яті з множиною
1-якщо поле переданого об'єкту класу вказує на ділянку пам'яті з множиною
*/
bool Set::_dataCheck(const Set& other)
{
	if (other._data == NULL)
	{

		cout << "Рядок для порівняння не існує!" << endl;

		return 0;
	}
	else
	{
		return 1;
	}
}

bool operator>(const Set& d1, const Set& d2)
{

	int i, j;
	for (i = 0; i < d2._currentSize; i++)
	{
		for (j = 0; j < d1._currentSize; j++)
		{
			if (d2._data[i] ==d1._data[j])
				break;
			
		}
		if (j == d1._currentSize) {
			return false;
		}
	
	}
	return true;
	
}

Set &operator--(Set& obj)
{
	 obj.DeleteLastElement();
	return obj;
}
