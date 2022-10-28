#pragma once

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <random>
#include <chrono>

using namespace std;

class Card
{
private:
	string _type;
	string _name;
	int _value;
	const string card_values[13]
	{ "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
public:
	Card(int value, string type);
	Card(const Card& other);
	~Card() {};
	void setType(string t);
	void setName(string n);
	void setValue(int v);
	void printCard();
	string getType() const;
	string getName() const;
	int getValue() const;
	Card& operator=(const Card& other);
	bool operator==(const Card& other)const; //if the value of the cards are equal.
	bool operator!=(const Card& other)const; //if the value of the cards are not equal.
	bool operator>(const Card& other)const; //if the value is bigger.
	bool operator<(const Card& other)const; //if the value is smaller.
};

class Deck {

private:
	vector<Card> deck;
	const string card_values[13]
	{ "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };

public:
	Deck() { fildeck(); }

	void fildeck();
	void printDeck();
	void shuffleDeck();
	Card outCard();
	int countCardInDeck();
};

class Player {

private:
	string _name;
	int _amount;
	vector<Card> _hand;

public:
	Player(string name, int amt = 0) : _name(name), _amount(amt) {};
	Player(const Player& other);
	~Player() {};

	void setName(string n);
	void setAmount(int am);

	string getName() const;
	int getAmount() const;
	vector<Card> getHand()const;

	void printPlayer();
	void addCard(Card c);
	void printHand();
	void amountUpdatePlus(int am);
	void amountUpdateMinus(int am);
	void deleteAllHand();
	int score()const;
};

