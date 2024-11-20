#include "Button.h"

Button::Button(float x, float y, float width, float height,const std::string& buttonText)
{
	button.setPosition(x, y);
	button.setSize({ width, height });
	button.setFillColor(sf::Color(0,0,0,0));

}

Button::~Button()
{
}

void Button::drawButton(sf::RenderWindow& window)
{
	window.draw(button);
	window.draw(text);
}

bool Button::isClicked(sf::Vector2f& mousePos)
{
	// kiem tra click trong 1 vung
	return button.getGlobalBounds().contains(mousePos);
}

