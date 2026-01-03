// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from drone_msgs:msg/MarkerCenter.idl
// generated code does not contain a copyright notice

#ifndef DRONE_MSGS__MSG__DETAIL__MARKER_CENTER__STRUCT_HPP_
#define DRONE_MSGS__MSG__DETAIL__MARKER_CENTER__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__drone_msgs__msg__MarkerCenter __attribute__((deprecated))
#else
# define DEPRECATED__drone_msgs__msg__MarkerCenter __declspec(deprecated)
#endif

namespace drone_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MarkerCenter_
{
  using Type = MarkerCenter_<ContainerAllocator>;

  explicit MarkerCenter_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->u = 0.0f;
      this->v = 0.0f;
      this->detected = false;
    }
  }

  explicit MarkerCenter_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->u = 0.0f;
      this->v = 0.0f;
      this->detected = false;
    }
  }

  // field types and members
  using _u_type =
    float;
  _u_type u;
  using _v_type =
    float;
  _v_type v;
  using _detected_type =
    bool;
  _detected_type detected;

  // setters for named parameter idiom
  Type & set__u(
    const float & _arg)
  {
    this->u = _arg;
    return *this;
  }
  Type & set__v(
    const float & _arg)
  {
    this->v = _arg;
    return *this;
  }
  Type & set__detected(
    const bool & _arg)
  {
    this->detected = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    drone_msgs::msg::MarkerCenter_<ContainerAllocator> *;
  using ConstRawPtr =
    const drone_msgs::msg::MarkerCenter_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<drone_msgs::msg::MarkerCenter_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<drone_msgs::msg::MarkerCenter_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      drone_msgs::msg::MarkerCenter_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<drone_msgs::msg::MarkerCenter_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      drone_msgs::msg::MarkerCenter_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<drone_msgs::msg::MarkerCenter_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<drone_msgs::msg::MarkerCenter_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<drone_msgs::msg::MarkerCenter_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__drone_msgs__msg__MarkerCenter
    std::shared_ptr<drone_msgs::msg::MarkerCenter_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__drone_msgs__msg__MarkerCenter
    std::shared_ptr<drone_msgs::msg::MarkerCenter_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MarkerCenter_ & other) const
  {
    if (this->u != other.u) {
      return false;
    }
    if (this->v != other.v) {
      return false;
    }
    if (this->detected != other.detected) {
      return false;
    }
    return true;
  }
  bool operator!=(const MarkerCenter_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MarkerCenter_

// alias to use template instance with default allocator
using MarkerCenter =
  drone_msgs::msg::MarkerCenter_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace drone_msgs

#endif  // DRONE_MSGS__MSG__DETAIL__MARKER_CENTER__STRUCT_HPP_
