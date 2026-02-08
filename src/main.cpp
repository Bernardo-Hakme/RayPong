#include "config.h"
#include "Ball.h"
#include "Paddle.h"

Color gameRed = Color{255, 0, 0, 255};
Color gameBrightRed = Color{255, 100, 100, 255};


int main()
{
	InitWindow(WIN_WIDTH, WIN_HEIGHT, "RayPong");
	SetTargetFPS(60);

	Ball ball(WIN_WIDTH/2, WIN_HEIGHT/2, BALL_RADIUS);
	Paddle paddleLeft(15, WIN_HEIGHT/2 - PADDLE_HEIGHT/2, PADDLE_WIDTH, PADDLE_HEIGHT);
	Paddle paddleRight(WIN_WIDTH-2*PADDLE_WIDTH, WIN_HEIGHT/2 - PADDLE_HEIGHT/2, PADDLE_WIDTH, PADDLE_HEIGHT);

	while(!WindowShouldClose())
	{
		// Event Handling
		ball.move();
		paddleLeft.moveCPU(ball.getPosY()); // change to moveWS() if a human is playing
		paddleRight.moveKeys();
		ball.collidesPaddle(paddleLeft.getPosX(), paddleLeft.getPosY(), paddleRight.getPosX(), paddleRight.getPosY(), PADDLE_WIDTH);
		
		if (ball.goalLeft())
		{
			paddleLeft.computeScore();
		}
		else if (ball.goalRight())
		{
			paddleRight.computeScore();
		}

		// Draw to screen
		BeginDrawing();
		ClearBackground(gameBrightRed);
		DrawRectangle(0, 0, WIN_WIDTH/2, WIN_HEIGHT, gameRed);
		DrawCircle(WIN_WIDTH/2, WIN_HEIGHT/2, 100, WHITE);

		DrawLine(WIN_WIDTH/2, 0, (WIN_WIDTH/2), WIN_HEIGHT, WHITE);

		DrawText(std::to_string(paddleLeft.getScore()).c_str(), (WIN_WIDTH/2)/2, 20, 80, WHITE);
		DrawText(std::to_string(paddleRight.getScore()).c_str(), WIN_WIDTH - (WIN_WIDTH/2)/2, 20, 80, WHITE);

		ball.Draw();
		paddleLeft.Draw();
		paddleRight.Draw();

		EndDrawing();
	}
	CloseWindow();

	std::cout << "\nFinal score:" << std::endl;
	std::cout << "Player left: " << paddleLeft.getScore() << "\n"
	<< "Player Right: " << paddleRight.getScore() << std::endl;
	return 0;
}