#include "Hit.h"
#include "graphics.h"
#include "config.h"


void Hit::draw()
{

	graphics::Brush br;

	float h = 1.0f * m_highlighted;


	br.texture = "";
	SETCOLOR(br.fill_color, h, h, h);
	br.outline_opacity = 1.0f * m_active;
	graphics::drawDisk(HIT_X, HIT_Y, HIT_WIDTH * 0.35f, br);
	graphics::resetPose();


	SETCOLOR(br.fill_color, 1, 1, 1);
	br.texture = ASSET_PATH + std::string("hit.png");
	br.outline_opacity = 0.0f;
	graphics::drawRect(HIT_X, HIT_Y, HIT_WIDTH, HIT_HEIGHT, br);


}

void Hit::update()
{
}

Hit* Hit::getInstance()
{
	if (!m_instance)
		m_instance = new Hit();
	return m_instance;
}

bool Hit::contains(float x, float y)
{
	return distance(x, y, HIT_X, HIT_Y) < HIT_WIDTH * 0.24f;
}

