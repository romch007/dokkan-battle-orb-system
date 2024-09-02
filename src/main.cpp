#include <SFML/Window/Mouse.hpp>
#include <array>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <orb.hpp>

int main() {
    std::array<std::array<Orb, 5>, 5> board;
    for (size_t x = 0; x < 5; x++) {
        for (size_t y = 0; y < 5; y++) {
            board[y][x] = Orb(x, y);
        }
    }

    const size_t maxIndex = board.size() - 1;
    const float top = board[maxIndex][0].getPosition().y;
    const float bottom = top + Orb::RADIUS * 2;
    const float right = board[maxIndex][board[maxIndex].size() - 1].getPosition().x + Orb::RADIUS * 2;

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

        // detect collisions
        const auto mousePos = sf::Mouse::getPosition(window);
        if (mousePos.y >= top && mousePos.y <= bottom && mousePos.x >= 0 && mousePos.x <= right) {
            std::cout << "Touching first orbs\n";
        } else {
            std::cout << "Not touching\n";
        }

        // draw everything here...

        /* Loop circles using custom class */
        for (const auto& row : board) {
            for (const auto& orb : row) {
                window.draw(orb);
            }
        }

        // end the current frame
        window.display();
    }

    return 0;
}
