#include "Menu.h"

Menu::Menu(float width, float height)
{
	font.loadFromFile("AGENCYB.ttf");

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Play");
	menu[0].setPosition(sf::Vector2f(width / 2, height /(3+1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Settings");
	menu[1].setPosition(sf::Vector2f(width / 2, height / (3 + 1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Exit");
	menu[2].setPosition(sf::Vector2f(width / 2, height / (3 + 1) * 3));

	selectedItemIndex = 0;

}

Menu::~Menu()
{
}

void Menu::drawMenu(sf::RenderWindow& window)
{
	for (int i = 0; i < 3; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::moveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);

	}


}

void Menu::moveDown()
{
		if (selectedItemIndex + 1 < 3)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);

	}
}

int Menu::getPressedItem()
{
	return selectedItemIndex;
}
