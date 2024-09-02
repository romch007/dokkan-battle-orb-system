#pragma once

#include <array>

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>

#include <color.hpp>

class Orb final : public sf::CircleShape {
public:
    Orb() = default;
    Orb(size_t x, size_t y);

    static const float RADIUS;

    void fade();
    void opacify();
    const sf::Color& color() const;
    const size_t& getX() const;
    const size_t& getY() const;

private:
    size_t m_x, m_y;
    sf::Color m_color = Color::NONE;

};

using Board = std::array<std::array<Orb, 5>, 5>;
