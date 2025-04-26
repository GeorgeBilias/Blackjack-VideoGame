#pragma once
#include "graphics.h"
#include "config.h"

class Button {
protected:
    bool m_active = false;
    bool m_highlighted = false;

public:
    virtual void draw() = 0;
    virtual bool contains(float x, float y) = 0;
    virtual ~Button() {}
	void update() {}
	void setHighlight(bool h) { m_highlighted = h; }
    // In Button.h
protected:
    virtual std::string getTextureName() const = 0;
    virtual float getX() const = 0;
    virtual float getY() const = 0;
    virtual float getWidth() const = 0;
    virtual float getHeight() const = 0;
    virtual bool useDiskShape() const = 0;

};

class Hit : public Button {
private:
	static Hit* m_instance;

public:
	void draw() override;
	bool contains(float x, float y) override;
	static Hit* getInstance();
	static void releaseInstance() {
		if (m_instance) delete m_instance; m_instance = nullptr;
	}
	std::string getTextureName() const override { return "hit.png"; }
	float getX() const override { return HIT_X; }
	float getY() const override { return HIT_Y; }
	float getWidth() const override { return HIT_WIDTH; }
	float getHeight() const override { return HIT_HEIGHT; }
	bool useDiskShape() const override { return true; }

};

class Stand : public Button {
private:
	static Stand* m_instance;

public:
	void draw() override;
	bool contains(float x, float y) override;
	static Stand* getInstance();
	static void releaseInstance() {
		if (m_instance) delete m_instance; m_instance = nullptr;
	}
	std::string getTextureName() const override { return "stand.png"; }
	float getX() const override { return STAND_X; }
	float getY() const override { return STAND_Y; }
	float getWidth() const override { return STAND_WIDTH; }
	float getHeight() const override { return STAND_HEIGHT; }
	bool useDiskShape() const override { return true; }

};
