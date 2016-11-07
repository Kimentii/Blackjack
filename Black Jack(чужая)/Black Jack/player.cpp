#include "player.h"
#include "random.h"
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

Player::Player()
{
	mTotal = 0;
	mMoney = 100.0f;
	mWager = 0.0f;
	mName = "Player";	
	mRetract = 0;
}

void Player::begin()
{
	cout << "== Welcome to Black Jack ==" << endl;
	cout << "===========================" << endl;
	cout << "Enter your caracter's name: ";
	getline(cin, mName);	
	cout << "You start game with $" << mMoney  << "!"<< endl;
}

int Player::deal(int value)
{
	int cards[2];
	int choice = 0;
	cards[0] = Random(1, 14);
	cards[1] = Random(1, 14);	
	value = cards[0] + cards[1];	
	if(cards[0] == 12 ) 
	{
		value -= 2;
	}
	if(cards[1] == 12)
	{
		value -= 2;
	}
	
	if(cards[0] == 13)
	{
		value -= 3;
	}
	if( cards[1] == 13)
	{
		value -= 3;
	}

	if(cards[0] == 14)
	{
		value -= 4;
	}	
	if(cards[1] == 14)
	{
		value -= 4;
	}
	
	cout << "\nCards: " << cards[0] << ", " << cards[1] << endl;
	cout << "Total: " << value << endl;;

	if(cards[0] == 11 || cards[1] == 11)
	{
		bool ok = false;
		do
		{
			cout << "\nAce 1 or 11?: ";
			cin >> choice;

			if(choice == 1)
			{
				value -= 10;
				ok = true;
			}
			else if(choice == 11)
			{
				ok = true;
			}
		}while(!ok);
	}
	return value;
}

int Player::game(int value)
{
	int card = 0;
	int choice = 1;	
	char redouble = 'n';

	if(value == 9 || value == 10 || value == 11)
	{		
		cout << "\nRedouble the bet?: Y/N: ";
		cin >> redouble;
		redouble = toupper(redouble);	

		if(redouble =='Y')
		{		
			setWager(getWager() * 2); 
			card = Random(1, 11);		

			if(card == 11)
			{
				bool ok = false;
				do
				{					
					cout << "\n1 or 11?: ";
					cin >> card;

					if(card == 1 || card == 11)
					{
						ok = true;
					}
				}while(!ok);
			}			
			value += card;
			cout << "\nYour card is: " << card << endl;
			cout << "Your card total is: " << value << endl;

			if(value > 21)
			{
				cout << "You bust!" << endl;
				//break;
				return value;
			}
		}
		else
		{			
			do
			{
				cout << "\nWould you like: \n"
					"1)Hit\n"
					"2)Stay :";
				cin >> choice;

				switch(choice)
				{
				case 1:
					card = Random(1, 14);
					
					if(card == 11)
					{
						bool ok = false;
						do
						{					
							cout << "\n1 or 11?: ";
							cin >> card;

							if(card == 1 || card == 11)
							{
								ok = true;
							}
						}while(!ok);
					}

					if(card == 12)
					{
						value -= 2;
					}
					else if(card == 13)
					{
						value -= 3;
					}
					else if(card == 14)
					{
						value -= 4;
					}

					value += card;
					cout << "\nYour card is: " << card << endl;
					cout << "Your card total is: " << value << endl;

					if(value > 21)
					{
						cout << "You bust!" << endl;
						//break;
						return value;
					}
					break;
				case 2:
					break;
				default:					
					break;
				}
			}while(choice == 1);
		}
	}
	else
	{		
		do
		{			
			cout << "\nWould you like: \n"
				"1)Hit\n"
				"2)Stay: ";
				
			cin >> choice;

			switch(choice)
			{
			case 1:
				card = Random(1, 14);
				
				if(card == 11)
				{
					bool ok = false;
					do
					{					
						cout << "\n1 or 11?: ";
						cin >> card;

						if(card == 1 || card == 11)
						{
							ok = true;
						}
					}while(!ok);
				}	

				
				if(card == 12)
				{
					value -= 2;
				}
				else if(card == 13)
				{
					value -= 3;
				}
				else if(card == 14)
				{
					value -= 4;
				}

				value += card;
				cout << "\nYour card is: " << card << endl;
				cout << "Your card total is: " << value << endl;

				if(value > 21)
				{
					cout << "You bust!" << endl;
					//break;
					return value;
				}
				break;
			case 2:
				break;
			default:				
				break;
			}
		}while(choice == 1);
	}
	return value;
}

float Player::getMoney()
{
	return mMoney;
}

void Player::setMoney(float money)
{
	mMoney += money;
}

int Player::getWager()
{
	return mWager;
}

void Player::setWager(float wager)
{
	mWager = wager;
}

int Player::getTotal()
{
	return mTotal;
}

void Player::setTotal(int total)
{
	mTotal = total;
}

void Player::viewStats()
{
	cout << endl;
	cout << "PLAYER STATS" << endl;
	cout << "============" << endl;
	cout << "Name = " << mName << endl;
	cout << "Games = " << numberGames() <<  endl;
	cout << "Wins = " << gamesWin() << endl;
	cout << "Lost = " << numberGames() - gamesWin() - numberPush() << endl;
	cout << "Push = " << numberPush() << endl;
	cout << "Money = $" << mMoney << endl;	
	cout << "END PLAYER STATS" << endl;
	cout << "================" << endl << endl;
}

void Player::rest()
{
	cout << "Resting..." << endl;
	mMoney = 100;
}

int Player::wins = 0;
int Player::nrGames = 0;
int Player::nrPush = 0;

int Player::gamesWin(int nr)
{	
	wins += nr;
	return wins;
}

int Player::numberGames(int nr)
{
	nrGames += nr;
	return nrGames;
}

int Player::numberPush(int nr)
{
	nrPush += nr;
	return nrPush;
}

int Player::gamesWin()
{
	return wins;
}

int Player::numberGames()
{
	return nrGames;
}

int Player::numberPush()
{
	return nrPush;
}
int Player::getRetract()
{
	return mRetract;
}

void Player::setRetract(int nr)
{
	mRetract = nr;
}