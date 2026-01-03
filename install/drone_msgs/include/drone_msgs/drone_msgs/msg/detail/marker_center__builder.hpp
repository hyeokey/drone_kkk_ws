// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from drone_msgs:msg/MarkerCenter.idl
// generated code does not contain a copyright notice

#ifndef DRONE_MSGS__MSG__DETAIL__MARKER_CENTER__BUILDER_HPP_
#define DRONE_MSGS__MSG__DETAIL__MARKER_CENTER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "drone_msgs/msg/detail/marker_center__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace drone_msgs
{

namespace msg
{

namespace builder
{

class Init_MarkerCenter_detected
{
public:
  explicit Init_MarkerCenter_detected(::drone_msgs::msg::MarkerCenter & msg)
  : msg_(msg)
  {}
  ::drone_msgs::msg::MarkerCenter detected(::drone_msgs::msg::MarkerCenter::_detected_type arg)
  {
    msg_.detected = std::move(arg);
    return std::move(msg_);
  }

private:
  ::drone_msgs::msg::MarkerCenter msg_;
};

class Init_MarkerCenter_v
{
public:
  explicit Init_MarkerCenter_v(::drone_msgs::msg::MarkerCenter & msg)
  : msg_(msg)
  {}
  Init_MarkerCenter_detected v(::drone_msgs::msg::MarkerCenter::_v_type arg)
  {
    msg_.v = std::move(arg);
    return Init_MarkerCenter_detected(msg_);
  }

private:
  ::drone_msgs::msg::MarkerCenter msg_;
};

class Init_MarkerCenter_u
{
public:
  Init_MarkerCenter_u()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MarkerCenter_v u(::drone_msgs::msg::MarkerCenter::_u_type arg)
  {
    msg_.u = std::move(arg);
    return Init_MarkerCenter_v(msg_);
  }

private:
  ::drone_msgs::msg::MarkerCenter msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::drone_msgs::msg::MarkerCenter>()
{
  return drone_msgs::msg::builder::Init_MarkerCenter_u();
}

}  // namespace drone_msgs

#endif  // DRONE_MSGS__MSG__DETAIL__MARKER_CENTER__BUILDER_HPP_
