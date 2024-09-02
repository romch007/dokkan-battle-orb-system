#include <SFML/Graphics/Color.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Graphics.hpp>

#include <orb.hpp>
#include <algorithm.hpp>

int main() {
    Board board;
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
        int index = -1;
        const auto mousePos = sf::Mouse::getPosition(window);
        if (mousePos.y >= top && mousePos.y <= bottom && mousePos.x >= 0 && mousePos.x <= right) {
            index = mousePos.x / (5 + Orb::RADIUS * 2); // 5 is here for the gap between the orbs
            index = index > maxIndex ? maxIndex : index; // security

            // fade every orb
            for (auto& row : board) {
                for (auto& orb : row) {
                    orb.fade();
                }
            }
        } else {
            // opacify every orb
            for (auto& row : board) {
                for (auto& orb : row) {
                    orb.opacify();
                }
            }
        }

        /* Loop circles using custom class */
        for (size_t y = 0; y < board.size(); y++) {
            auto& row = board[y];
            for (size_t x = 0; x < row.size(); x++) {
                Orb& orb = row[x];
                window.draw(orb);
            }
        }

        if (index != -1) {
            std::vector<const Orb*> orbs = findLongestPath(board, &board[maxIndex][index]);
            for (const Orb* orb : orbs) {
                Orb o = *orb;
                o.opacify();
                window.draw(o);
            }
        }

        // end the current frame
        window.display();
    }

    return 0;
}
