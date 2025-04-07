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
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Dokkan Battle");

    // run the program as long as the window is open
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
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
            // figure out the color of the path
            size_t i = 0;
            sf::Color color;
            do {
                color = orbs[i++]->color();
            } while (color == Color::RAINBOW); // there cannot be only rainbow orbs in the path

            for (const Orb* orb : orbs) {
                Orb o = *orb;
                o.opacify();
                window.draw(o);
                // burst orbs
                // left
                Orb* burst = &o;
                do {
                    if (*burst != *orb) { // so that orbs on the path are not drawn three times
                        burst->burst();
                        window.draw(*burst);
                    }
                    size_t x = burst->getX();
                    burst = x > 0 ? &board[orb->getY()][x - 1] : nullptr;
                } while (burst && burst->color() == color);
                // right
                burst = &o;
                do {
                    if (*burst != *orb) { // so that orbs on the path are not drawn three times
                        burst->burst();
                        window.draw(*burst);
                    }
                    size_t x = burst->getX();
                    burst = x < board[orb->getY()].size() - 1 ? &board[orb->getY()][x + 1] : nullptr;
                } while (burst && burst->color() == color);
            }
        }

        // end the current frame
        window.display();
    }

    return 0;
}
