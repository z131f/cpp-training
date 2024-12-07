#include "PoseHandler.hpp"
namespace adas
{

const std::unordered_map<char, int> direction_map = {{'N', 0}, {'E', 1}, {'S', 2}, {'W', 3}};
const std::unordered_map<int, char> reverse_direction_map = {{0, 'N'}, {1, 'E'}, {2, 'S'}, {3, 'W'}};

PoseHandler::PoseHandler(const Pose& pose) noexcept : point{pose.x, pose.y}, direction{direction_map.at(pose.heading)}
{
}
void PoseHandler::Move() noexcept
{
    Point add_point;
    switch (direction) {
    case 0:
        add_point = Point{0, 1};
        break;
    case 1:
        add_point = Point{1, 0};
        break;
    case 2:
        add_point = Point{0, -1};
        break;
    case 3:
        add_point = Point{-1, 0};
        break;
    }
    point += add_point;
}

void PoseHandler::TurnLeft() noexcept
{
    direction = (direction + 3) % 4;  // Turn left
}

void PoseHandler::TurnRight() noexcept
{
    direction = (direction + 1) % 4;  // Turn right
}

void PoseHandler::Fast() noexcept
{
    fast = !fast;
}

bool PoseHandler::IsFast() const noexcept
{
    return fast;
}

Pose PoseHandler::Query() const noexcept
{
    return Pose{point.GetX(), point.GetY(), reverse_direction_map.at(direction)};
}
}  // namespace adas
