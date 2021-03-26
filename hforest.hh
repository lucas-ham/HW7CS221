#pragma once

#include <list>
#include <memory>
#include "htree.hh" //come back to this, should probably remove (?)


class Hforest{
  public:
    using size_t = uint64_t;
    using tree_ptr_t = HTree::tree_ptr_t;
    Hforest(size_t size);
    void add_tree(tree_ptr_t tree);
    tree_ptr_t pop_tree();
  private:
    size_t size_;
    //tree_ptr_t heaparray_ [];
    vector<tree_ptr_t> forest_vect;

    //how do we initialize an array without really specifying size?
      //ie for heaparray_, needs to be declared but dont' really wanna declare it
    //linking HTree to this file? Using compiler isn't working at the moment
      //do we need to use Makefile?
      //is including htree.hh wrong?


    // std::make_heap(first,last)
};
