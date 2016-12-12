//TextFile.h
#pragma once
#include "File.h"
#include "Queue.h"
const char FNAME[] = "D:/��������/3 ���/��������/Blackjack/Blackjack/Blackjack/Lobby/Lobby";
template <class T>
class TextFile : File								//��������� ����
{
	streampos last_read_pos;						//��������� ������� ������
	streampos last_write_pos;						//��������� ������� ������
	fstream file;									//����
public:
	TextFile();										//����������� �� ���������
	TextFile(const char* fn);						//����������� � ����������
	~TextFile();									//����������
	void refresh();									//���������� �����
	void show();									//����� ����������� �����
	void close();									//�������� �����
	void clear_file();								//������� ����
	bool open(const char* fn);						//�������� �����
	bool open_trunc(const char* fn);				//��������� � ������������ ����������
	bool is_open();									//true ���� ���� ������
	bool eof();										//true ���� ����� �����
	bool empty();									//true ���� ���� ����
	int size();										//���������� ������ �����
	TextFile& operator << (const T& el);			//������ � ���� ��������
	TextFile& operator >> (T& el);					//������ �������� �� �����
	TextFile& operator << (const cQueue<T>& el);	//������ ������� � ����
	TextFile& operator >> (cQueue<T>& el);			//������ ������� �� �����
};