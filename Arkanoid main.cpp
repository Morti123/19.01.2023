#include "settings.h" 
#include "Function.h" 
#include "Textobj.h" 
#include "BALL.h" 
#include "BAT.h" 
#include "Break.h" 
using namespace sf;
int main()
{
	srand(time(nullptr));
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
	window.setFramerateLimit(FPS);
	RectangleShape Bat;
	initBat(Bat, BatColor, BatStartPos);
	float BatSpeedX = 0.f;
	Ball ball;
	ballInit(ball);
	TextObj scoreText;
	initText(scoreText, ball.Score);
	Brick brick;
	brickInit(brick, Brick_Color, BrickStartPos);
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		brickUpdate(brick);
		ballUpdate(ball);
		textUpdate(scoreText, ball.Score);
		if (Keyboard::isKeyPressed(Keyboard::Left)) { Bat.move(-5, 0); }
		if (Keyboard::isKeyPressed(Keyboard::Right)) { Bat.move(5, 0); }
		if (Bat.getPosition().x <= 0) {
			Bat.setPosition(0.f, WINDOW_HEIGHT - 2 * batHeight);
		}
		if (Bat.getPosition().x + batWidth >= WINDOW_WIDTH) {
			Bat.setPosition(WINDOW_WIDTH - batWidth, WINDOW_HEIGHT - 2 * batHeight);
		}
		if (ball.shape.getPosition().y >= (WINDOW_HEIGHT - 2 * BALL_RADIUS)) {
			ball.speedy = -ball.speedy;
			window.close();
		}
		Bat.move(0, BatSpeedX);
		BatSpeedX = 0;
		float ballX = ball.shape.getPosition().x;
		float ballY = ball.shape.getPosition().y;
		Vector2f midTop{ ballX + BALL_RADIUS,  ballY };
		Vector2f  mid{ ballX, ballY + BALL_RADIUS };
		Vector2f midBottom{ ballX + BALL_RADIUS,  ballY + 2 * BALL_RADIUS };
		if (pointInRect(Bat, mid)) {
			ball.speedx = -ball.speedx;
			ball.Score++;
		}
		if (pointInRect(Bat, midBottom)) {
			ball.speedy = -ball.speedy;
			ball.Score++;
		}
		if (pointInRect(Bat, midTop)) {
			ball.speedy = -ball.speedy;
			ball.Score++;
		}
		window.clear(sf::Color::Black);
		ballDraw(window, ball);
		window.draw(Bat);
		brickDraw(window, brick);
		textDraw(window, scoreText);
		window.display();
	}

	return 0;
}