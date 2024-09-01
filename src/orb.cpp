#include <SFML/Graphics/Color.hpp>

#include <orb.hpp>

const float Orb::RADIUS = 30.0;

Orb::Orb(size_t x, size_t y) : m_x(x), m_y(y), CircleShape(Orb::RADIUS) {
    setFillColor(sf::Color(100, 250, 50));
    setPosition(y % 2 == 0 ? x * 65.0 : x * 65.0 + 30.0, y * 65.0);
}
