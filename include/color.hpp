#pragma once

#include <random>
#include <SFML/Graphics/Color.hpp>

class Color {
public:
    inline static const sf::Color GREEN = sf::Color(0x64FA32FF);
    inline static const sf::Color YELLOW = sf::Color(0xEEBD41FF);
    inline static const sf::Color RED = sf::Color(0xC2212AFF);
    inline static const sf::Color BLUE = sf::Color(0x3B3CDDFF);
    inline static const sf::Color PURPLE = sf::Color(0xB52EDDFF);
    inline static const sf::Color RAINBOW = sf::Color(0xFFFFFFFF);
    inline static const sf::Color NONE = sf::Color(0x00000000);

    inline static sf::Color getRandomColor();

private:
    Color() {}

};

sf::Color Color::getRandomColor() {
    // generate random number in [0, 5]
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0, 5);

    switch (dist6(rng)) {
        case 0:
            return Color::GREEN;
        case 1:
            return Color::YELLOW;
        case 2:
            return Color::RED;
        case 3:
            return Color::BLUE;
        case 4:
            return Color::RAINBOW;
        default:
            return Color::PURPLE;
    }
}
