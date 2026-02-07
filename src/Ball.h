#ifndef BALL_H
#define BALL_H

class Ball
{
private:
    int posX;
    int posY;
    int radius;
    int directionX;
    int directionY;

public:
    Ball(int x, int y, int r);
    void Draw();
};

#endif