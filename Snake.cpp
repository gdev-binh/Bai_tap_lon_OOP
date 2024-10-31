#include "Snake.h"
#include <time.h>
void Snake::move()
{
    Snake  s[100];
    // di chuyen
    for (int i = length; i > 0; --i)
    {
        s[i].x = s[i - 1].x; 
        s[i].y = s[i - 1].y;
    }

    // dieu huong di
    if (dir == DOWN) s[0].y += 1;
    if (dir == LEFT) s[0].x -= 1;
    if (dir == RIGHT) s[0].x += 1;
    if (dir == UP) s[0].y -= 1;

    //// neu chay ra khoi 2 bien
    //if (s[0].x > N) s[0].x = 0;  if (s[0].x < 0) s[0].x = N;
    //if (s[0].y > M) s[0].y = 0;  if (s[0].y < 0) s[0].y = M;

    // neu no can cai duoi
    for (int i = 1; i < length; i++)
        if (s[0].x == s[i].x && s[0].y == s[i].y) 
            length = i;
}

