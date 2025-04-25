#pragma once

//Game with its functions
class Game
{
public:
	enum game_state_t {STATE_INIT, STATE_LOADING, STATE_IDLE};
protected:
	static Game* m_instance; // creating a game instance
	Game(); // game constructor
	game_state_t m_state = STATE_INIT;
	
public:
	static Game* getInstance(); // a getter for the instance (for checking if game already exists)
	void draw(); // drawing function (for items inside the canvas such as background etc.)
	void update(); // an update function to be used inside the game loop
	~Game(); // game destructor
	void init(); // initializing stuff
	bool running;

	static void releaseInstance() { if (m_instance) delete m_instance; m_instance = nullptr; }
};

