#include "hforest.hh"


Hforest::Hforest(size_t size)
  : size_(size)
  {
  heaparray_ = tree_ptr_t array [size];
}
