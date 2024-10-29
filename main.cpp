#include <SFML/Graphics.hpp>
#include <time.h>
using namespace sf;

int N = 15, M = 17;
int size = 32;
int w = size * N;
int h = size * M;

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
    for (int i = num; i > 0; --i)
    {
        s[i].x = s[i - 1].x; s[i].y = s[i - 1].y;
    }

    if (dir == 0) s[0].y += 1;
    if (dir == 1) s[0].x -= 1;
    if (dir == 2) s[0].x += 1;
    if (dir == 3) s[0].y -= 1;

    if ((s[0].x == f.x) && (s[0].y == f.y))
    {
        num++; f.x = rand() % N; f.y = rand() % M;
    }

    if (s[0].x > N) s[0].x = 0;  if (s[0].x < 0) s[0].x = N;
    if (s[0].y > M) s[0].y = 0;  if (s[0].y < 0) s[0].y = M;

    for (int i = 1; i < num; i++)
        if (s[0].x == s[i].x && s[0].y == s[i].y)  num = i;
}

int main()
{
    srand(time(0));

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
       // S_blue_head.setOrigin(S_blue_head.getLocalBounds().width, S_blue_head.getLocalBounds().height);
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

            dir = 0;
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
            S_blue_head.setRotation(-90.f);
        }

        if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            dir = 2;
            S_blue_head.setRotation(90.f);
        }

        if (Keyboard::isKeyPressed(Keyboard::Up))
        {
            dir = 3;
            S_blue_head.setRotation(0.f);
        }

        if (Keyboard::isKeyPressed(Keyboard::Down))
        {
            dir = 0;
            S_blue_head.setRotation(180.f);
        }


        if (timer > delay) { timer = 0; Tick(); }

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
                S_blue_head.setPosition(s[i].x * size, s[i].y * size);  window.draw(S_blue_head);
                continue;
            }
            S_blue.setPosition(s[i].x * size, s[i].y * size); 
            window.draw(S_blue);
        }

        S_blue.setPosition(f.x * size, f.y * size);  window.draw(S_blue);

        window.display();
    }

    return 0;
}