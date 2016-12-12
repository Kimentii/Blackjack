//Exception.h
#pragma once
#include <iostream>
using namespace std;
#pragma warning(disable: 4996)
const int LEN = 80;
class Exception													//Абстрактный класс исключения
{
protected:
	int NumOfError;												//Номер ошбики
public:
	Exception(int i = 0) : NumOfError(i) { }					//Конструктор по умолчанию
	virtual int error() { return NumOfError; }					//Возвращает номер ошибки
	virtual char* what() = 0;									//Возвращает описание ошибки
};
class InputExp : public Exception								//Ошибка ввода
{
	char desc[LEN];												//Описание ошибки
public:
	InputExp(int e = 1, const char* s = "wrong input.") : Exception(e) { strcpy(desc, s); }
	//Конструктор с параметрами по умолчанию по умолчанию
	int error() { return Exception::error(); }					//Возвращает номер ошибки
	char* what() { return desc; }								//Возвращает описание функции
};
class not_int : public InputExp
{
	char desc[LEN];
public:
	not_int() { strcpy(desc, "wrong input, please enter integer value."); NumOfError = 3; }	//Конструктор по умолчанию
	int error() { return Exception::error(); }					//Возвращает номер ошибки
	char* what() { return desc; }								//Возвращает описание ошибки
};
class not_eng : public InputExp									//Ошибка языка ввода
{
	char desc[LEN];
public:
	not_eng() { strcpy(desc, "wrong input, please use English."); NumOfError = 4; }	//Конструктор по умолчанию
	int error() { return Exception::error(); }					//Возвращает номер ошибки
	char* what() { return desc; }								//Возвращает описание ошибки
};
class out_of_size : public InputExp								//Ошибка размера ввода
{
	char desc[LEN];
public:
	out_of_size() { strcpy(desc, "wrong input, too much or too little."); NumOfError = 5; }
	int error() { return Exception::error(); }					//Возвращает номер ошибки
	char* what() { return desc; }								//Возвращает описание ошибки
};
class QueueExp : public Exception								//Неправильное действие в очереди
{
	char desc[LEN];
public:
	QueueExp(int e = 2, const char* s = "Wrong action.") { strcpy(desc, s); NumOfError = e; }
	//Конструктор по умолчанию
	int error() { return Exception::error(); }					//Возвращает номер ошибки
	char* what() { return desc; }								//Возвращает описание ошибки
};
class wrong_element : public QueueExp							//Попытка сослаться на
{																//несуществующий элемент
	char desc[LEN];
public:
	wrong_element() { strcpy(desc, "There is no such element."); NumOfError = 6; } 	//Конструктор по умолчанию
	int error() { return Exception::error(); }					//Возвращает номер ошибки
	char* what() { return desc; }								//Возвращает описание ошибки
};
class FileExp : public Exception								//Ошибка при работе с файломы
{
	char desc[LEN];
public:
	FileExp(int e = 7, const char* s = "Error with file") { strcpy(desc, s); NumOfError = e; }
	//Конструктор по умолчанию c праметрами
	int error() { return Exception::error(); }					//Возвращает номер ошибки
	char* what() { return desc; }								//Возвращает описание ошибки
};
class end_of_file : public FileExp								//Конец файла
{
	char desc[LEN];
public:
	end_of_file() { strcpy(desc, "End of file."); NumOfError = 8; }
	//Конструктор по умолчанию
	int error() { return Exception::error(); }					//Возвращает номер ошибки
	char* what() { return desc; }								//Возвращает описание ошибки
};