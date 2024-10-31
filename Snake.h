#pragma once


enum Direction { DOWN, LEFT, RIGHT, UP }; // HUONG DI CHUYEN

class Snake
{
private: 
    class Segment {
    // class toa do cac doan cua con ran
    public:
        int x; // theo cot
        int y; // theo hang`
    };
    Direction dir;
    int length;
    Segment s[100];

public:
    Snake(int length);
    void move(); // di chuyen
    int grow();
    bool checkCollision(); // kiem tra va cham  

    int getHeadX();
    int getHeadY();


};
