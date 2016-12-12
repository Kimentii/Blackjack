//SafeFunctions.h
#pragma once
#include "Exception.h"
int InputInt(istream& is = cin, int min = 0, int max = 2147483647);	//Функция воода int
void StringCheck(const char* s);									//Проверка на английский язык
void InputString(istream& is, char* s, int size);					//Воод строки
template <class T>
T SafeInput()														//Ввод int, double, char
{
	T el;															//Создаем элемент
	while (true)
	{
		try
		{
			cout << "Enter your " << typeid(T).name() << ": ";		//Вывод просьбы ввести элемент
			cin >> el;
			if (cin.eof())
			{
				throw InputExp(1, "End of file");
			}
			if (cin.fail() || (cin.peek() != '\n'))					//Если ошибка потока ввода
			{
				throw InputExp(1, "Please, enter number.");			//Вызов исключения ввода
			}
			return el;
		}
		catch (InputExp exp)										//Обработка исключения
		{
			bool e = cin.eof();
			cin.clear();											//Очистка ошибок потока ввода
			if (!e) while (cin.get() != '\n');						//Очистка лишних символов
			cout << "Error number is " << exp.error() << endl;		//Вывод ошибки
			cout << exp.what() << endl;								//Вывод описания ошибки
		}
	}
}																	//Безопасный ввод int, double, char
