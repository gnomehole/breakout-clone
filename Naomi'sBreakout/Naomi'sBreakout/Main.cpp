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

	sf::Vector2f rectSize = sf::Vector2f(150.f, 25.f);
	sf::Vector2f rectPos = sf::Vector2f((windowX / 2) - (rectSize.x / 2), (windowY / 2) - (rectSize.y / 2));
	sf::Vector2f ballPos = sf::Vector2f(rectPos.x, rectPos.y - rectSize.y);
	
	sf::Color Orange = sf::Color(255, 99, 71, 255);
	sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!");
	window.setFramerateLimit(60);
	sf::RectangleShape paddle(rectSize);
	paddle.setFillColor(Orange);
	paddle.setPosition(rectPos);

	sf::CircleShape ball(8.f);
	ball.setFillColor(sf::Color::Green);
	sf::Vector2f velocity = sf::Vector2f(0.f, 0.f);
	velocity.x = rand() % 10; //
	velocity.y = -5; 
	ball.setPosition(ballPos);
	while (window.isOpen())
	{


		if (ball.getPosition().x > windowX || ball.getPosition().x < 0)
		{
			velocity.x = -velocity.x;
		}

		if (ball.getPosition().y > windowY || ball.getPosition().y < 0)
		{
			velocity.y = -velocity.y; 
		}


		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			if (rectPos.x <= 0 )
			{
				rectPos.x = 0 + rectPos.x;
			}
			rectPos.x -= Speed;
			paddle.setPosition(rectPos);

		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			//copy
			if (rectPos.x = windowX)
			{
				rectPos.x = windowX + rectPos.x;
			}
			rectPos.x += Speed;
			paddle.setPosition(rectPos);

		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			if (rectPos.y = (0 - rectPos.y))
			{
				rectPos.x = 0 + rectPos.y;
			}
			rectPos.y += Speed;
			paddle.setPosition(rectPos);

		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			if (rectPos.y = (windowY + rectPos.y))
			{
				rectPos.y = windowY - rectPos.y;
			}
			rectPos.y -= Speed;

			paddle.setPosition(rectPos);


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