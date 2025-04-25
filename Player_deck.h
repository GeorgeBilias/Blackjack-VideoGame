#pragma once
#include "Card.h"
#include "config.h"
class Player_deck
{
	static Player_deck* m_instance;
public:
	void first_cards(Card c1, Card c2); // initializing the player's deck
	void showCards(); // a function to show the player's cards
	void getCard(Card c); // a function to get a card from the deck (Deck)
	int getNumberofCards(); // a function that returns the number of cards that there are in the player's deck
	int getValueofCards(); // a function that returns the value of the cards in the player's deck
	void draw(); // // a function that draws player's deck
	void resetdeck(); // a function that clears player's deck
	static Player_deck* getInstance();
	static void releaseInstance() { if (m_instance) delete m_instance; m_instance = nullptr; }
private:
	std::vector<Card> player_deck; // a vector for the player's deck (his cards)
};