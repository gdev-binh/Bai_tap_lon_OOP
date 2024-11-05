#include"Snake.h"
#include"Food.h"
#include"Menu.h"

#include<sstream>

int width_window = 18, height_window = 19; // kich thuoc cua window
int sizeGrid = 32;

enum GameState{MENU, PLAY, PAUSE, EXIT, CONFIRM_EXIT};

int main()
{
    // khoi tao window 
    sf::RenderWindow window(sf::VideoMode(width_window * sizeGrid, height_window * sizeGrid), "Snakeeee!");
    srand(time(0));

    Menu menu(window.getSize().x, window.getSize().y);
    GameState state = MENU;


    Snake snake; // khoi tao snake
    Food  food; // khoi tao food

    int score = 0; // diem 
    int record = 0; // ki luc cua diem

    // khai bao font chu~
    sf::Font font;
    font.loadFromFile("AGENCYB.ttf");

    //  score 
    sf::Text text_score;
    text_score.setFont(font);
    text_score.setString("0");
    text_score.setCharacterSize(24); // don vi pixel
    text_score.setStyle(sf::Text::Bold);
    text_score.setPosition(64, 20);

    // record
    sf::Text text_record;
    text_record.setFont(font);
    text_record.setString("0");
    text_record.setCharacterSize(24);
    text_record.setStyle(sf::Text::Bold);
    text_record.setPosition(140, 20);



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
    tFood.loadFromFile("images/apple.png");
    sf::Sprite	sFood(tFood);
    sFood.setPosition(16, 16);

    // hinh` anh? cup ki luc ( record )
    sf::Texture tCup;
    tCup.loadFromFile("images/cup.png");
    sf::Sprite sCup(tCup);
    sCup.setPosition(96, 16);

    // khoi tao clock
    sf::Clock clock;
    float timer = 0, delay = 0.1;


    // khoi tao viewGame tao mac dinh khung hinh`
    sf::View viewGame(sf::FloatRect(0, 0, 18 * 32, 19 * 32));

    while (window.isOpen())
    {
        bool checkRestarGame = false;

        // khoi tao time
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer = timer + time;

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            // khi thay doi kich thuoc cua so
            if (event.type == sf::Event::Resized)
            { // khi maximize thi` khong bi. dan~ pixel            
                float windowWidth = event.size.width; // khoi tao chieu rong moi khi kich thuoc cua so thay doi
                float windowHeight = event.size.height; // khoi tao chieu dai moi
                float aspectRatio = windowWidth / windowHeight; // khoi tao  ti le khung hinh

                if (aspectRatio > 0.94f) {
                    float viewportWidth = 0.947f / aspectRatio;
                    viewGame.setViewport(sf::FloatRect((1.0f - viewportWidth) / 2, 0, viewportWidth, 1));
                }
                else {
                    float viewportHeight = aspectRatio / 0.947f;
                    viewGame.setViewport(sf::FloatRect(0, (1.0f - viewportHeight) / 2, 1, viewportHeight));
                }

                window.setView(viewGame);

            }
            // menu
            if (state == MENU)
            {
                if (event.type == sf::Event::KeyPressed)
                {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                        menu.moveUpMenuMain();
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                        menu.moveDownMenuMain();
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
                    {
                        if (menu.getPressedItemMenuMain() == 0)
                        {
                            std::cout << "PLAY HAD CHOOSE" << std::endl;
                            state = PLAY;
                        }

                        if (menu.getPressedItemMenuMain() == 1)
                            std::cout << "SETTINGS HAD CHOOSE" << std::endl;
                        if (menu.getPressedItemMenuMain() == 2)
                        {
                            std::cout << "EXIT HAD CHOOSE" << std::endl;
                            window.close();
                        }

                    }
                
                }
            }
            if (state == PAUSE)
            {
                if (event.type == sf::Event::KeyPressed)
                {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                        menu.moveUpMenuPause();
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                        menu.moveDownMenuPause();
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
                    {
                        if (menu.getPressedItemMenuPause() == 0)
                        {
                            std::cout << "CONTINUE HAD CHOOSE" << std::endl;
                            state = PLAY;
                        }
                        if (menu.getPressedItemMenuPause() == 1)
                        {
                            std::cout << "RETURN HAD CHOOSE" << std::endl;
                            state = MENU;

                        }

                    }
                }
            }
             if (state == PLAY && event.type == sf::Event::KeyPressed)
             { 
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                {
                    state = PAUSE;
                    std::cout << "Pause has choosen!!" << std::endl;                       
                }
             }
        }
        window.clear();

        if (state == MENU) // con` o menu
        {
            snake = Snake();
            score = 0;
            food = Food();
            menu.drawMenuMain(window);

        }
        else if (state == PAUSE)
        {
            menu.drawMenuPause(window);
        }

        else if (state == PLAY) // khi da an Play
        {

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
                    if (score > record)
                        record = score;
                    snake.grow();
                }

                // check xem vi tri food co = vi tri con ran khong?
                while (!snake.checkFoodEqualSnake(food))
                {
                    food.foodRespawn();
                }
            }
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
                    if (i == 0 || j == 2 || i == width_window - 1 || j == height_window - 1)
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

            window.draw(sFood); // ve~ icon food
            // draw diem?
            std::stringstream ss_score, ss_record; // tao chuoi tu kieu du lieu int
            ss_score << score;
            text_score.setString(ss_score.str());
            window.draw(text_score);

            // ve ~icon cup
            window.draw(sCup);
            ss_record << record;
            text_record.setString(ss_record.str());
            window.draw(text_record);

            snake.drawSnake(window); // ve lai 
            food.drawFood(window);   // ve food moi ( new respawn )
        }

        window.display();
    }
    return 0;
}