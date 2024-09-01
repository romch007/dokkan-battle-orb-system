#pragma once

#include <SFML/Graphics/CircleShape.hpp>

class Orb final : public sf::CircleShape {
public:
    Orb() = default;
    Orb(size_t x, size_t y);

private:
    static const float RADIUS;
    size_t m_x, m_y;

};
