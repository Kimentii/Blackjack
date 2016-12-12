//TextFile.h
#pragma once
#include "File.h"
#include "Queue.h"
const char FNAME[] = "D:/Предметы/3 сем/Курсовая/Blackjack/Blackjack/Blackjack/Lobby/Lobby";
template <class T>
class TextFile : File								//Текстовый файл
{
	streampos last_read_pos;						//Последняя позиция чтения
	streampos last_write_pos;						//Последняя позиция записи
	fstream file;									//Файл
public:
	TextFile();										//Конструктор по умолчанию
	TextFile(const char* fn);						//Конструктор с параметром
	~TextFile();									//Деструктор
	void refresh();									//Обновление файла
	void show();									//Вывод содержимого файла
	void close();									//Закрытие файла
	void clear_file();								//Очищает файл
	bool open(const char* fn);						//Открытие файла
	bool open_trunc(const char* fn);				//Открывает с уничтожением информации
	bool is_open();									//true если файл открыт
	bool eof();										//true если конец файла
	bool empty();									//true если файл пуст
	int size();										//Возвращает размер файла
	TextFile& operator << (const T& el);			//Запись в файл элемента
	TextFile& operator >> (T& el);					//Чтение элемента из файла
	TextFile& operator << (const cQueue<T>& el);	//Запись очереди в файл
	TextFile& operator >> (cQueue<T>& el);			//Чтение очереди из файла
};