#include <SFML/Graphics.hpp>
#include"Game.h"


using namespace sf;

int N = 15, M = 17;
int size = 32;  // kich thuoc moi~ texture
int w = size * N; // chieu rong window 
int h = size * M; // chieu cao window 

int dir, num = 4;

Snake  snake(num);

Fruit f;

void Tick()
{
    // di chuyen
    snake.move();
    // neu chay ra khoi 2 bien
    snake.checkCollision();
}

int main()
{
    srand(time(0));

    RenderWindow window(VideoMode(w, h), "Snake Game!");
    //window.setFramerateLimit(60);

    // khi maximize giu nguyen khung hinh`
    //sf::View fixedView(sf::FloatRect(0, 0, w, h));
    //window.setView(fixedView);

    // background
    Texture T_background;
    T_background.loadFromFile("images/4a752c.png");
        Sprite S_background(T_background);
    // snake
    Texture T_blue_head, T_blue;
    T_blue_head.loadFromFile("images/blue_snake.png");
        Sprite S_blue_head(T_blue_head);
      //  S_blue_head.setOrigin(S_blue_head.getLocalBounds().height, S_blue_head.getLocalBounds().width );
    T_blue.loadFromFile("images/blue.png");
        Sprite S_blue(T_blue);

    Clock clock;
    float timer = 0, delay = 0.1;

    f.x = 10;
    f.y = 10;

    while (window.isOpen())
    {

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

            dir = 1;
        }


        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;

        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed)
                window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            dir = 1;
          //  S_blue_head.setRotation(-90.f);
        }

        if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            dir = 2;
          //  S_blue_head.setRotation(90.f);
        }

        if (Keyboard::isKeyPressed(Keyboard::Up))
        {
            dir = 3;
          //  S_blue_head.setRotation(0.f);
        }

        if (Keyboard::isKeyPressed(Keyboard::Down))
        {
            dir = 0;
          //  S_blue_head.setRotation(180.f);
        }


        if (timer > delay) 
        { 
            timer = 0; 
        
            Tick(); 
        }

        ////// draw  ///////
        window.clear();

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
            {
                S_background.setPosition(i * size, j * size);  window.draw(S_background);
            }

        for (int i = 0; i < num; i++)
        {
            if (i == 0)
            {
                // draw Head
                S_blue_head.setPosition(s[i].x * size, s[i].y * size);  window.draw(S_blue_head);
                continue;
            }
            // draw mid 
            S_blue.setPosition(s[i].x * size, s[i].y * size); 
            window.draw(S_blue);
        }

        S_blue.setPosition(f.x * size, f.y * size);  window.draw(S_blue);

        window.display();
    }

    return 0;
}