#include "CmderFactory.hpp"
namespace adas
{
std::list<std::function<void(PoseHandler& poseHandler)>> CmderFactory::GetCmders(
    const std::string& commands) const noexcept
{
    std::list<std::function<void(PoseHandler & poseHandler)>> cmders;

    for (const auto cmd : commands) {
        const auto it = cmderMap.find(cmd);
        if (it != cmderMap.end()) {
            cmders.push_back(it->second);
        }
    }

    return cmders;
}
}  // namespace adas
