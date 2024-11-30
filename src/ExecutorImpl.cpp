#include "ExecutorImpl.hpp"

#include <memory>

namespace adas
{

const std::unordered_map<char, int> direction_map = {{'N', 0}, {'E', 1}, {'S', 2}, {'W', 3}};
const std::unordered_map<int, char> reverse_direction_map = {{0, 'N'}, {1, 'E'}, {2, 'S'}, {3, 'W'}};

Executor* Executor::NewExecutor(const Pose& pose) noexcept
{
    return new (std::nothrow) ExecutorImpl(pose);
}

ExecutorImpl::ExecutorImpl(const Pose& pose) noexcept : pose(pose)
{
}

void ExecutorImpl::Execute(const std::string& commands) noexcept
{
    for (const auto cmd : commands) {
        if (cmd == 'M') {
            std::unique_ptr<MoveCommand> cmder = std::make_unique<MoveCommand>();
            cmder->DoOperate(*this);
        } else if (cmd == 'L') {
            std::unique_ptr<TurnLeftCommand> cmder = std::make_unique<TurnLeftCommand>();
            cmder->DoOperate(*this);
        } else if (cmd == 'R') {
            std::unique_ptr<TurnRightCommand> cmder = std::make_unique<TurnRightCommand>();
            cmder->DoOperate(*this);
        }
    }
}

void ExecutorImpl::Move() noexcept
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

void ExecutorImpl::TurnLeft() noexcept
{
    pose.heading = reverse_direction_map.at((direction_map.at(pose.heading) + 3) % 4);  // Turn left
}

void ExecutorImpl::TurnRight() noexcept
{
    pose.heading = reverse_direction_map.at((direction_map.at(pose.heading) + 1) % 4);  // Turn right
}

Pose ExecutorImpl::Query() const noexcept
{
    return pose;
}
}  // namespace adas
