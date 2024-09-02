#include <orb.hpp>
#include <color.hpp>

const float Orb::RADIUS = 30.0;

Orb::Orb(size_t x, size_t y) : m_x(x), m_y(y), CircleShape(Orb::RADIUS) {
    m_color = Color::getRandomColor();
    setFillColor(m_color);
    setPosition(y % 2 == 0 ? x * 65.0 : x * 65.0 + 30.0, y * 65.0);
}

void Orb::fade() {
    setFillColor(sf::Color(
                m_color.r,
                m_color.g,
                m_color.b,
                100
    ));
}

void Orb::opacify() {
    setFillColor(sf::Color(
                m_color.r,
                m_color.g,
                m_color.b,
                255
    ));
}

const sf::Color& Orb::color() const {
    return m_color;
}

const size_t& Orb::getX() const {
    return m_x;
}

const size_t& Orb::getY() const {
    return m_y;
}
