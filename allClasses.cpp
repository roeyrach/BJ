#include "allClasses.h"

Card::Card(int value, string type)
{
	this->_value = value;
	this->_type = type;
	this->_name = card_values[value] + ' ' + type;
}

Card::Card(const Card& other)
{
	this->_value = other._value;
	this->_type = other._type;
	this->_name = card_values[other._value] + ' ' + other._type;
}

void Card::setType(string t)
{
	this->_type = t;
}

void Card::setName(string n)
{
	this->_name = n;
}

void Card::setValue(int v)
{
	this->_value = v;
}

void Card::printCard()
{
	cout << this->getName();
}

string Card::getType() const
{
	return this->_type;
}

string Card::getName() const
{
	return this->_name;
}

int Card::getValue() const
{
	return this->_value;
}

Card& Card::operator=(const Card& other)
{
	if (this == &other)
		return *this;
	this->_value = other._value;
	this->_type = other._type;
	this->_name = other.card_values[other._value] + ' ' + other._type;
	return *this;
}

bool Card::operator==(const Card& other) const
{
	if (this->getValue() == other.getValue() && this->getType() == other.getType())
	{
		return true;
	}
	return false;
}

bool Card::operator!=(const Card& other) const
{
	if (this->getValue() != other.getValue() || this->getType() != other.getType())
	{
		return true;
	}
	return false;
}

bool Card::operator>(const Card& other) const
{
	if (this->getValue() > other.getValue())
		return true;
	return false;
}

bool Card::operator<(const Card& other) const
{
	if (this->getValue() < other.getValue())
		return true;
	return false;
}

void Deck::fildeck()
{
	for (int j = 0; j < 52; j++)//1-53
	{
		if (j <= 12)//13
		{
			deck.push_back(Card(j, "Spades"));
		}
		if (j >= 13 && j <= 25)//14 - 26
		{
			deck.push_back(Card(j - 13, "Clubs"));
		}
		if (j >= 26 && j <= 38)//27 - 39
		{
			deck.push_back(Card(j - 26, "Hearts"));
		}
		if (j >= 39)//40
		{
			deck.push_back(Card(j - 39, "Diamonds"));
		}
	}
}

void Deck::printDeck()
{
	for (int i = 0; i < deck.size(); i++)
	{
		Card temp(deck[i]);
		cout << "[" << temp.getName() << "]" << " ";
	}
}

void Deck::shuffleDeck()
{
	std::shuffle(deck.begin(), deck.end(), std::random_device());
}

Card Deck::outCard()
{
	Card tmp(deck.back());
	deck.pop_back();
	return tmp;
}

int Deck::countCardInDeck()
{
	return (deck.size());
}

Player::Player(const Player& other)
{
	this->_name = other._name;
	this->_amount = other._amount;
}

void Player::setName(string n)
{
	this->_name = n;
}

void Player::setAmount(int am)
{
	this->_amount = am;
}

string Player::getName() const
{
	return this->_name;
}

int Player::getAmount() const
{
	return this->_amount;
}

vector<Card> Player::getHand() const
{
	return this->_hand;
}

void Player::printPlayer()
{
	cout << this->getName() << " ";
	cout << this->getAmount();
	if (_hand.size() != 0)
	{
		for (int i = 0; i < _hand.size(); i++)
		{
			_hand[i].printCard();
		}
	}
}

void Player::addCard(Card c)
{
	_hand.push_back(c);
}

void Player::printHand()
{
	for (int i = 0; i < _hand.size(); i++)
	{
		Card temp(_hand[i]);
		cout << "[" << temp.getName() << "]" << ' ';
	}
}

void Player::amountUpdatePlus(int am)
{
	setAmount(this->_amount + am);
}

void Player::amountUpdateMinus(int am)
{
	setAmount(this->_amount - am);
}

void Player::deleteAllHand()
{
	if (_hand.size() == 0)
	{
		/*cout << "Hand is empty.";*/
		return;
	}
	_hand.clear();
	//if (_hand.size() == 0)
	//{
	//	cout << "All cards deleted.";
	//}

}

int Player::score() const
{
	int score = 0;

	for (int i = 0; i < _hand.size(); i++)
	{
		auto first = _hand[i].getName()[0];
		if (first == 'J' || first == 'Q' || first == 'K')
		{
			score += 10;
		}
		if (first == 'A')
		{
			score += 11;
		}
		if (_hand[i].getValue() >= 1 && _hand[i].getValue() <= 9)
		{
			score += _hand[i].getValue() + 1;
		}
	}
	for (int i = 0; i < _hand.size(); i++)
	{
		if (_hand[i].getName()[0] == 'A' && score > 21)
		{
			score -= 10;
		}
	}
	return score;
}



