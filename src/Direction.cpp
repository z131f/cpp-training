#include "Direction.hpp"

#include "Point.hpp"

namespace adas
{

Direction::Direction(const unsigned index, const char heading) noexcept : index{index}, heading{heading}
{
}

static const Direction directions[4] = {{0, 'E'}, {1, 'S'}, {2, 'W'}, {3, 'N'}};

const Direction& Direction::GetDirection(const char heading) noexcept
{
    for (const auto& direction : directions) {
        if (direction.heading == heading) {
            return direction;
        }
    }
    return directions[3];
}

const Point& Direction::Move() const noexcept
{
    // ESWN
    static const Point points[4] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
    return points[index];
}

const Direction& Direction::LeftOne() const noexcept
{
    return directions[(index + 3) % 4];
}

const Direction& Direction::RightOne() const noexcept
{
    return directions[(index + 1) % 4];
}

const char Direction::GetHeading() const noexcept
{
    return heading;
}

}  // namespace adas