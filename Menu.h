#pragma once
#include"Food.h"

class Menu
{
private:
	int selectedItemIndexMenu = 0;
	int selectedItemIndexPause = 0;
	int selectedItemIndexRestart = 0;
	int selectedItemIndexSetting = 1;


	sf::Font font;
	sf::Text menuMain[3];
	sf::Text menuPause[2];
	sf::Text menuRestart[2];
	sf::Text menuSetting[3];

public:
	Menu(float width, float height);
	~Menu();

	// draw selection
	void drawMenuMain(sf::RenderWindow &window);
	void drawMenuPause(sf::RenderWindow& window);
	void drawMenuRestart(sf::RenderWindow& window);
	void drawMenuSetting(sf::RenderWindow& window);


	// cac lenh di chuyen lua chon
	void moveUpMenuMain();
	void moveDownMenuMain();

	void moveUpMenuPause();
	void moveDownMenuPause();

	void moveUpMenuRestart();
	void moveDownMenuRestart();

	void moveUpMenuSetting();
	void moveDownMenuSetting();


	int getPressedItemMenuMain(); // lay vi tri option con` chon.

	int getPressedItemMenuPause(); // lay vi tri option con` chon.

	int getPressedItemMenuRestart();

	int getPressedItemMenuSetting();


	bool isMenuClick(sf::Vector2f& mousePos);
};

