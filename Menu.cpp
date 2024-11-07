#include "Menu.h"

Menu::Menu(float width, float height)
{
	font.loadFromFile("AGENCYB.ttf");

	// anh ne`n

	
	// play
	menuMain[0].setFont(font);
	menuMain[0].setFillColor(sf::Color(174, 35, 52));
	menuMain[0].setString("Play");
	menuMain[0].setCharacterSize(50);
	menuMain[0].setPosition(sf::Vector2f(width / 2, height /(3+1) * 1));

	// Settings
	menuMain[1].setFont(font);
	menuMain[1].setFillColor(sf::Color::White);
	menuMain[1].setString("Settings");
	menuMain[1].setCharacterSize(50);
	menuMain[1].setPosition(sf::Vector2f(width / 2, height / (3 + 1) * 2));

	// Exit 
	menuMain[2].setFont(font);
	menuMain[2].setFillColor(sf::Color::White);
	menuMain[2].setString("Exit");
	menuMain[2].setCharacterSize(50);
	menuMain[2].setPosition(sf::Vector2f(width / 2, height / (3 + 1) * 3));

	// Continue when pause
	menuPause[0].setFont(font);
	menuPause[0].setFillColor(sf::Color(174, 35, 52));
	menuPause[0].setString("Continue play");
	menuPause[0].setCharacterSize(50);
	menuPause[0].setPosition(sf::Vector2f(width / 2, height / (3 + 1) * 1));

	// Return to the main menu of State Pause
	menuPause[1].setFont(font);
	menuPause[1].setFillColor(sf::Color::White);
	menuPause[1].setString("Return menu");
	menuPause[1].setCharacterSize(50);
	menuPause[1].setPosition(sf::Vector2f(width / 2, height / (3 + 1) * 2));

	// Restart when die
	menuRestart[0].setFont(font);
	menuRestart[0].setFillColor(sf::Color(174, 35, 52));
	menuRestart[0].setString("Restart");
	menuRestart[0].setCharacterSize(50);
	menuRestart[0].setPosition(sf::Vector2f(width / 2, height /3));
	
	// Return to the main menu of State Die
	menuRestart[1].setFont(font);
	menuRestart[1].setFillColor(sf::Color::White);
	menuRestart[1].setString("Return menu");
	menuRestart[1].setCharacterSize(50);
	menuRestart[1].setPosition(sf::Vector2f(width / 2, height /(3+1)*2 ));
}

Menu::~Menu()
{
}

void Menu::drawMenuMain(sf::RenderWindow& window)
{
	sf::Texture T_background_menu;
	T_background_menu.loadFromFile("images/background_menu.png");
	sf::Sprite S_background_menu(T_background_menu);
	window.draw(S_background_menu);

	sf::Vector2f shadowOffset(3, 3); // do nga bong

	for (int i = 0; i < 3; i++)
	{
		sf::Text shadowText = menuMain[i]; // tao shadow cho text
		shadowText.setFillColor(sf::Color(50, 50, 50));
		shadowText.setPosition(menuMain[i].getPosition() + shadowOffset);
		window.draw(shadowText);

		window.draw(menuMain[i]);
	}
}

void Menu::drawMenuPause(sf::RenderWindow& window)
{
	sf::Texture T_background_menu;
	T_background_menu.loadFromFile("images/background_menu.png");
	sf::Sprite S_background_menu(T_background_menu);
	window.draw(S_background_menu);

	// khoi tao bien tao shadow cho text
	sf::Vector2f shadowOffset(3, 3); // do nga bong

	for (int i = 0; i < 2; i++)
	{
		sf::Text shadowText = menuPause[i]; // tao shadow cho text
		shadowText.setFillColor(sf::Color(50, 50, 50));
		shadowText.setPosition(menuPause[i].getPosition() + shadowOffset);
		window.draw(shadowText);

		window.draw(menuPause[i]);
	}

	

}

void Menu::drawMenuRestart(sf::RenderWindow& window)
{
	// ve background cho menu
	sf::Texture T_background_menu;
	T_background_menu.loadFromFile("images/background_menu.png");
	sf::Sprite S_background_menu(T_background_menu);
	window.draw(S_background_menu);

	// khoi tao bien tao shadow cho text
	sf::Vector2f shadowOffset(3, 3); // do nga bong
	for (int i = 0; i < 2; i++)
	{
		sf::Text shadowText = menuRestart[i]; // tao shadow cho text
		shadowText.setFillColor(sf::Color(50, 50, 50));
		shadowText.setPosition(menuRestart[i].getPosition() + shadowOffset);
		window.draw(shadowText);

		window.draw(menuRestart[i]);
	}



}


void Menu::moveUpMenuMain()
{
	if (selectedItemIndexMenu - 1 >= 0)
	{
		menuMain[selectedItemIndexMenu].setFillColor(sf::Color::White);
		selectedItemIndexMenu--;
		menuMain[selectedItemIndexMenu].setFillColor(sf::Color(174, 35, 52));
	}


}

void Menu::moveDownMenuMain()
{
	if (selectedItemIndexMenu + 1 < 3)
	{
		menuMain[selectedItemIndexMenu].setFillColor(sf::Color::White);
		selectedItemIndexMenu++;
		menuMain[selectedItemIndexMenu].setFillColor(sf::Color(174, 35, 52));

	}
}

void Menu::moveUpMenuPause()
{
	if (selectedItemIndexPause - 1 >= 0)
	{
		menuPause[selectedItemIndexPause].setFillColor(sf::Color::White);
		selectedItemIndexPause--;
		menuPause[selectedItemIndexPause].setFillColor(sf::Color(174, 35, 52));

	}
}

void Menu::moveDownMenuPause()
{
	if (selectedItemIndexPause + 1 < 2)
	{
		menuPause[selectedItemIndexPause].setFillColor(sf::Color::White);
		selectedItemIndexPause++;
		menuPause[selectedItemIndexPause].setFillColor(sf::Color(174, 35, 52));
	}

}

void Menu::moveUpMenuRestart()
{
	if (selectedItemIndexRestart - 1 >= 0)
	{
		menuRestart[selectedItemIndexRestart].setFillColor(sf::Color::White);
		selectedItemIndexRestart--;
		menuRestart[selectedItemIndexRestart].setFillColor(sf::Color(174, 35, 52));

	}
}

void Menu::moveDownMenuRestart()
{
	if (selectedItemIndexRestart + 1 < 2)
	{
		menuRestart[selectedItemIndexRestart].setFillColor(sf::Color::White);
		selectedItemIndexRestart++;
		menuRestart[selectedItemIndexRestart].setFillColor(sf::Color(174, 35, 52));
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

int Menu::getPressedItemMenuRestart()
{
	return selectedItemIndexRestart;
}

bool Menu::isMenuClick(sf::Vector2f& mousePos)
{
	return menuMain[0].getGlobalBounds().contains(mousePos);
}
