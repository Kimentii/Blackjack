#include "player.h"
#include "dealer.h"
#include <cstdlib>
#include <ctime>

void main()
{
	srand(time(0));
	Player player;
	Dealer dealer;
	float wager = 0.0f;
	int select = 0;	
	player.begin();

	cout << "1)Game, 2)Rest, 3)View Stats, 4)Quit: ";
	cin >> select;

	do
	{	
		if(select == 1)
		{
			cout << "How much money do you want to wager?: ";
			cin >> wager;
			bool done = false;

			do
			{
				if(wager > player.getMoney())
				{
					cout << "\nNo enough money!.\nPlease introduce corect wager: ";
					cin >> wager;
					done = false;
				}
				else
				{
					done = true;
				}
				
				player.setWager(wager);
			}while(!done);

			player.setTotal(player.deal(player.getTotal()));
			dealer.setTotal(dealer.deal(dealer.getTotal()));

			char retract = 'N';
			cout << "\nRectract? Y/N: ";
			cin >> retract;
			retract = toupper(retract);			

			if(retract == 'Y')
			{
				player.setRetract(1);
			}
			else
			{
				player.setRetract(0);
			}
			
			if(player.getRetract() == 1)
			{
				cout << endl << "You choice retract!" << endl;
				cout << "Dealer win!" << endl;
				player.setMoney(-(wager/2));
				player.setWager(0);
				player.numberGames(1);
			}
			else
			{
				player.setTotal(player.game(player.getTotal()));

				if(dealer.getTotal() < 17 && player.getTotal() < 21)
				{
					dealer.setTotal(dealer.game(dealer.getTotal()));
				}
				
				cout << "\nYour card total: " << player.getTotal();
				cout << "\nDealer card total:" << dealer.getTotal() << endl;
				
				if(player.getTotal() == dealer.getTotal())
				{
					cout << "\nPush" << endl;

					if(dealer.getInsurance() == 1)
					{
						player.setMoney(-(wager/2));
					}
					else
					{
						player.setMoney(0);
					}		
					player.setWager(0);
					player.numberGames(1);
					player.numberPush(1);
				}
			
				if(player.getTotal() > dealer.getTotal() && player.getTotal() < 21 || dealer.getTotal() > 21)
				{
					cout << "\nPlayer wins!" << endl;

					if(dealer.getInsurance() == 1)
					{
						player.setMoney(wager/2);
					}
					else
					{
						player.setMoney(wager);
					}
					player.setWager(0);
					player.numberGames(1);
					player.gamesWin(1);
				}

				if(player.getTotal() == 21)
				{
					cout << "\nPlayer has made BlackJack!" << endl;
					cout << "You win " << (wager * 1.5) << "$ !" << endl;

					if(dealer.getInsurance() == 1)
					{
						player.setMoney((wager * 1.5) - (wager / 2));
					}
					else
					{
						player.setMoney(wager*1.5);
					}				
					player.setWager(0);
					player.numberGames(1);
					player.gamesWin(1);
				}

				if(dealer.getTotal() == 21)
				{
					cout << "Dealer has made BlackJack!" << endl;

					if(dealer.getInsurance() == 0)
					{				
						cout << "You lose " << player.getWager() << "$ !" << endl;
						player.setMoney(-wager);
					}
					else
					{
						player.setMoney(0);
					}
					player.setWager(0);
					player.numberGames(1);				
				}

				if(player.getTotal() > 21 || player.getTotal() < dealer.getTotal() && dealer.getTotal() <= 21)
				{
					cout << "\nDealer wins!" << endl;
					
					if(dealer.getInsurance() == 1)
					{
						player.setMoney(-(wager + (wager/2)));
					}
					else
					{
						player.setMoney(-wager);
					}				
					player.setWager(0);
					player.numberGames(1);
				}
			}
			cout << "You have $" << player.getMoney() << endl << endl;
		}
		else if(select == 2)
		{
			player.rest();
		}
		else if(select == 3)
		{
			player.viewStats();
		}
			cout << "1)Game, 2)Rest, 3)View Stats, 4)Quit: ";
			cin >> select;
	}while(select == 1 || select == 2 || select == 3);
}