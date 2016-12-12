//LobbyInterface.cpp
#include "Queue.cpp"
#include "Player.h"
#include "SafeFunctions.h"
#include "Algorithm.cpp"
#include "TextFile.cpp"
#include <stack>
void LobbyInterface(cQueue<Player>& aLobby)					//Работа с лобби
{
	stack<cQueue<Player>> actions;							//Стек для отмены действий
	TextFile<Player> file(FNAME);							//Файл для записи лобби
	int x;
	Player bufPlr;
	cout.setf(ios::left);
	actions.push(aLobby);
	do
	{
		cout << "What do you want to do?" << endl;			//Вывод меню
		cout << "1 - Add player" << endl;
		cout << "2 - Show lobby" << endl;
		cout << "3 - Delete player from front" << endl;
		cout << "4 - Delete player from end" << endl;
		cout << "5 - Clear lobby" << endl;
		cout << "6 - Show size of lobby" << endl;
		cout << "7 - Sort lobby by player's name" << endl;
		cout << "8 - Shuffle lobby" << endl;
		cout << "9 - Save lobby" << endl;
		cout << "10 - Use your old lobby" << endl;
		cout << "11 - Remove my last atcion" << endl;
		cout << "0 - Go to main menu" << endl;
		cout << "Your choice: ";
		x = InputInt(cin, 0, 11);							//Ввод выбора
		switch (x)											//Вызов соответствующей функции
		{
		case 1:												//Добавление игрока
			actions.push(aLobby);
			cin >> bufPlr;
			aLobby.PushBack(bufPlr);
			system("cls");
			break;
		case 2:												//Вывод игроков
			system("cls");
			if (!aLobby.empty())
			{
				bufPlr.ShowTable();
				cout << aLobby;
			}
			else
			{
				cout << "Lobby is empty." << endl;
			}
			break;
		case 3:												//Удалние игрока из начала лобби
			actions.push(aLobby);
			try
			{
				aLobby.PopFront();
			}
			catch (QueueExp qe)
			{
				cout << "Error number is " << qe.error() << endl;
				cout << qe.what() << endl;
				system("pause");
			}
			system("cls");
			break;
		case 4:												//Удаления игрока из конца лобби
			actions.push(aLobby);
			try
			{
				aLobby.PopBack();
			}
			catch (QueueExp qe)
			{
				cout << "Error number is " << qe.error() << endl;
				cout << qe.what() << endl;
				system("pause");
			}
			system("cls");
			break;
		case 5:												//Очистка лобби
			actions.push(aLobby);
			aLobby.clear();
			system("cls");
			break;
		case 6:												//Вывод размера лобби
			system("cls");
			cout << "Size: " << aLobby.size() << endl;
			break;
		case 7:												//Сортировка лобби
			system("cls");
			actions.push(aLobby);
			if (!aLobby.empty())
			{
				Sort(aLobby.begin(), aLobby.end());
				cout << "Lobby was sorted." << endl;
			}
			else
			{
				cout << "Lobby is empty." << endl;
			}
			break;
		case 8:												//Перемешивание лобби
			system("cls");
			actions.push(aLobby);
			if (!aLobby.empty())
			{
				Random_Shuffle(aLobby.begin(), aLobby.end());
				cout << "Lobby was shuffled." << endl;
			}
			else
			{
				cout << "Lobby is empty." << endl;
			}
			break;
		case 9:												//Запись лобби в файл
			system("cls");
			file << aLobby;
			cout << "Lobby wrote." << endl;
			break;
		case 10:											//Чтение лобби из файла
			system("cls");
			actions.push(aLobby);
			file >> aLobby;
			break;
		case 11:											//Отмена действия
			system("cls");
			if (!actions.empty())
			{
				aLobby = actions.top();
				actions.pop();
			}
			else
			{
				cout << "Can't remove." << endl;
			}
			break;
		}
	} while (x);
	system("cls");
}