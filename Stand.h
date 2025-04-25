#pragma once
class Stand
{
	static Stand* m_instance;



	bool m_highlighted = false;
	bool m_active = false;
public:
	void draw();
	void update();
	Stand() {};
	void setHighlight(bool h) { m_highlighted = h; }
	void setActive(bool a) { m_active = a; }

	bool contains(float x, float y);

	static Stand* getInstance();
	static void releaseInstance() { if (m_instance) delete m_instance; m_instance = nullptr; }
};