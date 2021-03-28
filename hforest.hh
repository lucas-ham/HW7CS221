#pragma once

#include <list>
#include <memory>
#include <vector>
#include "htree.hh" //come back to this, should probably remove (?)


class Hforest{
  public:
    using size_t = uint64_t;
    using tree_ptr_t = HTree::tree_ptr_t;
    using forest_ptr_t = std::shared_ptr<Hforest>;

    void add_tree(tree_ptr_t tree);
    tree_ptr_t pop_tree();
    int size();
		Hforest();
		~Hforest() = default;
  private:
    std::vector<tree_ptr_t> forest_vect;
};
