#include <orb.hpp>
#include <color.hpp>

const float Orb::RADIUS = 30.0;

Orb::Orb(size_t x, size_t y) : m_x(x), m_y(y), CircleShape(Orb::RADIUS) {
    switch (x) {
        case 0:
            setFillColor(Color::YELLOW);
            break;

        case 1:
            setFillColor(Color::RED);
            break;

        case 2:
            setFillColor(Color::BLUE);
            break;

        case 3:
            setFillColor(Color::PURPLE);
            break;

        default:
            setFillColor(Color::GREEN);
            break;
    }
    setPosition(y % 2 == 0 ? x * 65.0 : x * 65.0 + 30.0, y * 65.0);
}
