//TextFile.cpp
#pragma once
#include "TextFile.h"
#include "Exception.h"
template <class T>
TextFile<T>::TextFile() {}									//Конструктор по умолчанию
template <class T>
TextFile<T>::TextFile(const char* fn) : File(fn), last_read_pos(0), last_write_pos(0)
{															//Конструктор с параметром
	file.open(fn, ios::in | ios::out | ios::binary);
	if (!file)
	{
		file.open(fn, ios::in | ios::out | ios::binary | ios::trunc);
	}
}
template <class T>
TextFile<T>::~TextFile()									//Деструктор
{
	file.close();
}
template <class T>
void TextFile<T>::refresh()									//Обновление файла
{
	if (file.is_open())
	{
		file.clear();
		last_read_pos = 0;
		last_write_pos = 0;
		file.seekg(last_read_pos, ios::beg);
		file.seekp(last_write_pos, ios::beg);
	}
}
template <class T>
void TextFile<T>::show()									//Вывод содержимого файла
{
	T buf;
	bool file_end = false;
	if (!file.is_open())									//Вызов ошибки если файл не открыт
	{
		throw FileExp(11, "File isn't open.");
	}
	if (file.eof())											//Обновление файла если eof
	{
		file.clear();
		file_end = true;
	}
	streampos lastRP = last_read_pos;
	last_read_pos = 0;
	try
	{
		while (1)											//Считываем элементы файла.
		{
			(*this) >> buf;
			if (file.eof()) break;
			cout << buf << endl;							//И выводим их
		}
	}
	catch (...)
	{
		throw;
	}
	file.clear();
	if (file_end) file.clear(1);
	last_read_pos = lastRP;
}
template <class T>
void TextFile<T>::close()									//Закрытие файла
{
	file.close();
}
template <class T>
void TextFile<T>::clear_file()								//Очистка файла
{
	file.close();
	open_trunc(file_name);
}
template <class T>
bool TextFile<T>::open(const char* fn)						//Открытие файла
{
	file.close();
	file.open(fn, ios::in | ios::out);						//Попытка открыть существующий файл
	if (!file)
	{
		file.open(fn, ios::in | ios::out | ios::trunc);		//Если файла нет, то создаем его
		if (!file)
		{
			return false;
		}
	}
	strcpy(file_name, fn);									//Запоминам путь к файлу
	last_read_pos = 0;
	last_write_pos = 0;
	return true;
}
template <class T>
bool TextFile<T>::open_trunc(const char* fn)				//Открытие с уничтожением информации
{
	file.close();
	file.open(fn, ios::in | ios::out | ios::trunc);
	if (!file)												//Если файл не открылся, то false
	{
		return false;
	}
	strcpy(file_name, fn);									//Запоминаем путь к файлу
	last_read_pos = 0;
	last_write_pos = 0;
	return true;
}
template <class T>
bool TextFile<T>::is_open()									//true если файл открыт
{
	return file.is_open();
}
template <class T>
bool TextFile<T>::eof()										//true если конец файла
{
	return file.eof();
}
template <class T>
bool TextFile<T>::empty()									//true если файл пуст
{
	try
	{
		if (size() == 0)									//Если размер равен 0, то
		{
			return true;									//Файл пуст
		}
		else
		{
			return false;
		}
	}
	catch (...)												//Абсолютный обрабодчик
	{
		throw;
	}
}
template <class T>
int TextFile<T>::size()										//Возвращает размер файла
{
	int size = 0;
	bool end_file = false;
	if (file.eof())											//Если конец файла, то
	{
		end_file = true;									//Обновление файла
		file.clear();
	}
	if (file.is_open())										//Если файл открыт
	{
		file.seekg(0, ios::end);
		size = file.tellg();
		file.seekg(last_read_pos, ios::beg);
		if (end_file)										//Востанавливаем конец файла если он был
		{
			file.clear(1);
		}
		return size;
	}
	else
	{
		throw FileExp(11, "File isn't open.");
	}
}
template <class T>
TextFile<T>& TextFile<T>::operator << (const T& el)			//Перегрузка <<
{
	if (file.is_open())										//Поэлементная запись файла
	{
		file.seekp(last_write_pos, ios::beg);
		file << el << ' ';
		last_write_pos = file.tellp();
		return *this;
	}
	else
	{
		throw FileExp(11, "File isn't open.");
	}
}
template <class T>
TextFile<T>& TextFile<T>::operator >> (T& el)				//Перегрузка >>
{
	if (!file.is_open())
	{
		throw FileExp(11, "File isn't open.");
	}
	if (file.eof())											//Если конец файла, то генерация ошибки
	{
		throw end_of_file();
	}
	file.seekg(last_read_pos, ios::beg);
	file >> el;												//Попытка считать элемент
	if (file.fail() && !file.eof())
	{
		throw FileExp(13, "Something is wrong with the information.");
	}
	last_read_pos = file.tellg();
	return *this;
}
template <class T>
TextFile<T>& TextFile<T>::operator << (const cQueue<T>& el)
{															//Перегрузка << для очереди
	if (file.is_open())
	{
		file.seekp(last_write_pos, ios::beg);
		file << el << ' ';									//Вызов перегрузки записи очереди в файлы
		last_write_pos = file.tellp();
		return *this;
	}
	else
	{
		throw FileExp(11, "File isn't open.");
	}
}
template <class T>
TextFile<T>& TextFile<T>::operator >> (cQueue<T>& el)		//Перегрузка >> для очереди
{
	if (!file.is_open())
	{
		throw FileExp(11, "File isn't open.");
	}
	if (file.eof())
	{
		throw end_of_file();
	}
	file.seekg(0, ios::beg);
	try
	{
		file >> el;											//Попытка считать очередь
	}
	catch (...)												//Абсолютный обработчик
	{
		throw;
	}
	if (file.fail() && !file.eof())
	{
		throw FileExp(13, "Something is wrong with the information.");
	}
	file.clear();
	file.seekg(last_read_pos, ios::beg);
	return *this;
}