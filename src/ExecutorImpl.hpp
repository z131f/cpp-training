#pragma once
#include "Executor.hpp"

namespace adas
{
class ExecutorImpl final : public Executor
{
public:
    explicit ExecutorImpl(const Pose& pose) noexcept;
    ~ExecutorImpl() noexcept = default;
    ExecutorImpl(const ExecutorImpl&) = delete;
    ExecutorImpl& operator=(const ExecutorImpl&) = delete;

    void Execute(const std::string& command) noexcept override;
    Pose Query(void) const noexcept override;

    void Move(void) noexcept;
    void TurnLeft(void) noexcept;
    void TurnRight(void) noexcept;
    void Fast(void) noexcept;
    bool IsFast(void) const noexcept;

private:
    Pose pose;
    bool fast = {false};
};
}  // namespace adas
