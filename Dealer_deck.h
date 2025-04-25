#pragma once
#include "Card.h"
#include "config.h"
class Dealer_deck
{
	static Dealer_deck* m_instance;
public:
	void first_cards(Card d1, Card d2); // initializing the player's deck
	void showCards(); // a function to show the player's cards
	void getCard(Card d); // a function to get a card from the deck (Deck)
	int getNumberofCards(); // a function that returns the number of cards that there are in the player's deck
	int getValueofCards(); // a function that returns the value of the cards in the player's deck
	void draw(); // a function that draws dealer's deck
	void resetdeck(); // a function that clears dealer's deck
	static Dealer_deck* getInstance();
	static void releaseInstance() { if (m_instance) delete m_instance; m_instance = nullptr; }
private:
	std::vector<Card> dealer_deck; // a vector for the player's deck (his cards)
};