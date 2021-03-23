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
  if (!this){
    return nullptr
  }
  if (this->get_key() == key){
    return {};
  }
  Direction dirLeft = LEFT;
  const auto left_res = path_to(this.get_child(dirLeft), key);
  if (left_res) {
    std::list return_list = {dirLeft};
    return return_list.splice(return_list.end(), left_res);
  }
  Direction dirRight = RIGHT;
  const auto right_res = path_to(this.get_child(dirRight), key);
  if (right_res) {
    std::list return_list = {dirRight};
    return return_list.splice(return_list.end(), right_res);
  } else{
    return nullptr;
  }

  return nullptr;
}

HTree::key_t HTree::get_key() const    //do we need to specify namespace for the functions?
{
  return this->key;
}
HTree::value_t HTree::get_value() const
{
  return this->value;
}

HTree::tree_ptr_t HTree::get_child(Direction dir) const
{
  switch (dir){
    case LEFT:
      return this->left;

    case RIGHT:
      return this->right;

    default:
      return nullptr;
  }
}
