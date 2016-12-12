//File.cpp
#include "File.h"
File::File(const char* fn)							//Конструктор по умолчанию
{
	strcpy(file_name, fn);							//Запоминаем имя файла
}