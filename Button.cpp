#include "Button.h"
#include "graphics.h"
#include "config.h"

void Button::draw() {
    graphics::Brush br;
    float h = 1.0f * m_highlighted;

    br.texture = "";
    SETCOLOR(br.fill_color, h, h, h);
    br.outline_opacity = 1.0f * m_active;

    if (useDiskShape() && useBackground())
        graphics::drawDisk(getX(), getY(), getWidth() * 0.35f, br);
    else if (!useDiskShape() && useBackground())
        graphics::drawRect(getX(), getY(), getWidth(), getHeight(), br);

    graphics::resetPose();

    SETCOLOR(br.fill_color, 1, 1, 1);
    br.texture = ASSET_PATH + getTextureName();
    br.outline_opacity = 0.0f;
    graphics::drawRect(getX(), getY(), getWidth(), getHeight(), br);
}

bool Button::contains(float x, float y)
{
    return distance(x, y, getX(), getY()) < getWidth() * 0.24f;
}

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

Stand* Stand::getInstance()
{
    if (!m_instance)
        m_instance = new Stand();
    return m_instance;
}

void Stand::draw() {
    Button::draw();
}

bool Stand::contains(float x, float y) {
    return Button::contains(x, y);
}

Replay* Replay::getInstance() {
    if (!m_instance) {
        m_instance = new Replay();
    }
    return m_instance;
}

void Replay::draw() {
    Button::draw();
}

bool Replay::contains(float x, float y) {
    return Button::contains(x, y);
}

Exit* Exit::getInstance() {
    if (!m_instance) {
        m_instance = new Exit();
    }
    return m_instance;
}

void Exit::draw() {
    Button::draw();
}

bool Exit::contains(float x, float y) {
    return Button::contains(x, y);
}