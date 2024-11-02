<<<<<<< HEAD
#include"Snake.h"
#include"Food.h"
int width = 15, height = 17; // khoi tao kich thuoc map
int sizeGrid = 32;

=======
#include <SFML/Graphics.hpp>
#include <time.h>
using namespace sf;

int N = 15, M = 17;
int size = 32;  // kich thuoc texture
int w = size * N; // chieu rong window 
int h = size * M; // chieu cao window 

int dir, num = 4;

class Snake
{
public:
    int x, y;
}  s[100];

class Fruit
{
public:
    int x, y;
} f;

void Tick()
{
    // di chuyen
    for (int i = num; i > 0; --i)
    {
        s[i].x = s[i - 1].x; s[i].y = s[i - 1].y;
    }

    // dieu huong di
    if (dir == 0) s[0].y += 1;
    if (dir == 1) s[0].x -= 1;
    if (dir == 2) s[0].x += 1;
    if (dir == 3) s[0].y -= 1;

    // khi dung trung fruit
    if ((s[0].x == f.x) && (s[0].y == f.y))
    {
        num++; f.x = rand() % N; f.y = rand() % M;
    }

    // neu chay ra khoi 2 bien
    if (s[0].x > N) s[0].x = 0;  if (s[0].x < 0) s[0].x = N;
    if (s[0].y > M) s[0].y = 0;  if (s[0].y < 0) s[0].y = M;

    // neu no can cai duoi
    for (int i = 1; i < num; i++)
        if (s[0].x == s[i].x && s[0].y == s[i].y)  num = i;
}
>>>>>>> main

int main()
{
    srand(time(0));

<<<<<<< HEAD
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
=======
    RenderWindow window(VideoMode(w, h), "Snake Game!");
    window.setFramerateLimit(60);


    // background
    Texture T_background;
    T_background.loadFromFile("images/4a752c.png");
        Sprite S_background(T_background);
    // snake
    Texture T_blue_head, T_blue;
    T_blue_head.loadFromFile("images/blue_snake.png");
        Sprite S_blue_head(T_blue_head);
        S_blue_head.setOrigin(S_blue_head.getLocalBounds().height, S_blue_head.getLocalBounds().width );
    T_blue.loadFromFile("images/blue.png");
        Sprite S_blue(T_blue);
>>>>>>> main

    sf::Clock clock;
    float timer = 0, delay = 0.1;


    while (window.isOpen())
    {
<<<<<<< HEAD
=======

        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            num = 4;
            for (int i = 0; i < num; ++i)
            {
                s[i].x = N / 2;
                s[i].y = M / 2 + i;
            }

            f.x = rand() % N;
            f.y = rand() % M;

            dir = 0;
        }


>>>>>>> main
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
<<<<<<< HEAD
            snake.setDirectionSnake(DOWN);
=======
            dir = 1;
            S_blue_head.setRotation(-90.f);
>>>>>>> main
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
<<<<<<< HEAD
            snake.setDirectionSnake(LEFT);
=======
            dir = 2;
            S_blue_head.setRotation(90.f);
>>>>>>> main
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
<<<<<<< HEAD
            snake.setDirectionSnake(RIGHT);
=======
            dir = 3;
            S_blue_head.setRotation(0.f);
>>>>>>> main
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
<<<<<<< HEAD
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

=======
            dir = 0;
            S_blue_head.setRotation(180.f);
        }


        if (timer > delay) { timer = 0; Tick(); }

        ////// draw  ///////
>>>>>>> main
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

<<<<<<< HEAD
        snake.drawSnake(window);
        food.drawFood(window);
=======
        for (int i = 0; i < num; i++)
        {
            if (i == 0)
            {
                S_blue_head.setPosition(s[i].x * size, s[i].y * size);  window.draw(S_blue_head);
                continue;
            }
            S_blue.setPosition(s[i].x * size, s[i].y * size); 
            window.draw(S_blue);
        }

        S_blue.setPosition(f.x * size, f.y * size);  window.draw(S_blue);

>>>>>>> main
        window.display();
    }
    return 0;
}