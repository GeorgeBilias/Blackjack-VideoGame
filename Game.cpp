#include "Game.h"
#include "graphics.h"
#include "config.h"
#include "Deck.h"
#include "Hit.h"
#include "Stand.h"
#include "Exit.h"
#include "Replay.h"
#include "Card.h"
#include <iostream>
#include "Base_deck.h"

//Game functions
void Game::update()
{
	if (m_state == STATE_INIT) 
	{
		return;
	}
	if (m_state == STATE_LOADING)
	{
		init();
		m_state = STATE_IDLE;
		return;
	}

	Hit* myhit = Hit::getInstance();
	myhit->update();

	Stand* mystand = Stand::getInstance();
	mystand->update();

	Exit* myexit = Exit::getInstance();
	myexit->update();

	Replay* myreplay = Replay::getInstance();
	myreplay->update();

	graphics::MouseState ms;
	graphics::getMouseState(ms);

	float mx = graphics::windowToCanvasX(ms.cur_pos_x);
	float my = graphics::windowToCanvasX(ms.cur_pos_y);

	Hit* m_active_hit = nullptr;
	Hit* cur_player = nullptr;

	Stand* m_active_stand = nullptr;
	Stand* cur_player_stand = nullptr;

	Exit* m_active_exit = nullptr;
	Exit* cur_player_exit = nullptr;

	Replay* m_active_replay = nullptr;
	Replay* cur_player_replay = nullptr;

	if (myhit->contains(mx, my) && running)
	{
		myhit->setHighlight(true);
		cur_player = myhit;
	}
	else
		myhit->setHighlight(false);
	
	if (ms.button_left_pressed && cur_player && running)
	{
		m_active_hit = cur_player;
		graphics::playSound(std::string(ASSET_PATH) + "buttonsound.mp3", 1.0f, false);
		Deck* mydeck = Deck::getInstance();
		Player_deck* myplayerdeck = Player_deck::getInstance();
		Card c = mydeck->giveCard();
		myplayerdeck->getCard(c);
		
	}

	if (mystand->contains(mx, my) && running)
	{
		mystand->setHighlight(true);
		cur_player_stand = mystand;
	}
	else
		mystand->setHighlight(false);

	if (ms.button_left_pressed && cur_player_stand && running)
	{
		m_active_stand = cur_player_stand;
		graphics::playSound(std::string(ASSET_PATH) + "buttonsound.mp3", 1.0f, false);
		Deck* mydeck = Deck::getInstance();
		Dealer_deck* mydealerdeck = Dealer_deck::getInstance();

		while (mydealerdeck->getValueofCards() <= 17) {
			Card d = mydeck->giveCard();
			mydealerdeck->getCard(d);
		}

	}

	if (myexit->contains(mx, my) )
	{
		myexit->setHighlight(true);
		cur_player_exit = myexit;
	}
	else
		myexit->setHighlight(false);

	if (ms.button_left_pressed && cur_player_exit)
	{
		m_active_exit = cur_player_exit;
		graphics::playSound(std::string(ASSET_PATH) + "buttonsound.mp3", 1.0f, false);
		graphics::stopMessageLoop();
		graphics::setFullScreen(false);
	}

	if (myreplay->contains(mx, my))
	{
		myreplay->setHighlight(true);
		cur_player_replay = myreplay;
	}
	else
		myreplay->setHighlight(false);

	if (ms.button_left_pressed && cur_player_replay)
	{
		m_active_replay = cur_player_replay;
		graphics::playSound(std::string(ASSET_PATH) + "buttonsound.mp3", 1.0f, false);

		running = true;

		Deck* mydeck = Deck::getInstance();
		mydeck->resetdeck();

		mydeck->fill_deck();
		mydeck->randomise_cards();

		Dealer_deck* mydealerdeck = Dealer_deck::getInstance();
		mydealerdeck->resetdeck();


		Player_deck* myplayerdeck = Player_deck::getInstance();
		myplayerdeck->resetdeck();

		//proti karta
		Card c1 = mydeck->giveCard();

		//deuteri karta
		Card c2 = mydeck->giveCard();

		myplayerdeck->first_cards(c1, c2);

	}
}

