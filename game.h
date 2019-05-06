#include <ncurses.h>
#include <stdlib.h>
#include <math.h>

struct Pos2D
{
    int x;
    int y;


    Pos2D operator=(const Pos2D &rhs)
    {
        x = rhs.x;
        y = rhs.y;
        return *this;
    }
};

Pos2D operator+(Pos2D lhs, Pos2D rhs)
{
    Pos2D sum;

    sum.x = lhs.x + rhs.x;
    sum.y = lhs.y + rhs.y;
    return sum;
}

void randomDraw(WINDOW *win, Pos2D bounds, char c)
{
    int drawX = ((rand() % bounds.x) + 1) * 2, drawY = (rand() % bounds.y) + 1;

    mvwaddch(win, drawY, drawX, c);
}

bool charBetween(WINDOW *win, Pos2D start, Pos2D end, char c)
{
    // Check chars at endpoints first
    if((mvwinch(win, start.y, start.x) & A_CHARTEXT) == c || (mvwinch(win, end.y, end.x) & A_CHARTEXT) == c)
        return true;

    // Find unit vector between two points
    Pos2D u = start;
    double ux = end.x - start.x, uy = end.y - start.y;
    double mag = sqrt(pow(ux, 2) + pow(uy, 2));
    ux /= mag;
    uy /= mag;


    // Iterate over unit vector until endpoint is passed
    for(int i = 0; i <= mag; i++)
    {
        u.y = start.y + (uy * i);
        u.x = start.x + (ux * i);
        if((mvwinch(win, u.y, u.x) & A_CHARTEXT) == c)
        {
            addch(' ');
            return true;
        }
    }

    return false;
}