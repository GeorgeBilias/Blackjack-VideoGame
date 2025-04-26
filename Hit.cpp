#include "Hit.h"
#include "graphics.h"
#include "config.h"


Hit* Hit::getInstance()
{
	if (!m_instance)
		m_instance = new Hit();
	return m_instance;
}

void Hit::draw() {
	Button::draw();
}

bool Hit::contains(float x, float y) {
	return Button::contains(x, y);
}