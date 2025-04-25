#include "Replay.h"
#include "graphics.h"
#include "config.h"


void Replay::draw()
{

	graphics::Brush br;

	float h = 1.0f * m_highlighted;
	SETCOLOR(br.fill_color, h, h, h);
	br.texture = ASSET_PATH + std::string("replay.png");
	br.outline_opacity = 1.0f * m_active;
	
	graphics::drawRect(REPLAY_X, REPLAY_Y, REPLAY_WIDTH, REPLAY_HEIGHT, br);
	graphics::resetPose();

}

void Replay::update()
{
}

Replay* Replay::getInstance()
{
	if (!m_instance)
		m_instance = new Replay();
	return m_instance;
}

bool Replay::contains(float x, float y)
{
	return distance(x, y, REPLAY_X, REPLAY_Y) < REPLAY_WIDTH * 0.40f;
}

