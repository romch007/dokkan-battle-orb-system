#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>

int main() {
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Dokkan Battle");

    // run the program as long as the window is open
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...

        /* First circles
        sf::CircleShape circle(30.0);
        circle.setFillColor(sf::Color(100, 250, 50));
        window.draw(circle);

        sf::CircleShape circle2(30.0);
        circle2.setFillColor(sf::Color(230, 20, 20));
        circle2.setPosition(0.0, 65.0);
        window.draw(circle2);
        */

        /* Loop circles */
        for (size_t x = 0; x < 5; x++) {
            for (size_t y = 0; y < 5; y++) {
                sf::CircleShape circle(30.0);
                circle.setFillColor(sf::Color(100, 250, 50));
                circle.setPosition(y % 2 == 0 ? x * 65.0 : x * 65.0 + 30.0, y * 65.0);
                window.draw(circle);
            }
        }

        // end the current frame
        window.display();
    }

    return 0;
}
