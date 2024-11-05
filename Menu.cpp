#include "Menu.h"

Menu::Menu(float width, float height)
{
	font.loadFromFile("AGENCYB.ttf");

	// play
	menuMain[0].setFont(font);
	menuMain[0].setFillColor(sf::Color::Red);
	menuMain[0].setString("Play");
	menuMain[0].setPosition(sf::Vector2f(width / 2, height /(3+1) * 1));

	// Settings
	menuMain[1].setFont(font);
	menuMain[1].setFillColor(sf::Color::White);
	menuMain[1].setString("Settings");
	menuMain[1].setPosition(sf::Vector2f(width / 2, height / (3 + 1) * 2));

	// Exit 
	menuMain[2].setFont(font);
	menuMain[2].setFillColor(sf::Color::White);
	menuMain[2].setString("Exit");
	menuMain[2].setPosition(sf::Vector2f(width / 2, height / (3 + 1) * 3));

	menuPause[0].setFont(font);
	menuPause[0].setFillColor(sf::Color::Red);
	menuPause[0].setString("Continue play");
	menuPause[0].setPosition(sf::Vector2f(width / 2, height / (3 + 1) * 1));

	menuPause[1].setFont(font);
	menuPause[1].setFillColor(sf::Color::White);
	menuPause[1].setString("Return to the main menu");
	menuPause[1].setPosition(sf::Vector2f(width / 2, height / (3 + 1) * 2));

	selectedItemIndexMenu = 0;
}

Menu::~Menu()
{
}

void Menu::drawMenuMain(sf::RenderWindow& window)
{
	for (int i = 0; i < 3; i++)
	{
		window.draw(menuMain[i]);
	}
}

void Menu::drawMenuPause(sf::RenderWindow& window)
{
	window.draw(menuPause[0]);
	window.draw(menuPause[1]);

}

void Menu::moveUpMenuMain()
{
	if (selectedItemIndexMenu - 1 >= 0)
	{
		menuMain[selectedItemIndexMenu].setFillColor(sf::Color::White);
		selectedItemIndexMenu--;
		menuMain[selectedItemIndexMenu].setFillColor(sf::Color::Red);

	}


}

void Menu::moveDownMenuMain()
{
	if (selectedItemIndexMenu + 1 < 3)
	{
		menuMain[selectedItemIndexMenu].setFillColor(sf::Color::White);
		selectedItemIndexMenu++;
		menuMain[selectedItemIndexMenu].setFillColor(sf::Color::Red);

	}
}

void Menu::moveUpMenuPause()
{
	if (selectedItemIndexPause - 1 >= 0)
	{
		menuPause[selectedItemIndexPause].setFillColor(sf::Color::White);
		selectedItemIndexPause--;
		menuPause[selectedItemIndexPause].setFillColor(sf::Color::Red);

	}
}

void Menu::moveDownMenuPause()
{
	if (selectedItemIndexPause + 1 < 2)
	{
		menuPause[selectedItemIndexPause].setFillColor(sf::Color::White);
		selectedItemIndexPause++;
		menuPause[selectedItemIndexPause].setFillColor(sf::Color::Red);
	}

}

int Menu::getPressedItemMenuMain()
{
	return selectedItemIndexMenu;
}

int Menu::getPressedItemMenuPause()
{
	return selectedItemIndexPause;
}
