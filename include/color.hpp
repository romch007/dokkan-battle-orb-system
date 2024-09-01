#pragma once

#include <SFML/Graphics/Color.hpp>

class Color {
public:
    inline static const sf::Color GREEN = sf::Color(0x64FA32FF);
    inline static const sf::Color YELLOW = sf::Color(0xEEBD41FF);
    inline static const sf::Color RED = sf::Color(0xC2212AFF);
    inline static const sf::Color BLUE = sf::Color(0x3B3CDDFF);
    inline static const sf::Color PURPLE = sf::Color(0xB52EDDFF);

private:
    Color() {}

};
