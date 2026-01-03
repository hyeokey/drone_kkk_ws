// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from drone_msgs:msg/MarkerCenter.idl
// generated code does not contain a copyright notice

#ifndef DRONE_MSGS__MSG__DETAIL__MARKER_CENTER__STRUCT_H_
#define DRONE_MSGS__MSG__DETAIL__MARKER_CENTER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/MarkerCenter in the package drone_msgs.
typedef struct drone_msgs__msg__MarkerCenter
{
  float u;
  float v;
  bool detected;
} drone_msgs__msg__MarkerCenter;

// Struct for a sequence of drone_msgs__msg__MarkerCenter.
typedef struct drone_msgs__msg__MarkerCenter__Sequence
{
  drone_msgs__msg__MarkerCenter * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} drone_msgs__msg__MarkerCenter__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DRONE_MSGS__MSG__DETAIL__MARKER_CENTER__STRUCT_H_
