#pragma once
class Set
{
public:
	Set(); //конструктор за замовчуванням
	Set(char* data, int size); //конструктор з параметрами
	Set(char* data); //спрощений конструктор з параметрами
	Set(const Set& other); //конструктор копіювання
	~Set(); //деструктор
	int SetData(char* data, int size); //сеттер для множини
	int SetData(char* data); //спрощений сеттер для множини
	void SetCurrentSize(int currentSize); //сеттер для поточного розміру
	char* GetData(); //геттер для множини
	int GetCurrentSize(); //геттер для розміру множини
	int GetMaxSize(); //геттер для максимального розміру множини
	int Print(); //вивід множини
	void DeleteLastElement();

	friend bool operator> (const Set& d1, const Set& d2);
	friend Set& operator--(Set& obj);
	int operator!=(const Set& other); //оператор перевірки множин на рівність
	Set operator=(const Set& other); //оператор присвоювання для повного копіювання полів іншого об'єкту класу
private:
	void _deleteDuplicates(char* data); //для видалення елементів, які повторюються у масиві data
	bool _dataCheck(const Set& other); //для перевірки на те, чи поле-покажчик елементу класу вказує на ділянку в пам'яті, чи на NULL-pointer
	bool _checkDuplicates(char* data); //для перевірки на те, чи в масиві data є елементи, що повторюються

	char* _data; //покажчик на початок рядка
	int _currentSize; //поточний розмір
	int _maxSize; //максимальний розмір рядка
};