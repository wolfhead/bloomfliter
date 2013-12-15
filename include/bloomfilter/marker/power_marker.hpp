#ifndef _BLOOMFILTER_MARKER_POWER_MARKER_HPP_
#define _BLOOMFILTER_MARKER_POWER_MARKER_HPP_
/**
  @file power_marker.hpp
  @author Wolfhead
*/

namespace blf {

class PowerMarker {
 public:
  static uint64_t Mark(uint64_t hash, uint64_t size, unsigned char* mask) {
    *mask = 0x01 << (hash & 0x07);
    return (hash >> 3) & (size - 1);
  }

  static bool Suitable(uint64_t size) {
    return (size & (size - 1)) == 0;
  }
};

} //namespace blf

#endif // _BLOOMFILTER_MARKER_POWER_MARKER_HPP_

