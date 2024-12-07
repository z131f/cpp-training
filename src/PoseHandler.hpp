#pragma once
#include "Direction.hpp"
#include "Executor.hpp"
#include "Point.hpp"

namespace adas
{
class PoseHandler final
{
public:
    PoseHandler(const Pose& pose) noexcept;
    PoseHandler(const PoseHandler&) = delete;
    PoseHandler& operator=(const PoseHandler&) = delete;

public:
    void Forward(void) noexcept;
    void Backward(void) noexcept;
    void TurnLeft(void) noexcept;
    void TurnRight(void) noexcept;
    void Fast(void) noexcept;
    bool IsFast(void) const noexcept;
    void Reverse(void) noexcept;
    bool IsReversed(void) const noexcept;
    Pose Query(void) const noexcept;

private:
    Point point;
    const Direction* facing;
    bool fast{false};
    bool reverse{false};
};
}  // namespace adas
