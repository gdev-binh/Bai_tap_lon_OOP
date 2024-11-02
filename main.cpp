#include"Snake.h"
#include"Food.h"
int width = 15, height = 17; // khoi tao kich thuoc map
int sizeGrid = 32;


int main()
{
    srand(time(0));

    Snake snake;
    Food  food;
    sf::RenderWindow window(sf::VideoMode(15 * 32, 17 * 32), "SFML works!");

    // hinh` anh background
    sf::Texture T_background1;
    T_background1.loadFromFile("images/1.png");
    sf::Sprite S_background1(T_background1);

    sf::Texture T_background2;
    T_background2.loadFromFile("images/96ec59.png");
    sf::Sprite S_background2(T_background2);

    sf::Clock clock;
    float timer = 0, delay = 0.1;


    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer = timer + time;
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            snake.setDirectionSnake(DOWN);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            snake.setDirectionSnake(LEFT);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            snake.setDirectionSnake(RIGHT);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            snake.setDirectionSnake(UP);
        }
        if (timer > delay)
        {
            timer = 0;
            snake.snakeMove();
            if (snake.getHeadX() == food.getPositionFoodX() &&
                snake.getHeadY() == food.getPositionFoodY())
            {
                snake.grow();
                food.foodRespawn();
            }
        }

        window.clear();
        for (int i = 0; i < width; i++) // ve~ map
            for (int j = 0; j < height; j++)
            {
                if (i % 2 == 0)
                {
                    if (j % 2 != 0)
                    {
                        S_background2.setPosition(i * sizeGrid, j * sizeGrid);
                        window.draw(S_background2);
                    }
                    else
                    {
                        S_background1.setPosition(i * sizeGrid, j * sizeGrid);
                        window.draw(S_background1);
                    }

                }
                else
                {
                    if (j % 2 == 0)
                    {
                        S_background2.setPosition(i * sizeGrid, j * sizeGrid);
                        window.draw(S_background2);
                    }
                    else
                    {
                        S_background1.setPosition(i * sizeGrid, j * sizeGrid);
                        window.draw(S_background1);
                    }
                }

            }

        snake.drawSnake(window);
        food.drawFood(window);
        window.display();
    }
    return 0;
}