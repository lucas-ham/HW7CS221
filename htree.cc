/*
 * HTree: a class to represent a tree node with two values: a key
 * and a value.
 */

#include "htree.hh"

// Return an optional list of directions from root to a node of a given key.
// If key not contained in this tree, returns nullptr
HTree::possible_path_t
HTree::path_to(key_t key) const
{
  if (get_key() == key){
    return possible_path_t(new path_t());
  }
  Direction dirLeft = Direction::LEFT;
  tree_ptr_t leftChild = get_child(dirLeft);
  if (leftChild){
    auto left_res = get_child(dirLeft)->path_to(key);
    if (left_res) {
      left_res->push_front(dirLeft);
      return left_res;
    }
  }
  }


  Direction dirRight = Direction::RIGHT;
  tree_ptr_t rightChild = get_child(dirRight);
  if (rightChild) {
    auto right_res = get_child(dirRight)->path_to(key);
    if (right_res) {
      right_res->push_front(dirRight);
      return right_res;
    }
  }

  return nullptr;
}

HTree::key_t HTree::get_key() const    //do we need to specify namespace for the functions?
{
  return key;
}
HTree::value_t HTree::get_value() const
{
  return value;
}

HTree::tree_ptr_t HTree::get_child(Direction dir) const
{
  const Direction dirLeft = Direction::LEFT;
  const Direction dirRight = Direction::RIGHT;
  switch (dir){
    case dirLeft:
      return left;

    case dirRight:
      return right;

    default:
      return nullptr;
  }
}

HTree::HTree(key_t key,
      value_t value,
      tree_ptr_t left,
      tree_ptr_t right)
      : key(key), value(value), left(left), right(right)
       {
       }
