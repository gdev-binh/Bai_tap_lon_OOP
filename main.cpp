#include"Snake.h"
#include"Menu.h"
#include"Button.h"
#include<sstream>

int width_window = 18, height_window = 19; // kich thuoc cua window
int sizeGrid = 32;

enum GameState{MENU, PLAY, PAUSE, EXIT, RESTART, SETTING};

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

    
    // hinh` anh? loa
    sf::Texture tSpeaker, tSpeakerMute;
    tSpeaker.loadFromFile("images/speaker.png");
    tSpeakerMute.loadFromFile("images/speaker-mute.png");

    sf::Sprite sSpeaker(tSpeaker); 
    sSpeaker.setPosition(15 * 32, 16);
    sf::Sprite sSpeakerMute(tSpeakerMute);
    sSpeakerMute.setPosition(15 * 32, 16);

    // hinh anh? am nhac
    sf::Texture tMusic, tMusicMute;
    tMusic.loadFromFile("images/music-icon.png");
    tMusicMute.loadFromFile("images/icon-music-mute.png");
    
    sf::Sprite sMusic(tMusic);
    sMusic.setPosition(13 * 32, 16);
    sf::Sprite sMusicMute(tMusicMute);
    sMusicMute.setPosition(13 * 32, 16);


    // khoi tao clock
    sf::Clock clock;
    float timer = 0, delay = 0.12; // mac dinh la` 0.12


   //  khoi tao bien load file music 
    sf::SoundBuffer eat;
    eat.loadFromFile("eat.wav");

    sf::Sound eatSound;
    eatSound.setBuffer(eat);
    eatSound.setVolume(30);
    
    sf::Music music;
    music.openFromFile("musicBackground.wav");
    music.play();
    music.setLoop(true);

    
    // khoi tao viewGame tao mac dinh khung hinh`
    sf::View viewGame(sf::FloatRect(0, 0, 18 * 32, 19 * 32));
    bool checkDie = false;

    // khoi tao cac nut
    Button speakerButton(15 * 32, 16, 32, 32, ""); bool turnSpeaker = true;
    Button musicButton(13 * 32, 16, 32, 32, "");   bool turnMusic = true;
    
    // cac nut state menu
    Button playButton(250, 160, 200, 50, "Play");
    Button settingsButton(250, 312, 200, 50, "Settings");
    Button exitButton(250, 462, 200, 50, "Exit");

    // cac nut state pause
    //Button continueButton()
    

    while (window.isOpen())
    {

        // khoi tao time
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer = timer + time;

        sf::Event event;
        while (window.pollEvent(event))
        {
            // kiem tra nhap chuot
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    // lay vi tri con chuot trong cua so?
                    sf::Vector2f mousePos = window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
                    // click nut play
                    if (state == MENU)
                    {
                        if (playButton.isClicked(mousePos))
                        {
                            std::cout << "Play button clicked !\n";
                            state = PLAY;
                        }
                        // click nut setting
                        if (settingsButton.isClicked(mousePos))
                        {
                            std::cout << "Setting button clicked !\n";
                            state = SETTING;
                        }
                        // click nut thoat
                        if (exitButton.isClicked(mousePos))
                        {
                            std::cout << "Exit button clicked !\n";
                            window.close();
                        }

                    }                       
                    // click nut nhac
                    if (musicButton.isClicked(mousePos))
                    {
                        turnMusic = !turnMusic;
                        std::cout << "Music button clicked !\n";
                        if (turnMusic)
                            music.play();
                        else
                            music.pause();
                    }
                    // click nut am thanh 
                    if (speakerButton.isClicked(mousePos))
                    {
                        turnSpeaker = !turnSpeaker;
                        std::cout << "Speaker button clicked !\n";
                        if (turnSpeaker)

                            eatSound.play();
                        else
                            eatSound.stop();
                    }
    
                }
            }
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
            // STATE MENU
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
                        {
                            std::cout << "SETTINGS HAD CHOOSE" << std::endl;
                            state = SETTING;
                        }

                        if (menu.getPressedItemMenuMain() == 2)
                        {
                            std::cout << "EXIT HAD CHOOSE" << std::endl;
                            window.close();
                        }
                    }                
                }
            }
            // STATE PAUSE
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
            // STATE PLAY
             if (state == PLAY)
             {
                 if (event.type == sf::Event::KeyPressed)
                 {
                     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                     {
                         state = PAUSE;
                         std::cout << "Pause has choosen!!" << std::endl;
                     }
                 }
             }
             // STATE RESTART
             if (state == RESTART && event.type == sf::Event::KeyPressed)
             {
                 if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                     menu.moveUpMenuRestart();
                 if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                     menu.moveDownMenuRestart();
                 if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
                 {
                     if (menu.getPressedItemMenuRestart() == 0)
                     {
                         std::cout << "RESTART HAD CHOOSE" << std::endl;
                         state = PLAY;
                         score = 0;
                         snake = Snake();
                         food = Food();
                         checkDie = false;
                     }
                     if (menu.getPressedItemMenuRestart() == 1)
                     {
                         std::cout << "RETURN MAIN MENU" << std::endl;
                         state = MENU;

                     }

                 }
             }
             if (state == SETTING && event.type == sf::Event::KeyPressed)
             {
                 if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                     menu.moveUpMenuSetting();
                 if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                     menu.moveDownMenuSetting();
                 if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
                 {
                     if (menu.getPressedItemMenuSetting() == 0)
                     {
                         std::cout << "EASY MODE HAD CHOOSE" << std::endl;
                         delay = 0.2;
                     }

                     if (menu.getPressedItemMenuSetting() == 1)
                     {
                         std::cout << "MEDIUM MODE HAD CHOOSE" << std::endl;
                         delay = 0.12;
                     }

                     if (menu.getPressedItemMenuSetting() == 2)
                     {
                         std::cout << "HARD MODE HAD CHOOSE" << std::endl;
                         delay = 0.07;
                     }
                 }
                 if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) ||
                     sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                 {
                     state = MENU;
                 }
             }

      
        }
        // ket thuc while (open)

        window.clear();

        if (state == MENU) // con` o menu
        {
            snake = Snake();
            score = 0;
            food = Food();
            checkDie = false;       
            menu.drawMenuMain(window);
            playButton.drawButton(window);
            settingsButton.drawButton(window);
            exitButton.drawButton(window);
           
        }
        else if (state == PAUSE)
        {        
            menu.drawMenuPause(window);
        }
        else if (state == RESTART)
        {
            menu.drawMenuRestart(window);

            // ve diem sau khi chet va
            sf::Sprite icon_cup(tCup);
            icon_cup.setPosition(9*32, 32 *2 );
            window.draw(icon_cup);


            sf::Sprite icon_food(tFood);
            icon_food.setPosition(9 * 32, 32 * 4);
            window.draw(icon_food);
            std::stringstream ss_score, ss_record; // tao chuoi tu kieu du lieu int
          
            ss_record << record;
            text_record.setString(ss_record.str());
            text_record.setPosition(11 * 32, 32 * 2);

            window.draw(text_record);
            
            ss_score << score;
            text_score.setString(ss_score.str());
            text_score.setPosition(11*32, 32*4);
            window.draw(text_score);



        }
        else if (state == SETTING)
        {
            menu.drawMenuSetting(window);
        }
        else if (state == PLAY) // khi da an Play
        {
            // dieu khien 
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                snake.setDirectionSnake(DOWN);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                snake.setDirectionSnake(LEFT);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                snake.setDirectionSnake(RIGHT);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                snake.setDirectionSnake(UP);
            }
            if (timer > delay)
            {
                timer = 0;
                snake.snakeMove();

                // check snake die

                if (snake.checkSnakeDie())
                {
                    checkDie = true;
                }
                if (checkDie)
                {
                    state = RESTART;
                    std::cout << "You died" << std::endl;
                }

                // check snake eat food
                if (snake.getSnakePositionX(0) == food.getPositionFoodX() &&
                    snake.getSnakePositionY(0) == food.getPositionFoodY())
                {
                    if(turnSpeaker)
                        eatSound.play();
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
            text_score.setPosition(64, 20);
            window.draw(text_score);

            // ve ~icon cup
            window.draw(sCup);
            ss_record << record;
            text_record.setString(ss_record.str());
            text_record.setPosition(140, 20);
            window.draw(text_record);

            snake.drawSnake(window); // ve lai 
            food.drawFood(window);   // ve food moi ( new respawn )
        }
        window.draw(sSpeaker);
        speakerButton.drawButton(window);

        window.draw(sMusic);
        musicButton.drawButton(window);
        window.display();
    }
    return 0;
}