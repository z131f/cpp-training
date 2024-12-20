#include "ActionGroup.hpp"

#include <algorithm>
#include <cstdint>

#include "CmderFactory.hpp"

namespace adas
{
class ForwarAction final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.Forward();
    }
};
class BackwardAction final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.Backward();
    }
};
class TurnLeftAction final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.TurnLeft();
    }
};
class ReverseTurnLeftAction final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.TurnRight();
    }
};
class TurnRightAction final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.TurnRight();
    }
};
class ReverseTurnRightAction final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.TurnLeft();
    }
};
class FastAction final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.Fast();
    }
};
class ReverseAction final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.Reverse();
    }
};
ActionGroup::ActionGroup(const std::list<ActionType>& actions) noexcept : actions(actions)
{
}
void ActionGroup::PushAction(const ActionType actionType) noexcept
{
    actions.push_back(actionType);
}

void ActionGroup::DoOperate(PoseHandler& poseHandler) const noexcept
{
    static std::vector<std::function<void(PoseHandler & poseHandler)>> actionVec = {
        ForwarAction(),    BackwardAction(),         TurnLeftAction(), ReverseTurnLeftAction(),
        TurnRightAction(), ReverseTurnRightAction(), FastAction(),     ReverseAction(),
    };
    std::for_each(actions.begin(), actions.end(), [&poseHandler](const ActionType actionType) mutable noexcept {
        actionVec[static_cast<uint16_t>(actionType)](poseHandler);
    });
}

}  // namespace adas
