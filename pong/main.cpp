#include "raylib.h"

struct Ball
{
	float x, y, speedX, speedY, radius;

	void Draw()
	{
		DrawCircle(int(x), int(y), radius, WHITE);

	}

};

struct Paddle
{
	float x, y, speed, width, height;


	void Draw()
	{
		DrawRectangle(x-width/2, y-height/2 , 10, 100, WHITE);
	}
};

int main()
{
	InitWindow(800, 600, "Pong");
	SetWindowState(FLAG_VSYNC_HINT);

	Ball ball;

	ball.x = GetScreenWidth() / 2.0f;
	ball.y = GetScreenHeight() / 2.0f;
	ball.radius = 5.0;
	ball.speedX = 100;
	ball.speedY = 300;

	Paddle leftPaddle;

	leftPaddle.x = 50;
	leftPaddle.y = GetScreenHeight() / 2;
	leftPaddle.width = 10;
	leftPaddle.height = 100;
	leftPaddle.speed = 500;

	Paddle rightPaddle;

	rightPaddle.x = GetScreenWidth() - 50;
	rightPaddle.y = GetScreenHeight() / 2;
	rightPaddle.width = 10;
	rightPaddle.height = 100;
	rightPaddle.speed = 500;


	while (!WindowShouldClose())
	{
		ball.x += ball.speedX* GetFrameTime();
		ball.y += ball.speedY* GetFrameTime();
		
		if (ball.y < 0)
		{
			ball.y = 0;
			ball.speedY *= -1;
		}

		if (ball.y > GetScreenHeight())
		{
			ball.y = GetScreenHeight();
			ball.speedY *= -1;
		}

		if (IsKeyDown(KEY_W))
		{
			leftPaddle.y -= leftPaddle.speed * GetFrameTime();
		}

		if (IsKeyDown(KEY_S))
		{
			leftPaddle.y += leftPaddle.speed * GetFrameTime();
		}

		if (IsKeyDown(KEY_UP))
		{
			rightPaddle.y -= rightPaddle.speed * GetFrameTime();
		}

		if (IsKeyDown(KEY_DOWN))
		{
			rightPaddle.y += rightPaddle.speed * GetFrameTime();
		}

		BeginDrawing();
			ClearBackground(BLACK);

			ball.Draw();
			leftPaddle.Draw();
			rightPaddle.Draw();

			DrawFPS(10, 0);
		EndDrawing();
	}

	CloseWindow();

	return 0;
}