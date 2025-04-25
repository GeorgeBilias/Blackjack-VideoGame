#pragma once
#include "Card.h"
#include "config.h"
#include "Base_deck.h"

class Dealer_deck : public Base_deck
{
	static Dealer_deck* m_instance;
public:
	void draw(); // // a function that draws dealer's deck
	static Dealer_deck* getInstance();
	static void releaseInstance() { if (m_instance) delete m_instance; m_instance = nullptr; }
private:
	std::vector<Card> dealer_deck; // a vector for the player's deck (his cards)
};