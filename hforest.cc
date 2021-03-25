#include "hforest.hh"


Hforest::Hforest(size_t size)
  : size(size)
  {
  heaparray = tree_ptr_t array [size];
}
