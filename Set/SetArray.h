#pragma once
class Set
{
public:
	Set(); //����������� �� �������������
	Set(char* data, int size); //����������� � �����������
	Set(char* data); //��������� ����������� � �����������
	Set(const Set& other); //����������� ���������
	~Set(); //����������
	int SetData(char* data, int size); //������ ��� �������
	int SetData(char* data); //��������� ������ ��� �������
	void SetCurrentSize(int currentSize); //������ ��� ��������� ������
	char* GetData(); //������ ��� �������
	int GetCurrentSize(); //������ ��� ������ �������
	int GetMaxSize(); //������ ��� ������������� ������ �������
	int Print(); //���� �������
	void DeleteLastElement();

	friend bool operator> (const Set& d1, const Set& d2);
	friend Set& operator--(Set& obj);
	int operator!=(const Set& other); //�������� �������� ������ �� ������
	Set operator=(const Set& other); //�������� ������������ ��� ������� ��������� ���� ������ ��'���� �����
private:
	void _deleteDuplicates(char* data); //��� ��������� ��������, �� ������������ � ����� data
	bool _dataCheck(const Set& other); //��� �������� �� ��, �� ����-�������� �������� ����� ����� �� ������ � ���'��, �� �� NULL-pointer
	bool _checkDuplicates(char* data); //��� �������� �� ��, �� � ����� data � ��������, �� ������������

	char* _data; //�������� �� ������� �����
	int _currentSize; //�������� �����
	int _maxSize; //������������ ����� �����
};