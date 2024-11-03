#include"Snake.h"
#include"Food.h"

#include<sstream>

int width_window = 18, height_window = 19; // kich thuoc cua window
int sizeGrid = 32;


int main()
{
    srand(time(0));

    Snake snake; // khoi tao snake
    Food  food; // khoi tao food

    int score = 0; // diem 
    int record; // ki luc cua diem

    sf::RenderWindow window(sf::VideoMode(width_window*sizeGrid, height_window*sizeGrid), "SFML works!");

    // khai bao font chu~
    sf::Font font;
    font.loadFromFile("AGENCYB.ttf");
    sf::Text text;
    text.setFont(font);
    text.setString("0");
    text.setCharacterSize(24); // don vi pixel
    text.setStyle(sf::Text::Bold);
    text.setPosition(64, 16);
  

    // hinh` anh background map
    sf::Texture T_background1;
    T_background1.loadFromFile("images/1ebc73.png");
    sf::Sprite S_background1(T_background1);

    sf::Texture T_background2;
    T_background2.loadFromFile("images/91db69.png");
    sf::Sprite S_background2(T_background2);

    // hinh` anh? khung vien`
    sf::Texture T_khung_vien;
    T_khung_vien.loadFromFile("images/239063.png");
    sf::Sprite S_khung_vien(T_khung_vien);

    // hinh` anh? khung tren
    sf::Texture T_khung_tren;
    T_khung_tren.loadFromFile("images/165a4c.png");
    sf::Sprite S_khung_tren(T_khung_tren);

    // hinh` anh food
    sf::Texture tFood;
    tFood.loadFromFile("images/4d65b4.png");
    sf::Sprite	sFood(tFood);
    sFood.setPosition(16, 16);



    sf::Clock clock;
    float timer = 0, delay = 0.1;


    sf::View view(sf::FloatRect(0, 0, 15 * 32, 17 * 32));
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

            if (event.type == sf::Event::Resized)
            { // khi maximize thi` khong bi. dan~ pixel            
                float windowWidth = event.size.width; // khoi tao chieu rong moi khi kich thuoc cua so thay doi
                float windowHeight = event.size.height; // khoi tao chieu dai moi
                float aspectRatio = windowWidth / windowHeight; // khoi tao  ti le khung hinh

                if (aspectRatio > 0.88f) { 
                    float viewportWidth = 0.88f / aspectRatio;
                    view.setViewport(sf::FloatRect((1.0f - viewportWidth) / 2, 0, viewportWidth, 1));
                }
                else { 
                    float viewportHeight = aspectRatio / 0.88f;
                    view.setViewport(sf::FloatRect(0, (1.0f - viewportHeight) / 2, 1, viewportHeight));
                }

                window.setView(view);

            
            }
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

            // check snake eat food
            if (snake.getSnakePositionX(0) == food.getPositionFoodX() &&
                snake.getSnakePositionY(0) == food.getPositionFoodY())
            {
                score++;
                snake.grow();
                // check xem vi tri food co = vi tri con ran khong?
                for (int i = 0; i < snake.getSnakeSize(); i++)
                {
                   if (food.getPositionFoodX() == snake.getSnakePositionX(i) &&
                       food.getPositionFoodY() == snake.getSnakePositionY(i))
                   {
                       food.foodRespawn();
                   }
                }
            }
        }

        window.clear();

        // ve~ map
        for (int i = 0; i < width_window; i++) 
            for (int j = 0; j < height_window; j++)
            {
                if (j == 0 || j == 1)
                {
                    S_khung_tren.setPosition(i * sizeGrid, j * sizeGrid);
                    window.draw(S_khung_tren);
                    continue;
                }
                if (i == 0 || j == 2 || i == width_window-1 || j == height_window-1 )
                {
                    S_khung_vien.setPosition(i * sizeGrid, j * sizeGrid);
                    window.draw(S_khung_vien);
                    continue;
                }

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
        window.draw(sFood);
     
        // draw diem?
        std::stringstream ss; // tao chuoi tu kieu du lieu int
        ss << score;
        text.setString(ss.str());
        window.draw(text);


        snake.drawSnake(window);
        food.drawFood(window);
        window.display();
    }
    return 0;
}