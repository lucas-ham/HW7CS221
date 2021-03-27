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
  if (this->get_key() == key){
    return possible_path_t(new path_t());
  }
  Direction dirLeft = Direction::LEFT;
  tree_ptr_t leftChild = this->get_child(dirLeft);

  if (leftChild){
    const auto left_res = this->get_child(dirLeft)->path_to(key);
    if (left_res) {
      possible_path_t return_ptr;
      *return_ptr = {dirLeft};
      return_ptr->splice(return_ptr->end(), *left_res);
      return return_ptr;
    }
  }


  Direction dirRight = Direction::RIGHT;
  tree_ptr_t rightChild = this->get_child(dirRight);
  if (rightChild) {
    const auto right_res = this->get_child(dirRight)->path_to(key);
    if (right_res) {
      possible_path_t return_ptr;
      *return_ptr = {dirRight};
      return_ptr->splice(return_ptr->end(), *right_res);
      return return_ptr;
    }
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
  const Direction dirLeft = Direction::LEFT;
  const Direction dirRight = Direction::RIGHT;
  switch (dir){
    case dirLeft:
      return this->left;

    case dirRight:
      return this->right;

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
