//Menu.cpp
#include "Game.h"
#include "Queue.cpp"
#include "SafeFunctions.h"
#include "Interface.h"
#include <iomanip>
void Menu()
{
	int choise;
	cQueue<Player> aLobby;									//����� �������
	do
	{
		cout << "1 - Play game" << endl;						
		cout << "2 - Make lobby" << endl;
		cout << "3 - Show lobby" << endl;
		cout << "0 - exit" << endl;
		cout << "Your choice: ";
		choise = InputInt(cin, 0, 3);						//���� ������
		switch (choise)										//����� ��������������� �������
		{
		case 1:												//����
			system("cls");
			if (aLobby.empty())
			{
				cout << "Please, make lobby of players." << endl;
			}
			else
			{
				Game aGame(aLobby);
				aGame.Play();
			}
			break;
		case 2:												//������ � �����
			system("cls");
			LobbyInterface(aLobby);
			break;
		case 3:												//����� �����
			system("cls");
			if (!aLobby.empty())
			{
				aLobby[0].ShowTable();
				cout << aLobby;
			}
			else
			{
				cout << "Lobby is empty." << endl;
			}
			break;
		}
	} while (choise);
}