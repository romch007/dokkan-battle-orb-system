#pragma once

#include <SFML/Graphics/CircleShape.hpp>

class Orb final : public sf::CircleShape {
public:
    Orb() = default;
    Orb(size_t x, size_t y);

    static const float RADIUS;

private:
    size_t m_x, m_y;

};
