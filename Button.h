#pragma once

#include"Food.h"
class Button
{
private:
	sf::RectangleShape button;
	sf::Text text;
	sf::Font font;


public:

	Button(float x, float y, float width, float height,const std::string& buttonText );

	void drawButton(sf::RenderWindow& window);
	bool isClicked(sf::Vector2f& mousePos);


};


