#include "PoseHandler.hpp"
namespace adas
{

const std::unordered_map<char, int> direction_map = {{'N', 0}, {'E', 1}, {'S', 2}, {'W', 3}};
const std::unordered_map<int, char> reverse_direction_map = {{0, 'N'}, {1, 'E'}, {2, 'S'}, {3, 'W'}};

PoseHandler::PoseHandler(const Pose& pose) noexcept : pose(pose)
{
}
void PoseHandler::Move() noexcept
{
    switch (pose.heading) {
    case 'N':
        ++pose.y;
        break;
    case 'E':
        ++pose.x;
        break;
    case 'S':
        --pose.y;
        break;
    case 'W':
        --pose.x;
        break;
    }
}

void PoseHandler::TurnLeft() noexcept
{
    pose.heading = reverse_direction_map.at((direction_map.at(pose.heading) + 3) % 4);  // Turn left
}

void PoseHandler::TurnRight() noexcept
{
    pose.heading = reverse_direction_map.at((direction_map.at(pose.heading) + 1) % 4);  // Turn right
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
    return pose;
}
}  // namespace adas
