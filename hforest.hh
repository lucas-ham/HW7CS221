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

/*
Thread 2 received signal SIGSEGV, Segmentation fault.
      0x0000000100006898 in std::__1::list<HTree::Direction, std::__1::allocator<HTree::Direction> >::size (this=0x0)
    at /Library/Developer/CommandLineTools/usr/bin/../include/c++/v1/list:932
932	    size_type size() const _NOEXCEPT     {return base::__sz();}


929 	    allocator_type get_allocator() const _NOEXCEPT;
 930
 931 	    _LIBCPP_INLINE_VISIBILITY
-> 932 	    size_type size() const _NOEXCEPT     {return base::__sz();}
 933 	    _LIBCPP_NODISCARD_AFTER_CXX17 _LIBCPP_INLINE_VISIBILITY
 934 	    bool empty() const _NOEXCEPT         {return base::empty();}
 935 	    _LIBCPP_INLINE_VISIBILITY

*/


    // std::make_heap(first,last)
};
