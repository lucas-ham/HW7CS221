/*
 * test_tree: A simple unit test for the Tree data structure.
 */

#include "htree.hh"
#include <cassert>

#include <iostream>

using namespace std;

// Create an elaborate example test tree:
HTree::tree_ptr_t create_test_tree()
{
  return
    make_shared<HTree>(126, 1,
		make_shared<HTree>(50, 1,				//left child of root
			make_shared<HTree>(30, 1, nullptr, 		//left child of left child of root
				make_shared<HTree>(50, 1)		//left of left of left of root	
				),	
			make_shared<HTree>(20, 1,			//right of left of root
				make_shared<HTree>(40, 1,		//left of right of left of root
					make_shared<HTree>(10, 1),	//left of left of right of left of root
					make_shared<HTree>(5, 1)	//right of left of right of left of root	
					),
				make_shared<HTree>(80, 1,		//right of right of left of root
					make_shared<HTree>(126, 1),	//left of right of right of left of root
					make_shared<HTree>(40, 1)	//right of right of right of left of root
					)
				)
		    )
		);
}

void test_htree(const HTree::tree_ptr_t root)
{
  assert(*(root->path_to(126)) == HTree::path_t({ }));

  assert(*(root->path_to(50)) == HTree::path_t({ HTree::Direction::LEFT }) ); 

  assert(*(root->path_to(20)) == HTree::path_t({HTree::Direction::LEFT, HTree::Direction::RIGHT}));

  assert((root->get_child(HTree::Direction::LEFT))->get_key()  == 50);

  assert(((root->get_child(HTree::Direction::LEFT))->get_child(HTree::Direction::RIGHT))->get_key() == 20); 

}

int main()
{
  auto root = create_test_tree();
  test_htree(root);

  return 0;
}
