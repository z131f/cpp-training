#include "ExecutorImpl.hpp"

#include <memory>

#include "Command.hpp"

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
        std::unique_ptr<ICommand> cmder;
        if (cmd == 'M') {
            cmder = std::make_unique<MoveCommand>();
        } else if (cmd == 'L') {
            cmder = std::make_unique<TurnLeftCommand>();
        } else if (cmd == 'R') {
            cmder = std::make_unique<TurnRightCommand>();
        } else if (cmd == 'F') {
            cmder = std::make_unique<FastCommand>();
        }
        if (cmder) {
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

void ExecutorImpl::Fast() noexcept
{
    fast = !fast;
}

bool ExecutorImpl::IsFast() const noexcept
{
    return fast;
}

Pose ExecutorImpl::Query() const noexcept
{
    return pose;
}
}  // namespace adas
