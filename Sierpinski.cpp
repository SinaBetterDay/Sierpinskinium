#include <SFML/Graphics.hpp>
using namespace sf;
#include "points.h"

void inputPoints(points& shape, sf::RenderWindow& window);

int main()
{
    VideoMode vm(1920, 1080);

    RenderWindow window(vm, "No, no..... no", Style::Default);

    RectangleShape rectangle;

    while (window.isOpen())
    {
        //points triangle;
        //inputPoints(triangle, window);
        /*
        ********************
        Handle user's input
        ********************
        */
        //sf::RenderWindow window(sf::VideoMode(1920, 1080), "Chaos Game");

        RectangleShape dot(Vector2f(200, 40));

        Event event;
        

        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case Event::Closed:
                window.close();
                break;
            case Event::MouseButtonPressed:
                dot.setSize(Vector2f(10, 10));
                dot.setPosition(event.mouseButton.x, event.mouseButton.y);
                break;
            }
        }
        ///first vector goes hereeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee or not?
        ///its for the first 4 dot inputs
        /// second vector goes here for the points that get put in for the triangle
        /// now we have a while loop that goes through with the algorithm and draw a triangle


        window.clear();
        window.draw(dot);
        window.display();
       

        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }

        /*
        *********************
        Update the scene
        *********************
        */

        //Change variable values and access functions here?

        /*
        **********************
        Draw the scene
        **********************
        */

        //Show everything that we drew
        window.display();
    }

    return 0;
}
