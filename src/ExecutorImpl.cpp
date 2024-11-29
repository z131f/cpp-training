#include "ExecutorImpl.hpp"

namespace adas
{
Executor* Executor::NewExecutor(const Pose& pose) noexcept
{
    return new (std::nothrow) ExecutorImpl(pose);
}

ExecutorImpl::ExecutorImpl(const Pose& pose) noexcept : pose(pose)
{
}

void ExecutorImpl::Execute(const std::string& commands) noexcept
{
    const std::unordered_map<char, int> direction_map = {
        {'N', 0},
        {'E', 1},
        {'S', 2},
        {'W', 3}
    };

    const std::unordered_map<int, char> reverse_direction_map = {
        {0, 'N'},
        {1, 'E'},
        {2, 'S'},
        {3, 'W'}
    };

    for (const auto cmd : commands) {
        if (cmd == 'M') {
            switch (pose.heading) {
                case 'N': ++pose.y; break;
                case 'E': ++pose.x; break;
                case 'S': --pose.y; break;
                case 'W': --pose.x; break;
            }
        } else if (cmd == 'L') {
            pose.heading = reverse_direction_map.at((direction_map.at(pose.heading) + 3) % 4);  // Turn left
        } else if (cmd == 'R') {
            pose.heading = reverse_direction_map.at((direction_map.at(pose.heading) + 1) % 4);  // Turn right
        }
    }
}

Pose ExecutorImpl::Query() const noexcept
{
    return pose;
}
}  // namespace adas
