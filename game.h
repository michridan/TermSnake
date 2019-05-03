#include <ncurses.h>
#include <stdlib.h>

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
    int drawX = (rand() % bounds.x) + 1, drawY = (rand() % bounds.y) + 1;

    drawX += (drawX % 2) - 1; //TODO: Find a way to get rid of this

    mvwaddch(win, drawY, drawX, c);
}

/*
bool charBetween(WINDOW *win, Pos2D start, Pos2D end, char c)
{
    for(int x = start.x; x <= end.x; x++)
    {
        for(int y = start.y; y <=)
    }
    if(mvwinch())

}
*/