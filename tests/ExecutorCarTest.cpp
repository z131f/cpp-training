#include <gtest/gtest.h>

#include <memory>

#include "Executor.hpp"
#include "PoseEq.hpp"

namespace adas
{
TEST(ExecutorCarTest, should_return_x_plus_2_given_command_is_M_facing_is_E_status_is_normal_vehicle_is_car)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    // when
    executor->Execute("M");
    // then
    const Pose target({2, 0, 'E'});
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorCarTest, should_return_N_and_y_plus_1_given_command_is_L_facing_is_E_status_is_normal_vehicle_is_car)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    // when
    executor->Execute("L");
    // then
    const Pose target({0, 1, 'N'});
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorCarTest, should_return_S_and_y_minus_1_given_command_is_R_facing_is_E_status_is_normal_vehicle_is_car)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    // when
    executor->Execute("R");
    // then
    const Pose target({0, -1, 'S'});
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorCarTest, should_return_x_minus_2_given_command_is_M_facing_is_E_status_is_B_vehicle_is_car)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    // when
    executor->Execute("BM");
    // then
    const Pose target({-2, 0, 'E'});
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorCarTest, should_return_S_and_y_plus_1_given_command_is_L_facing_is_E_status_is_B_vehicle_is_car)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    // when
    executor->Execute("BL");
    // then
    const Pose target({0, 1, 'S'});
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorCarTest, should_return_N_and_y_minus_1_given_command_is_R_facing_is_E_status_is_B_vehicle_is_car)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    // when
    executor->Execute("BR");
    // then
    const Pose target({0, -1, 'N'});
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorCarTest, should_return_x_plus_4_given_command_is_M_facing_is_E_status_is_F_vehicle_is_car)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    // when
    executor->Execute("FM");
    // then
    const Pose target({4, 0, 'E'});
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorCarTest, should_return_N_and_x_plus_1_y_plus_1_given_command_is_L_facing_is_E_status_is_F_vehicle_is_car)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    // when
    executor->Execute("FL");
    // then
    const Pose target({1, 1, 'N'});
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorCarTest, should_return_S_and_x_plus_1_y_minus_1_given_command_is_R_facing_is_E_status_is_F_vehicle_is_car)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    // when
    executor->Execute("FR");
    // then
    const Pose target({1, -1, 'S'});
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorCarTest, should_return_x_minus_4_given_command_is_M_facing_is_E_status_is_BF_vehicle_is_car)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    // when
    executor->Execute("BFM");
    // then
    const Pose target({-4, 0, 'E'});
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorCarTest, should_return_S_and_x_minus_1_y_plus_1_given_command_is_L_facing_is_E_status_is_BF_vehicle_is_car)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    // when
    executor->Execute("BFL");
    // then
    const Pose target({-1, 1, 'S'});
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorCarTest,
     should_return_N_and_x_minus_1_y_minus_1_given_command_is_R_facing_is_E_status_is_BF_vehicle_is_car)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    // when
    executor->Execute("BFR");
    // then
    const Pose target({-1, -1, 'N'});
    ASSERT_EQ(target, executor->Query());
}
}  // namespace adas