Game* Game::getInstance()
{
	if (!m_instance)
	{
		m_instance = new Game();
	}
	return m_instance;
	
}

void Game::init()
{
	//graphics::preloadBitmaps(ASSET_PATH);
	graphics::playMusic(std::string(ASSET_PATH) + "sound.mp3", 0.1f, true, 4000);

	Deck* mydeck = Deck::getInstance();
	mydeck -> fill_deck();
	mydeck -> randomise_cards();
	Player_deck* myplayerdeck = Player_deck::getInstance();

	//proti karta
	Card c1 = mydeck -> giveCard();

	//deuteri karta
	Card c2 = mydeck -> giveCard();

	myplayerdeck->first_cards(c1, c2);

	running = true;

}


void Game::draw()
{
	//Creates a brush 
	graphics::Brush br;
	br.outline_opacity = 0.0f;
	SETCOLOR(br.fill_color, 1.0f, 1.0f, 1.0f);

	if (m_state == STATE_INIT)
	{
		graphics::setFont(std::string(ASSET_PATH) + "bodoni.ttf");
		graphics::drawText(CANVAS_WIDTH/3, CANVAS_HEIGHT/2 , 60.0f , "  Loading..", br);
		m_state = STATE_LOADING;
		return;
	}
		
	br.outline_opacity = 0.0f;

	Player_deck* myplayerdeck = Player_deck::getInstance();
	Dealer_deck* mydealerdeck = Dealer_deck::getInstance();
	
	//We create the background
	br.texture = std::string(ASSET_PATH) + "blackjack_background.png";
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_WIDTH, br);

	//We create a mat on top of the background
	br.texture = std::string(ASSET_PATH) + "mat.png";
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2 - 35, CANVAS_WIDTH - 100.0f, CANVAS_HEIGHT + 150, br);
	//We create some cards on the top left of the screen
	br.texture = std::string(ASSET_PATH) + "cards.png";
	// and reverse them
	graphics::setOrientation(180.f);
	graphics::drawRect(CARD_X, CARD_Y, CARD_WIDTH, CARD_HEIGHT, br);
	// reverse back so everything we do next will be normal
	graphics::setOrientation(0.f);


	//draws values from player's deck and dealer's deck
	myplayerdeck->draw();
	char info[40];
	sprintf_s(info, "VALUE: %3.0i", myplayerdeck->getValueofCards());
	graphics::drawText(50, 470, 30, info, br);

	mydealerdeck->draw();
	char infod[40];
	sprintf_s(infod, "VALUE: %3.0i", mydealerdeck->getValueofCards());
	graphics::drawText(800, 180, 30, infod, br);

	//draws all buttons 
	Hit* myhit = Hit::getInstance();
	myhit->draw();

	Stand* mystand = Stand::getInstance();
	mystand->draw();

	Exit* myexit = Exit::getInstance();
	myexit->draw();

	Replay* myreplay = Replay::getInstance();
	myreplay->draw();
	

	// draws end screen 
	if (myplayerdeck->getValueofCards() > 21) {

		br.texture = std::string(ASSET_PATH) + "blackjack_background.png";
		graphics::drawRect(CANVAS_WIDTH / 6, CANVAS_HEIGHT / 2, CANVAS_WIDTH*2, CANVAS_HEIGHT / 4, br);

		SETCOLOR(br.fill_color, 1.0f, 0.82f, 0.18f);
		char infor[40];
		sprintf_s(infor, "YOU LOST BECAUSE YOU HIT: %3.0i", myplayerdeck->getValueofCards());
		graphics::drawText(CANVAS_WIDTH / 6, CANVAS_HEIGHT / 2, 40, infor, br);
		running = false;
	}
	else if (mydealerdeck->getValueofCards() > 21) {

		br.texture = std::string(ASSET_PATH) + "blackjack_background.png";
		graphics::drawRect(CANVAS_WIDTH / 6, CANVAS_HEIGHT / 2, CANVAS_WIDTH * 2, CANVAS_HEIGHT / 4, br);

		SETCOLOR(br.fill_color, 1.0f, 0.82f, 0.18f);
		char infor[40];
		sprintf_s(infor, "YOU WIN BECAUSE DEALER HIT: %3.0i", mydealerdeck->getValueofCards());
		graphics::drawText(CANVAS_WIDTH / 6, CANVAS_HEIGHT / 2, 40, infor, br);
		running = false;
	}
	else if ((myplayerdeck->getValueofCards() == mydealerdeck->getValueofCards()) && mydealerdeck->getValueofCards() != 0)  {

		br.texture = std::string(ASSET_PATH) + "blackjack_background.png";
		graphics::drawRect(CANVAS_WIDTH / 6, CANVAS_HEIGHT / 2, CANVAS_WIDTH * 2, CANVAS_HEIGHT / 4, br);

		SETCOLOR(br.fill_color, 1.0f, 0.82f, 0.18f);
		char infor[40];
		sprintf_s(infor, "TIE BEACUSE BOTH HIT: %3.0i", myplayerdeck->getValueofCards());
		graphics::drawText(CANVAS_WIDTH / 6, CANVAS_HEIGHT / 2, 40, infor, br);
		running = false;
	}
	else if (mydealerdeck->getValueofCards()> myplayerdeck->getValueofCards() && mydealerdeck->getValueofCards()<=21 ) {

		br.texture = std::string(ASSET_PATH) + "blackjack_background.png";
		graphics::drawRect(CANVAS_WIDTH / 6, CANVAS_HEIGHT / 2, CANVAS_WIDTH * 2, CANVAS_HEIGHT / 4, br);

		SETCOLOR(br.fill_color, 1.0f, 0.82f, 0.18f);
		char infor[40];
		sprintf_s(infor, "YOU LOST BECAUSE DEALER HIT: %3.0i", mydealerdeck->getValueofCards());
		graphics::drawText(CANVAS_WIDTH / 6, CANVAS_HEIGHT / 2, 40, infor, br);
		running = false;
	}
	else if ((mydealerdeck->getValueofCards() < myplayerdeck->getValueofCards()) && mydealerdeck->getValueofCards()!=0) {

		br.texture = std::string(ASSET_PATH) + "blackjack_background.png";
		graphics::drawRect(CANVAS_WIDTH / 6, CANVAS_HEIGHT / 2, CANVAS_WIDTH * 2, CANVAS_HEIGHT / 4, br);

		SETCOLOR(br.fill_color, 1.0f, 0.82f, 0.18f);
		char infor[40];
		sprintf_s(infor, "YOU WIN BECAUSE YOU HIT: %3.0i", myplayerdeck->getValueofCards());
		graphics::drawText(CANVAS_WIDTH / 6, CANVAS_HEIGHT / 2, 40, infor, br);
		running = false;
	}	
}


Game::Game()
{
}

Game::~Game()
{	
	
	Deck* mydeck = Deck::getInstance();
	mydeck->resetdeck();

	Player_deck* myplayerdeck = Player_deck::getInstance();
	myplayerdeck->resetdeck();

	Dealer_deck* mydealerdeck = Dealer_deck::getInstance();
	mydealerdeck->resetdeck();

	Stand::releaseInstance();
	Exit::releaseInstance();
	Hit::releaseInstance();
	Replay::releaseInstance();
	Deck::releaseInstance();
	Player_deck::releaseInstance();
	Dealer_deck::releaseInstance();
	Game::releaseInstance();
}


Stand* Stand::m_instance = nullptr;
Exit* Exit::m_instance = nullptr;
Hit* Hit::m_instance = nullptr;
Replay* Replay::m_instance = nullptr;
Deck* Deck::m_instance = nullptr;
Player_deck* Player_deck::m_instance = nullptr;
Dealer_deck* Dealer_deck::m_instance = nullptr;
Game* Game::m_instance = nullptr;