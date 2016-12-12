//File.h
#pragma once
#include <iostream>
#include <fstream>
#pragma warning(disable:4996)
using namespace std;
class File							//Файл
{
protected:
	char file_name[80];				//Имя файла
public:
	File(const char* fn = "");		//Конструктор с параметрами по умолчанию
	~File() {}						//Деструктор
};