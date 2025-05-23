#pragma once
#include "Card.h"
#include "config.h"

class Base_deck
{

public:
	void first_cards(Card c1, Card c2); // initializing the player's deck
	void getCard(Card c); // a function to get a card from the deck (Deck)
	int getNumberofCards(); // a function that returns the number of cards that there are in the player's deck
	int getValueofCards(); // a function that returns the value of the cards in the player's deck
	void resetdeck(); // a function that clears dealer's deck

protected:
	std::vector<Card> deck; // a vector for the player's deck (his cards)
};

class Dealer_deck : public Base_deck
{
	static Dealer_deck* m_instance;
public:
	void draw(); // // a function that draws dealer's deck
	static Dealer_deck* getInstance();
	static void releaseInstance() { if (m_instance) delete m_instance; m_instance = nullptr; }
};

class Player_deck : public Base_deck
{
	static Player_deck* m_instance;
public:
	void draw(); // // a function that draws player's deck
	static Player_deck* getInstance();
	static void releaseInstance() { if (m_instance) delete m_instance; m_instance = nullptr; }
};