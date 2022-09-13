#include "SFML/Graphics.hpp"
#include <iostream>

int main()
{
	sf::RenderWindow window( sf::VideoMode( 1920, 1080 ), "No, no..... no" );

	sf::RectangleShape dot(sf::Vector2f(200, 40));

	dot.setSize(sf::Vector2f(4, 4));

	while ( window.isOpen( ) )
	{
		sf::Event event;

		while ( window.pollEvent( event ) )
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
      }
		}
		window.clear( );
    window.draw(dot);
    window.display( );
	}
}
