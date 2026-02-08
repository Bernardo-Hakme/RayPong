#ifndef PADDLE_H
#define PADDLE_H

class Paddle
{
private:
    int posX;
    int posY;
    int width;
    int height;
    int score;

public:
    Paddle(int x, int y, int w, int h);

    int getPosX();
    int getPosY();
    int getScore();

    void Draw();
    void moveWS();
    void moveKeys();
    void moveCPU(int ballPosY);
    void computeScore();
};




#endif