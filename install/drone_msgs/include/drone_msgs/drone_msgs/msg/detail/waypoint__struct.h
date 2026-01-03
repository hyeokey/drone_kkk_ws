// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from drone_msgs:msg/Waypoint.idl
// generated code does not contain a copyright notice

#ifndef DRONE_MSGS__MSG__DETAIL__WAYPOINT__STRUCT_H_
#define DRONE_MSGS__MSG__DETAIL__WAYPOINT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Waypoint in the package drone_msgs.
typedef struct drone_msgs__msg__Waypoint
{
  float x;
  float y;
  float z;
  float yaw;
  bool valid;
} drone_msgs__msg__Waypoint;

// Struct for a sequence of drone_msgs__msg__Waypoint.
typedef struct drone_msgs__msg__Waypoint__Sequence
{
  drone_msgs__msg__Waypoint * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} drone_msgs__msg__Waypoint__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DRONE_MSGS__MSG__DETAIL__WAYPOINT__STRUCT_H_
