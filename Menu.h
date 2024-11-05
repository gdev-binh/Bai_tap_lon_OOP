#pragma once
#include"Food.h"

class Menu
{
private:
	int selectedItemIndexMenu = 0;
	int selectedItemIndexPause = 0;

	sf::Font font;
	sf::Text menuMain[3];
	sf::Text menuPause[2];

public:
	Menu(float width, float height);
	~Menu();

	void drawMenuMain(sf::RenderWindow &window);
	void drawMenuPause(sf::RenderWindow& window);

	void moveUpMenuMain();
	void moveDownMenuMain();

	void moveUpMenuPause();
	void moveDownMenuPause();


	int getPressedItemMenuMain(); // lay vi tri option con` chon.

	int getPressedItemMenuPause(); // lay vi tri option con` chon.



};

