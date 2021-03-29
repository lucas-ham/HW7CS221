#include <cassert>

#include "hforest.hh"
#include "htree.hh"

#include <iostream>


//Hforest::forest_ptr_t create_forest(){
Hforest create_forest(){
	//Hforest::forest_ptr_t forest = std::make_shared<new Hforest>; 		//intialize forest
	auto forest = Hforest();
	forest.add_tree(std::make_shared<HTree>(1, 10, nullptr, nullptr));
	forest.add_tree(std::make_shared<HTree>(2, 20, nullptr, nullptr));
	forest.add_tree(std::make_shared<HTree>(3, 5, nullptr, nullptr));
	forest.add_tree(std::make_shared<HTree>(4, 50, nullptr, nullptr));  			//add trees, this also tests the add_tree method

	return forest;

}

void test_forest(Hforest frst){
	assert((frst.size()) == 4);										//test size of tree

	assert((frst.pop_tree())->get_key() == 4);		//test pop_tree

	assert((frst.size()) == 3);										//test size after pop_tree

	assert((frst.pop_tree())->get_key() == 2);		//test pop_tree again

	frst.pop_tree();
	frst.pop_tree();															//empty tree of all values

	std::cout<<frst.size();
	assert(frst.size() == 0);											//check that size is empty

	assert(frst.pop_tree() == nullptr);						//test pop_tree on an empty forest, return nullptr
}


int main() {
	auto forest = create_forest();
	test_forest(forest);
	return 0;
}
