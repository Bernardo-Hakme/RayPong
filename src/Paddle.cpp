#include "Paddle.h"
#include "config.h"

Paddle::Paddle(int x, int y, int w, int h)
    : posX(x), posY(y), width(w), height(h)
{
    score = 0;
}

int Paddle::getPosX()
{
    return posX;
}

int Paddle::getPosY()
{
    return posY;
}

int Paddle::getScore()
{
    return score;
}

void Paddle::Draw()
{
    DrawRectangle(posX, posY, width, height, WHITE);
}


void Paddle::moveWS()
{
    if (IsKeyDown(KEY_S))
    {
        if (posY + height < WIN_HEIGHT)
        {
            posY += SPEED;
        }
        else
        {
            posY = WIN_HEIGHT - height; // eliminate change of "sinking"
        }
    }
    if (IsKeyDown(KEY_W))
    {
        if (posY > 0)
        {
            posY -= SPEED;
        }
        else
        {
            posY = 0; // eliminate chance of sinking
        }
    }
}

void Paddle::moveKeys()
{
    if (IsKeyDown(KEY_DOWN))
    {
        if (posY + height < WIN_HEIGHT)
        {
            posY += SPEED;
        }
        else
        {
            posY = WIN_HEIGHT - height; // eliminate sinking
        }
    }
    if (IsKeyDown(KEY_UP))
    {
        if (posY > 0)
        {
            posY -= SPEED;
        }
        else
        {
            posY = 0; // eliminate sinking
        }
    }
}

void Paddle::moveCPU(int ballPosY)
{
    if (posY + height/2 < ballPosY)
    {
        if (posY + height < WIN_HEIGHT)
        {
            posY += SPEED;
        }
        else
        {
            posY = WIN_HEIGHT - height;
        }
    }
    if (posY + height/2 > ballPosY)
    {
        if (posY > 0)
        {
            posY -= SPEED;
        }
        else
        {
            posY = 0;
        }
    }
}

void Paddle::computeScore()
{
    score++;
}