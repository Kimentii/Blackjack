//Deck.h
#include "Deck.h"
#include "TextFile.cpp"
Deck::Deck(int n) : m_NumberOfCards(n)
{
	m_Cards.reserve(m_NumberOfCards);
	Populate();
}
Deck::~Deck() {}
void Deck::Populate()
{
	Clear();
	if (m_NumberOfCards == 52)
	{
		for (int s = Card::CLUBS; s <= Card::SPADES; ++s)		//Создает в колоде карты всех мастей и весов
		{
			for (int r = Card::ACE; r <= Card::KING; ++r)
			{
				Add(Card(static_cast<Card::rank>(r), static_cast<Card::suit>(s)));
			}
		}
	}
	else
	{
		for (int s = Card::CLUBS; s <= Card::SPADES; ++s)		//Создает в колоде карты от 6 до короля
		{
			for (int r = Card::SIX; r <= Card::KING; ++r)
			{
				Add(Card(static_cast<Card::rank>(r), static_cast<Card::suit>(s)));
			}
		}
		for (int s = Card::CLUBS; s <= Card::SPADES; ++s)		//Добавление тузов всех мастей в колоду
		{
			Add(Card(Card::ACE, static_cast<Card::suit>(s)));
		}
	}
}
void Deck::Shuffle()										//Перемешивает колоду
{
	random_shuffle(m_Cards.begin(), m_Cards.end());
}
void Deck::Deal(Hand& aHand)
{
	if (!m_Cards.empty())									//Если в колоде есть карты, то
	{
		aHand.Add(m_Cards.back());							//Добовляет в руку карту
		m_Cards.pop_back();									//Удаляет её из колоды
	}
	else
	{
		cout << "Out of cards. Unable to deal.";
	}
}
void Deck::AdditionalCards(GenericPlayer& aGP)
{
	TextFile<Hand> file;
	char c;
	file.open_trunc(STEP);
	cout << endl;
	while (!(aGP.IsBusted()) && aGP.IsHitting() && !Empty())
	{
		//Раздает карты игроку, пока у него не перебор или пока он хочет взять еще одну
		file << aGP;
		Deal(aGP);
		cout << aGP << endl;
		cout << "Do you want to take a step back?(y/n)" << endl;
		cin >> c;
		if (c == 'y' || c == 'Y')
		{
			file >> aGP;
			file.refresh();
			cout << aGP << endl;
		}
		else
		{
			file.clear_file();
		}
		if (aGP.IsBusted())									//Если перебор, то
		{
			aGP.Bust();										//Объявляет перебор у игрока
		}
	}
}
void Deck::AdditionalCardsHouse(GenericPlayer& aGP)
{
	cout << endl;
	while (!(aGP.IsBusted()) && aGP.IsHitting() && !Empty())
	{
		//Раздает карты игроку, пока у него не перебор или пока он хочет взять еще одну
		Deal(aGP);
		cout << aGP << endl;
		if (aGP.IsBusted())									//Если перебор, то
		{
			aGP.Bust();										//Объявляет перебор у игрока
		}
	}
}
bool Deck::Empty()											//Возвращает true, если колода пуста
{
	return m_Cards.empty();
}