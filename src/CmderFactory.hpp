#pragma once

#include <functional>
#include <list>
#include <unordered_map>

#include "ActionGroup.hpp"
#include "Command.hpp"

namespace adas
{
using Cmder = std::function<ActionGroup(PoseHandler& poseHandler)>;
using CmderList = std::list<Cmder>;
class CmderFactory final
{
public:
    CmderFactory(void) noexcept = default;
    ~CmderFactory(void) noexcept = default;
    CmderFactory(const CmderFactory&) noexcept = delete;
    CmderFactory(const std::string vehicle) noexcept;
    CmderFactory& operator=(const CmderFactory&) noexcept = delete;

public:
    CmderList GetCmders(const std::string& commands) const noexcept;

private:
    std::string ParseCommandString(std::string_view commands) const noexcept;
    void ReplaceAll(std::string& inout, std::string_view what, std::string_view with) const noexcept;

private:
    std::unordered_map<char, Cmder> BuildCmdMap(std::string vehicle) const noexcept;
    const std::unordered_map<char, Cmder> cmderMap;
};
}  // namespace adas
