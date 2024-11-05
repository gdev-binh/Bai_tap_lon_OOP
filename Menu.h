#pragma once
#include"Food.h"

class Menu
{
private:
	int selectedItemIndex = 0;
	sf::Font font;
	sf::Text menu[3];

public:
	Menu(float width, float height);
	~Menu();

	void drawMenu(sf::RenderWindow &window);

	void moveUp();
	void moveDown();


	int getPressedItem(); // lay vi option con` chon.



};

