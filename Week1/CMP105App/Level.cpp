#include "Level.h"

Level::Level(sf::RenderWindow* hwnd)
{
	window = hwnd;

	// initialise game objects
	rect.setSize(sf::Vector2f(50, 50));
	rect.setPosition(200, 200);
	rect.setFillColor(sf::Color::Red);

	circle.setRadius(50);
	circle.setFillColor(sf::Color::Blue);
	circle.setOutlineColor(sf::Color::Red);
	circle.setPosition((window->getSize().x * 0.5) - circle.getRadius(), (window->getSize().y * 0.5)- circle.getRadius());

	redrect.setPosition(100, 100);
	redrect.setSize(sf::Vector2f(100, 100));
	redrect.setFillColor(sf::Color::Red);

	greenrect.setFillColor (sf::Color::Green);
	greenrect.setSize(sf::Vector2f(redrect.getSize().x * 0.5 , redrect.getSize().y * 0.5 ));
	greenrect.setPosition(redrect.getPosition().x + (greenrect.getSize().x/2), redrect.getPosition().y + (greenrect.getSize().y / 2));

	yellowrect.setFillColor(sf::Color::Yellow);
	yellowrect.setSize(sf::Vector2f(greenrect.getSize().x * 0.5, greenrect.getSize().y * 0.5));
	yellowrect.setPosition(greenrect.getPosition().x + (yellowrect.getSize().x / 2), greenrect.getPosition().y + (yellowrect.getSize().y / 2));

	if (!font.loadFromFile("font/arial.ttf")) 
	{
		std::cout << "Eror loading font\n";
	
	}
	text.setFont(font);
	text.setString("Hello World");
	text.setCharacterSize(24);
	text.setFillColor (sf::Color::Red);
	text.setPosition(window->getSize().x * 0.5 - (text.getCharacterSize() * 2), 0);

	lastrect.setFillColor(sf::Color::Green);
	lastrect.setSize(sf::Vector2f(50, 50));
}



Level::~Level()
{
}

// handle user input
void Level::handleInput()
{
	
}

// Update game objects
void Level::update()
{
	lastrect.setPosition(window->getSize().x - lastrect.getSize().x, window->getSize().y - lastrect.getSize().y);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(rect);
	window->draw(circle);
	window->draw(redrect);
	window->draw(greenrect);
	window->draw(yellowrect);
	window->draw(text);
	window->draw(lastrect);
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