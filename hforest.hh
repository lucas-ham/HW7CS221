#pragma once

#include <list>
#include <memory>
#include <vector>
#include "htree.hh" //come back to this, should probably remove (?)


class Hforest{
  public:
    using size_t = uint64_t;
    using tree_ptr_t = HTree::tree_ptr_t;

    void add_tree(tree_ptr_t tree);
    tree_ptr_t pop_tree();
    int size();
  private:
    //tree_ptr_t heaparray_ [];
    std::vector<tree_ptr_t> forest_vect;

    //how do we initialize an array without really specifying size?
      //ie for heaparray_, needs to be declared but dont' really wanna declare it
    //linking HTree to this file? Using compiler isn't working at the moment
      //do we need to use Makefile?
      //is including htree.hh wrong?


    // std::make_heap(first,last)
};
