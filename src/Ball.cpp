#include "Ball.h"
#include "config.h"

Ball::Ball(int x, int y, int r)
    : posX(x), posY(y), radius(r)
{
    directionX = 3.0;
    directionY = 3.0;
}

int Ball::getPosX()
{
    return posX;
}

int Ball::getPosY()
{
    return posY;
}

int Ball::getRadius()
{
    return radius;
}

void Ball::Draw()
{
    DrawCircle(posX, posY, radius, YELLOW);
}

bool Ball::collides()
{
    if (posX + radius >= WIN_WIDTH)
    {
        directionX *= -1;
        posX = WIN_WIDTH - radius;  // Clamp position
        return true;
    }
    if (posX - radius <= 0)
    {
        directionX *= -1;
        posX = radius;  // Clamp position
        return true;
    }
    if (posY + radius >= WIN_HEIGHT)
    {
        directionY *= -1;
        posY = WIN_HEIGHT - radius;  // Clamp position
        return true;
    }
    if (posY - radius <= 0)
    {
        directionY *= -1;
        posY = radius;  // Clamp position
        return true;
    }
    return false;
}

void Ball::move()
{
    this->collides();
    posX += directionX;
    posY += directionY;
}

void Ball::collidesPaddle(
    int paddleLeftPosX, int paddleLeftPosY,int paddleRightPosX, int paddleRightPosY, int paddleWidth
)
{
    // Left paddle
    if (posX - radius <= paddleLeftPosX + paddleWidth &&
    (posY - radius >= paddleLeftPosY) && (posY + radius <= paddleLeftPosY + PADDLE_HEIGHT))
    {
        directionX *= -1;
    }

    // Right paddle
    if (posX + radius >= paddleRightPosX &&
    (posY - radius >= paddleRightPosY) && (posY + radius <= paddleRightPosY + PADDLE_HEIGHT))
    {
        directionX *= -1;
    }
}

bool Ball::goalLeft()
{
    if (posX + radius >= WIN_WIDTH)
    {
        resetBall();
        return true;
    }
    return false;
}

bool Ball::goalRight()
{
    if (posX - radius <= 0)
    {
        resetBall();
        return true;
    }
    return false;
}

void Ball::resetBall()
{
    posX = WIN_WIDTH/2;
    posY = WIN_HEIGHT/2;

    int speedChoices[2] = {-1,1};
    directionX *= speedChoices[GetRandomValue(0,1)];
    directionY *= speedChoices[GetRandomValue(0,1)];
}