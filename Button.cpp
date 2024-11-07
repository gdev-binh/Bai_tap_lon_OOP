#include "Button.h"

Button::Button(float x, float y, float width, float height,const std::string& buttonText)
{
	button.setPosition(x, y);
	button.setSize({ width, height });
	button.setFillColor(sf::Color(0,0,0,150));
	

	//font.loadFromFile("AGENCYB.ttf");
	// co the chen` text vao
	//text.setFont(font);
	//text.setString(buttonText);
	//text.setCharacterSize(24);
	//text.setFillColor(sf::Color::White);

	//sf::FloatRect textBounds = text.getLocalBounds();
	//text.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
	//text.setPosition(x + width / 2.0f, y + height / 2.0f);
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

