
#include <iostream>
#include "allClasses.h"

using namespace std;

int main()
{

	string tmp;
	cout << "Hello and welcome to Black Jack!!!" << endl;
	cout << "Would you like to play?" << endl << "write yes/no: ";
	cin >> tmp;
	if (tmp == "yes")
	{
		cout << "Let's play!!!" << endl;
		string player1Name;
		int player1Amount = 0;
		cout << "Write your name: ";
		cin >> player1Name;
		cout << "How much money do you want to change?(above 5$) :";
		cin >> player1Amount;
		Player player1(player1Name, player1Amount);
		Player dealer("Dealer", 5000);
		Deck deck1;
		deck1.fildeck();
		deck1.fildeck();
		deck1.fildeck();
		deck1.shuffleDeck();
		bool exit = true;
		cout << "The deck has been shuffled" << endl;
		while (exit)
		{
			cout << "Player bet? :";
			int bet;
			bool aCard = true;
			cin >> bet;
			player1.amountUpdateMinus(bet);
			dealer.addCard(deck1.outCard());
			player1.addCard(deck1.outCard());
			player1.addCard(deck1.outCard());
			dealer.addCard(deck1.outCard());
			cout << "The dealer's hand: " << endl << "first card: [COVERD]" << " second card: "
				<< "[" << dealer.getHand()[1].getName() << "]" << endl;
			cout << player1.getName() << "'s hand: ";
			player1.printHand();
			cout << " " << player1.getName() << "'s score = " << player1.score() << endl;
			if (player1.score() == 21)
			{
				player1.amountUpdatePlus((bet * 2));
				cout << "You won !!!" << endl;
				cout << "You won " << (bet * 2) << "$" << ", your amount right now is: " << player1.getAmount() << endl;
				player1.deleteAllHand();
				dealer.deleteAllHand();
				aCard = false;
			}
			bool dealerTurn = false;
			if (player1.score() != 21)
			{
				while (aCard)
				{
					cout << "Another card? yes/no" << endl;
					string anotherCard;
					cin >> anotherCard;
					if (anotherCard == "yes")
					{
						player1.addCard(deck1.outCard());
						player1.printHand();
						cout << player1.getName() << "'s score = " << player1.score() << endl;
						/////////////////////////////////////////////////////////////////////
						if (player1.score() == 21)
						{
							player1.amountUpdatePlus((bet * 2));
							cout << "You won !!!" << endl;
							cout << "You won " << (bet * 2) << "$" << ", your amount right now is: " << player1.getAmount() << endl;
							player1.deleteAllHand();
							dealer.deleteAllHand();
							aCard = false;
							dealerTurn = true;
							break;
						}
						/////////////////////////////////////////////////////////////////////
						if (player1.score() > 21)
						{
							cout << endl << "You lost" << endl;
							cout << "Your amount now is " << player1.getAmount() << endl;
							player1.deleteAllHand();
							dealer.deleteAllHand();
							dealerTurn = true;
							aCard = false;
							break;
						}
					}
					if (anotherCard == "no")
					{
						aCard = false;
						break;
					}
					/////////////////////////////////////////////////////////////////////
				}
				if (player1.score() < 21 && dealerTurn == false)
				{
					cout << "Dealer reveal full hand: ";
					dealer.printHand();
					cout << "dealer's score = " << dealer.score() << endl;
					cout << endl;
					if (dealer.score() == player1.score() && dealer.score() >= 17)
					{
						player1.amountUpdatePlus(bet);
						cout << "Draw" << endl;
						player1.deleteAllHand();
						dealer.deleteAllHand();
						aCard = false;
					}
					bool handChanged = false;
					if (dealer.score() == 21 || dealer.score() > player1.score())
					{
						handChanged = true;
						cout << "You lost" << endl;
						cout << "Your amount now is " << player1.getAmount() << endl;
						player1.deleteAllHand();
						dealer.deleteAllHand();
					}
					if (dealer.score() < 21 && player1.score() != 21 || player1.score() > 21)
					{
						while (dealer.score() <= 17)
						{
							dealer.addCard(deck1.outCard());
						}
						dealer.printHand();
						if (dealer.score() == player1.score())
						{
							player1.amountUpdatePlus(bet);
							cout << "Draw" << endl;
							player1.deleteAllHand();
							dealer.deleteAllHand();
							aCard = false;

						}
						cout << "dealer's score = " << dealer.score() << endl;
						if ((dealer.score() == 21 && handChanged == false) || (dealer.score() > player1.score() && dealer.score() <= 21 && handChanged == false))
						{
							cout << "You lost" << endl;
							cout << "Your amount now is " << player1.getAmount() << "$" << endl;
							player1.deleteAllHand();
							dealer.deleteAllHand();
						}
						cout << endl;
						if (dealer.score() > 21 || dealer.score() < player1.score())
						{
							player1.amountUpdatePlus((bet * 2));
							cout << "You won !!!" << endl;
							cout << "You won " << (bet * 2) << "$" << ", your amount right now is: " << player1.getAmount() << endl;
							player1.deleteAllHand();
							dealer.deleteAllHand();
						}
					}

				}

			}
		}
	}

	else
		cout << "Ok bye!";
}
