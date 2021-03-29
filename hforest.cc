#include "hforest.hh"

bool compare_trees(Hforest::tree_ptr_t t1, Hforest::tree_ptr_t t2) {

  return t1->get_value() < t2->get_value();

}

//Hforest::Hforest()
//	: forest_vect({})
//{}

int Hforest::size() {
  return forest_vect.size();
}

void Hforest::add_tree(tree_ptr_t tree) { 				//doesn't care if the forest is empty or not, still works on an empty forest
  forest_vect.push_back(tree);							//add to the vector aribtrarily
  std::make_heap(forest_vect.begin(), forest_vect.end(), compare_trees);	//this makes the entire vector into a heap, only one element that isn't already organized into the heap
}

Hforest::tree_ptr_t Hforest::pop_tree() {
  if (forest_vect.size() == 0){    		//first check that the forest is not empty
    return nullptr;
  }
  Hforest::tree_ptr_t highest = forest_vect[0];			//heap is sorted, so the highest tree starts in the 0 index
  std::pop_heap(forest_vect.begin(), forest_vect.end());	//pop_heap keeps the heap structure intact while removing the highest element
  return highest;	// max heap has highest valued tree at 0 index
}
