#include <iostream>
#include <vector>
#include "game.h"
using namespace std;


class Segment
{
    private:
    Pos2D pos;
    public:
    Segment(Pos2D newPos)
    {
        pos = newPos;
    }

    Pos2D get_pos()
    {
        return pos;
    }
};

class Snake
{
    private:
    vector<Segment> *body;

    public:
    Snake(Pos2D initPos)
    {
        Segment head(initPos);
        body = new vector<Segment>();
        body->insert(body->begin(), head);
    }

    Segment getHead()
    {
        return body->front();
    }

    Segment getTail()
    {
        return body->back();
    }

    bool inBounds(int size)
    {
        if(getHead().get_pos().x <= 0 || getHead().get_pos().x >= (size * 2) - 1|| getHead().get_pos().y <= 0 || getHead().get_pos().y >= size - 1)
            return FALSE;
        return TRUE;
    }

    void move(Pos2D velocity)
    {
        Segment newHead(getHead().get_pos() + velocity); 

        body->insert(body->begin(), newHead);
    }

    void removeTail()
    {
        body->pop_back();
    }
};