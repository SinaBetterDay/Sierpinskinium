#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <vector>

using namespace std;
using namespace sf;

int main() {
    // this basically opens a window
    VideoMode vm(1920, 1080);
    RenderWindow window(vm, "No, no..... no", Style::Default);
    RectangleShape rectangle;

    vector<Vector2f> vertices;
    vector<Vector2f> points;

    while (window.isOpen()) {
        
		// events aka mouse button etc.. 
        Event event;

        //handle inputs? idk
		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			window.close();
		}
        
             
        while (window.pollEvent(event)) // first loop that gets inputs
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }

            if (event.type == Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == Mouse::Left)
                {
                    cout << "the right button was pressed" << endl;
                    cout << "mouse x: " << event.mouseButton.x << endl;
                    cout << "mouse y: " << event.mouseButton.y << endl;

                    if (vertices.size() < 3)
                    {
                        vertices.push_back(Vector2f(event.mouseButton.x, event.mouseButton.y));
                    }
                    else if (points.size() == 0)
                    {
                        //fourth click
                        points.push_back(Vector2f(event.mouseButton.x, event.mouseButton.y));
                    }
                }
            }
        }

        RectangleShape dot(Vector2f(10, 10));
        dot.setPosition(event.mouseButton.x, event.mouseButton.y);
        dot.setFillColor(Color::Magenta);

        int midpoint_x, midpoint_y;
        int vert_select = rand() % 3 ;
        double scale_factor = 0.5;



       /////////////////////////////////////need to rewrite this whole jawn
        if (points.size() > 0)
        {
            ///generate more points
            //select random vertex
            //calculate midpoints between random vertex and the last point in the vector
            ///push back to the newly generated coord.

            midpoint_x = points[points.size() - 1].x - (vertices[vert_select].x - points[points.size() - 1].x) * scale_factor;
            midpoint_y = points[points.size() - 1].y - (vertices[vert_select].y - points[points.size() - 1].y) * scale_factor;

      			//points.push_back(Vector2f(midpoint_x, midpoint_y));
      
            cout << "points[points.size() - 1].x\t" << points[points.size() - 1].x << endl;
            cout << "vertices[vert_select].x\t" << vertices[vert_select].x << endl;
            cout << "scale_factor\t" << scale_factor << endl;
            cout << "midpoint_y\t" << midpoint_y << endl;
            cout << "midpoint_x\t" << midpoint_x << endl << endl;
      
      		RectangleShape dot(Vector2f(10, 10));
            dot.setSize(Vector2f(10, 10));
      		dot.setPosition(midpoint_x, midpoint_y);
      
      		sleep(seconds(2));
      
            }
                  
              
            switch (event.type) {           
      
                // this case makes a 10 by 10 pixel dot where mouse clicks
            case Event::MouseButtonPressed:
                dot.setSize(Vector2f(10, 10));
                dot.setPosition(event.mouseButton.x, event.mouseButton.y);
                break;

         

        }


            /// its for the first 4 dot inputs
            /// second vector goes here for the points that get put in for the
            /// triangle now we have a while loop that goes through with the
            /// algorithm and draw a triangle

        window.clear();
        for (int i = 0; i < vertices.size(); i++)
        {
            RectangleShape dot(Vector2f(10, 10));
            dot.setPosition(Vector2f(vertices[i].x, vertices[i].y));
            dot.setFillColor(Color::Magenta);
            window.draw(dot);
        }
        
        window.display();

        
        
        
        
        // Show everything that we drew
        window.display();
    }

    return 0;
}
