// Generated by gencpp from file turtlebot3_example/Turtlebot3ActionGoal.msg
// DO NOT EDIT!


#ifndef TURTLEBOT3_EXAMPLE_MESSAGE_TURTLEBOT3ACTIONGOAL_H
#define TURTLEBOT3_EXAMPLE_MESSAGE_TURTLEBOT3ACTIONGOAL_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <actionlib_msgs/GoalID.h>
#include <turtlebot3_example/Turtlebot3Goal.h>

namespace turtlebot3_example
{
template <class ContainerAllocator>
struct Turtlebot3ActionGoal_
{
  typedef Turtlebot3ActionGoal_<ContainerAllocator> Type;

  Turtlebot3ActionGoal_()
    : header()
    , goal_id()
    , goal()  {
    }
  Turtlebot3ActionGoal_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , goal_id(_alloc)
    , goal(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef  ::actionlib_msgs::GoalID_<ContainerAllocator>  _goal_id_type;
  _goal_id_type goal_id;

   typedef  ::turtlebot3_example::Turtlebot3Goal_<ContainerAllocator>  _goal_type;
  _goal_type goal;





  typedef boost::shared_ptr< ::turtlebot3_example::Turtlebot3ActionGoal_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::turtlebot3_example::Turtlebot3ActionGoal_<ContainerAllocator> const> ConstPtr;

}; // struct Turtlebot3ActionGoal_

typedef ::turtlebot3_example::Turtlebot3ActionGoal_<std::allocator<void> > Turtlebot3ActionGoal;

typedef boost::shared_ptr< ::turtlebot3_example::Turtlebot3ActionGoal > Turtlebot3ActionGoalPtr;
typedef boost::shared_ptr< ::turtlebot3_example::Turtlebot3ActionGoal const> Turtlebot3ActionGoalConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::turtlebot3_example::Turtlebot3ActionGoal_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::turtlebot3_example::Turtlebot3ActionGoal_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::turtlebot3_example::Turtlebot3ActionGoal_<ContainerAllocator1> & lhs, const ::turtlebot3_example::Turtlebot3ActionGoal_<ContainerAllocator2> & rhs)
{
  return lhs.header == rhs.header &&
    lhs.goal_id == rhs.goal_id &&
    lhs.goal == rhs.goal;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::turtlebot3_example::Turtlebot3ActionGoal_<ContainerAllocator1> & lhs, const ::turtlebot3_example::Turtlebot3ActionGoal_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace turtlebot3_example

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::turtlebot3_example::Turtlebot3ActionGoal_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::turtlebot3_example::Turtlebot3ActionGoal_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::turtlebot3_example::Turtlebot3ActionGoal_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::turtlebot3_example::Turtlebot3ActionGoal_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::turtlebot3_example::Turtlebot3ActionGoal_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::turtlebot3_example::Turtlebot3ActionGoal_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::turtlebot3_example::Turtlebot3ActionGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "629663823fea578d64180162f10bec87";
  }

  static const char* value(const ::turtlebot3_example::Turtlebot3ActionGoal_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x629663823fea578dULL;
  static const uint64_t static_value2 = 0x64180162f10bec87ULL;
};

template<class ContainerAllocator>
struct DataType< ::turtlebot3_example::Turtlebot3ActionGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "turtlebot3_example/Turtlebot3ActionGoal";
  }

  static const char* value(const ::turtlebot3_example::Turtlebot3ActionGoal_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::turtlebot3_example::Turtlebot3ActionGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n"
"\n"
"Header header\n"
"actionlib_msgs/GoalID goal_id\n"
"Turtlebot3Goal goal\n"
"\n"
"================================================================================\n"
"MSG: std_msgs/Header\n"
"# Standard metadata for higher-level stamped data types.\n"
"# This is generally used to communicate timestamped data \n"
"# in a particular coordinate frame.\n"
"# \n"
"# sequence ID: consecutively increasing ID \n"
"uint32 seq\n"
"#Two-integer timestamp that is expressed as:\n"
"# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n"
"# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n"
"# time-handling sugar is provided by the client library\n"
"time stamp\n"
"#Frame this data is associated with\n"
"string frame_id\n"
"\n"
"================================================================================\n"
"MSG: actionlib_msgs/GoalID\n"
"# The stamp should store the time at which this goal was requested.\n"
"# It is used by an action server when it tries to preempt all\n"
"# goals that were requested before a certain time\n"
"time stamp\n"
"\n"
"# The id provides a way to associate feedback and\n"
"# result message with specific goal requests. The id\n"
"# specified must be unique.\n"
"string id\n"
"\n"
"\n"
"================================================================================\n"
"MSG: turtlebot3_example/Turtlebot3Goal\n"
"# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n"
"# Define the goal\n"
"geometry_msgs/Vector3 goal\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Vector3\n"
"# This represents a vector in free space. \n"
"# It is only meant to represent a direction. Therefore, it does not\n"
"# make sense to apply a translation to it (e.g., when applying a \n"
"# generic rigid transformation to a Vector3, tf2 will only apply the\n"
"# rotation). If you want your data to be translatable too, use the\n"
"# geometry_msgs/Point message instead.\n"
"\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
;
  }

  static const char* value(const ::turtlebot3_example::Turtlebot3ActionGoal_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::turtlebot3_example::Turtlebot3ActionGoal_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.goal_id);
      stream.next(m.goal);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Turtlebot3ActionGoal_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::turtlebot3_example::Turtlebot3ActionGoal_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::turtlebot3_example::Turtlebot3ActionGoal_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "goal_id: ";
    s << std::endl;
    Printer< ::actionlib_msgs::GoalID_<ContainerAllocator> >::stream(s, indent + "  ", v.goal_id);
    s << indent << "goal: ";
    s << std::endl;
    Printer< ::turtlebot3_example::Turtlebot3Goal_<ContainerAllocator> >::stream(s, indent + "  ", v.goal);
  }
};

} // namespace message_operations
} // namespace ros

#endif // TURTLEBOT3_EXAMPLE_MESSAGE_TURTLEBOT3ACTIONGOAL_H
