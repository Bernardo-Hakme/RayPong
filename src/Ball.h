#ifndef BALL_H
#define BALL_H

class Ball
{
private:
    int posX;
    int posY;
    int radius;
    double directionX;
    double directionY;      // careful with the fps (if > 3 already buggy)

public:
    Ball(int x, int y, int r);
    
    int getPosX();
    int getPosY();
    int getRadius();

    void Draw();
    void move();
    bool collides();
    void collidesPaddle(int paddleLeftPosX, int paddleLeftPosY, int paddleRightPosX, int PaddleRightPosY, int paddleWidth);
    bool goalLeft();
    bool goalRight();
    void resetBall();
};

#endif