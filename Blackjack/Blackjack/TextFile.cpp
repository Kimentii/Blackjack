//TextFile.cpp
#pragma once
#include "TextFile.h"
#include "Exception.h"
template <class T>
TextFile<T>::TextFile() {}									//����������� �� ���������
template <class T>
TextFile<T>::TextFile(const char* fn) : File(fn), last_read_pos(0), last_write_pos(0)
{															//����������� � ����������
	file.open(fn, ios::in | ios::out | ios::binary);
	if (!file)
	{
		file.open(fn, ios::in | ios::out | ios::binary | ios::trunc);
	}
}
template <class T>
TextFile<T>::~TextFile()									//����������
{
	file.close();
}
template <class T>
void TextFile<T>::refresh()									//���������� �����
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
void TextFile<T>::show()									//����� ����������� �����
{
	T buf;
	bool file_end = false;
	if (!file.is_open())									//����� ������ ���� ���� �� ������
	{
		throw FileExp(11, "File isn't open.");
	}
	if (file.eof())											//���������� ����� ���� eof
	{
		file.clear();
		file_end = true;
	}
	streampos lastRP = last_read_pos;
	last_read_pos = 0;
	try
	{
		while (1)											//��������� �������� �����.
		{
			(*this) >> buf;
			if (file.eof()) break;
			cout << buf << endl;							//� ������� ��
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
void TextFile<T>::close()									//�������� �����
{
	file.close();
}
template <class T>
void TextFile<T>::clear_file()								//������� �����
{
	file.close();
	open_trunc(file_name);
}
template <class T>
bool TextFile<T>::open(const char* fn)						//�������� �����
{
	file.close();
	file.open(fn, ios::in | ios::out);						//������� ������� ������������ ����
	if (!file)
	{
		file.open(fn, ios::in | ios::out | ios::trunc);		//���� ����� ���, �� ������� ���
		if (!file)
		{
			return false;
		}
	}
	strcpy(file_name, fn);									//��������� ���� � �����
	last_read_pos = 0;
	last_write_pos = 0;
	return true;
}
template <class T>
bool TextFile<T>::open_trunc(const char* fn)				//�������� � ������������ ����������
{
	file.close();
	file.open(fn, ios::in | ios::out | ios::trunc);
	if (!file)												//���� ���� �� ��������, �� false
	{
		return false;
	}
	strcpy(file_name, fn);									//���������� ���� � �����
	last_read_pos = 0;
	last_write_pos = 0;
	return true;
}
template <class T>
bool TextFile<T>::is_open()									//true ���� ���� ������
{
	return file.is_open();
}
template <class T>
bool TextFile<T>::eof()										//true ���� ����� �����
{
	return file.eof();
}
template <class T>
bool TextFile<T>::empty()									//true ���� ���� ����
{
	try
	{
		if (size() == 0)									//���� ������ ����� 0, ��
		{
			return true;									//���� ����
		}
		else
		{
			return false;
		}
	}
	catch (...)												//���������� ����������
	{
		throw;
	}
}
template <class T>
int TextFile<T>::size()										//���������� ������ �����
{
	int size = 0;
	bool end_file = false;
	if (file.eof())											//���� ����� �����, ��
	{
		end_file = true;									//���������� �����
		file.clear();
	}
	if (file.is_open())										//���� ���� ������
	{
		file.seekg(0, ios::end);
		size = file.tellg();
		file.seekg(last_read_pos, ios::beg);
		if (end_file)										//�������������� ����� ����� ���� �� ���
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
TextFile<T>& TextFile<T>::operator << (const T& el)			//���������� <<
{
	if (file.is_open())										//������������ ������ �����
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
TextFile<T>& TextFile<T>::operator >> (T& el)				//���������� >>
{
	if (!file.is_open())
	{
		throw FileExp(11, "File isn't open.");
	}
	if (file.eof())											//���� ����� �����, �� ��������� ������
	{
		throw end_of_file();
	}
	file.seekg(last_read_pos, ios::beg);
	file >> el;												//������� ������� �������
	if (file.fail() && !file.eof())
	{
		throw FileExp(13, "Something is wrong with the information.");
	}
	last_read_pos = file.tellg();
	return *this;
}
template <class T>
TextFile<T>& TextFile<T>::operator << (const cQueue<T>& el)
{															//���������� << ��� �������
	if (file.is_open())
	{
		file.seekp(last_write_pos, ios::beg);
		file << el << ' ';									//����� ���������� ������ ������� � �����
		last_write_pos = file.tellp();
		return *this;
	}
	else
	{
		throw FileExp(11, "File isn't open.");
	}
}
template <class T>
TextFile<T>& TextFile<T>::operator >> (cQueue<T>& el)		//���������� >> ��� �������
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
		file >> el;											//������� ������� �������
	}
	catch (...)												//���������� ����������
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