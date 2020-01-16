#include "Level.h"

Level::Level(sf::RenderWindow* hwnd)
{
	window = hwnd;

	// initialise game objects
	rect.setSize(sf::Vector2f(100, 100));
	rect.setPosition(100, 100);
	rect.setFillColor(sf::Color::Red); 

	rect1.setSize(sf::Vector2f(50, 50));
	rect1.setPosition(125, 125);
	rect1.setFillColor(sf::Color::Green);

	rect2.setSize(sf::Vector2f(25, 25));
	rect2.setPosition(137, 137);
	rect2.setFillColor(sf::Color::Magenta);

	circle.setRadius(50);
	circle.setPosition(600 - 50, 337 - 50);
	circle.setFillColor(sf::Color::Blue);
	circle.setOutlineColor(sf::Color::Red);
	circle.setOutlineThickness(2.f);

	circle1.setRadius(7);
	circle1.setPosition(566, 320 );
	circle1.setFillColor(sf::Color::Black);
	circle1.setOutlineColor(sf::Color::Green);
	circle1.setOutlineThickness(1.f);


	circle2.setRadius(7);
	circle2.setPosition(620, 320);
	circle2.setFillColor(sf::Color::Black);
	circle2.setOutlineColor(sf::Color::Green);
	circle2.setOutlineThickness(1.f);
}

Level::~Level()
{
}

// handle user input
void Level::handleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		facePosition.x--;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		facePosition.x++;
	}
}

// Update game objects
void Level::update()
{
	circle.setPosition(facePosition.x, facePosition.y);
	circle1.setPosition(facePosition.x + 20, facePosition.y + 20);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(rect);
	window->draw(rect1);
	window->draw(rect2);
	window->draw(circle);
	window->draw(circle1);
	window->draw(circle2);

	endDraw();
}

void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}