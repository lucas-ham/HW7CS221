#pragma once

#include <list>
#include <memory>


class Hforest{
  public:
    using size_t = uint64_t;
    using tree_ptr_t = HTree::tree_ptr_t;
    Hforest(size_t size){};
    int size(){

    }
    void add_tree(tree_ptr_t tree){
    }
    tree_ptr_t pop_tree(){

    }
  private:
    size_t size;
    tree_ptr_t heaparray [size];

    // std::make_heap(first,last)
}
