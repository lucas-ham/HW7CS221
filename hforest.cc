#include "hforest.hh"

bool compare_trees(tree_ptr_t t1, tree_ptr_t t2) {

    return t1->get_value() < t2->get_value();

}

int Hforest::size() {
  return forest_vect.size();
}

void Hforest::add_tree(tree_ptr_t tree) {
  forest_vect.push_back(tree);
  std::make_heap(forest_vect.begin(), forest_vect.end(), compare_trees);
}

Hforest::tree_ptr_t Hforest::pop_tree() {
  Hforest::tree_ptr_t highest = forest_vect[0];
  std::pop_heap(forest_vect.begin(), forest_vect.end());
  return highest;
}
