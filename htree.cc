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
  if (this.get_key() == key){
    return {};
  }
  const auto left_res = path_to(this.get_child("LEFT"), key);
  if left_res {
    std::list return_list = {LEFT};
    return return_list.splice(return_list.end(), left_res);
  }

  const auto right_res = path_to(this.get_child("RIGHT"), key);
  if right_res {
    std::list return_list = {RIGHT};
    return return_list.splice(return_list.end(), right_res);
  } else{
    return nullptr;
  }
}
//
// std::string path_to(tree_ptr_t tree, key_type key)
// {
//   if (!tree) {
//     return "-";
//   }
//
//   if (tree->key_ == key) {
//     return "";
//   }
//
//   const auto left_res = path_to(tree->left_, key);
//   if (left_res != "-") {
//     return "L" + left_res;
//   }
//   const auto right_res = path_to(tree->right_, key);
//   if (right_res == "-") {
//     return "-";
//   } else {
//     return "R" + right_res;
//   }
// }
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
    case "LEFT":
      return this->left;

    case "RIGHT":
      return this->right;

    default:
      return nullptr;
  }
}
