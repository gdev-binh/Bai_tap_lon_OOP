#pragma once


enum Direction { DOWN, LEFT, RIGHT, UP }; // HUONG DI CHUYEN

class Snake
{
private: 
    Direction dir;
    int length = 4;

public:
    int x, y;
    void move();
};
