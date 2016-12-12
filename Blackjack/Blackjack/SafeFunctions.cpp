//SafeFunctions.cpp
#pragma once
#include "SafeFunctions.h"
#include "Exception.h"
int InputInt(istream& is, int min, int max)
{
	int num;
	while (1)
	{
		is >> num;										//Считывание числа
		try
		{
			if (is.fail() || (is.peek() != '\n'))		//Если в потоке ввода ошибка или конец
			{
				throw new not_int();					//Вызов исключения не числа
			}
			if (num < min || num > max)					//Если слишком большое число или маленькое
			{
				throw new out_of_size();				//Вызов исключения размера
			}
			if (is.eof())
			{
				throw new InputExp(1, "End of file.");	//Генерация исключения конца файла
			}
		}
		catch (InputExp* exp)							//Обработка исключения
		{
			bool e = is.eof();
			is.clear();
			if (!e) while (is.get() != '\n');			//Удаление лишних символов
			cout << "Number of error is " << exp->error() << endl;
			cout << exp->what() << endl;
			delete exp;
			continue;
		}
		return num;
	}
}
void StringCheck(const char* s)
{
	int i;
	for (i = 0; s[i]; i++)								//Проверка всех символов
	{
		if ((s[i] < 'A') || (s[i] > 'z') || ((s[i] > 'Z') && (s[i] < 'a')))
		{												//Если введен не английский символ
			throw not_eng();							//Вызов исключения
		}
	}
}
void InputString(istream& is, char* s, int size)
{
	char buf[256];										//Создание буферной строки
	while (1)
	{
		is >> buf;										//Ввод буферной строки
		try
		{
			if (is.eof())
			{
				throw InputExp(1, "End of file");
			}
			if ((strlen(buf) + 1) > size)				//Если размер не верен, то
			{
				throw out_of_size();					//вызов исключения
			}
			StringCheck(buf);							//Проверка на английский язык
			break;
		}
		catch (InputExp& ne)							//Обработка исключения
		{
			if (is.eof())
			{
				is.clear();
			}
			cout << "Number of error is " << ne.error() << endl;
			cout << ne.what() << endl;
			continue;									//Продолжение цикла
		}
	}
	strcpy(s, buf);
}