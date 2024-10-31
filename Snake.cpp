#include "Snake.h"
#include <time.h>
Snake::Snake(int length)
{
    this->length = length;
}
void Snake::move()
{
    // di chuyen
    for (int i = length; i > 0; --i)
    {
        s[i].x = s[i - 1].x; 
        s[i].y = s[i - 1].y;
       /*
       co the? nhu dung` cau lenh nay`
       s[i] = s[i-1];
       */
    }

    // dieu huong di
    if (dir == DOWN) s[0].y += 1;
    if (dir == LEFT) s[0].x -= 1;
    if (dir == RIGHT) s[0].x += 1;
    if (dir == UP) s[0].y -= 1;



  

}
bool Snake::checkCollision() // kiem tra va cham
{
    // neu chay ra khoi 2 bien
    if (s[0].x > 15) 
        s[0].x = 0;  
    if (s[0].x < 0)
        s[0].x = 15;

    if (s[0].y > 17) 
        s[0].y = 0;  
    if (s[0].y < 0) 
        s[0].y = 17;

    // neu can cai duoi
    for (int i = 1; i < length; i++)
       
        if (s[0].x == s[i].x && s[0].y == s[i].y)
            return true;


}
int  Snake::grow()
{
    return length++;
}
int Snake::getHeadX()
{
    return s[0].x;
}
int Snake::getHeadY()
{
    return s[0].y;
}

