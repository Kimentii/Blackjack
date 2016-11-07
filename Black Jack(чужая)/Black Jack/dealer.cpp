#include "dealer.h"
#include "random.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Dealer::Dealer()
{
	mTotal = 0;
	mInsurance = 0;
}

int Dealer::deal(int value)
{
	int cards[2];
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

	

	cout << "\nDealer cards: " << cards[0] << ", ||";//cards[1];

	if(cards[0] == 11)
	{
		char insurance = 'n';
		cout << "\nInsurance? Y/N: ";
		cin >> insurance;
		insurance = toupper(insurance);

		if(insurance == 'Y')
		{
			cout << "You have insurance!" << endl;
			setInsurance(1);
		}
		else
		{
			cout << "You no have insurance!" << endl;
			setInsurance(0);
		}
	}

	if(cards[0] == 11 || cards[1] == 11)
	{
		if(value > 21)
			value -= 10;
	}
	return value;
}

int Dealer::game(int value)
{
	int card = 0;

	while(value < 17)
	{
		card = Random(1, 14);

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

		if(card == 11 && value > 21)
		{
			card -= 10;
		}

		if(value > 21)
		{
			cout << "\nDealer Busts!" << endl;
		}
	}
	return value;
}

int Dealer::getTotal()
{
	return mTotal;
}

void Dealer::setTotal(int total)
{
	mTotal = total;
}

int Dealer::getInsurance()
{
	return mInsurance;
}

void Dealer::setInsurance(int add)
{
	mInsurance = add;
}