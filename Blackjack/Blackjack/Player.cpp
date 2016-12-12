//Player.cpp
#include "Player.h"
#include "SafeFunctions.h"
#include <fstream>
#include <iomanip>
Player::Player(const char* name, int p) : GenericPlayer(name), m_Points(p), m_NumOfWin(0), m_NumOfLose(0), m_NumOfPush(0) {}
Player::~Player() {}
bool Player::IsHitting() const							//Хочет ли игрок тянуть карту
{
	cout << m_Name << ". do you want a hit? (Y/N): ";
	char response;
	cin >> response;									//Считывает выбор
	return (response == 'y' || response == 'Y');		//Возвращает true, если игрок хочет тянуть карту
}
void Player::Win()										//Объявляет что игрок победил
{
	cout << m_Name << " wins.\n";
	m_NumOfWin++;
	m_Points += 500;
}
void Player::Lose()										//Объявляет что игрок проиграл
{
	cout << m_Name << " loses.\n";
	m_NumOfLose++;
	if(m_Points >= 500) m_Points -= 500;
}
void Player::Push() 									//Объявляет ничью
{
	cout << m_Name << " pushes.\n";
	m_NumOfPush++;
}
void Player::ShowTable()								//Вывод таблицы для вывода
{
	cout << setw(20) << "Name";
	cout << setw(20) << "Win";
	cout << setw(20) << "Lose";
	cout << setw(20) << "Push";
	cout << setw(20) << "Points" << endl;
}
const char* Player::GetName()							//Возвращает имя игрока
{
	return m_Name;
}
ostream& operator << (ostream& os, const Player& aPlr)	//Вывод на экран игрока
{
	os << setw(20) << aPlr.m_Name;
	os << setw(20) << aPlr.m_NumOfWin;
	os << setw(20) << aPlr.m_NumOfLose;
	os << setw(20) << aPlr.m_NumOfPush;
	os << setw(20) << aPlr.m_Points;
	return os;
}
istream& operator >> (istream& is, Player& aPlr)		//Перегрузка ввода с клавиатуры
{
	cout << "Enter name: ";
	is >> aPlr.m_Name;
	return is;
}
bool Player::operator == (const Player& aHum)			//Перегрузка ==
{
	if (!strcmp(m_Name, aHum.m_Name)) return true;
	else return false;
}
bool Player::operator != (const Player& aHum)			//Перегрузка !=
{
	if (strcmp(m_Name, aHum.m_Name)) return true;
	else return false;
}
bool Player::operator > (const Player& aHum)			//Перегрузка >
{
	if (strcmp(m_Name, aHum.m_Name) > 0) return true;
	else return false;
}
bool Player::operator < (const Player& aHum)			//Перегрузка <
{
	if (strcmp(m_Name, aHum.m_Name) < 0) return true;
	else return false;
}
fstream& operator >> (fstream& is, Player& aPlr)		//Чтение из файла
{
	is >> aPlr.m_Name;
	is >> aPlr.m_NumOfWin;
	is >> aPlr.m_NumOfLose;
	is >> aPlr.m_NumOfPush;
	is >>  aPlr.m_Points;
	return is;
}
fstream& operator << (fstream& os, const Player& aPlr)	//Запись в файл
{
	os << ' ' << aPlr.m_Name;
	os << ' ' << aPlr.m_NumOfWin;
	os << ' ' << aPlr.m_NumOfLose;
	os << ' ' << aPlr.m_NumOfPush;
	os << ' ' << aPlr.m_Points;
	return os;
}