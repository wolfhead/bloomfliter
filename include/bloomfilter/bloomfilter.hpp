#ifndef _BLOOMFILTER_BLOOMFILTER_HPP_
#define _BLOOMFILTER_BLOOMFILTER_HPP_
/**
  @file bloomfilter.h
  @author Wolfhead
*/
#include <stdlib.h>
#include <stdint.h>

namespace blf {

template<typename Hasher, typename Marker>
class BloomFilter {
 public:
  BloomFilter() : bytes_(0), hashes_(0), addr_(NULL) {}

  int Init(void* addr, uint64_t bytes, unsigned int hashes) {
    if (!Marker::Suitable(bytes)) {
      return -1;
    }

    bytes_ = bytes;
    hashes_ = hashes;
    addr_ = addr;
  }

  bool Check(const void* key, unsigned int len) {
    unsigned char mask;
    uint64_t index;

    for (unsigned int i = 0; i != hashes_; ++i) {
      index = Marker::Mark(Hasher::Hash(key, len, i), bytes_, &mask);
      if (!(addr_[index] & mask)) {
        return false;
      }
    }
    return true;
  }

  void Set(const void* key, unsigned int len) {
    unsigned char mask;
    uint64_t index;

    for (unsigned int i = 0; i != hashes_; ++i) {
      index = Marker::Mark(Hasher::Hash(key, len, i), bytes_, &mask);
      addr_[index] |= mask;
    }
  }

 private:
  uint64_t bytes_;
  unsigned int hashes_;
  unsigned char* addr_;
};


} //namespace blf

#endif // _BLOOMFILTER_BLOOMFILTER_HPP_

