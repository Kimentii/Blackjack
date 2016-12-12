//Player.h
#pragma once
#include "GenericPlayer.h"
class Player : public GenericPlayer
{
public:
	Player(const char* name = "", int p = 3000);
	virtual ~Player();
	virtual bool IsHitting() const;						//���������� ����� �� ����� ����� �����
	void Win();											//����������, ��� ����� �������
	void Lose();										//����������, ��� ����� ��������
	void Push();										//��������� �����
	void ShowTable();									//����� �������
	const char* GetName();								//���������� ���
	bool operator == (const Player& aHum);				//���������� ==
	bool operator != (const Player& aHum);				//���������� !=
	bool operator > (const Player& aHum);				//���������� >
	bool operator < (const Player& aHum);				//���������� <
	friend ostream& operator << (ostream& os, const Player& aPlr);	//���������� ������
	friend istream& operator >> (istream& is, Player& aPlr);		//���������� �����
	friend fstream& operator >> (fstream& is, Player& aPlr);		//���������� ������ �� �����
	friend fstream& operator << (fstream& os, const Player& aPlr);	//���������� ������ � ����
private:
	int m_Points;										//���� ������
	int m_NumOfWin;										//���������� �����
	int m_NumOfLose;									//���������� ���������
	int m_NumOfPush;									//����������� ������ � �����
};