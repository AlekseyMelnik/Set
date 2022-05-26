#define _CRT_SECURE_NO_WARNINGS
#include "stdlib.h"
#include "stdio.h"
#include "conio.h"
#include "locale.h"
#include "string.h"
#include "windows.h"
#include <iostream>
#include "SetArray.h"
using namespace std;


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char* data = new char[256];
	strcpy(data, "123123jimboj");
	Set set(data);
	
	set.Print();
	cout << "Оператор -- :" << std::endl;
	--set;
	set.Print();


	char* data1 = new char[256];
	strcpy(data1, "123123");
	Set set1(data1);
	cout << "Оператор >:" << endl;
	if (set > set1) {
		cout << "set1 подмножество set" << endl;
	}
	cout << "Оператор !=:" << endl;
	if (set != set1) {
		std::cout << "Set!=set1" << endl;
	}
}

