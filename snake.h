/****************************************
*               snake.h                 *
* This file defines the Snake class, as *
* well as the segment class, which it   *
* uses. The snake represents the player *
* in this game. It relies on game.h for *
* utility functions.                    *
****************************************/
#ifndef SNAKE_H
#define SNAKE_H

#include <iostream>
#include <vector>
#include "game.h"
using namespace std;

// Represents a single unit of the snake
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

// A vector of segments
// able to report whether or not the snake is alive
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

    bool isAlive(int size)
    {
        return inBounds(size) && !bodyCollision();
    }

    bool inBounds(int size)
    {
        if(getHead().get_pos().x <= 0 || getHead().get_pos().x >= (size * 2) - 1|| getHead().get_pos().y <= 0 || getHead().get_pos().y >= size - 1)
            return FALSE;
        return TRUE;
    }

    bool bodyCollision()
    {
        vector<Segment>::iterator check = body->begin();
        for(check++; check != body->end(); check++)
        {
            if(check->get_pos() == getHead().get_pos())
                return true;
        }
        return false;
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

#endif