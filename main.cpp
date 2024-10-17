#include <SFML/Graphics.hpp>
#include "Snake.h"


int main(){
    Snake snake;
 
sf::RenderWindow window(sf::VideoMode(800, 600), "Di chuyen đoi tuong voi AWSD");


sf::Texture texture;
if (!texture.loadFromFile("blue_snake.png")) {
    // Handle error
}
sf::Texture texture1;
if(!texture1.loadFromFile("blue.png"))
{ }

sf::Sprite sprite;
sprite.setTexture(texture);
// sprite.setPosition(375.0f, 275.0f);
window.draw(sprite);

sf::Sprite sprite1;
sprite1.setTexture(texture1);
sprite1.setPosition(0.f, 0.f);
window.draw(sprite1);






float moveSpeed = 200.0f;

char setRotationHead = 'D'; // A W S D
float rotationSpeed = 90.0f;

sf::Clock clock;
while (window.isOpen()) {
    float deltaTime = clock.restart().asSeconds();

    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        sprite.move(0.0f, -moveSpeed * deltaTime);
        // neu ma` dang khong huong len thi huong len tren nua
        if (setRotationHead == 'D') 
        {
            while(setRotationHead)
            {

            }
            sprite.rotate(-rotationSpeed);
            setRotationHead = 'W';
        }
        else if (setRotationHead == 'A')
        {
            sprite.rotate(rotationSpeed);
            setRotationHead = 'W';
        }
            

    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        sprite.move(0.0f, moveSpeed * deltaTime);
        if (setRotationHead == 'D')
        {
            sprite.rotate(rotationSpeed);
            setRotationHead = 'S';
        }
        else if (setRotationHead == 'A')
        {
            sprite.rotate(-rotationSpeed);
            setRotationHead = 'S';
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        sprite.move(-moveSpeed * deltaTime, 0.0f);
        if (setRotationHead == 'W')
        {
            sprite.rotate(-rotationSpeed);
            setRotationHead = 'A';
        }
        else if (setRotationHead == 'S')
        {
            sprite.rotate(rotationSpeed);
            setRotationHead = 'A';
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        sprite.move(moveSpeed * deltaTime, 0.0f);
        if (setRotationHead == 'W')
        {
            sprite.rotate(rotationSpeed);
            setRotationHead = 'D';
        }
        else if (setRotationHead == 'S')
        {
            sprite.rotate(-rotationSpeed);
            setRotationHead = 'D';
        }
    }

    window.clear();
    window.draw(sprite1);
    window.draw(sprite);
    window.display();
}

return 0;
}