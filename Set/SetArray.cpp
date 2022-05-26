#include <iostream>
#include "SetArray.h"
#define MaxSize 35
using namespace std;

/*
����������� ��� ���������
*/
Set::Set()
{

	cout << "\n\n���������� ����������� �� �������������-" << this << "!\n\n";
 
	if (!(_data = new char[MaxSize]))
	{

		cout << "�� ������� ������� ���'��� ����� ��������� �������!" << endl;
 
		exit(0);
	}
	_currentSize = 0;
	_maxSize = MaxSize;
}

/*
����������� � �����������
����:
data-�������� �� ����������� �����, �������� �� ����������
size-�����, ��� ������ �������� ������ �������, �������� �� ���������
*/
Set::Set(char* data, int size)
{

	cout << "\n\n���������� ����������� � �����������-" << this << "!\n\n";
 
	if (strlen(data) > MaxSize)
	{

		cout << "������ �������� ������� ����� �� ����������� ��������!" << endl;
 
		exit(0);
	}

	if (size <0 || size > strlen(data) || size > MaxSize)
	{

		cout << "������ ���������� �������� ������ �������!" << endl;

		exit(0);
	}

	if (!(_data = new char[MaxSize]))
	{
 
		cout << "�� ������� ������� ���'��� ����� ��������� �������!" << endl;
 
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
��������� ����������� � �����������
����:
data-�������� �� ����������� �����, �������� �� ����������
*/
Set::Set(char* data)
{

	cout << "\n\n���������� ��������� ����������� � ����� ����������-" << this << "!\n\n";
 
	if (strlen(data) > MaxSize)
	{

		cout << "������ �������� ������� ����� �� ����������� ��������!" << endl;

		exit(0);
	}
	if (!(_data = new char[MaxSize]))
	{

		cout << "�� ������� ������� ���'��� ����� ��������� �������!" << endl;

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
����������� ���������
����:
other-����� ���� �����, �������� �� ����������
*/
Set::Set(const Set& other)
{

	cout << "\n\n���������� ����������� ���������-" << this << "!\n\n";
 
	_currentSize = other._currentSize;
	_maxSize = other._maxSize;

	if (!(_data = new char[MaxSize]))
	{

		cout << "�� ������� ������� ���'��� ����� ��������� �������!" << endl;

		exit(0);
	}

	for (int i = 0; i < _currentSize; i++)
	{
		_data[i] = other._data[i];
	}
}

/*
����������
*/
Set::~Set()
{

	cout << "\n\n���������� ����������-" << this << "!\n\n" << endl;
 
	delete[] _data;
}

/*
����� Print ��� ������ � ������� �������
�����:
1-��� �������� �������� ������
0-� �������, ���� ������� ��� ����� �� ���� ��������
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

		cout << "����� ��� ����� �� ��� ���������!" << endl;

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
����� GetData ��� ��������� �������� ���� _data ��'���� �����
�����:
�������� �� ����� � ��������� �������� � ����� ��� �������� �� nullpointer
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
����� GetCurrentSize ��� ��������� �������� ���� _currentSize ��'���� �����
�����:
������� ������ �������, ��� �������� � ��� _currentSize ��'���� �����
*/
int Set::GetCurrentSize()
{
	return _currentSize;
}

/*
����� GetMaxSize ��� ��������� �������� ���� _maxSize ��'���� �����
�����:
����������� ������ �������, ��� �������� � ��� _maxSize ��'���� �����
*/
int Set::GetMaxSize()
{
	return _maxSize;
}

/*
����� SetData ��� ������ ������� � ����� data �� ������ _data
����:
data-�������� �� ����������� �����, �������� �� ����������
size-������� �������� �������� �������, �������� �� ���������
�����:
0-���� �� ��� ��������� �����
1-��� �������� �������� ������
*/
int Set::SetData(char* data, int size)
{
	if (strlen(data) > MaxSize)
	{

		cout << "������ �������� ������� ����� �� ����������� ��������!" << endl;

		exit(0);
	}
	if (size <0 || size > strlen(data) || size > MaxSize)
	{

		cout << "������ ���������� �������� ������ �������!" << endl;

		exit(0);
	}

	if (data == NULL)
	{

		printf("�� �� �������� ����� � ���������� ��� ������� ���� �����!\n");

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

			cout << "�� ������� ������� ���'��� ����� ��������� �������!" << endl;
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
��������� ����� SetData ��� ������ ������� � ����� data �� ������ _data
����:
data-�������� �� ����������� �����, �������� �� ����������
�����:
0-���� �� ��� ��������� �����
1-��� �������� �������� ������
*/
int Set::SetData(char* data)
{
	int size;
	if (strlen(data) > _maxSize)
	{

		cout << "������ �������� ������� ����� �� ����������� ��������!" << endl;


		exit(0);
	}
	if (data == NULL)
	{
		printf("�� �� �������� ����� � ���������� ��� ������� ���� �����!\n");

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

			cout << "�� ������� ������� ���'��� ����� ��������� �������!" << endl;

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
����� SetCurrentSize ��� ������ ��������� ������ ������� � ���� _currentSize
����:
currentSize-�����, ��� ������ �������� ��������� ������ �������, �������� �� ���������
*/
void Set::SetCurrentSize(int currentSize)
{
	if (currentSize < 0)
	{
		cout << "�������� ���� �������� ��� ��������� ������ ����� �� � ���������!\n";

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

			cout << "�� ������� ������� ���'��� ����� ����������� ��������� �������!" << endl;

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

			cout << "�� ������� ������� ���'��� ����� ��������� �������!" << endl;

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
�������������� ��������� �������� ������ �� ������
����:
other-����� ���� �����, �������� �� ����������
�����:
-2-���� ���� � ������ �� ����
1-���� ������� ���
0-���� ������� �� ���
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
�������������� ��������� ������������ ����� ��������� ��ﳿ ��� ��������� ��'���� �����
����:
other-����� ���� �����, �������� �� ����������
�����:
����� ���� �����
*/
Set Set::operator=(const Set& other)
{
	if (this == &other)
	{

		cout << "��������� ����������������!" << endl;
		return *this;
	}

	if (_data != NULL)
	{
		delete[] _data;
	}

	if (!(_data = new char[other._currentSize]))
	{

		cout << "�� ������� ������� ���'��� ����� ��������� �������!" << endl;

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
������� ��� ��������� ��������, �� ������������ � ����� data
����:
data-�������� �� ����� � ���'��
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
������� ��� ��������� �������� �� ������������, � ����� data
����:
data-�������� �� ����� � ���'��
�����:
1-���� �������� ������������ � �����
0-���� �������� �� ������������ � �����
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
������� ��� �������� ����, �� ���� ���������� ��'���� ����� ����� �� ������ ���'�� � ��������
����:
other-����� ���� �����, �������� �� ����������
�����:
0-���� ���� ���������� ��'���� ����� �� ����� �� ������ ���'�� � ��������
1-���� ���� ���������� ��'���� ����� ����� �� ������ ���'�� � ��������
*/
bool Set::_dataCheck(const Set& other)
{
	if (other._data == NULL)
	{

		cout << "����� ��� ��������� �� ����!" << endl;

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
