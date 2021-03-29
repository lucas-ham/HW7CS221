#include <cassert>

#include "hforest.hh"
#include "htree.hh"

#include <iostream>


//Hforest::forest_ptr_t create_forest(){
Hforest create_forest(){
	//Hforest::forest_ptr_t forest = std::make_shared<new Hforest>; 		//intialize forest
	auto forest = Hforest(); 
	forest.add_tree(std::make_shared<HTree>(1, 10));
	forest.add_tree(std::make_shared<HTree>(2, 20));
	forest.add_tree(std::make_shared<HTree>(3, 5));
	forest.add_tree(std::make_shared<HTree>(4, 50));

	return forest;

}

void test_forest(Hforest frst){
	assert((frst.pop_tree())->get_key() == 4);
}


int main() {
	auto forest = create_forest();
	test_forest(forest);
	return 0;
}
