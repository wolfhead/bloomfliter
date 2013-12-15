#ifndef _BLOOMFILTER_MARKER_NAIVE_MARKER_HPP_
#define _BLOOMFILTER_MARKER_NAIVE_MARKER_HPP_
/**
  @file naive_marker.hpp
  @author Wolfhead
*/

namespace blf {

class NaiveMarker {
 public:
  /**
    translate the hash code into the index of the byte and a mask of the bit
    @param hash the hash code
    @param size size in bytes
    @param mask
    @return the index in byte
  */
  static uint64_t Mark(uint64_t hash, uint64_t size, unsigned char* mask) {
    *mask = 0x01 << (hash 0x07);
    return (hash >> 3) % size;
  }

  static bool Suitable(uint64_t size) {
    return true;
  }
 
};

} //namespace blf

#endif // _BLOOMFILTER_MARKER_NAIVE_MARKER_HPP_

