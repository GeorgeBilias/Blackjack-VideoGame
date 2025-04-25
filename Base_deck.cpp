#include "Base_deck.h"

void Base_deck::first_cards(Card c1, Card c2)
{
    deck.push_back(c1);
    deck.push_back(c2);
}

void Base_deck::getCard(Card c)
{
    deck.push_back(c);
}

int Base_deck::getNumberofCards()
{
    return deck.size();
}

int Base_deck::getValueofCards()
{
    int sum = 0;
    for (auto& card : deck)
        sum += card.getValue();
    return sum;
}

void Base_deck::resetdeck()
{
    deck.clear();
}
