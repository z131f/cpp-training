#pragma once
#include "Executor.hpp"
#include "PoseHandler.hpp"

namespace adas
{
class ExecutorImpl final : public Executor
{
public:
    explicit ExecutorImpl(const Pose& pose) noexcept;
    ExecutorImpl(const Pose& pose, std::string vehicle) noexcept;
    ~ExecutorImpl() noexcept = default;
    ExecutorImpl(const ExecutorImpl&) = delete;
    ExecutorImpl& operator=(const ExecutorImpl&) = delete;
    Pose Query(void) const noexcept;
    void Execute(const std::string& command) noexcept override;

private:
    PoseHandler poseHandler;
    std::string vehicle = "default";
};
}  // namespace adas
