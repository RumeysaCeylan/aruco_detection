// Generated by gencpp from file basit_uygulamalar/Mesafe.msg
// DO NOT EDIT!


#ifndef BASIT_UYGULAMALAR_MESSAGE_MESAFE_H
#define BASIT_UYGULAMALAR_MESSAGE_MESAFE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace basit_uygulamalar
{
template <class ContainerAllocator>
struct Mesafe_
{
  typedef Mesafe_<ContainerAllocator> Type;

  Mesafe_()
    : mesafe(0.0)  {
    }
  Mesafe_(const ContainerAllocator& _alloc)
    : mesafe(0.0)  {
  (void)_alloc;
    }



   typedef double _mesafe_type;
  _mesafe_type mesafe;





  typedef boost::shared_ptr< ::basit_uygulamalar::Mesafe_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::basit_uygulamalar::Mesafe_<ContainerAllocator> const> ConstPtr;

}; // struct Mesafe_

typedef ::basit_uygulamalar::Mesafe_<std::allocator<void> > Mesafe;

typedef boost::shared_ptr< ::basit_uygulamalar::Mesafe > MesafePtr;
typedef boost::shared_ptr< ::basit_uygulamalar::Mesafe const> MesafeConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::basit_uygulamalar::Mesafe_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::basit_uygulamalar::Mesafe_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::basit_uygulamalar::Mesafe_<ContainerAllocator1> & lhs, const ::basit_uygulamalar::Mesafe_<ContainerAllocator2> & rhs)
{
  return lhs.mesafe == rhs.mesafe;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::basit_uygulamalar::Mesafe_<ContainerAllocator1> & lhs, const ::basit_uygulamalar::Mesafe_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace basit_uygulamalar

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::basit_uygulamalar::Mesafe_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::basit_uygulamalar::Mesafe_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::basit_uygulamalar::Mesafe_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::basit_uygulamalar::Mesafe_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::basit_uygulamalar::Mesafe_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::basit_uygulamalar::Mesafe_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::basit_uygulamalar::Mesafe_<ContainerAllocator> >
{
  static const char* value()
  {
    return "67ce55637aff33e83a28f98ea42e7243";
  }

  static const char* value(const ::basit_uygulamalar::Mesafe_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x67ce55637aff33e8ULL;
  static const uint64_t static_value2 = 0x3a28f98ea42e7243ULL;
};

template<class ContainerAllocator>
struct DataType< ::basit_uygulamalar::Mesafe_<ContainerAllocator> >
{
  static const char* value()
  {
    return "basit_uygulamalar/Mesafe";
  }

  static const char* value(const ::basit_uygulamalar::Mesafe_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::basit_uygulamalar::Mesafe_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float64 mesafe\n"
;
  }

  static const char* value(const ::basit_uygulamalar::Mesafe_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::basit_uygulamalar::Mesafe_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.mesafe);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Mesafe_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::basit_uygulamalar::Mesafe_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::basit_uygulamalar::Mesafe_<ContainerAllocator>& v)
  {
    s << indent << "mesafe: ";
    Printer<double>::stream(s, indent + "  ", v.mesafe);
  }
};

} // namespace message_operations
} // namespace ros

#endif // BASIT_UYGULAMALAR_MESSAGE_MESAFE_H
