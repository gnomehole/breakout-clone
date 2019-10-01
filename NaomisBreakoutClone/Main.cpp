#include <SFML/Graphics.hpp>


int main()
{
	int windowX = 600;
	int windowY = 600;
	int Speed = 10;
	int Leftbound;
	int Rightbound;
	int Topbound;

	bool HitsWall = false;

	sf::Vector2f paddleSize = sf::Vector2f(150.f, 25.f);
	sf::Vector2f paddlePos = sf::Vector2f((windowX / 2) - (paddleSize.x / 2), (windowY / 2) - (paddleSize.y / 2));
	sf::Vector2f ballPos = sf::Vector2f((windowX / 2), (windowY / 2));
	//collision vector to make it easier to tweak
	


	sf::Color Orange = sf::Color(255, 99, 71, 255);
	sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!");
	window.setFramerateLimit(60);
	sf::RectangleShape paddle(paddleSize);
	paddle.setFillColor(Orange);
	paddle.setPosition(paddlePos);

	sf::CircleShape ball(8.f);
	ball.setFillColor(sf::Color::Green);
	sf::Vector2f velocity = sf::Vector2f(0.f, 0.f);
	velocity.x = rand() % 10; //this is just to give a little more character to the physics so it doesnt look too robotic
	velocity.y = -5;
	ball.setPosition(ballPos);
	while (window.isOpen())
	{
		
		//this inverts the velocity and simulates physics
		//NOTE! I'm using ball.getPosition to get the ball position and not just ballPos.ALWAYS make that mistake maybe it will sink in this time lol
		//ball X boundary
		//for paddle collision maybe i could make a get paddle position method and call it when the paddle is moved 
		//X boundry screen wrapping
		if (ball.getPosition().x > windowX)
		{
			//velocity.x = -velocity.x;
			 ballPos.x = 0;
			 ballPos.y = ball.getPosition().y;
			 ball.setPosition(ballPos);
		}
		if (ball.getPosition().x < 0)
		{
			//velocity.x = -velocity.x;
			ballPos.x = windowX;
			ballPos.y = ball.getPosition().y;
			ball.setPosition(ballPos);
		}
		//ball Y boundary screen wrapping
		if (ball.getPosition().y < 0)
		{
			ballPos.y = windowY;
			ballPos.x = ball.getPosition().x;
			ball.setPosition(ballPos);
		}
		if (ball.getPosition().y > windowY)
		{
			ballPos.y = 0;
			ballPos.x = ball.getPosition().x;
			ball.setPosition(ballPos);
		}
		//paddle movement and boundaries
		//Left
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			if (paddlePos.x <= 0.f)
			{
				paddlePos.x = 0;
			}
			paddlePos.x -= Speed;
			paddle.setPosition(paddlePos);
		}
		//Right
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			if (paddlePos.x >= (windowX - paddleSize.x))
			{
				paddlePos.x = (windowX - paddleSize.x);
			}
			paddlePos.x += Speed;
			paddle.setPosition(paddlePos);
		}
		//Down
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			if (paddlePos.y >= (windowY - paddleSize.y))
			{
				paddlePos.y = (windowY - paddleSize.y);
			}
			paddlePos.y += Speed;
			paddle.setPosition(paddlePos);
		}
		//Up
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			if (paddlePos.y <= 0)
			{
				paddlePos.y = 0;
			}
			paddlePos.y -= Speed;

			paddle.setPosition(paddlePos);
		}
		//(ball.getPosition().y <= (paddlePos.y + paddleSize.y) && ball.getPosition().y >= paddlePos.y) 
		//the paddle collision is just an if statement that checks if the ball x,y values are in range of the paddle x,y with the paddle size taken into acc
		//this feels like a messy way to write it but it works for now. if the paddle is moving too fast on y axis sometimes it goes therough the ball
		//its still too slow :( 
		if ((ball.getPosition().x <= (paddlePos.x + paddleSize.x) && ball.getPosition().x >= (paddlePos.x)) && ball.getPosition().y == paddlePos.y)
		{
			velocity = -velocity;
		}
		ball.move(velocity);
		
		sf::Event event;
		//Pollevent is our window updating 
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		window.clear();
		window.draw(paddle);
		window.draw(ball);
		window.display();
	}

	return 0;
	
}

