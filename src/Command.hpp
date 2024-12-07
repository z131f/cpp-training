#pragma once
#include "ExecutorImpl.hpp"
#include "PoseHandler.hpp"

namespace adas
{
class ICommand
{
public:
    virtual ~ICommand() = default;
    virtual void DoOperate(PoseHandler& poseHandler) const noexcept = 0;
};

class MoveCommand final : public ICommand
{
public:
    void DoOperate(PoseHandler& poseHandler) const noexcept
    {
        if (poseHandler.IsFast()) {
            poseHandler.Move();
        }
        poseHandler.Move();
    }
};
class TurnLeftCommand final : public ICommand
{
public:
    void DoOperate(PoseHandler& poseHandler) const noexcept
    {
        if (poseHandler.IsFast()) {
            poseHandler.Move();
        }
        poseHandler.TurnLeft();
    }
};
class TurnRightCommand final : public ICommand
{
public:
    void DoOperate(PoseHandler& poseHandler) const noexcept
    {
        if (poseHandler.IsFast()) {
            poseHandler.Move();
        }
        poseHandler.TurnRight();
    }
};
class FastCommand final : public ICommand
{
public:
    void DoOperate(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.Fast();
    }
};
}  // namespace adas
